#if HAS_PTHREAD && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#if HAS_PTHREAD
#include <pthread.h>
#include <time.h>
#endif
#if HAS_UNISTD
#include <unistd.h>
#include <sys/stat.h>
#endif

#include "c.h"
#include "c_file.h"
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
    pthread_t caller;
    bool requireCaller;
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
    if (capture->requireCaller) {
        CHECK(pthread_equal(pthread_self(), capture->caller));
    }
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
    capture->caller = pthread_self();
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
            const CapturedOutput* data = findOutput(&capture, "m10_outputx54est.data");
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
testDataSymbols(void) {
    /*
     * One active segment containing A and one passive segment containing BC.
     * The functions copy the passive segment and perform a zero-length copy
     * from the active segment.
     */
    static U8 bytes[] = {
        0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00, 0x01, 0x04, 0x01, 0x60,
        0x00, 0x00, 0x03, 0x03, 0x02, 0x00, 0x00, 0x05, 0x03, 0x01, 0x00, 0x01,
        0x07, 0x18, 0x03, 0x06, 0x6D, 0x65, 0x6D, 0x6F, 0x72, 0x79, 0x02, 0x00,
        0x03, 0x72, 0x75, 0x6E, 0x00, 0x00, 0x05, 0x65, 0x6D, 0x70, 0x74, 0x79,
        0x00, 0x01, 0x0C, 0x01, 0x02, 0x0A, 0x1B, 0x02, 0x0C, 0x00, 0x41, 0x08,
        0x41, 0x00, 0x41, 0x02, 0xFC, 0x08, 0x01, 0x00, 0x0B, 0x0C, 0x00, 0x41,
        0x00, 0x41, 0x00, 0x41, 0x00, 0xFC, 0x08, 0x00, 0x00, 0x0B, 0x0B, 0x0B,
        0x02, 0x00, 0x41, 0x00, 0x0B, 0x01, 0x41, 0x01, 0x02, 0x42, 0x43
    };
    static const char* const moduleNames[] = {"a-b", "a_b"};
    static const char* const prefixes[] = {"m3_aX2Db", "m3_aX5Fb"};
    static const char* const filePrefixes[] = {"m3_ax2db", "m3_ax5fb"};
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    WasmFunctionIDs ids;
    size_t nameIndex;
    reader.buffer.data = bytes;
    reader.buffer.length = sizeof(bytes);
    wasmModuleRead(&reader, &error);
    CHECK(error == NULL);
    ids = outputFunctionIDs(reader.module);
    for (nameIndex = 0; nameIndex < 2; nameIndex++) {
        unsigned int variant;
        for (variant = 0; variant < 16; variant++) {
            OutputCapture capture;
            WasmCWriteModuleOptions options;
            const CapturedOutput* header;
            const CapturedOutput* implementation;
            const char* source;
            const char* prefix = prefixes[nameIndex];
            char expected[128];
            char dataName[64];
            U32 segmentIndex;
            sprintf(dataName, "%s.data", filePrefixes[nameIndex]);
            captureInitialize(&capture);
            options = captureOptions(&capture);
            options.dataSegmentMode = (WasmDataSegmentMode)(variant % 4);
            options.functionsPerFile = variant & 4 ? 1 : 2;
            options.pretty = (variant & 8) != 0;
            options.multipleModules = options.pretty;
            CHECK(wasmCWriteModule(reader.module, moduleNames[nameIndex],
                options, ids, emptyWasmFunctionIDs));
            CHECK(capture.diagnosticCount == 0);
            header = findOutput(&capture, "output-test.h");
            implementation = findOutput(&capture, "output-test.c");
            CHECK(header != NULL && implementation != NULL);
            source = (const char*)implementation->bytes;
            for (segmentIndex = 0; segmentIndex < 2; segmentIndex++) {
                const CapturedOutput* function = implementation;
                if (options.functionsPerFile == 1) {
                    sprintf(expected, "%s.s%010lu.c", filePrefixes[nameIndex],
                        (unsigned long)(1 - segmentIndex));
                    function = findOutput(&capture, expected);
                    CHECK(function != NULL);
                }
                sprintf(expected, "%sData%lu+", prefix, (unsigned long)segmentIndex);
                CHECK(strstr((const char*)function->bytes, expected) != NULL);
                if (options.dataSegmentMode == wasmDataSegmentModeArrays) {
                    sprintf(expected, "extern const U8 %sData%lu[];",
                        prefix, (unsigned long)segmentIndex);
                    CHECK(strstr((const char*)header->bytes, expected) != NULL);
                    sprintf(expected, "const U8 %sData%lu[]%s{",
                        prefix, (unsigned long)segmentIndex, options.pretty ? " = " : "=");
                    CHECK(strstr(source, expected) != NULL);
                } else {
                    sprintf(expected, "extern const U8* %sData%lu;",
                        prefix, (unsigned long)segmentIndex);
                    CHECK(strstr((const char*)header->bytes, expected) != NULL);
                    sprintf(expected, "const U8* %sData%lu;",
                        prefix, (unsigned long)segmentIndex);
                    CHECK(strstr(source, expected) != NULL);
                    sprintf(expected, "%sData%lu%s%sData%s%lu;",
                        prefix, (unsigned long)segmentIndex, options.pretty ? " = " : "=",
                        prefix, options.pretty ? " + " : "+", (unsigned long)segmentIndex);
                    CHECK(strstr(source, expected) != NULL);
                }
            }
            sprintf(expected, ", %sData0, 1);", prefix);
            CHECK(strstr(source, expected) != NULL);
            switch (options.dataSegmentMode) {
                case wasmDataSegmentModeArrays:
                    CHECK(findOutput(&capture, dataName) == NULL);
                    break;
                case wasmDataSegmentModeGNULD:
                    sprintf(expected, "extern const U8 %sData[];", prefix);
                    CHECK(strstr(source, expected) != NULL);
                    break;
                case wasmDataSegmentModeSectcreate1:
                    sprintf(expected, "%sData[] __asm(\"section$start$__DATA$%s\");",
                        prefix, prefix);
                    CHECK(strstr(source, expected) != NULL);
                    break;
                case wasmDataSegmentModeSectcreate2: {
                    const char* init;
                    const char* lookup;
                    sprintf(expected, "InitDataSegments(%sInstance* i) {", prefix);
                    init = strstr(source, expected);
                    sprintf(expected, "getsectdata(\"__DATA\", \"%s\", &len);", prefix);
                    lookup = strstr(source, expected);
                    CHECK(init != NULL && lookup != NULL && lookup > init);
                    break;
                }
            }
            if (options.dataSegmentMode != wasmDataSegmentModeArrays) {
                const CapturedOutput* data = findOutput(&capture, dataName);
                CHECK(data != NULL && data->length == 3);
                CHECK(memcmp(data->bytes, "ABC", 3) == 0);
            }
            checkClosed(&capture);
            captureFree(&capture);
        }
    }
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(reader.module);
}

