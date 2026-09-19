#if HAS_PTHREAD && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#if HAS_PTHREAD
#include <pthread.h>
#include <time.h>
#endif
#if HAS_UNISTD
#include <unistd.h>
#include <sys/stat.h>
#endif

#include "c.h"
#include "reader.h"
#include "output_internal.h"
#include "output_test.h"
#include "path.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testOutputs: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

typedef struct CapturedOutput {
    char name[64];
    WasmOutputKind kind;
    U8* bytes;
    size_t length;
} CapturedOutput;

typedef struct OutputTrace {
    size_t writes;
    bool writeFailed;
    bool closed;
    bool aborted;
} OutputTrace;

typedef enum OutputFailure {
    outputSuccess,
    outputOpenFailure,
    outputWriteFailure,
    outputCloseFailure,
    outputCompleteFailure
} OutputFailure;

typedef struct OutputCapture {
#if HAS_PTHREAD
    pthread_mutex_t mutex;
#endif
    CapturedOutput files[8];
    size_t count;
    OutputTrace traces[8];
    size_t opened;
    size_t diagnosticCount;
    WasmDiagnosticCode diagnosticCode;
    int systemError;
    OutputFailure failure;
    const char* failureName;
    const char* failureBytes;
    WasmMemoryOutput memory;
} OutputCapture;

typedef struct TracedSink {
    OutputCapture* capture;
    WasmOutputSink inner;
    size_t index;
    bool selected;
} TracedSink;

static void captureLock(OutputCapture* capture) {
#if HAS_PTHREAD
    CHECK(pthread_mutex_lock(&capture->mutex) == 0);
#else
    UNUSED_PARAMETER(capture);
#endif
}

static void captureUnlock(OutputCapture* capture) {
#if HAS_PTHREAD
    CHECK(pthread_mutex_unlock(&capture->mutex) == 0);
#else
    UNUSED_PARAMETER(capture);
#endif
}

static
WasmBool
captureComplete(
    void* context, const char* name, WasmOutputKind kind,
    const U8* bytes, size_t length, int* systemError
) {
    OutputCapture* capture = (OutputCapture*)context;
    CapturedOutput* file;
    CHECK(bytes[length] == 0);
    if (capture->failure == outputCompleteFailure
        && strcmp(name, capture->failureName) == 0) {
        *systemError = EIO;
        return false;
    }
    captureLock(capture);
    CHECK(capture->count < 8);
    file = &capture->files[capture->count++];
    CHECK(strlen(name) < sizeof(file->name));
    strcpy(file->name, name);
    file->kind = kind;
    file->length = length;
    file->bytes = (U8*)malloc(length + 1);
    CHECK(file->bytes != NULL);
    memcpy(file->bytes, bytes, length + 1);
    captureUnlock(capture);
    return true;
}

static
void
captureInitialize(OutputCapture* capture) {
    memset(capture, 0, sizeof(*capture));
#if HAS_PTHREAD
    CHECK(pthread_mutex_init(&capture->mutex, NULL) == 0);
#endif
    capture->memory.context = capture;
    capture->memory.complete = captureComplete;
}

static
void
captureFree(OutputCapture* capture) {
    size_t index;
    for (index = 0; index < capture->count; index++) {
        free(capture->files[index].bytes);
    }
#if HAS_PTHREAD
    CHECK(pthread_mutex_destroy(&capture->mutex) == 0);
#endif
}

static
void
captureDiagnostic(void* context, const WasmDiagnostic* diagnostic) {
    OutputCapture* capture = (OutputCapture*)context;
    captureLock(capture);
    capture->diagnosticCount++;
    capture->diagnosticCode = diagnostic->code;
    switch (diagnostic->code) {
        case wasmDiagnosticOutputOpenFailed:
        case wasmDiagnosticOutputWriteFailed:
        case wasmDiagnosticOutputCloseFailed:
            capture->systemError = diagnostic->info.outputFailed.systemError;
            CHECK(strcmp(diagnostic->info.outputFailed.name, capture->failureName) == 0);
            CHECK(strcmp(diagnostic->location.outputName, capture->failureName) == 0);
            break;
        default:
            break;
    }
    captureUnlock(capture);
    errno = EDOM;
}

