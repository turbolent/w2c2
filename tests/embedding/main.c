#if TEST_STDBOOL
#include <stdbool.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if HAS_PTHREAD
#include <pthread.h>
#endif

#include "w2c2.h"
#include "c.h"
#include "reader.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL embedding: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

typedef struct File {
    char name[32];
    WasmOutputKind kind;
    U8* bytes;
    size_t length;
} File;

typedef struct Capture {
    WasmMemoryOutput memory;
    File files[8];
    size_t count;
    size_t errors;
    WasmDiagnosticCode code;
    WasmBool reject;
#if HAS_PTHREAD
    pthread_mutex_t mutex;
#endif
} Capture;

/* Two functions and a data segment containing embedded zeros. */
static const U8 moduleBytes[] = {
    0, 97, 115, 109, 1, 0, 0, 0,
    1, 4, 1, 96, 0, 0,
    3, 3, 2, 0, 0,
    5, 3, 1, 0, 1,
    10, 7, 2, 2, 0, 11, 2, 0, 11,
    11, 10, 1, 0, 65, 0, 11, 4, 0, 255, 10, 0
};

static void
lock(Capture* capture) {
#if HAS_PTHREAD
    CHECK(pthread_mutex_lock(&capture->mutex) == 0);
#else
    (void)capture;
#endif
}

static void
unlock(Capture* capture) {
#if HAS_PTHREAD
    CHECK(pthread_mutex_unlock(&capture->mutex) == 0);
#else
    (void)capture;
#endif
}

static WasmBool
complete(
    void* context, const char* name, WasmOutputKind kind,
    const U8* bytes, size_t length, int* systemError
) {
    Capture* capture = (Capture*)context;
    File* file;
    (void)systemError;
    CHECK(bytes[length] == 0);
    if (capture->reject && kind == wasmOutputC) {
        return 0;
    }
    lock(capture);
    CHECK(capture->count < 8);
    file = &capture->files[capture->count++];
    CHECK(strlen(name) < sizeof(file->name));
    strcpy(file->name, name);
    file->kind = kind;
    file->length = length;
    file->bytes = (U8*)malloc(length + 1);
    CHECK(file->bytes != NULL);
    memcpy(file->bytes, bytes, length + 1);
    unlock(capture);
    return 255;
}

static void
report(void* context, const WasmDiagnostic* diagnostic) {
    Capture* capture = (Capture*)context;
    if (diagnostic->severity == wasmDiagnosticError) {
        lock(capture);
        capture->errors++;
        capture->code = diagnostic->code;
        unlock(capture);
    }
}

static void
initialize(Capture* capture) {
    memset(capture, 0, sizeof(*capture));
    capture->memory.context = capture;
    capture->memory.complete = complete;
#if HAS_PTHREAD
    CHECK(pthread_mutex_init(&capture->mutex, NULL) == 0);
#endif
}

static void
release(Capture* capture) {
    size_t index;
    for (index = 0; index < capture->count; index++) {
        free(capture->files[index].bytes);
    }
#if HAS_PTHREAD
    CHECK(pthread_mutex_destroy(&capture->mutex) == 0);
#endif
}

static WasmCWriteModuleOptions
configure(Capture* capture) {
    WasmCWriteModuleOptions options = emptyWasmCWriteModuleOptions;
    options.outputName = "example.c";
    options.output = wasmMemoryOutputProvider(&capture->memory);
    options.diagnostics.context = capture;
    options.diagnostics.report = report;
    return options;
}