static
void
testDataSectionNameLimits(WasmModule* module, WasmFunctionIDs ids) {
    static const struct {
        const char* name;
        bool fits;
    } cases[] = {
        {"abcdefghijkl", true},
        {"abcdefghijklm", false},
        {"swift-wasi", true},
        {"swift_wasi1", false},
        {"\360\237\230\200a", true},
        {"\360\237\230\200ab", false}
    };
    size_t index;
    for (index = 0; index < sizeof(cases) / sizeof(cases[0]); index++) {
        unsigned int mode;
        for (mode = 0; mode < 4; mode++) {
            OutputCapture capture;
            WasmCWriteModuleOptions options;
            const bool accepted = cases[index].fits || mode < 2;
            captureInitialize(&capture);
            options = captureOptions(&capture);
            options.dataSegmentMode = (WasmDataSegmentMode)mode;
            CHECK(wasmCWriteModule(module, cases[index].name,
                options, ids, emptyWasmFunctionIDs) == accepted);
            if (accepted) {
                CHECK(capture.diagnosticCount == 0);
            } else {
                CHECK(capture.diagnosticCount == 1);
                CHECK(capture.diagnosticCode == wasmDiagnosticDataSectionNameTooLong);
                CHECK(capture.opened == 0 && capture.count == 0);
            }
            checkClosed(&capture);
            captureFree(&capture);
        }
    }
}

static
void
appendOutputDebugLine(WasmModule* module, U64 address, U64 number) {
    WasmDebugLine line;
    line.address = address;
    line.number = number;
    line.path = (char*)malloc(sizeof("debug-input.c"));
    CHECK(line.path != NULL);
    strcpy(line.path, "debug-input.c");
    CHECK(wasmDebugLinesAppend(&module->debugLines, line));
}

static
void
checkOutputDebugLines(const CapturedOutput* output, const U32* expected, size_t count) {
    const char* cursor;
    size_t index;
    CHECK(output != NULL);
    cursor = (const char*)output->bytes;
    for (index = 0; index < count; index++) {
        unsigned long number = 0;
        char path[64];
        cursor = strstr(cursor, "#line ");
        CHECK(cursor != NULL);
        CHECK(sscanf(cursor, "#line %lu \"%63[^\"]\"", &number, path) == 2);
        if (number != expected[index]) {
            fprintf(stderr, "FAIL testDebugLineLookup: %s directive %lu: %lu != %lu\n",
                output->name, (unsigned long)index, number, (unsigned long)expected[index]);
            exit(1);
        }
        CHECK(strcmp(path, "debug-input.c") == 0);
        cursor = strchr(cursor, '\n');
        CHECK(cursor != NULL);
        cursor++;
    }
    CHECK(strstr(cursor, "#line ") == NULL);
}