static
WasmBool
tracedWrite(void* context, const U8* bytes, size_t length, int* systemError) {
    TracedSink* sink = (TracedSink*)context;
    OutputTrace* trace = &sink->capture->traces[sink->index];
    CHECK(!trace->closed && !trace->aborted && !trace->writeFailed);
    trace->writes++;
    if (sink->selected && sink->capture->failure == outputWriteFailure
        && (sink->capture->failureBytes == NULL
            || (length == strlen(sink->capture->failureBytes)
                && memcmp(bytes, sink->capture->failureBytes, length) == 0))) {
        if (sink->capture->failureBytes == NULL) {
            CHECK(trace->writes == 1);
        }
        trace->writeFailed = true;
        *systemError = EIO;
        return false;
    }
    return sink->inner.write(sink->inner.context, bytes, length, systemError);
}

static
WasmBool
tracedClose(void* context, int* systemError) {
    TracedSink* sink = (TracedSink*)context;
    OutputTrace* trace = &sink->capture->traces[sink->index];
    WasmBool result;
    CHECK(!trace->closed && !trace->aborted);
    trace->closed = true;
    if (sink->selected && sink->capture->failure == outputCloseFailure) {
        sink->inner.abort(sink->inner.context);
        *systemError = EIO;
        result = false;
    } else {
        result = sink->inner.close(sink->inner.context, systemError);
    }
    free(sink);
    return result;
}

static
void
tracedAbort(void* context) {
    TracedSink* sink = (TracedSink*)context;
    OutputTrace* trace = &sink->capture->traces[sink->index];
    CHECK(!trace->closed && !trace->aborted);
    trace->aborted = true;
    sink->inner.abort(sink->inner.context);
    free(sink);
}

static
WasmBool
tracedOpen(
    void* context, const char* name, WasmOutputKind kind,
    WasmOutputSink* output, int* systemError
) {
    OutputCapture* capture = (OutputCapture*)context;
    WasmOutputProvider provider = wasmMemoryOutputProvider(&capture->memory);
    const bool selected = capture->failureName != NULL
        && strcmp(name, capture->failureName) == 0;
    TracedSink* sink;
    if (selected && capture->failure == outputOpenFailure) {
        *systemError = EIO;
        return false;
    }
    sink = (TracedSink*)malloc(sizeof(*sink));
    CHECK(sink != NULL);
    CHECK(provider.open(provider.context, name, kind, &sink->inner, systemError));
    sink->capture = capture;
    sink->selected = selected;
    captureLock(capture);
    CHECK(capture->opened < 8);
    sink->index = capture->opened++;
    captureUnlock(capture);
    output->context = sink;
    output->write = tracedWrite;
    output->close = tracedClose;
    output->abort = tracedAbort;
    return true;
}

static
WasmCWriteModuleOptions
captureOptions(OutputCapture* capture) {
    WasmCWriteModuleOptions options = emptyWasmCWriteModuleOptions;
    options.outputName = "output-test.c";
    options.output.context = capture;
    options.output.open = tracedOpen;
    options.diagnostics.context = capture;
    options.diagnostics.report = captureDiagnostic;
    options.functionsPerFile = 1;
    options.threadCount = 2;
    return options;
}

static
void
checkClosed(const OutputCapture* capture) {
    size_t index;
    for (index = 0; index < capture->opened; index++) {
        const OutputTrace* trace = &capture->traces[index];
        CHECK(trace->closed != trace->aborted);
    }
}

static
const CapturedOutput*
findOutput(const OutputCapture* capture, const char* name) {
    size_t index;
    for (index = 0; index < capture->count; index++) {
        if (strcmp(capture->files[index].name, name) == 0) {
            return &capture->files[index];
        }
    }
    return NULL;
}