static void
testSuccess(void) {
    unsigned variant;
    for (variant = 0; variant < 5; variant++) {
        Capture translated;
        Capture lowLevel;
        WasmCWriteModuleOptions options;
        WasmModuleReader reader = emptyWasmModuleReader;
        WasmModuleReaderError* error = NULL;
        WasmFunctionIDs ids = emptyWasmFunctionIDs;
        U8* input = (U8*)malloc(sizeof(moduleBytes));
        size_t index;
        const size_t inputLength = variant == 4 ? 8 : sizeof(moduleBytes);
        CHECK(input != NULL);
        memcpy(input, moduleBytes, sizeof(moduleBytes));
        initialize(&translated);
        initialize(&lowLevel);
        options = configure(&translated);
        options.pretty = variant & 1 ? 255 : 0;
        options.debug = 255;
        options.multipleModules = variant & 1 ? 255 : 0;
        options.functionsPerFile = variant & 2 ? 1 : 0;
        options.threadCount = variant & 2 ? 4 : 0;
        options.dataSegmentMode = variant & 2 ? wasmDataSegmentModeGNULD : wasmDataSegmentModeArrays;
        CHECK(wasmTranslate(input, inputLength, "example", &options));
        CHECK(memcmp(input, moduleBytes, sizeof(moduleBytes)) == 0);
        CHECK(translated.errors == 0);
        CHECK(translated.count == (variant & 2 ? 5U : 2U));

        reader.buffer.data = input;
        reader.buffer.length = inputLength;
        reader.debug = options.debug;
        wasmModuleRead(&reader, &error);
        CHECK(error == NULL);
        options.output = wasmMemoryOutputProvider(&lowLevel.memory);
        options.diagnostics.context = &lowLevel;
        if (options.functionsPerFile == 0) {
            options.functionsPerFile = reader.module->functions.count;
        }
        CHECK(wasmFunctionIDsInitialize(reader.module->functions,
            options.functionsPerFile < reader.module->functions.count, &ids));
        CHECK(wasmCWriteModule(reader.module, "example", options, ids, emptyWasmFunctionIDs));
        CHECK(lowLevel.errors == 0);
        wasmFunctionIDsFree(&ids);
        wasmModuleFree(reader.module);
        free(input);

        CHECK(lowLevel.count == translated.count);
        for (index = 0; index < translated.count; index++) {
            const File* file = &translated.files[index];
            size_t other;
            for (other = 0; other < lowLevel.count; other++) {
                const File* expected = &lowLevel.files[other];
                if (strcmp(file->name, expected->name) == 0) {
                    CHECK(file->kind == expected->kind);
                    CHECK(file->length == expected->length);
                    CHECK(memcmp(file->bytes, expected->bytes, file->length + 1) == 0);
                    break;
                }
            }
            CHECK(other < lowLevel.count);
            if (file->kind == wasmOutputData) {
                const U8 expected[] = {0, 255, 10, 0};
                CHECK(file->length == sizeof(expected));
                CHECK(memcmp(file->bytes, expected, sizeof(expected)) == 0);
            }
        }
        release(&translated);
        release(&lowLevel);
    }
}

static void
testFailures(void) {
    /* A valid function returning two i32 values is currently unsupported. */
    static const U8 unsupported[] = {
        0, 97, 115, 109, 1, 0, 0, 0,
        1, 6, 1, 96, 0, 2, 127, 127,
        3, 2, 1, 0,
        10, 8, 1, 6, 0, 65, 0, 65, 0, 11
    };
    Capture capture;
    WasmCWriteModuleOptions options;
    initialize(&capture);
    options = configure(&capture);
    CHECK(!wasmTranslate(moduleBytes, sizeof(moduleBytes), "example", NULL));
    CHECK(!wasmTranslate(NULL, sizeof(moduleBytes), "example", &options));
    CHECK(capture.errors == 1 && capture.code == wasmDiagnosticInvalidTranslationArgument);
    CHECK(!wasmTranslate(moduleBytes, sizeof(moduleBytes), "", &options));
    CHECK(capture.errors == 2 && capture.code == wasmDiagnosticInvalidTranslationArgument);
    options.outputName = NULL;
    CHECK(!wasmTranslate(moduleBytes, sizeof(moduleBytes), "example", &options));
    CHECK(capture.errors == 3 && capture.code == wasmDiagnosticInvalidTranslationArgument);
    options.outputName = "";
    CHECK(!wasmTranslate(moduleBytes, sizeof(moduleBytes), "example", &options));
    CHECK(capture.errors == 4 && capture.code == wasmDiagnosticInvalidTranslationArgument);
    options.outputName = "example.c";
    options.output.open = NULL;
    CHECK(!wasmTranslate(moduleBytes, sizeof(moduleBytes), "example", &options));
    CHECK(capture.errors == 5 && capture.code == wasmDiagnosticInvalidTranslationArgument);
    options.output = wasmMemoryOutputProvider(&capture.memory);
    CHECK(capture.count == 0);
    CHECK(!wasmTranslate(moduleBytes, 1, "example", &options));
    CHECK(capture.errors == 6 && capture.code == wasmDiagnosticReaderFailed);
    CHECK(!wasmTranslate(unsupported, sizeof(unsupported), "example", &options));
    CHECK(capture.errors == 7 && capture.code == wasmDiagnosticUnsupportedFunctionResults);
    release(&capture);
    initialize(&capture);
    capture.reject = 255;
    CHECK(!wasmTranslate(moduleBytes, sizeof(moduleBytes), "example", &options));
    CHECK(capture.errors == 1 && capture.code == wasmDiagnosticOutputCloseFailed);
    CHECK(capture.count == 1 && capture.files[0].kind == wasmOutputHeader);
    release(&capture);
}

#if HAS_PTHREAD
static void*
translateThread(void* context) {
    (void)context;
    testSuccess();
    testFailures();
    return NULL;
}
#endif

int
main(void) {
    unsigned iteration;
    CHECK(sizeof(WasmBool) == 1);
    for (iteration = 0; iteration < 10; iteration++) {
        testSuccess();
        testFailures();
    }
#if HAS_PTHREAD
    {
        pthread_t threads[2];
        CHECK(pthread_create(&threads[0], NULL, translateThread, NULL) == 0);
        CHECK(pthread_create(&threads[1], NULL, translateThread, NULL) == 0);
        CHECK(pthread_join(threads[0], NULL) == 0);
        CHECK(pthread_join(threads[1], NULL) == 0);
    }
#endif
    return 0;
}