static
void
testDebugLineLookup(void) {
    /*
     * Each function contains i32.const 2147483647,
     * drop,
     * and end.
     * The five-byte immediate skips several debug-row addresses.
     */
    static U8 bytes[] = {
        0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00,
        0x03, 0x05, 0x04, 0x00, 0x00, 0x00, 0x00,
        0x0A, 0x29, 0x04,
        0x09, 0x00, 0x41, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x1A, 0x0B,
        0x09, 0x00, 0x41, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x1A, 0x0B,
        0x09, 0x00, 0x41, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x1A, 0x0B,
        0x09, 0x00, 0x41, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x1A, 0x0B
    };
    static const U32 offsets[] = {0, 1, 1, 3, 4, 5, 6};
    static const U32 fileSizes[] = {4, 2, 1, 0};
    static const char* fileNames[] = {
        "m10_outputx54est.s0000000000.c", "m10_outputx54est.s0000000001.c", "m10_outputx54est.s0000000002.c", "m10_outputx54est.s0000000003.c"
    };
    /*
     * Expected directives at the function signature,
     * i32.const,
     * drop,
     * and end.
     */
    static const U32 expectedLines[3][4][4] = {
        {{11, 11, 15, 15}, {111, 111, 115, 115},
         {209, 209, 215, 215}, {311, 311, 315, 315}},
        {{0}, {500, 500}, {500, 500, 500, 500}, {500, 500, 500, 500}},
        {{0}, {0}, {0}, {0}}
    };
    static const size_t expectedCounts[3][4] = {
        {4, 4, 4, 4}, {0, 2, 4, 4}, {0, 0, 0, 0}
    };
    size_t scenario;

    for (scenario = 0; scenario < 3; scenario++) {
        WasmModuleReader reader = emptyWasmModuleReader;
        WasmModuleReaderError* error = NULL;
        WasmFunctionIDs ids;
        WasmDebugLines originalLines;
        size_t index;
        size_t layout;
        reader.buffer.data = bytes;
        reader.buffer.length = sizeof(bytes);
        wasmModuleRead(&reader, &error);
        CHECK(error == NULL);
        ids = outputFunctionIDs(reader.module);
        for (index = 0; index < 2; index++) {
            const WasmFunctionID saved = ids.functionIDs[index];
            ids.functionIDs[index] = ids.functionIDs[3 - index];
            ids.functionIDs[3 - index] = saved;
        }

        if (scenario == 0) {
            for (index = 0; index < 4; index++) {
                size_t row;
                const size_t start = reader.module->functions.functions[index].start;
                for (row = 0; row < sizeof(offsets) / sizeof(offsets[0]); row++) {
                    /* Function 2 starts between debug rows. */
                    if (index == 2 && offsets[row] == 1) {
                        continue;
                    }
                    appendOutputDebugLine(reader.module, start - 1 + offsets[row], 100 * index + 9 + row);
                }
            }
        } else if (scenario == 1) {
            /*
             * The first function precedes the table.
             * Later instructions and functions extend beyond its last row.
             */
            appendOutputDebugLine(reader.module, reader.module->functions.functions[1].start + 2, 500);
        }
        originalLines = reader.module->debugLines;

        for (layout = 0; layout < sizeof(fileSizes) / sizeof(fileSizes[0]); layout++) {
            const U32 functionsPerOutput = fileSizes[layout] == 0 ? 4 : fileSizes[layout];
            unsigned int mode;
            for (mode = 0; mode < 4; mode++) {
                OutputCapture capture;
                WasmCWriteModuleOptions options;
                size_t fileIndex;
                captureInitialize(&capture);
                options = captureOptions(&capture);
                options.functionsPerFile = fileSizes[layout];
                options.threadCount = 1 + mode % 2;
                options.pretty = mode >= 2;
                options.debug = true;
                CHECK(wasmCWriteModule(reader.module, "outputTest", options, ids, emptyWasmFunctionIDs));
                CHECK(capture.diagnosticCount == 0);

                for (fileIndex = 0; fileIndex < 4 / functionsPerOutput; fileIndex++) {
                    const char* name = fileSizes[layout] == 4 ? "output-test.c" : fileNames[fileIndex];
                    U32 expected[16];
                    size_t count = 0;
                    U32 functionOffset;
                    for (functionOffset = 0; functionOffset < functionsPerOutput; functionOffset++) {
                        const U32 functionIndex = ids.functionIDs[
                            fileIndex * functionsPerOutput + functionOffset
                        ].functionIndex;
                        size_t line;
                        for (line = 0; line < expectedCounts[scenario][functionIndex]; line++) {
                            expected[count++] = expectedLines[scenario][functionIndex][line];
                        }
                    }
                    checkOutputDebugLines(findOutput(&capture, name), expected, count);
                }
                CHECK(reader.module->debugLines.debugLines == originalLines.debugLines);
                CHECK(reader.module->debugLines.length == originalLines.length);
                checkClosed(&capture);
                captureFree(&capture);
            }
        }
        wasmFunctionIDsFree(&ids);
        wasmModuleFree(reader.module);
    }
}