static
WasmModule*
readOutputModule(void) {
    static U8 bytes[] = {
        0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00,
        0x02, 0x0D, 0x01, 0x03, 'e', 'n', 'v', 0x04, 'b', 'a', 's', 'e', 0x03, 0x7F, 0x00,
        0x03, 0x03, 0x02, 0x00, 0x00,
        0x04, 0x04, 0x01, 0x70, 0x00, 0x40,
        0x05, 0x03, 0x01, 0x00, 0x01,
        0x06, 0x0B, 0x02, 0x7F, 0x00, 0x41, 0x11, 0x0B, 0x7F, 0x00, 0x23, 0x00, 0x0B,
        0x09, 0x07, 0x01, 0x00, 0x41, 0x1F, 0x0B, 0x01, 0x00,
        0x0A, 0x07, 0x02, 0x02, 0x00, 0x0B, 0x02, 0x00, 0x0B,
        0x0B, 0x0A, 0x01, 0x00, 0x41, 0x17, 0x0B, 0x04, 0x00, 0xFF, 0x0A, 0x00
    };
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    reader.buffer.data = bytes;
    reader.buffer.length = sizeof(bytes);
    wasmModuleRead(&reader, &error);
    CHECK(error == NULL);
    return reader.module;
}

static
WasmFunctionIDs
outputFunctionIDs(WasmModule* module) {
    WasmFunctionIDs ids = emptyWasmFunctionIDs;
    U32 index;
    for (index = 0; index < module->functions.count; index++) {
        WasmFunctionID id = emptyWasmFunctionID;
        id.functionIndex = index;
        memcpy(id.hash, module->functions.functions[index].hash, SHA1_DIGEST_LENGTH);
        CHECK(wasmFunctionIDsAppend(&ids, id));
    }
    return ids;
}

static
void
compareFiles(const OutputCapture* capture, const char* directory) {
    size_t index;
    for (index = 0; index < capture->count; index++) {
        const CapturedOutput* output = &capture->files[index];
        char* path = wasmPathJoin(directory, output->name);
        FILE* file;
        size_t offset;
        CHECK(path != NULL);
        file = fopen(path, output->kind == wasmOutputData ? "rb" : "r");
        CHECK(file != NULL);
        for (offset = 0; offset < output->length; offset++) {
            CHECK(fgetc(file) == output->bytes[offset]);
        }
        CHECK(fgetc(file) == EOF && !ferror(file));
        CHECK(fclose(file) == 0);
        CHECK(remove(path) == 0);
        free(path);
    }
}

static
void
testOutputEquivalence(WasmModule* module, WasmFunctionIDs ids) {
    unsigned int variant;
    U32 index;
    for (index = 0; index < module->functions.count; index++) {
        WasmDebugLine line;
        line.address = module->functions.functions[index].start;
        line.number = 10 + index;
        line.path = (char*)malloc(sizeof("output-input.c"));
        CHECK(line.path != NULL);
        strcpy(line.path, "output-input.c");
        CHECK(wasmDebugLinesAppend(&module->debugLines, line));
    }
    for (variant = 0; variant < 8; variant++) {
        OutputCapture capture;
        WasmCWriteModuleOptions options;
        WasmFunctionIDs staticIDs = ids;
        WasmFunctionIDs dynamicIDs = emptyWasmFunctionIDs;
        captureInitialize(&capture);
        options = captureOptions(&capture);
        options.dataSegmentMode = (WasmDataSegmentMode)(variant % 4);
        options.pretty = variant >= 4;
        options.debug = variant >= 4;
        options.multipleModules = variant >= 4;
        options.functionsPerFile = variant == 0 ? 2 : 1;
        if (variant >= 4) {
            staticIDs.length = 1;
            dynamicIDs = ids;
            dynamicIDs.functionIDs++;
            dynamicIDs.length = 1;
        }
        CHECK(wasmCWriteModule(module, "outputTest", options, staticIDs, dynamicIDs));
        CHECK(capture.diagnosticCount == 0);
        CHECK(findOutput(&capture, "output-test.h") != NULL);
        CHECK(findOutput(&capture, "output-test.c") != NULL);
        if (options.dataSegmentMode != wasmDataSegmentModeArrays) {
            const CapturedOutput* data = findOutput(&capture, "datasegments");
            static const U8 expected[] = {0x00, 0xFF, 0x0A, 0x00};
            CHECK(data != NULL && data->kind == wasmOutputData);
            CHECK(data->length == sizeof(expected));
            CHECK(memcmp(data->bytes, expected, sizeof(expected)) == 0);
        }
        checkClosed(&capture);
        CHECK(fopen("output-test.c", "r") == NULL && errno == ENOENT);
        CHECK(fopen("output-test.h", "r") == NULL && errno == ENOENT);
        options.output = wasmFileOutputProvider(".");
        CHECK(wasmCWriteModule(module, "outputTest", options, staticIDs, dynamicIDs));
        compareFiles(&capture, ".");
        captureFree(&capture);
    }
}

