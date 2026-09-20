/* Expose POSIX stream and descriptor declarations under strict C89. */
#if HAS_UNISTD && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#if HAS_PTHREAD
#include <pthread.h>
#endif
#if HAS_UNISTD
#include <unistd.h>
#include <sys/stat.h>
#endif

#include "c.h"
#include "reader.h"
#include "diagnostic_print.h"
#include "diagnostic_internal.h"
#include "diagnostic_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testDiagnostics: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

typedef struct DiagnosticCapture {
#if HAS_PTHREAD
    pthread_mutex_t mutex;
#endif
    U32 count;
    WasmDiagnostic last;
    WasmModuleReaderError readerError;
    char name[128];
} DiagnosticCapture;

static
void
captureInitialize(DiagnosticCapture* capture) {
    memset(capture, 0, sizeof(*capture));
#if HAS_PTHREAD
    CHECK(pthread_mutex_init(&capture->mutex, NULL) == 0);
#endif
}

static
void
captureDestroy(DiagnosticCapture* capture) {
#if HAS_PTHREAD
    CHECK(pthread_mutex_destroy(&capture->mutex) == 0);
#else
    UNUSED_PARAMETER(capture);
#endif
}

static
void
captureDiagnostic(void* context, const WasmDiagnostic* diagnostic) {
    DiagnosticCapture* capture = (DiagnosticCapture*)context;
    const char* name = NULL;
    size_t nameLength = 0;
#if HAS_PTHREAD
    CHECK(pthread_mutex_lock(&capture->mutex) == 0);
#endif
    capture->count++;
    capture->last = *diagnostic;
    switch (diagnostic->code) {
        case wasmDiagnosticReaderFailed:
            capture->readerError = *diagnostic->info.readerFailed.error;
            capture->last.info.readerFailed.error = &capture->readerError;
            break;
        case wasmDiagnosticOutputOpenFailed:
        case wasmDiagnosticOutputWriteFailed:
        case wasmDiagnosticOutputCloseFailed:
            name = diagnostic->info.outputFailed.name;
            nameLength = strlen(name);
            break;
        case wasmDiagnosticDuplicateFunctionName:
            name = diagnostic->info.duplicateFunctionName.name.data;
            nameLength = diagnostic->info.duplicateFunctionName.name.length;
            capture->last.info.duplicateFunctionName.name.data = capture->name;
            break;
        case wasmDiagnosticSkippedCustomSection:
            name = diagnostic->info.skippedCustomSection.name.data;
            nameLength = diagnostic->info.skippedCustomSection.name.length;
            capture->last.info.skippedCustomSection.name.data = capture->name;
            break;
        default:
            break;
    }
    if (name != NULL) {
        CHECK(nameLength < sizeof(capture->name));
        memcpy(capture->name, name, nameLength);
        capture->name[nameLength] = 0;
    }
#if HAS_PTHREAD
    CHECK(pthread_mutex_unlock(&capture->mutex) == 0);
#endif
    /* A callback must not change the system error attached to a report. */
    errno = EDOM;
}

static
WasmDiagnostics
captureReporting(DiagnosticCapture* capture) {
    WasmDiagnostics reporting = emptyWasmDiagnostics;
    reporting.report = captureDiagnostic;
    reporting.context = capture;
    return reporting;
}

static U8 diagnosticModuleBytes[] = {
    0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00,
    0x01, 0x09, 0x02, 0x60, 0x00, 0x00, 0x60, 0x00, 0x02, 0x7F, 0x7F,
    0x03, 0x03, 0x02, 0x00, 0x00,
    0x04, 0x04, 0x01, 0x70, 0x00, 0x01,
    0x05, 0x03, 0x01, 0x00, 0x01,
    0x0A, 0x07, 0x02, 0x02, 0x00, 0x0B, 0x02, 0x00, 0x0B,
    0x0B, 0x07, 0x01, 0x00, 0x41, 0x00, 0x0B, 0x01, 0x78
};

static
WasmModule*
readDiagnosticModule(void) {
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    reader.buffer.data = diagnosticModuleBytes;
    reader.buffer.length = sizeof(diagnosticModuleBytes);
    wasmModuleRead(&reader, &error);
    CHECK(error == NULL);
    return reader.module;
}