static
void
testWorkerCounts(WasmModule* module, WasmFunctionIDs ids, WasmBool pretty) {
    static const struct {
        size_t staticCount;
        size_t dynamicCount;
        U32 functionsPerFile;
        bool singleJobPerGroup;
    } cases[] = {
        {0, 0, 1, true},
        {2, 0, 1, false},
        {0, 2, 1, false},
        {1, 1, 1, true},
        {0, 2, 2, true},
        {0, 2, 0, true}
    };
    static const U32 threadCounts[] = {0, 2, UINT32_MAX};
    WasmModule emptyModule;
    WasmFunctionID reversedIDs[2];
    size_t variant;
    memset(&emptyModule, 0, sizeof(emptyModule));
    if (pretty) {
        CHECK(ids.length == 2);
        reversedIDs[0] = ids.functionIDs[1];
        reversedIDs[1] = ids.functionIDs[0];
        ids.functionIDs = reversedIDs;
    }

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
#if HAS_PTHREAD
        expected.requireCaller = true;
#endif
        options = captureOptions(&expected);
        options.functionsPerFile = cases[variant].functionsPerFile;
        options.threadCount = 1;
        options.pretty = pretty;
        options.debug = pretty;
        options.multipleModules = pretty;
        CHECK(wasmCWriteModule(input, "outputTest", options, staticIDs, dynamicIDs));
        CHECK(expected.diagnosticCount == 0);
        checkClosed(&expected);

        for (index = 0; index < sizeof(threadCounts) / sizeof(threadCounts[0]); index++) {
            OutputCapture actual;
            size_t fileIndex;
            captureInitialize(&actual);
#if HAS_PTHREAD
            actual.requireCaller = threadCounts[index] == 0 || cases[variant].singleJobPerGroup;
#endif
            options = captureOptions(&actual);
            options.functionsPerFile = cases[variant].functionsPerFile;
            options.threadCount = threadCounts[index];
            options.pretty = pretty;
            options.debug = pretty;
            options.multipleModules = pretty;
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
testProviderFailures(WasmModule* module, WasmFunctionIDs ids, U32 threadCount) {
    static const char* names[] = {
        "output-test.h", "output-test.c", "m10_outputx54est.s0000000000.c", "m10_outputx54est.data", "m10_outputx54est.s0000000001.c"
    };
    size_t index;
    OutputFailure failure;
    for (index = 0; index < sizeof(names) / sizeof(names[0]); index++) {
        for (failure = outputOpenFailure; failure <= outputCompleteFailure; failure++) {
            OutputCapture capture;
            WasmCWriteModuleOptions options;
            captureInitialize(&capture);
#if HAS_PTHREAD
            capture.requireCaller = threadCount <= 1;
#endif
            capture.failure = failure;
            capture.failureName = names[index];
            options = captureOptions(&capture);
            options.threadCount = threadCount;
            options.dataSegmentMode = wasmDataSegmentModeGNULD;
            CHECK(!wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
            CHECK(capture.diagnosticCount == 1);
            CHECK(capture.systemError == EIO);
            CHECK(capture.diagnosticCode == (failure == outputOpenFailure
                ? wasmDiagnosticOutputOpenFailed : failure == outputWriteFailure
                ? wasmDiagnosticOutputWriteFailed : wasmDiagnosticOutputCloseFailed));
            CHECK(findOutput(&capture, names[index]) == NULL);
            if (strcmp(names[index], "m10_outputx54est.s0000000001.c") == 0) {
                CHECK(findOutput(&capture, "m10_outputx54est.s0000000000.c") != NULL);
                CHECK(findOutput(&capture, "output-test.c") == NULL);
            }
            if (index == 1 && failure <= outputWriteFailure) {
                CHECK(capture.opened == (failure == outputOpenFailure ? 1U : 2U));
            }
            checkClosed(&capture);
            captureFree(&capture);
            captureInitialize(&capture);
            options = captureOptions(&capture);
            options.threadCount = threadCount;
            CHECK(wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
            CHECK(capture.diagnosticCount == 0);
            checkClosed(&capture);
            captureFree(&capture);
        }
    }
}

static
void
testOutputNames(WasmModule* module, WasmFunctionIDs ids) {
    static const struct {
        const char* name;
        U32 functionsPerFile;
        size_t dynamicCount;
        WasmDataSegmentMode dataMode;
        WasmDiagnosticCode error;
    } cases[] = {
        {"output-test.h", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"output-test.H", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"w2c2_base.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"W2C2_BASE.C", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"m10_outputx54est.s0000000000.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"m10_outputx54est.s0000000001.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"M10_OUTPUTX54EST.S0000000000.C", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"m10_outputx54est.s0000000000.c", 0, 0, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"m10_outputx54est.d0000000000.c", 1, 1, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"m10_outputx54est.d0000000001.c", 1, 2, wasmDataSegmentModeArrays, wasmDiagnosticOutputNameConflict},
        {"m10_outputx54est.data", 1, 0, wasmDataSegmentModeGNULD, wasmDiagnosticOutputNameConflict},
        {"M10_OUTPUTX54EST.DATA", 1, 0, wasmDataSegmentModeSectcreate1, wasmDiagnosticOutputNameConflict},
        {"m10_outputx54est.data", 1, 0, wasmDataSegmentModeSectcreate2, wasmDiagnosticOutputNameConflict},
        {"", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {".", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"..", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"dir/file.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"dir\\file.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"quote\".c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"line\n.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"line\r.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"tab\t.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"delete\177.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"tri?" "?/.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"tri?" "?=.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"tri?" "?-.c", 1, 0, wasmDataSegmentModeArrays, wasmDiagnosticInvalidOutputName},
        {"name with spaces.c", 1, 0, wasmDataSegmentModeArrays, 0},
        {"name", 1, 0, wasmDataSegmentModeArrays, 0},
        {"question?.c", 1, 0, wasmDataSegmentModeArrays, 0},
        {"question?" "?.c", 1, 0, wasmDataSegmentModeArrays, 0},
        {"m10_outputx54est.s0000000002.c", 1, 0, wasmDataSegmentModeArrays, 0},
        {"m10_outputx54est.s0000000000.c", 2, 0, wasmDataSegmentModeArrays, 0},
        {"m10_outputx54est.s0000000001.c", 1, 1, wasmDataSegmentModeArrays, 0},
        {"m10_outputx54est.d0000000001.c", 1, 1, wasmDataSegmentModeArrays, 0},
        {"m10_outputx54est.d0000000000.c", 1, 0, wasmDataSegmentModeArrays, 0},
        {"m10_outputx54est.data", 1, 0, wasmDataSegmentModeArrays, 0},
        {"m3_fac.s0000000000.c", 1, 0, wasmDataSegmentModeArrays, 0}
    };
    size_t index;
    for (index = 0; index < sizeof(cases) / sizeof(cases[0]); index++) {
        OutputCapture capture;
        WasmCWriteModuleOptions options;
        WasmFunctionIDs staticIDs = ids;
        WasmFunctionIDs dynamicIDs = ids;
        captureInitialize(&capture);
        options = captureOptions(&capture);
        options.outputName = cases[index].name;
        options.functionsPerFile = cases[index].functionsPerFile;
        options.dataSegmentMode = cases[index].dataMode;
        staticIDs.length -= cases[index].dynamicCount;
        dynamicIDs.functionIDs += staticIDs.length;
        dynamicIDs.length = cases[index].dynamicCount;
        CHECK(wasmCWriteModule(module, "outputTest", options, staticIDs, dynamicIDs)
            == (cases[index].error == 0));
        if (cases[index].error != 0) {
            CHECK(capture.diagnosticCount == 1 && capture.diagnosticCode == cases[index].error);
            CHECK(capture.opened == 0 && capture.count == 0);
        } else {
            size_t fileIndex;
            CHECK(capture.diagnosticCount == 0);
            CHECK(findOutput(&capture, cases[index].name) != NULL);
            for (fileIndex = 0; fileIndex < capture.count; fileIndex++) {
                size_t previous;
                for (previous = 0; previous < fileIndex; previous++) {
                    CHECK(!wasmCFileNamesEqual(capture.files[fileIndex].name, capture.files[previous].name));
                }
            }
        }
        checkClosed(&capture);
        captureFree(&capture);
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
    CHECK(strstr((const char*)generated->bytes, "i->g2=(*i->g0);") != NULL);
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
testFloatConstants(void) {
    static const struct {
        U32 f32;
        U64 f64;
    } cases[] = {
        {0x00000000U, W2C2_LL(0x0000000000000000U)},
        {0x3F800000U, W2C2_LL(0x3FF0000000000000U)},
        {0x3FC00000U, W2C2_LL(0x3FF8000000000000U)},
        {0x3DCCCCCDU, W2C2_LL(0x3FB999999999999AU)},
        {0x00000001U, W2C2_LL(0x0000000000000001U)},
        {0x007FFFFFU, W2C2_LL(0x000FFFFFFFFFFFFFU)},
        {0x00800000U, W2C2_LL(0x0010000000000000U)},
        {0x7F7FFFFFU, W2C2_LL(0x7FEFFFFFFFFFFFFFU)},
        {0x7F800000U, W2C2_LL(0x7FF0000000000000U)},
        {0x7FC00000U, W2C2_LL(0x7FF8000000000000U)},
        {0x7F800001U, W2C2_LL(0x7FF0000000000001U)},
        {0x7FA00000U, W2C2_LL(0x7FF0000000800000U)},
        {0x7FC00001U, W2C2_LL(0x7FF8000000000001U)},
        {0x7FFFFFFFU, W2C2_LL(0x7FFFFFFFFFFFFFFFU)}
    };
    WasmModule* module = readOutputModule();
    WasmFunctionIDs ids = outputFunctionIDs(module);
    size_t index;
    unsigned int variant;
    module->globals.globals[0].type.valueType = wasmValueTypeF32;
    module->globals.globals[1].type.valueType = wasmValueTypeF64;
    for (index = 0; index < sizeof(cases) / sizeof(cases[0]); index++) {
        for (variant = 0; variant < 8; variant++) {
            const U32 bits32 = cases[index].f32 | (variant % 2 ? 0x80000000U : 0);
            const U64 bits64 = cases[index].f64 | (variant % 2 ? W2C2_LL(0x8000000000000000U) : 0);
            U8 code32[] = {0x43, 0, 0, 0, 0, 0x1A, 0x0B};
            U8 code64[] = {0x44, 0, 0, 0, 0, 0, 0, 0, 0, 0x1A, 0x0B};
            U8 init32[6];
            U8 init64[10];
            char expected[2][64];
            size_t byte;
            size_t type;
            OutputCapture capture;
            WasmCWriteModuleOptions options;
            for (byte = 0; byte < 4; byte++) {
                code32[byte + 1] = (U8)(bits32 >> (byte * 8));
            }
            for (byte = 0; byte < 8; byte++) {
                code64[byte + 1] = (U8)(bits64 >> (byte * 8));
            }
            memcpy(init32, code32, sizeof(init32));
            memcpy(init64, code64, sizeof(init64));
            init32[sizeof(init32) - 1] = 0x0B;
            init64[sizeof(init64) - 1] = 0x0B;
            module->globals.globals[0].init.data = init32;
            module->globals.globals[0].init.length = sizeof(init32);
            module->globals.globals[1].init.data = init64;
            module->globals.globals[1].init.length = sizeof(init64);
            module->functions.functions[0].code.data = code32;
            module->functions.functions[0].code.length = sizeof(code32);
            module->functions.functions[1].code.data = code64;
            module->functions.functions[1].code.length = sizeof(code64);
            sprintf(expected[0], "f32_reinterpret_i32(0x%08XU)", bits32);
            sprintf(expected[1], "f64_reinterpret_i64(W2C2_LL(0x%016llXU))", bits64);
            captureInitialize(&capture);
            options = captureOptions(&capture);
            options.functionsPerFile = variant % 4 < 2 ? 2 : 1;
            options.pretty = variant >= 4;
            CHECK(wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
            CHECK(capture.diagnosticCount == 0);
            for (type = 0; type < 2; type++) {
                size_t fileIndex;
                size_t count = 0;
                for (fileIndex = 0; fileIndex < capture.count; fileIndex++) {
                    const char* cursor = (const char*)capture.files[fileIndex].bytes;
                    while ((cursor = strstr(cursor, expected[type])) != NULL) {
                        count++;
                        cursor += strlen(expected[type]);
                    }
                }
                /* Each constant occurs in a function and a global initializer. */
                CHECK(count == 2);
            }
            checkClosed(&capture);
            captureFree(&capture);
        }
    }
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(module);
}

static
void
testFloatConstantLocales(void) {
    static const char* locales[] = {
        "C", "de_DE.UTF-8", "fr_FR.UTF-8", "de_DE", "fr_FR",
        "German_Germany.1252", "French_France.1252"
    };
    const char* current = setlocale(LC_NUMERIC, NULL);
    char* previous = (char*)malloc(strlen(current) + 1);
    bool testedComma = false;
    size_t index;
    CHECK(previous != NULL);
    strcpy(previous, current);
    for (index = 0; index < sizeof(locales) / sizeof(locales[0]); index++) {
        char* selected;
        current = setlocale(LC_NUMERIC, locales[index]);
        if (current == NULL) {
            CHECK(index != 0);
            continue;
        }
        if (index != 0 && strcmp(localeconv()->decimal_point, ",") != 0) {
            continue;
        }
        selected = (char*)malloc(strlen(current) + 1);
        CHECK(selected != NULL);
        strcpy(selected, current);
        testFloatConstants();
        CHECK(strcmp(setlocale(LC_NUMERIC, NULL), selected) == 0);
        free(selected);
        if (index != 0) {
            testedComma = true;
            break;
        }
    }
    CHECK(setlocale(LC_NUMERIC, previous) != NULL);
    free(previous);
    if (!testedComma) {
        fprintf(stderr, "SKIP testFloatConstantLocales: no comma-decimal locale installed\n");
    }
}

static
void
testMemorySize(void) {
    static U8 code[] = {0x3F, 0x00, 0x1A, 0x0B};
    WasmModule* module = readOutputModule();
    WasmFunctionIDs ids = outputFunctionIDs(module);
    unsigned int shared;
    module->functions.functions[0].code.data = code;
    module->functions.functions[0].code.length = sizeof(code);
    for (shared = 0; shared < 2; shared++) {
        OutputCapture capture;
        WasmCWriteModuleOptions options;
        const CapturedOutput* implementation;
        module->memories.memories[0].shared = shared != 0;
        module->memories.memories[0].max = 1;
        captureInitialize(&capture);
        options = captureOptions(&capture);
        options.functionsPerFile = 2;
        CHECK(wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
        CHECK(capture.diagnosticCount == 0);
        implementation = findOutput(&capture, "output-test.c");
        CHECK(implementation != NULL);
        CHECK(strstr((const char*)implementation->bytes, "wasmMemorySize(i->m0)") != NULL);
        checkClosed(&capture);
        captureFree(&capture);
    }
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(module);
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
testFunctionBufferReuse(void) {
    static const size_t instructionCounts[] = {1024, 1, 0, 2048, 0, 2};
    static const U32 fileSizes[] = {1, 2, 6};
    WasmModule module;
    WasmFunctionType type = wasmEmptyFunctionType;
    WasmFunction functions[6];
    U8 code[6][3 * 2048 + 1];
    WasmFunctionIDs ids;
    size_t index;
    unsigned int mode;

    memset(&module, 0, sizeof(module));
    module.functionTypes.functionTypes = &type;
    module.functionTypes.count = 1;
    module.functions.functions = functions;
    module.functions.count = 6;
    for (index = 0; index < 6; index++) {
        size_t instruction;
        for (instruction = 0; instruction < instructionCounts[index]; instruction++) {
            /* i32.const 42; drop */
            code[index][3 * instruction] = 0x41;
            code[index][3 * instruction + 1] = 42;
            code[index][3 * instruction + 2] = 0x1A;
        }
        code[index][3 * instructionCounts[index]] = 0x0B;
        functions[index] = wasmEmptyFunction;
        functions[index].code.data = code[index];
        functions[index].code.length = 3 * instructionCounts[index] + 1;
    }
    ids = outputFunctionIDs(&module);

    for (mode = 0; mode < 2; mode++) {
        OutputCapture references[6];
        const char* bodies[6];
        size_t layout;

        /* Translate each function separately so its buffer starts empty. */
        for (index = 0; index < 6; index++) {
            WasmFunctionIDs singleID = ids;
            WasmCWriteModuleOptions options;
            const CapturedOutput* output;
            singleID.functionIDs = &ids.functionIDs[index];
            singleID.length = 1;
            captureInitialize(&references[index]);
            options = captureOptions(&references[index]);
            options.pretty = mode != 0;
            CHECK(wasmCWriteModule(&module, "outputTest", options, singleID, emptyWasmFunctionIDs));
            CHECK(references[index].diagnosticCount == 0);
            output = findOutput(&references[index], "m10_outputx54est.s0000000000.c");
            CHECK(output != NULL);
            bodies[index] = strstr((const char*)output->bytes, "void f");
            CHECK(bodies[index] != NULL);
            checkClosed(&references[index]);
        }

        for (layout = 0; layout < sizeof(fileSizes) / sizeof(fileSizes[0]); layout++) {
            U32 threads;
            for (threads = 1; threads <= 2; threads++) {
                OutputCapture capture;
                WasmCWriteModuleOptions options;
                captureInitialize(&capture);
                options = captureOptions(&capture);
                options.functionsPerFile = fileSizes[layout];
                options.threadCount = threads;
                options.pretty = mode != 0;
                CHECK(wasmCWriteModule(&module, "outputTest", options, ids, emptyWasmFunctionIDs));
                CHECK(capture.diagnosticCount == 0);
                for (index = 0; index < 6; index++) {
                    size_t fileIndex;
                    size_t matches = 0;
                    for (fileIndex = 0; fileIndex < capture.count; fileIndex++) {
                        const char* match = strstr((const char*)capture.files[fileIndex].bytes, bodies[index]);
                        if (match != NULL) {
                            CHECK(strstr(match + strlen(bodies[index]), bodies[index]) == NULL);
                            matches++;
                        }
                    }
                    CHECK(matches == 1);
                }
                checkClosed(&capture);
                captureFree(&capture);
            }
        }
        for (index = 0; index < 6; index++) {
            captureFree(&references[index]);
        }
    }
    wasmFunctionIDsFree(&ids);
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
testCStringEscaping(void) {
    static const char* strings[] = {
        "", "ordinary/path.c", ("\"\\\n\r\t\0017AF\177\303\251\?" "\?/end\\"), "a\0b"
    };
    static const char* escaped[] = {
        "", "ordinary/path.c", "\\\"\\\\\\012\\015\\011\\0017AF\\177\\303\\251\\?\\?/end\\\\", "a\\000b"
    };
    static const char* identifiers[] = {
        "0_", "15_ordinaryX2FpathX2Ec", "19_X22X5CX0AX0DX09X017AFX7FXC3XA9X3FX3FX2FendX5C", "3_aX00b"
    };
    size_t index;
    for (index = 0; index < sizeof(strings) / sizeof(strings[0]); index++) {
        WasmModule* module = readOutputModule();
        WasmFunctionIDs ids = outputFunctionIDs(module);
        WasmGlobalImport* import = &module->globalImports.imports[0];
        const size_t size = index == 3 ? sizeof("a\0b") : strlen(strings[index]) + 1;
        const bool hasNul = memchr(strings[index], 0, size - 1) != NULL;
        unsigned int mode;
        char resolve[512];
        char exportName[256];
        char assemblyName[256];
        char debugLine[256];
        free(import->module.data);
        free(import->name.data);
        import->module.data = (char*)malloc(size);
        import->module.length = size - 1;
        import->name.data = (char*)malloc(size);
        import->name.length = size - 1;
        CHECK(import->module.data != NULL && import->name.data != NULL);
        memcpy(import->module.data, strings[index], size);
        memcpy(import->name.data, strings[index], size);
        module->exports.exports = (WasmExport*)malloc(sizeof(WasmExport));
        CHECK(module->exports.exports != NULL);
        module->exports.count = 1;
        module->exports.exports[0] = wasmEmptyExport;
        module->exports.exports[0].name.data = (char*)malloc(size);
        module->exports.exports[0].name.length = size - 1;
        CHECK(module->exports.exports[0].name.data != NULL);
        memcpy(module->exports.exports[0].name.data, strings[index], size);
        module->functions.functions[0].exportName = module->exports.exports[0].name;
        CHECK(wasmNamesAppend(&module->functionNames, emptyWasmName));
        {
            WasmName name;
            WasmDebugLine line;
            name.data = (char*)malloc(size);
            name.length = size - 1;
            CHECK(name.data != NULL);
            memcpy(name.data, strings[index], size);
            CHECK(wasmNamesAppend(&module->functionNames, name));
            line.address = module->functions.functions[0].start;
            line.number = 17;
            line.path = (char*)malloc(size);
            CHECK(line.path != NULL);
            memcpy(line.path, strings[index], size);
            CHECK(wasmDebugLinesAppend(&module->debugLines, line));
        }
        sprintf(resolve, "resolve(wasmNameFromBytes(\"%s\", %lu), wasmNameFromBytes(\"%s\", %lu));",
            escaped[index], (unsigned long)(size - 1), escaped[index], (unsigned long)(size - 1));
        sprintf(exportName, ",{\"%s\",%lu}},", escaped[index], (unsigned long)(size - 1));
        sprintf(assemblyName, " __asm__(\"m10_outputTestDebug1Name%s\")", identifiers[index]);
        sprintf(debugLine, "#line 17 \"%s\"\n", hasNul ? "a" : escaped[index]);
        for (mode = 0; mode < 4; mode++) {
            OutputCapture capture;
            WasmCWriteModuleOptions options;
            size_t fileIndex;
            size_t lineCount = 0;
            bool foundAssemblyName = false;
            const CapturedOutput* implementation;
            captureInitialize(&capture);
            options = captureOptions(&capture);
            options.functionsPerFile = mode % 2 == 0 ? 2 : 1;
            options.pretty = mode >= 2;
            options.debug = true;
            CHECK(wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
            CHECK(capture.diagnosticCount == 0);
            implementation = findOutput(&capture, "output-test.c");
            CHECK(implementation != NULL);
            CHECK(strstr((const char*)implementation->bytes, resolve) != NULL);
            CHECK(strstr((const char*)implementation->bytes, exportName) != NULL);
            for (fileIndex = 0; fileIndex < capture.count; fileIndex++) {
                const char* source = (const char*)capture.files[fileIndex].bytes;
                const char* cursor = source;
                if (strstr(source, assemblyName) != NULL) {
                    foundAssemblyName = true;
                }
                while ((cursor = strstr(cursor, "#line ")) != NULL) {
                    CHECK(strncmp(cursor, debugLine, strlen(debugLine)) == 0);
                    lineCount++;
                    cursor += strlen(debugLine);
                }
            }
            CHECK(foundAssemblyName);
            /* Both functions have a signature directive and an end-instruction directive. */
            CHECK(lineCount == 4);
            checkClosed(&capture);
            captureFree(&capture);
        }
        wasmFunctionIDsFree(&ids);
        wasmModuleFree(module);
    }
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
testAbortedTranslation(WasmModule* module, WasmFunctionIDs ids, U32 threadCount) {
    static U8 invalidCall[] = {0x10};
    const Buffer previous = module->functions.functions[0].code;
    OutputCapture capture;
    WasmCWriteModuleOptions options;
    captureInitialize(&capture);
#if HAS_PTHREAD
    capture.requireCaller = threadCount <= 1;
#endif
    options = captureOptions(&capture);
    options.threadCount = threadCount;
    module->functions.functions[0].code.data = invalidCall;
    module->functions.functions[0].code.length = sizeof(invalidCall);
    /* A prior diagnostic suppresses secondary output errors. */
    capture.failure = outputCloseFailure;
    capture.failureName = "m10_outputx54est.s0000000000.c";
    CHECK(!wasmCWriteModule(module, "outputTest", options, ids, emptyWasmFunctionIDs));
    CHECK(capture.diagnosticCount == 1);
    CHECK(capture.diagnosticCode == wasmDiagnosticInvalidInstruction);
    CHECK(findOutput(&capture, "m10_outputx54est.s0000000000.c") == NULL);
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
    if (kind == wasmOutputC && strcmp(name, "output-test.c") != 0) {
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
    testOutputNames(module, ids);
    testDataSymbols();
    testDataSectionNameLimits(module, ids);
    testDebugLineLookup();
    testCStringEscaping();
    testWorkerCounts(module, ids, false);
    testWorkerCounts(module, ids, true);
    testProviderFailures(module, ids, 1);
    testProviderFailures(module, ids, UINT32_MAX);
    testConstantExpressions(module, ids);
    testFloatConstantLocales();
    testMemorySize();
    testMemoryEdges();
    testFunctionBufferReuse();
    testOutputBuffer();
    testOutputFormatting();
    testBorrowedBuffer();
    testAbortedTranslation(module, ids, 1);
    testAbortedTranslation(module, ids, 2);
#if HAS_PTHREAD
    testWorkerHandoff();
    testIndependentTranslations(module, ids);
#endif
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(module);
    fprintf(stderr, "PASS testOutputs\n");
}