static
void
testWorkerCounts(WasmModule* module, WasmFunctionIDs ids) {
    static const struct {
        size_t staticCount;
        size_t dynamicCount;
        U32 functionsPerFile;
    } cases[] = {
        {0, 0, 1},
        {2, 0, 1},
        {0, 2, 1},
        {1, 1, 1},
        {0, 2, 2},
        {0, 2, 0}
    };
    static const U32 threadCounts[] = {0, 2, UINT32_MAX};
    WasmModule emptyModule;
    size_t variant;
    memset(&emptyModule, 0, sizeof(emptyModule));

    for (variant = 0; variant < sizeof(cases) / sizeof(cases[0]); variant++) {
        const WasmModule* input = cases[variant].staticCount + cases[variant].dynamicCount == 0
            ? &emptyModule : module;
        WasmFunctionIDs staticIDs = ids;
        WasmFunctionIDs dynamicIDs = ids;
        WasmCWriteModuleOptions options;
        OutputCapture expected;
        size_t index;

        staticIDs.length = cases[variant].staticCount;
        dynamicIDs.functionIDs += staticIDs.length;
        dynamicIDs.length = cases[variant].dynamicCount;

        captureInitialize(&expected);
        options = captureOptions(&expected);
        options.functionsPerFile = cases[variant].functionsPerFile;
        options.threadCount = 1;
        CHECK(wasmCWriteModule(input, "outputTest", options, staticIDs, dynamicIDs));
        CHECK(expected.diagnosticCount == 0);
        checkClosed(&expected);

        for (index = 0; index < sizeof(threadCounts) / sizeof(threadCounts[0]); index++) {
            OutputCapture actual;
            size_t fileIndex;
            captureInitialize(&actual);
            options = captureOptions(&actual);
            options.functionsPerFile = cases[variant].functionsPerFile;
            options.threadCount = threadCounts[index];
            CHECK(wasmCWriteModule(input, "outputTest", options, staticIDs, dynamicIDs));
            CHECK(actual.diagnosticCount == 0);
            CHECK(actual.count == expected.count);
            for (fileIndex = 0; fileIndex < expected.count; fileIndex++) {
                const CapturedOutput* reference = &expected.files[fileIndex];
                const CapturedOutput* output = findOutput(&actual, reference->name);
                CHECK(output != NULL);
                CHECK(output->kind == reference->kind);
                CHECK(output->length == reference->length);
                CHECK(memcmp(output->bytes, reference->bytes, output->length) == 0);
            }
            checkClosed(&actual);
            captureFree(&actual);
        }
        captureFree(&expected);
    }
}

