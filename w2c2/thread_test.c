#include <errno.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "c.h"
#include "thread_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf( \
                stderr, \
                "FAIL testThreadErrors: line %d: %s\n", \
                __LINE__, \
                #condition \
            ); \
            exit(1); \
        } \
    } while (0)

#if HAS_PTHREAD
#include <pthread.h>

static unsigned int initCalls;
static unsigned int destroyCalls;
static unsigned int createCalls;
static unsigned int joinCalls;
static unsigned int failInit;
static unsigned int failCreate;
static bool failAllocation;
static jmp_buf fatalJump;
static WasmDiagnostic captured;
static unsigned int diagnosticCount;
static unsigned int checkedCalls;
static unsigned int fatalPrints;
static const char* fatalCall;
static char fatalError[256];

static int threadTestMutexInit(
    pthread_mutex_t* mutex,
    const pthread_mutexattr_t* attributes
) {
    if (++initCalls == failInit) return EAGAIN;
    return pthread_mutex_init(mutex, attributes);
}

static int threadTestConditionInit(
    pthread_cond_t* condition,
    const pthread_condattr_t* attributes
) {
    if (++initCalls == failInit) return EAGAIN;
    return pthread_cond_init(condition, attributes);
}

static int threadTestMutexDestroy(pthread_mutex_t* mutex) {
    destroyCalls++;
    return pthread_mutex_destroy(mutex);
}

static int threadTestConditionDestroy(pthread_cond_t* condition) {
    destroyCalls++;
    return pthread_cond_destroy(condition);
}

static int threadTestCreate(
    pthread_t* thread,
    const pthread_attr_t* attributes,
    void* (*run)(void*),
    void* context
) {
    if (++createCalls == failCreate) return EAGAIN;
    return pthread_create(thread, attributes, run, context);
}

static int threadTestJoin(pthread_t thread, void** result) {
    joinCalls++;
    return pthread_join(thread, result);
}

static void* threadTestAllocate(size_t count, size_t size) {
    return failAllocation ? NULL : calloc(count, size);
}

static void threadTestAbort(void) {
    longjmp(fatalJump, 1);
}

static int threadTestResult(int error) {
    checkedCalls++;
    return error;
}

static int threadTestPrint(FILE* file, const char* format, ...) {
    va_list arguments;
    const char* message;
    CHECK(file == stderr);
    CHECK(strcmp(format, "w2c2: %s failed: %s\n") == 0);
    va_start(arguments, format);
    fatalCall = va_arg(arguments, const char*);
    message = va_arg(arguments, const char*);
    va_end(arguments);
    CHECK(strlen(message) < sizeof(fatalError));
    strcpy(fatalError, message);
    fatalPrints++;
    /* A failed diagnostic write must still abort. */
    return EOF;
}

#define pthread_mutex_init threadTestMutexInit
#define pthread_cond_init threadTestConditionInit
#define pthread_mutex_destroy threadTestMutexDestroy
#define pthread_cond_destroy threadTestConditionDestroy
#define pthread_create threadTestCreate
#define pthread_join threadTestJoin
#define calloc threadTestAllocate
#define abort threadTestAbort
#define fprintf threadTestPrint
#define wasmCWriteModule threadTestWriteModule
#define wasmCWriteAtomicLoadExpr threadTestWriteAtomicLoadExpr
#include "c.c"
#undef wasmCWriteModule
#undef wasmCWriteAtomicLoadExpr
#undef abort
#undef fprintf
#undef calloc
#undef pthread_mutex_init
#undef pthread_cond_init
#undef pthread_mutex_destroy
#undef pthread_cond_destroy
#undef pthread_create
#undef pthread_join

static void threadTestDiagnostic(
    void* context,
    const WasmDiagnostic* diagnostic
) {
    (void)context;
    captured = *diagnostic;
    diagnosticCount++;
}

static void testThreadInitialization(void) {
    for (failInit = 1; failInit <= 3; failInit++) {
        WasmCImplementationConcurrentWriter writer;
        WasmDiagnosticContext diagnostics = emptyWasmDiagnosticContext;
        diagnostics.diagnostics.report = threadTestDiagnostic;
        initCalls = destroyCalls = diagnosticCount = 0;
        CHECK(!wasmCImplementationConcurrentWriterInitialize(
            &writer,
            &diagnostics
        ));
        CHECK(initCalls == failInit && destroyCalls == failInit - 1);
        CHECK(diagnosticCount == 1 && captured.code == wasmDiagnosticThreadFailed);
        CHECK(captured.info.threadFailed.systemError == EAGAIN);
        CHECK(captured.info.threadFailed.operation == (failInit == 1
            ? wasmDiagnosticThreadMutexInitialize : wasmDiagnosticThreadConditionInitialize));
    }
    failInit = 0;
}

static void testThreadCreation(void) {
    WasmCWriteModuleOptions options = emptyWasmCWriteModuleOptions;
    WasmCOutputNames names = emptyWasmCOutputNames;
    OutputBuffer buffer = emptyOutputBuffer;
    unsigned int variant;
    options.threadCount = 2;
    options.functionsPerFile = 1;
    names.staticCount = 2;
    for (variant = 0; variant < 3; variant++) {
        WasmDiagnosticContext diagnostics = emptyWasmDiagnosticContext;
        diagnostics.diagnostics.report = threadTestDiagnostic;
        failAllocation = variant == 0;
        failCreate = variant;
        initCalls = destroyCalls = createCalls = joinCalls = diagnosticCount = 0;
        CHECK(!wasmCWriteModuleImplementationFiles(
            &buffer,
            NULL,
            "threadTest",
            &names,
            emptyWasmFunctionIDs,
            's',
            options,
            &diagnostics
        ));
        CHECK(initCalls == 3 && destroyCalls == 3 && diagnosticCount == 1);
        CHECK(createCalls == variant && joinCalls == (variant == 2 ? 1U : 0U));
        if (variant == 0) {
            CHECK(captured.code == wasmDiagnosticAllocationFailed);
        } else {
            CHECK(captured.code == wasmDiagnosticThreadFailed);
            CHECK(captured.info.threadFailed.operation == wasmDiagnosticThreadCreate);
            CHECK(captured.info.threadFailed.systemError == EAGAIN);
        }
    }
    failAllocation = false;
    failCreate = 0;
}

static void testFatalThreadError(void) {
    checkedCalls = fatalPrints = 0;
    WASM_C_THREAD_CHECK(threadTestResult(0));
    CHECK(checkedCalls == 1 && fatalPrints == 0);
    if (setjmp(fatalJump) == 0) {
        WASM_C_THREAD_CHECK(threadTestResult(EINVAL));
        CHECK(false);
    }
    CHECK(checkedCalls == 2 && fatalPrints == 1);
    CHECK(strcmp(fatalCall, "threadTestResult(EINVAL)") == 0);
    CHECK(strcmp(fatalError, strerror(EINVAL)) == 0);
}
#endif

void testThreadErrors(void) {
#if HAS_PTHREAD
    testThreadInitialization();
    testThreadCreation();
    testFatalThreadError();
    fprintf(stderr, "PASS testThreadErrors\n");
#else
    fprintf(stderr, "SKIP testThreadErrors: pthreads unavailable\n");
#endif
}