static
WasmFunctionIDs
diagnosticFunctionIDs(const WasmModule* module) {
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
WasmCWriteModuleOptions
diagnosticOptions(DiagnosticCapture* capture) {
    WasmCWriteModuleOptions options = emptyWasmCWriteModuleOptions;
    options.outputName = "diagnostic-test.c";
    options.output = wasmFileOutputProvider(".");
    options.functionsPerFile = 1;
    options.threadCount = 2;
    options.diagnostics = captureReporting(capture);
    return options;
}

static
void
testReaderDiagnostics(void) {
    static U8 customModule[] = {
        0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x04, 0x03, 'x', 0x00, 'y'
    };
    static U8 names[] = {
        0x00, 0x12, 0x04, 'n', 'a', 'm', 'e',
        0x01, 0x0B, 0x02, 0x00, 0x03, 'f', 0x00, 'g', 0x01, 0x03, 'f', 0x00, 'g'
    };
    U8 namedModule[sizeof(diagnosticModuleBytes) + sizeof(names)];
    DiagnosticCapture capture;
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    captureInitialize(&capture);
    reader.diagnostics = captureReporting(&capture);
    wasmModuleRead(&reader, &error);
    CHECK(error != NULL);
    CHECK(capture.count == 1);
    CHECK(capture.last.severity == wasmDiagnosticError);
    CHECK(capture.last.code == wasmDiagnosticReaderFailed);
    CHECK(capture.last.info.readerFailed.error->code == wasmModuleReaderInvalidMagic);
    reader.buffer.data = customModule;
    reader.buffer.length = sizeof(customModule);
    wasmModuleRead(&reader, &error);
    CHECK(error == NULL);
    CHECK(capture.count == 2);
    CHECK(capture.last.code == wasmDiagnosticSkippedCustomSection);
    CHECK(capture.last.severity == wasmDiagnosticInfo);
    CHECK(capture.last.info.skippedCustomSection.name.length == 3);
    CHECK(memcmp(capture.name, "x\0y", 3) == 0);
    memcpy(namedModule, diagnosticModuleBytes, sizeof(diagnosticModuleBytes));
    memcpy(namedModule + sizeof(diagnosticModuleBytes), names, sizeof(names));
    reader.buffer.data = namedModule;
    reader.buffer.length = sizeof(namedModule);
    reader.debug = true;
    wasmModuleRead(&reader, &error);
    CHECK(error == NULL);
    CHECK(capture.count == 3);
    CHECK(capture.last.code == wasmDiagnosticDuplicateFunctionName);
    CHECK(capture.last.info.duplicateFunctionName.previousIndex == 0);
    CHECK(capture.last.info.duplicateFunctionName.currentIndex == 1);
    CHECK(capture.last.info.duplicateFunctionName.name.length == 3);
    CHECK(memcmp(capture.name, "f\0g", 3) == 0);
    {
        FILE* file = tmpfile();
        char line[128];
        CHECK(file != NULL);
        wasmDiagnosticPrint(file, &capture.last, NULL);
        CHECK(fseek(file, 0, SEEK_SET) == 0);
        CHECK(fgets(line, sizeof(line), file) != NULL);
        CHECK(strcmp(line, "w2c2: ignoring duplicate function name f\\x00g used by functions 0 and 1\n") == 0);
        CHECK(fclose(file) == 0);
    }
    wasmModuleFree(reader.module);
    captureDestroy(&capture);
}

static
void
testOutputFailures(void) {
#if HAS_UNISTD
    static const char* names[] = {
        "diagnostic-test.h", "diagnostic-test.c", "m10_diagnostic.s0000000000.c",
        "m10_diagnostic.s0000000001.c", "m10_diagnostic.data"
    };
    WasmModule* module = readDiagnosticModule();
    WasmFunctionIDs ids = diagnosticFunctionIDs(module);
    size_t index;
    DiagnosticCapture capture;
    WasmCWriteModuleOptions options;
    captureInitialize(&capture);
    options = diagnosticOptions(&capture);
    options.dataSegmentMode = wasmDataSegmentModeGNULD;
    for (index = 0; index < sizeof(names) / sizeof(names[0]); index++) {
        /* A directory at the output path makes opening the file fail. */
        remove(names[index]);
        CHECK(mkdir(names[index], 0700) == 0);
        CHECK(!wasmCWriteModule(module, "diagnostic", options, ids, emptyWasmFunctionIDs));
        CHECK(capture.count == index + 1);
        CHECK(capture.last.severity == wasmDiagnosticError);
        CHECK(capture.last.code == wasmDiagnosticOutputOpenFailed);
        CHECK(capture.last.info.outputFailed.systemError != 0);
        CHECK(strcmp(capture.name, names[index]) == 0);
        CHECK(rmdir(names[index]) == 0);
        CHECK(wasmCWriteModule(module, "diagnostic", options, ids, emptyWasmFunctionIDs));
        CHECK(capture.count == index + 1);
    }
    for (index = 0; index < sizeof(names) / sizeof(names[0]); index++) {
        CHECK(remove(names[index]) == 0);
    }
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(module);
    captureDestroy(&capture);
#endif
}

static
void
testUnsupportedInstructions(void) {
    static U8 tableCopy[] = {
        0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0xFC, 0x0E, 0x00, 0x00, 0x0B
    };
    static U8 unknownAtomic[] = {0xFE, 0x7F, 0x0B};
    static U8 indirectMultiResult[] = {0x41, 0x00, 0x11, 0x01, 0x00, 0x1A, 0x1A, 0x0B};
    static U8 invalidCall[] = {0x10};
    Buffer cases[4];
    size_t index;
    WasmModule* module = readDiagnosticModule();
    WasmFunctionIDs ids = diagnosticFunctionIDs(module);
    cases[0].data = tableCopy;
    cases[0].length = sizeof(tableCopy);
    cases[1].data = unknownAtomic;
    cases[1].length = sizeof(unknownAtomic);
    cases[2].data = indirectMultiResult;
    cases[2].length = sizeof(indirectMultiResult);
    cases[3].data = invalidCall;
    cases[3].length = sizeof(invalidCall);
    for (index = 0; index < 4; index++) {
        DiagnosticCapture capture;
        WasmCWriteModuleOptions options;
        captureInitialize(&capture);
        options = diagnosticOptions(&capture);
        module->functions.functions[0].code = cases[index];
        CHECK(!wasmCWriteModule(module, "diagnostic", options, ids, emptyWasmFunctionIDs));
        CHECK(capture.count == 1);
        CHECK(capture.last.severity == wasmDiagnosticError);
        CHECK(capture.last.location.hasFunctionIndex);
        CHECK(capture.last.location.functionIndex == 0);
        if (index < 2) {
            CHECK(capture.last.code == wasmDiagnosticUnsupportedOpcode);
            CHECK(capture.last.info.unsupportedOpcode.family
                == (index == 0 ? wasmDiagnosticOpcodeMisc : wasmDiagnosticOpcodeThreads));
            CHECK(capture.last.info.unsupportedOpcode.opcode == (index == 0 ? 0x0EU : 0x7FU));
        } else if (index == 2) {
            CHECK(capture.last.code == wasmDiagnosticUnsupportedFunctionResults);
            CHECK(capture.last.info.unsupportedFunctionResults.typeIndex == 1);
            CHECK(capture.last.info.unsupportedFunctionResults.resultCount == 2);
        } else {
            CHECK(capture.last.code == wasmDiagnosticInvalidInstruction);
            CHECK(capture.last.info.invalidInstruction.opcode == wasmOpcodeCall);
        }
        captureDestroy(&capture);
    }
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(module);
}

static
void
testDataDropNoOp(void) {
    static U8 dataDrop[] = {0xFC, 0x09, 0x00, 0x0B};
    WasmModule* module = readDiagnosticModule();
    WasmFunctionIDs ids = diagnosticFunctionIDs(module);
    DiagnosticCapture capture;
    WasmCWriteModuleOptions options;
    captureInitialize(&capture);
    options = diagnosticOptions(&capture);
    module->functions.functions[0].code.data = dataDrop;
    module->functions.functions[0].code.length = sizeof(dataDrop);
    CHECK(wasmCWriteModule(module, "diagnostic", options, ids, emptyWasmFunctionIDs));
    CHECK(capture.count == 0);
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(module);
    captureDestroy(&capture);
}

static
void
testUnsupportedSignatures(void) {
    static U8 importModule[] = {
        0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x06, 0x01, 0x60, 0x00, 0x02, 0x7F, 0x7F,
        0x02, 0x07, 0x01, 0x01, 'm', 0x01, 'f', 0x00, 0x00
    };
    WasmModule* module = readDiagnosticModule();
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    WasmFunctionIDs ids = diagnosticFunctionIDs(module);
    DiagnosticCapture capture;
    WasmCWriteModuleOptions options;
    captureInitialize(&capture);
    options = diagnosticOptions(&capture);
    module->functions.functions[0].functionTypeIndex = 1;
    CHECK(!wasmCWriteModule(module, "diagnostic", options, ids, emptyWasmFunctionIDs));
    CHECK(capture.count == 1);
    CHECK(capture.last.code == wasmDiagnosticUnsupportedFunctionResults);
    CHECK(capture.last.info.unsupportedFunctionResults.typeIndex == 1);
    reader.buffer.data = importModule;
    reader.buffer.length = sizeof(importModule);
    wasmModuleRead(&reader, &error);
    CHECK(error == NULL);
    CHECK(!wasmCWriteModule(reader.module, "diagnostic", options,
        emptyWasmFunctionIDs, emptyWasmFunctionIDs));
    CHECK(capture.count == 2);
    CHECK(capture.last.code == wasmDiagnosticUnsupportedFunctionResults);
    CHECK(capture.last.info.unsupportedFunctionResults.typeIndex == 0);
    wasmModuleFree(reader.module);
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(module);
    captureDestroy(&capture);
}

static
void
testDwarfDiagnostics(void) {
    WasmDebugSections input = {0, 0, NULL};
    WasmDebugLines lines;
    DiagnosticCapture capture;
    captureInitialize(&capture);
    lines = wasmParseDebugInfo(input, captureReporting(&capture));
    CHECK(capture.count == 0);
    CHECK(lines.length == 0);
    wasmDebugLinesFree(&lines);
#if HAS_LIBDWARF || HAS_OLD_LIBDWARF
    {
        static U8 invalidUnit[] = {
            0x08, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
            0x00, 0x00, 0x04, 0x00
        };
        static U8 abbreviations[] = {0x00};
        WasmDebugSection sections[3];
        memset(sections, 0, sizeof(sections));
        sections[0].name.data = "";
        sections[0].name.length = sizeof("") - 1;
        sections[1].name.data = ".debug_info";
        sections[1].name.length = sizeof(".debug_info") - 1;
        sections[1].buffer.data = invalidUnit;
        sections[1].buffer.length = sizeof(invalidUnit);
        sections[2].name.data = ".debug_abbrev";
        sections[2].name.length = sizeof(".debug_abbrev") - 1;
        sections[2].buffer.data = abbreviations;
        sections[2].buffer.length = sizeof(abbreviations);
        input.length = 3;
        input.debugSections = sections;
        lines = wasmParseDebugInfo(input, captureReporting(&capture));
    }
    CHECK(capture.count == 1);
    CHECK(capture.last.severity == wasmDiagnosticWarning);
    CHECK(capture.last.code == wasmDiagnosticDwarfFailure);
    CHECK(lines.length == 0);
    wasmDebugLinesFree(&lines);
#endif
    captureDestroy(&capture);
}

#if HAS_PTHREAD
typedef struct ConcurrentTranslation {
    WasmModule* module;
    WasmFunctionIDs ids;
    bool dynamic;
    DiagnosticCapture capture;
} ConcurrentTranslation;

static
void*
translateConcurrently(void* context) {
    ConcurrentTranslation* translation = (ConcurrentTranslation*)context;
    WasmCWriteModuleOptions options = diagnosticOptions(&translation->capture);
    options.outputName = translation->dynamic ? "diagnostic-dynamic.c" : "diagnostic-static.c";
    CHECK(!wasmCWriteModule(translation->module, "diagnostic", options,
        translation->dynamic ? emptyWasmFunctionIDs : translation->ids,
        translation->dynamic ? translation->ids : emptyWasmFunctionIDs));
    CHECK(translation->capture.count >= 1);
    CHECK(translation->capture.last.code == wasmDiagnosticInvalidInstruction);
    return NULL;
}

static
void
testConcurrentDiagnostics(void) {
    static U8 invalidCall[] = {0x10};
    ConcurrentTranslation translations[2];
    pthread_t threads[2];
    WasmModule* module = readDiagnosticModule();
    WasmFunctionIDs ids = diagnosticFunctionIDs(module);
    size_t index;
    for (index = 0; index < 2; index++) {
        module->functions.functions[index].code.data = invalidCall;
        module->functions.functions[index].code.length = sizeof(invalidCall);
        translations[index].module = module;
        translations[index].ids = ids;
        translations[index].dynamic = index != 0;
        captureInitialize(&translations[index].capture);
    }
    for (index = 0; index < 2; index++) {
        CHECK(pthread_create(&threads[index], NULL,
            translateConcurrently, &translations[index]) == 0);
    }
    for (index = 0; index < 2; index++) {
        CHECK(pthread_join(threads[index], NULL) == 0);
        captureDestroy(&translations[index].capture);
    }
    wasmFunctionIDsFree(&ids);
    wasmModuleFree(module);
}
#endif

static
void
testSilentDiagnostics(void) {
#if HAS_UNISTD
    FILE* captured = tmpfile();
    int savedError;
    int savedOutput;
    long length;
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    WasmCWriteModuleOptions options = emptyWasmCWriteModuleOptions;
    CHECK(captured != NULL);
    CHECK(fflush(stderr) == 0);
    CHECK(fflush(stdout) == 0);
    savedError = dup(2);
    savedOutput = dup(1);
    CHECK(savedError >= 0 && savedOutput >= 0);
    CHECK(dup2(fileno(captured), 2) >= 0);
    CHECK(dup2(fileno(captured), 1) >= 0);
    wasmModuleRead(&reader, &error);
    if (wasmCWriteModule(NULL, NULL, options, emptyWasmFunctionIDs, emptyWasmFunctionIDs)) {
        fputs("unexpected success", stderr);
    }
    fflush(stderr);
    fflush(stdout);
    CHECK(dup2(savedError, 2) >= 0);
    CHECK(dup2(savedOutput, 1) >= 0);
    CHECK(close(savedError) == 0);
    CHECK(close(savedOutput) == 0);
    CHECK(fseek(captured, 0, SEEK_END) == 0);
    length = ftell(captured);
    CHECK(fclose(captured) == 0);
    CHECK(error != NULL);
    CHECK(length == 0);
#endif
}

void
testDiagnostics(void) {
    testReaderDiagnostics();
    testOutputFailures();
    testUnsupportedInstructions();
    testUnsupportedSignatures();
    testDataDropNoOp();
    testDwarfDiagnostics();
#if HAS_PTHREAD
    testConcurrentDiagnostics();
#endif
    testSilentDiagnostics();
    CHECK(remove("diagnostic-test.c") == 0);
    CHECK(remove("diagnostic-test.h") == 0);
    CHECK(remove("m10_diagnostic.s0000000000.c") == 0);
    CHECK(remove("m10_diagnostic.s0000000001.c") == 0);
#if HAS_PTHREAD
    CHECK(remove("diagnostic-static.c") == 0);
    CHECK(remove("diagnostic-static.h") == 0);
    CHECK(remove("diagnostic-dynamic.c") == 0);
    CHECK(remove("diagnostic-dynamic.h") == 0);
    CHECK(remove("m10_diagnostic.d0000000000.c") == 0);
    /* The first worker failure may stop translation before the second file is created. */
    CHECK(remove("m10_diagnostic.d0000000001.c") == 0 || errno == ENOENT);
#endif
    fprintf(stderr, "PASS testDiagnostics\n");
}