static
void
testProviderFailures(WasmModule* module, WasmFunctionIDs ids) {
    static const char* names[] = {
        "output-test.h", "output-test.c", "s0000000000.c", "datasegments"
    };
    size_t index;
    OutputFailure failure;
    for (index = 0; index < sizeof(names) / sizeof(names[0]); index++) {
        for (failure = outputOpenFailure; failure <= outputCompleteFailure; failure++) {
            OutputCapture capture;
            WasmCWriteModuleOptions options;
            captureInitialize(&capture);
            capture.failure = failure;
            capture.failureName = names[index];
            options = captureOptions(&capture);
            options.threadCount = UINT32_MAX;
            options.dataSegmentMode = wasmDataSegmentModeGNULD;
            CHECK(!wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
            CHECK(capture.diagnosticCount == 1);
            CHECK(capture.systemError == EIO);
            CHECK(capture.diagnosticCode == (failure == outputOpenFailure
                ? wasmDiagnosticOutputOpenFailed : failure == outputWriteFailure
                ? wasmDiagnosticOutputWriteFailed : wasmDiagnosticOutputCloseFailed));
            CHECK(findOutput(&capture, names[index]) == NULL);
            if (index == 1 && failure <= outputWriteFailure) {
                CHECK(capture.opened == (failure == outputOpenFailure ? 1U : 2U));
            }
            checkClosed(&capture);
            captureFree(&capture);
            captureInitialize(&capture);
            options = captureOptions(&capture);
            CHECK(wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
            CHECK(capture.diagnosticCount == 0);
            checkClosed(&capture);
            captureFree(&capture);
        }
    }
}

static
void
testConstantExpressions(WasmModule* module, WasmFunctionIDs ids) {
    static const char* values[] = {"17", "23", "31"};
    static U8 invalidConstant[] = {0x41};
    Buffer* expressions[3];
    size_t index;
    OutputCapture capture;
    WasmCWriteModuleOptions options;
    const CapturedOutput* generated;
    captureInitialize(&capture);
    options = captureOptions(&capture);
    CHECK(wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
    generated = findOutput(&capture, "output-test.c");
    CHECK(generated != NULL);
    CHECK(strstr((const char*)generated->bytes, "i->g1=17U;") != NULL);
    CHECK(strstr((const char*)generated->bytes, "i->g2=(*i->env__base);") != NULL);
    CHECK(strstr((const char*)generated->bytes, "23U") != NULL);
    CHECK(strstr((const char*)generated->bytes, "offset=31U;") != NULL);
    CHECK(capture.diagnosticCount == 0);
    checkClosed(&capture);
    captureFree(&capture);

    expressions[0] = &module->globals.globals[0].init;
    expressions[1] = &module->dataSegments.dataSegments[0].offset;
    expressions[2] = &module->elementSegments.elementSegments[0].offset;
    for (index = 0; index < 3; index++) {
        const Buffer previous = *expressions[index];
        captureInitialize(&capture);
        capture.failure = outputWriteFailure;
        capture.failureName = "output-test.c";
        capture.failureBytes = values[index];
        options = captureOptions(&capture);
        CHECK(!wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
        CHECK(capture.diagnosticCount == 1);
        CHECK(capture.diagnosticCode == wasmDiagnosticOutputWriteFailed);
        CHECK(capture.systemError == EIO);
        CHECK(findOutput(&capture, "output-test.c") == NULL);
        checkClosed(&capture);
        captureFree(&capture);

        captureInitialize(&capture);
        capture.failure = outputCloseFailure;
        capture.failureName = "output-test.c";
        options = captureOptions(&capture);
        expressions[index]->data = invalidConstant;
        expressions[index]->length = sizeof(invalidConstant);
        CHECK(!wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
        CHECK(capture.diagnosticCount == 1);
        CHECK(capture.diagnosticCode == wasmDiagnosticInvalidInstruction);
        CHECK(findOutput(&capture, "output-test.c") == NULL);
        checkClosed(&capture);
        captureFree(&capture);
        *expressions[index] = previous;
    }
}

static
void
testMemoryEdges(void) {
    OutputCapture capture;
    WasmOutputProvider provider;
    WasmOutputSink sink;
    int systemError = 0;
    U8 byte = 1;
    captureInitialize(&capture);
    provider = wasmMemoryOutputProvider(&capture.memory);
    CHECK(provider.open(provider.context, "empty", wasmOutputData, &sink, &systemError));
    CHECK(sink.close(sink.context, &systemError));
    CHECK(capture.count == 1 && capture.files[0].length == 0);
    CHECK(provider.open(provider.context, "overflow", wasmOutputData, &sink, &systemError));
    CHECK(!sink.write(sink.context, &byte, (size_t)-1, &systemError));
    CHECK(systemError == ENOMEM);
    sink.abort(sink.context);
    CHECK(capture.count == 1);
    captureFree(&capture);
}

static
void
testOutputBuffer(void) {
    static const U8 bytes[] = {0, 1, 0xFF, 0};
    OutputBuffer buffer = emptyOutputBuffer;
    size_t index;
    CHECK(outputBufferInitialize(&buffer));
    CHECK(buffer.length == 0 && buffer.data[0] == 0);
    CHECK(outputBufferAppend(&buffer, NULL, 0));
    for (index = 0; index < 128; index++) {
        CHECK(outputBufferAppend(&buffer, bytes, sizeof(bytes)));
        CHECK(buffer.length == (index + 1) * sizeof(bytes));
        CHECK(buffer.data[buffer.length] == 0);
    }
    {
        U8* data = buffer.data;
        const size_t capacity = buffer.capacity;
        CHECK(!outputBufferAppend(&buffer, bytes, (size_t)-1));
        CHECK(!outputBufferAppend(&buffer, bytes, (size_t)-1 - buffer.length));
        CHECK(buffer.data == data && buffer.capacity == capacity);
        CHECK(buffer.length == 128 * sizeof(bytes));
        CHECK(buffer.data[buffer.length] == 0);
    }
    for (index = 0; index < 128; index++) {
        CHECK(memcmp(buffer.data + index * sizeof(bytes), bytes, sizeof(bytes)) == 0);
    }
    outputBufferFree(&buffer);
    CHECK(buffer.data == NULL && buffer.length == 0 && buffer.capacity == 0);
}

static
void
testOutputFormatting(void) {
    static const char* expected =
        "4294967295 2147483647 -2147483647 -2147483648\n"
        "18446744073709551615 9223372036854775807 -9223372036854775807 -9223372036854775808\n"
        "FFFFFFFF 00000001 FFFFFFFFFFFFFFFF 0000000000000001\n"
        "0.100000001 0.10000000000000001";
    OutputBuffer buffer = emptyOutputBuffer;
    WasmDiagnosticContext diagnostics = emptyWasmDiagnosticContext;
    WasmOutput output;
    CHECK(outputBufferInitialize(&buffer));
    output = wasmOutputForBuffer(&buffer, &diagnostics);
    wasmOutputU32(&output, UINT32_MAX);
    wasmOutputChar(&output, ' ');
    wasmOutputI32(&output, INT32_MAX);
    wasmOutputChar(&output, ' ');
    wasmOutputI32(&output, INT32_MIN + 1);
    wasmOutputChar(&output, ' ');
    wasmOutputI32(&output, INT32_MIN);
    wasmOutputChar(&output, '\n');
    wasmOutputU64(&output, UINT64_MAX);
    wasmOutputChar(&output, ' ');
    wasmOutputI64(&output, INT64_MAX);
    wasmOutputChar(&output, ' ');
    wasmOutputI64(&output, INT64_MIN + 1);
    wasmOutputChar(&output, ' ');
    wasmOutputI64(&output, INT64_MIN);
    wasmOutputChar(&output, '\n');
    wasmOutputU32Hex(&output, UINT32_MAX);
    wasmOutputChar(&output, ' ');
    wasmOutputU32Hex(&output, 1);
    wasmOutputChar(&output, ' ');
    wasmOutputU64Hex(&output, UINT64_MAX);
    wasmOutputChar(&output, ' ');
    wasmOutputU64Hex(&output, 1);
    wasmOutputChar(&output, '\n');
    wasmOutputF32(&output, 0.1F);
    wasmOutputChar(&output, ' ');
    wasmOutputF64(&output, 0.1);
    CHECK(wasmOutputClose(&output));
    CHECK(buffer.length == strlen(expected));
    CHECK(strcmp((const char*)buffer.data, expected) == 0);
    outputBufferFree(&buffer);
}

static
void
testBorrowedBuffer(void) {
    OutputBuffer builder = emptyOutputBuffer;
    WasmDiagnosticContext diagnostics = emptyWasmDiagnosticContext;
    WasmOutput output;
    OutputCapture capture;
    U8 byte = 1;
    captureInitialize(&capture);
    capture.failureName = "buffer.c";
    diagnostics.location.outputName = capture.failureName;
    diagnostics.diagnostics.context = &capture;
    diagnostics.diagnostics.report = captureDiagnostic;
    CHECK(outputBufferInitialize(&builder));
    output = wasmOutputForBuffer(&builder, &diagnostics);
    wasmOutputHex(&output, 10, wasmOutputHexUpperPadded);
    wasmOutputChar(&output, '/');
    wasmOutputHex(&output, 10, wasmOutputHexLower);
    CHECK(wasmOutputClose(&output));
    CHECK(strcmp((const char*)builder.data, "0A/a") == 0);

    output = wasmOutputForBuffer(&builder, &diagnostics);
    wasmOutputWrite(&output, &byte, (size_t)-1);
    CHECK(output.failed);
    CHECK(capture.diagnosticCount == 1);
    CHECK(capture.diagnosticCode == wasmDiagnosticOutputWriteFailed);
    CHECK(capture.systemError == ENOMEM);
    wasmOutputString(&output, "ignored");
    CHECK(!wasmOutputClose(&output));
    CHECK(capture.diagnosticCount == 1);
    CHECK(builder.length == 4 && strcmp((const char*)builder.data, "0A/a") == 0);
    outputBufferFree(&builder);
    captureFree(&capture);
}

static
void
testAbortedTranslation(WasmModule* module, WasmFunctionIDs ids) {
    static U8 invalidCall[] = {0x10};
    const Buffer previous = module->functions.functions[0].code;
    OutputCapture capture;
    WasmCWriteModuleOptions options;
    captureInitialize(&capture);
    options = captureOptions(&capture);
    module->functions.functions[0].code.data = invalidCall;
    module->functions.functions[0].code.length = sizeof(invalidCall);
    /* A prior diagnostic suppresses secondary output errors. */
    capture.failure = outputCloseFailure;
    capture.failureName = "s0000000000.c";
    CHECK(!wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
    CHECK(capture.diagnosticCount == 1);
    CHECK(capture.diagnosticCode == wasmDiagnosticInvalidInstruction);
    CHECK(findOutput(&capture, "s0000000000.c") == NULL);
    CHECK(findOutput(&capture, "output-test.c") == NULL);
    checkClosed(&capture);
    module->functions.functions[0].code = previous;
    captureFree(&capture);
}

#if HAS_PTHREAD
typedef struct HandoffOutput {
    OutputCapture capture;
    pthread_cond_t ready;
    size_t started;
    bool stalled;
} HandoffOutput;

static
WasmBool
handoffOpen(
    void* context, const char* name, WasmOutputKind kind,
    WasmOutputSink* output, int* systemError
) {
    HandoffOutput* handoff = (HandoffOutput*)context;
    if (kind == wasmOutputC && (name[0] == 's' || name[0] == 'd')) {
        struct timespec deadline;
        deadline.tv_sec = time(NULL) + 10;
        deadline.tv_nsec = 0;

        captureLock(&handoff->capture);
        handoff->started++;
        CHECK(pthread_cond_broadcast(&handoff->ready) == 0);
        /*
         * No job may finish before all four workers have started.
         * The deadline only prevents a lost notification from hanging the test.
         */
        while (handoff->started < 4 && !handoff->stalled) {
            const int result = pthread_cond_timedwait(
                &handoff->ready, &handoff->capture.mutex, &deadline
            );
            CHECK(result == 0 || result == ETIMEDOUT);
            if (result == ETIMEDOUT && handoff->started < 4) {
                handoff->stalled = true;
                CHECK(pthread_cond_broadcast(&handoff->ready) == 0);
            }
        }
        captureUnlock(&handoff->capture);
    }
    return tracedOpen(&handoff->capture, name, kind, output, systemError);
}

static
void
testWorkerHandoff(void) {
    static U8 bytes[] = {
        0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00,
        0x03, 0x05, 0x04, 0x00, 0x00, 0x00, 0x00,
        0x0A, 0x0D, 0x04,
        0x02, 0x00, 0x0B, 0x02, 0x00, 0x0B,
        0x02, 0x00, 0x0B, 0x02, 0x00, 0x0B
    };
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    WasmFunctionIDs ids;
    unsigned int dynamic;
    reader.buffer.data = bytes;
    reader.buffer.length = sizeof(bytes);
    wasmModuleRead(&reader, &error);
    CHECK(error == NULL);
    ids = outputFunctionIDs(reader.module);

    for (dynamic = 0; dynamic < 2; dynamic++) {
        HandoffOutput handoff;
        WasmCWriteModuleOptions options;
        captureInitialize(&handoff.capture);
        CHECK(pthread_cond_init(&handoff.ready, NULL) == 0);
        handoff.started = 0;
        handoff.stalled = false;
        options = captureOptions(&handoff.capture);
        options.threadCount = 4;
        options.output.context = &handoff;
        options.output.open = handoffOpen;
        CHECK(wasmCWriteModule(
            reader.module, "outputTest", options,
            dynamic ? emptyWasmFunctionIDs : ids,
            dynamic ? ids : emptyWasmFunctionIDs
        ));
        CHECK(!handoff.stalled);
        CHECK(handoff.started == 4);
        CHECK(handoff.capture.count == 6);
        CHECK(handoff.capture.diagnosticCount == 0);
        checkClosed(&handoff.capture);
        CHECK(pthread_cond_destroy(&handoff.ready) == 0);
        captureFree(&handoff.capture);
    }
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(reader.module);
}

typedef struct OutputTranslation {
    WasmModule* module;
    WasmFunctionIDs ids;
    OutputCapture capture;
    const char* directory;
} OutputTranslation;

static
void*
translateOutput(void* context) {
    OutputTranslation* translation = (OutputTranslation*)context;
    WasmCWriteModuleOptions options = captureOptions(&translation->capture);
    if (translation->directory != NULL) {
        options.output = wasmFileOutputProvider(translation->directory);
    }
    CHECK(wasmCWriteModule(translation->module, "outputTest", options,
        translation->ids, emptyWasmFunctionIDs));
    CHECK(translation->capture.diagnosticCount == 0);
    return NULL;
}

static
void
testIndependentTranslations(WasmModule* module, WasmFunctionIDs ids) {
    OutputTranslation translations[2];
    pthread_t threads[2];
    size_t index;
#if HAS_UNISTD
    char previousDirectory[4096];
    char currentDirectory[4096];
    static const char* directories[] = {"output-test [a]*", "output-test [b]?"};
    CHECK(getcwd(previousDirectory, sizeof(previousDirectory)) != NULL);
#endif
    for (index = 0; index < 2; index++) {
        translations[index].module = module;
        translations[index].ids = ids;
        translations[index].directory = NULL;
        captureInitialize(&translations[index].capture);
        CHECK(pthread_create(&threads[index], NULL, translateOutput, &translations[index]) == 0);
    }
    for (index = 0; index < 2; index++) {
        CHECK(pthread_join(threads[index], NULL) == 0);
        CHECK(translations[index].capture.count == 4);
        checkClosed(&translations[index].capture);
    }
#if HAS_UNISTD
    for (index = 0; index < 2; index++) {
        CHECK(mkdir(directories[index], 0700) == 0);
        translations[index].directory = directories[index];
        CHECK(pthread_create(&threads[index], NULL, translateOutput, &translations[index]) == 0);
    }
    for (index = 0; index < 2; index++) {
        CHECK(pthread_join(threads[index], NULL) == 0);
        compareFiles(&translations[index].capture, directories[index]);
        CHECK(rmdir(directories[index]) == 0);
    }
    CHECK(getcwd(currentDirectory, sizeof(currentDirectory)) != NULL);
    CHECK(strcmp(previousDirectory, currentDirectory) == 0);
#endif
    for (index = 0; index < 2; index++) {
        captureFree(&translations[index].capture);
    }
}
#endif

void
testOutputs(void) {
    WasmModule* module = readOutputModule();
    WasmFunctionIDs ids = outputFunctionIDs(module);
    testOutputEquivalence(module, ids);
    testWorkerCounts(module, ids);
    testProviderFailures(module, ids);
    testConstantExpressions(module, ids);
    testMemoryEdges();
    testOutputBuffer();
    testOutputFormatting();
    testBorrowedBuffer();
    testAbortedTranslation(module, ids);
#if HAS_PTHREAD
    testWorkerHandoff();
    testIndependentTranslations(module, ids);
#endif
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(module);
    fprintf(stderr, "PASS testOutputs\n");
}
