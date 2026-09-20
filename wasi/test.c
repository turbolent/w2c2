#include "../w2c2/w2c2_base.h"
#include "wasi.h"
#include <stdio.h>
#include <limits.h>
#include "mac.h"

extern char** environ;

extern
U32
wasi_snapshot_preview1__poll_oneoff(
    void* instance,
    U32 inPointer,
    U32 outPointer,
    U32 subscriptionCount,
    U32 eventCountPointer
);

#define TEST_MEMORY_SIZE 4096
#define TEST_SUBSCRIPTION_SIZE 48
#define TEST_EVENT_SIZE 32
#define TEST_IN_POINTER 0
#define TEST_OUT_POINTER 1024
#define TEST_EVENT_COUNT_POINTER 3072

static U8 testMemoryData[TEST_MEMORY_SIZE];
static wasmMemory testMemory;

extern
U32
wasi__threadX2Dspawn(
    wasmModuleInstance* instance,
    U32 startArg
);

extern
bool
resolvePath(
    char* directory,
    char* path,
    U32 pathLength,
    char result[PATH_MAX]
);

void
testResolvePath(
    char* directory,
    char* path,
    char* expected,
    bool valid
) {
    char result[PATH_MAX];
    if (resolvePath(directory, path, (U32)strlen(path), result) != valid) {
        fprintf(stderr, "FAIL resolvePath(%s, %s): should succeed\n", directory, path);
        exit(1);
    }

    if (valid) {
        if (strcmp(result, expected) != 0) {
            fprintf(stderr, "FAIL resolvePath(%s, %s): %s != %s\n", directory, path, result, expected);
            exit(1);
        }

        fprintf(stderr, "OK resolvePath(%s, %s) == %s\n", directory, path, expected);
    } else {
        fprintf(stderr, "OK resolvePath(%s, %s) is invalid as expected\n", directory, path);
    }
}

void
testMacToPosixPath(
    char* path,
    char* expected
) {
    char result[PATH_MAX];
    strcpy(result, path);

    macToPosixPath(result);

    if (strcmp(result, expected) != 0) {
        fprintf(stderr, "FAIL macToPosixPath(%s): %s != %s\n", path, result, expected);
        exit(1);
    }

    fprintf(stderr, "OK macToPosixPath(%s) == %s\n", path, expected);
}

void
testPosixToMacPath(
    char* path,
    char* expected
) {
    char result[PATH_MAX];
    strcpy(result, path);

    posixToMacPath(result);

    if (strcmp(result, expected) != 0) {
        fprintf(stderr, "FAIL posixToMacPath(%s): %s != %s\n", path, result, expected);
        exit(1);
    }

    fprintf(stderr, "OK posixToMacPath(%s) == %s\n", path, expected);
}

/* Unused but expected by the WASI implementation */
wasmMemory* wasiMemory(void* instance) {
    UNUSED_PARAMETER(instance);
    return &testMemory;
}

#if HAS_POLL

void
failPollTest(
    const char* name,
    const char* field
) {
    fprintf(stderr, "FAIL %s: unexpected %s\n", name, field);
    exit(1);
}

void
expectPollU32(
    const char* name,
    const char* field,
    U32 actual,
    U32 expected
) {
    if (actual != expected) {
        fprintf(
            stderr,
            "FAIL %s: %s: %lu != %lu\n",
            name,
            field,
            (unsigned long)actual,
            (unsigned long)expected
        );
        exit(1);
    }
}

void
expectPollU64(
    const char* name,
    const char* field,
    U64 actual,
    U64 expected
) {
    if (actual != expected) {
        failPollTest(name, field);
    }
}

void
resetPollMemory(void) {
    memset(testMemory.data, 0, testMemory.size);
}

U32
pollSubscriptionPointer(
    U32 index
) {
    return TEST_IN_POINTER + index * TEST_SUBSCRIPTION_SIZE;
}

U32
pollEventPointer(
    U32 index
) {
    return TEST_OUT_POINTER + index * TEST_EVENT_SIZE;
}

void
setPollSubscription(
    U32 index,
    U64 userdata,
    WasiEventType type
) {
    U32 pointer = pollSubscriptionPointer(index);

    memset(testMemory.data + pointer, 0, TEST_SUBSCRIPTION_SIZE);
    i64_store(&testMemory, pointer, userdata);
    i32_store8(&testMemory, pointer + 8, type);
}

void
setPollClockSubscription(
    U32 index,
    U64 userdata,
    U32 clockID,
    U64 timeout,
    WasiSubclockFlags flags
) {
    U32 pointer = pollSubscriptionPointer(index);

    setPollSubscription(index, userdata, WASI_EVENT_TYPE_CLOCK);
    i32_store(&testMemory, pointer + 16, clockID);
    i64_store(&testMemory, pointer + 24, timeout);
    i64_store(&testMemory, pointer + 32, 0);
    i32_store16(&testMemory, pointer + 40, flags);
}

void
setPollFDSubscription(
    U32 index,
    U64 userdata,
    WasiEventType type,
    U32 wasiFD
) {
    U32 pointer = pollSubscriptionPointer(index);

    setPollSubscription(index, userdata, type);
    i32_store(&testMemory, pointer + 16, wasiFD);
}

U32
callPollOneoff(
    U32 subscriptionCount
) {
    return wasi_snapshot_preview1__poll_oneoff(
        NULL,
        TEST_IN_POINTER,
        TEST_OUT_POINTER,
        subscriptionCount,
        TEST_EVENT_COUNT_POINTER
    );
}

void
expectPollEvent(
    const char* name,
    U32 index,
    U64 userdata,
    WasiErrno error,
    WasiEventType type,
    WasiEventRwFlags flags
) {
    U32 pointer = pollEventPointer(index);

    expectPollU64(
        name,
        "userdata",
        i64_load(&testMemory, pointer),
        userdata
    );
    expectPollU32(
        name,
        "error",
        i32_load16_u(&testMemory, pointer + 8),
        error
    );
    expectPollU32(
        name,
        "type",
        i32_load8_u(&testMemory, pointer + 10),
        type
    );
    expectPollU64(
        name,
        "nbytes",
        i64_load(&testMemory, pointer + 16),
        0
    );
    expectPollU32(
        name,
        "flags",
        i32_load16_u(&testMemory, pointer + 24),
        flags
    );
}

void
testPollOneoffValidation(void) {
    const char* name = "poll_oneoff validation";
    U32 error = WASI_ERRNO_SUCCESS;

    resetPollMemory();
    error = callPollOneoff(0);
    expectPollU32(name, "zero subscriptions", error, WASI_ERRNO_INVAL);

    resetPollMemory();
    setPollSubscription(0, 1, 255);
    error = callPollOneoff(1);
    expectPollU32(name, "invalid event type", error, WASI_ERRNO_INVAL);

    resetPollMemory();
    setPollClockSubscription(
        0,
        2,
        WASI_CLOCK_PROCESS_CPUTIME_ID,
        0,
        0
    );
    error = callPollOneoff(1);
    expectPollU32(name, "unsupported clock", error, WASI_ERRNO_NOTSUP);

    resetPollMemory();
    setPollClockSubscription(0, 3, WASI_CLOCK_REALTIME, 0, 2);
    error = callPollOneoff(1);
    expectPollU32(name, "invalid clock flags", error, WASI_ERRNO_INVAL);

    error = wasi_snapshot_preview1__poll_oneoff(
        NULL,
        TEST_MEMORY_SIZE - 1,
        TEST_OUT_POINTER,
        1,
        TEST_EVENT_COUNT_POINTER
    );
    expectPollU32(name, "invalid memory", error, WASI_ERRNO_FAULT);

    fprintf(stderr, "OK %s\n", name);
}

void
testPollOneoffClocks(void) {
    const char* name = "poll_oneoff clocks";
    U32 error = WASI_ERRNO_SUCCESS;

    resetPollMemory();
    setPollClockSubscription(0, 11, WASI_CLOCK_MONOTONIC, 1000000, 0);
    error = callPollOneoff(1);
    expectPollU32(name, "relative result", error, WASI_ERRNO_SUCCESS);
    expectPollU32(
        name,
        "relative event count",
        i32_load(&testMemory, TEST_EVENT_COUNT_POINTER),
        1
    );
    expectPollEvent(
        name,
        0,
        11,
        WASI_ERRNO_SUCCESS,
        WASI_EVENT_TYPE_CLOCK,
        0
    );

    resetPollMemory();
    setPollClockSubscription(
        0,
        12,
        WASI_CLOCK_MONOTONIC,
        0,
        WASI_SUBCLOCK_FLAGS_ABSTIME
    );
    error = callPollOneoff(1);
    expectPollU32(name, "absolute result", error, WASI_ERRNO_SUCCESS);
    expectPollEvent(
        name,
        0,
        12,
        WASI_ERRNO_SUCCESS,
        WASI_EVENT_TYPE_CLOCK,
        0
    );

    resetPollMemory();
    setPollClockSubscription(0, 13, WASI_CLOCK_REALTIME, 0, 0);
    setPollClockSubscription(1, 14, WASI_CLOCK_MONOTONIC, 0, 0);
    error = callPollOneoff(2);
    expectPollU32(name, "multiple result", error, WASI_ERRNO_SUCCESS);
    expectPollU32(
        name,
        "multiple event count",
        i32_load(&testMemory, TEST_EVENT_COUNT_POINTER),
        2
    );
    expectPollEvent(
        name,
        0,
        13,
        WASI_ERRNO_SUCCESS,
        WASI_EVENT_TYPE_CLOCK,
        0
    );
    expectPollEvent(
        name,
        1,
        14,
        WASI_ERRNO_SUCCESS,
        WASI_EVENT_TYPE_CLOCK,
        0
    );

    fprintf(stderr, "OK %s\n", name);
}

#if HAS_UNISTD

void
testPollOneoffFDRead(void) {
    const char* name = "poll_oneoff FD read";
    int paddingPipe[2];
    int eventPipe[2];
    U32 wasiFD = 0;
    U32 error = WASI_ERRNO_SUCCESS;
    char value = 'x';

    if (pipe(paddingPipe) != 0 || pipe(eventPipe) != 0) {
        failPollTest(name, "pipe creation");
    }
    if (!wasiFileDescriptorAdd(eventPipe[0], NULL, &wasiFD)) {
        failPollTest(name, "descriptor creation");
    }
    close(paddingPipe[0]);
    close(paddingPipe[1]);

    if ((int)wasiFD == eventPipe[0]) {
        failPollTest(name, "guest descriptor mapping");
    }
    if (write(eventPipe[1], &value, 1) != 1) {
        failPollTest(name, "pipe write");
    }

    resetPollMemory();
    setPollFDSubscription(0, 21, WASI_EVENT_TYPE_FD_READ, wasiFD);
    error = callPollOneoff(1);
    expectPollU32(name, "result", error, WASI_ERRNO_SUCCESS);
    expectPollU32(
        name,
        "event count",
        i32_load(&testMemory, TEST_EVENT_COUNT_POINTER),
        1
    );
    expectPollEvent(
        name,
        0,
        21,
        WASI_ERRNO_SUCCESS,
        WASI_EVENT_TYPE_FD_READ,
        0
    );

    if (!wasiFileDescriptorClose(wasiFD)) {
        failPollTest(name, "descriptor close");
    }
    close(eventPipe[1]);
    fprintf(stderr, "OK %s\n", name);
}

void
testPollOneoffFDWrite(void) {
    const char* name = "poll_oneoff FD write";
    int eventPipe[2];
    U32 wasiFD = 0;
    U32 error = WASI_ERRNO_SUCCESS;

    if (pipe(eventPipe) != 0) {
        failPollTest(name, "pipe creation");
    }
    if (!wasiFileDescriptorAdd(eventPipe[1], NULL, &wasiFD)) {
        failPollTest(name, "descriptor creation");
    }

    resetPollMemory();
    setPollFDSubscription(0, 22, WASI_EVENT_TYPE_FD_WRITE, wasiFD);
    error = callPollOneoff(1);
    expectPollU32(name, "result", error, WASI_ERRNO_SUCCESS);
    expectPollEvent(
        name,
        0,
        22,
        WASI_ERRNO_SUCCESS,
        WASI_EVENT_TYPE_FD_WRITE,
        0
    );

    if (!wasiFileDescriptorClose(wasiFD)) {
        failPollTest(name, "descriptor close");
    }
    close(eventPipe[0]);
    fprintf(stderr, "OK %s\n", name);
}

void
testPollOneoffCompaction(void) {
    const char* name = "poll_oneoff compaction";
    int eventPipe[2];
    U32 wasiFD = 0;
    U32 error = WASI_ERRNO_SUCCESS;

    if (pipe(eventPipe) != 0) {
        failPollTest(name, "pipe creation");
    }
    if (!wasiFileDescriptorAdd(eventPipe[0], NULL, &wasiFD)) {
        failPollTest(name, "descriptor creation");
    }

    resetPollMemory();
    setPollFDSubscription(0, 23, WASI_EVENT_TYPE_FD_READ, wasiFD);
    setPollClockSubscription(1, 24, WASI_CLOCK_MONOTONIC, 0, 0);
    error = callPollOneoff(2);
    expectPollU32(name, "result", error, WASI_ERRNO_SUCCESS);
    expectPollU32(
        name,
        "event count",
        i32_load(&testMemory, TEST_EVENT_COUNT_POINTER),
        1
    );
    expectPollEvent(
        name,
        0,
        24,
        WASI_ERRNO_SUCCESS,
        WASI_EVENT_TYPE_CLOCK,
        0
    );

    if (!wasiFileDescriptorClose(wasiFD)) {
        failPollTest(name, "descriptor close");
    }
    close(eventPipe[1]);
    fprintf(stderr, "OK %s\n", name);
}

void
testPollOneoffInvalidFD(void) {
    const char* name = "poll_oneoff invalid FD";
    U32 error = WASI_ERRNO_SUCCESS;

    resetPollMemory();
    setPollFDSubscription(
        0,
        25,
        WASI_EVENT_TYPE_FD_READ,
        UINT32_MAX
    );
    error = callPollOneoff(1);
    expectPollU32(name, "result", error, WASI_ERRNO_SUCCESS);
    expectPollU32(
        name,
        "event count",
        i32_load(&testMemory, TEST_EVENT_COUNT_POINTER),
        1
    );
    expectPollEvent(
        name,
        0,
        25,
        WASI_ERRNO_BADF,
        WASI_EVENT_TYPE_FD_READ,
        0
    );

    fprintf(stderr, "OK %s\n", name);
}

void
testPollOneoffHangup(void) {
    const char* name = "poll_oneoff hangup";
    int eventPipe[2];
    U32 wasiFD = 0;
    U32 error = WASI_ERRNO_SUCCESS;

    if (pipe(eventPipe) != 0) {
        failPollTest(name, "pipe creation");
    }
    if (!wasiFileDescriptorAdd(eventPipe[0], NULL, &wasiFD)) {
        failPollTest(name, "descriptor creation");
    }
    close(eventPipe[1]);

    resetPollMemory();
    setPollFDSubscription(0, 26, WASI_EVENT_TYPE_FD_READ, wasiFD);
    error = callPollOneoff(1);
    expectPollU32(name, "result", error, WASI_ERRNO_SUCCESS);
    expectPollEvent(
        name,
        0,
        26,
        WASI_ERRNO_PIPE,
        WASI_EVENT_TYPE_FD_READ,
        WASI_EVENT_RW_FLAGS_HANGUP
    );

    if (!wasiFileDescriptorClose(wasiFD)) {
        failPollTest(name, "descriptor close");
    }
    fprintf(stderr, "OK %s\n", name);
}

#endif /* HAS_UNISTD */

void
testPollOneoff(void) {
    testPollOneoffValidation();
    testPollOneoffClocks();
#if HAS_UNISTD
    testPollOneoffFDRead();
    testPollOneoffFDWrite();
    testPollOneoffCompaction();
    testPollOneoffInvalidFD();
    testPollOneoffHangup();
#endif /* HAS_UNISTD */
}

#endif /* HAS_POLL */

#if defined(WASM_THREAD_TYPE) && (defined(WASM_ATOMICS_MSVC) || defined(WASM_ATOMICS_GCC))

typedef struct TestThreadInstance {
    wasmModuleInstance common;
} TestThreadInstance;

static WASM_MUTEX_TYPE testThreadMutex;
static WASM_COND_TYPE testThreadCondition;
static bool testThreadStarted = false;
static bool testThreadFreed = false;
static U32 testThreadStartArg = 0;

static
void
testThreadStart(
    void* instance,
    U32 threadID,
    U32 startArg
) {
    UNUSED_PARAMETER(instance);
    UNUSED_PARAMETER(threadID);

    WASM_MUTEX_LOCK(&testThreadMutex);
    testThreadStarted = true;
    testThreadStartArg = startArg;
    WASM_MUTEX_UNLOCK(&testThreadMutex);
}

static
void
testUnexpectedThreadStart(void* instance, U32 threadID, U32 startArg) {
    UNUSED_PARAMETER(instance);
    UNUSED_PARAMETER(threadID);
    UNUSED_PARAMETER(startArg);
    fprintf(stderr, "FAIL thread-spawn: matched an export with an embedded NUL\n");
    abort();
}

static wasmFuncExport testThreadFuncExports[] = {
    {(wasmFunc)testUnexpectedThreadStart, {"wasi_thread_start\0suffix", sizeof("wasi_thread_start\0suffix") - 1}},
    {(wasmFunc)testThreadStart, {"wasi_thread_start", sizeof("wasi_thread_start") - 1}},
    {NULL, {NULL, 0}}
};

static
wasmModuleInstance*
newTestThreadChild(
    wasmModuleInstance* self
) {
    TestThreadInstance* child = (TestThreadInstance*)calloc(
        1,
        sizeof(TestThreadInstance)
    );
    if (child == NULL) {
        abort();
    }
    child->common = *self;
    return &child->common;
}

static
void
freeTestThreadChild(
    wasmModuleInstance* child
) {
    free(child);

    WASM_MUTEX_LOCK(&testThreadMutex);
    testThreadFreed = true;
    WASM_COND_SIGNAL(&testThreadCondition);
    WASM_MUTEX_UNLOCK(&testThreadMutex);
}

static
void
testThreadSpawnCleanup(void) {
    TestThreadInstance root;
    U32 threadID;

    memset(&root, 0, sizeof(root));
    root.common.funcExports = testThreadFuncExports;
    root.common.newChild = newTestThreadChild;
    root.common.freeChild = freeTestThreadChild;

    if (!WASM_MUTEX_INIT(&testThreadMutex)) {
        fprintf(stderr, "FAIL thread-spawn: mutex initialization failed\n");
        exit(1);
    }
    if (!WASM_COND_INIT(&testThreadCondition)) {
        fprintf(stderr, "FAIL thread-spawn: condition initialization failed\n");
        exit(1);
    }

    threadID = wasi__threadX2Dspawn(&root.common, 42);
    if (threadID == (U32)-1) {
        fprintf(stderr, "FAIL thread-spawn: thread creation failed\n");
        exit(1);
    }

    WASM_MUTEX_LOCK(&testThreadMutex);
    while (!testThreadFreed) {
        if (!WASM_COND_RELATIVE_WAIT(
                &testThreadCondition,
                &testThreadMutex,
                W2C2_LL(5000000000)
            )) {
            fprintf(stderr, "FAIL thread-spawn: child cleanup timed out\n");
            exit(1);
        }
    }
    if (!testThreadStarted || testThreadStartArg != 42) {
        fprintf(stderr, "FAIL thread-spawn: start function was not called\n");
        exit(1);
    }
    WASM_MUTEX_UNLOCK(&testThreadMutex);

    WASM_COND_FREE(&testThreadCondition);
    WASM_MUTEX_FREE(&testThreadMutex);

    fprintf(stderr, "OK thread-spawn cleanup\n");
}

#endif

int
main(int argc, char* argv[]) {
    memset(&testMemory, 0, sizeof(testMemory));
    testMemory.data = testMemoryData;
    testMemory.size = TEST_MEMORY_SIZE;

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        exit(1);
    }

    testResolvePath("/", "", "", false);
    testResolvePath("/", "/bar", "/bar", true);
    testResolvePath("/", "bar", "/bar", true);
    testResolvePath("/foo", "", "", false);
    testResolvePath("/foo", "/bar", "/bar", true);
    testResolvePath("/foo", "bar", "/foo/bar", true);
    testResolvePath("/foo/bar", "", "", false);
    testResolvePath("/foo/bar", "/baz/qux", "/baz/qux", true);
    testResolvePath("/foo/bar", "baz/qux", "/foo/bar/baz/qux", true);

    testPosixToMacPath(
        "../../Volume/../../../foo/bar/../../more/yes/../last/..",
        ":::Volume::::foo:bar:::more:yes::last::"
    );
    testPosixToMacPath(
        "Volume/../../../foo/bar/../../more/yes/../last/..",
        ":Volume::::foo:bar:::more:yes::last::"
    );
    testPosixToMacPath(
        "./Volume/../../../foo/bar/../../more/yes/../last/..",
        ":Volume::::foo:bar:::more:yes::last::"
    );
    testPosixToMacPath(
        "/Volume/../../../foo/bar/../../more/yes/../last/../..",
        "Volume::::foo:bar:::more:yes::last:::"
    );

    testMacToPosixPath(
        ":Volume::::foo:bar:::more:yes::last::",
        "./Volume/../../../foo/bar/../../more/yes/../last/../"
    );
    testMacToPosixPath(
        "::Volume::::foo:bar:::more:yes::last::",
        "./../Volume/../../../foo/bar/../../more/yes/../last/../"
    );
    testMacToPosixPath(
        ":::Volume::::foo:bar:::more:yes::last::",
        "./../../Volume/../../../foo/bar/../../more/yes/../last/../"
    );
    testMacToPosixPath(
        "Volume::::foo:bar:::more:yes::last:::",
        "/Volume/../../../foo/bar/../../more/yes/../last/../../"
    );

#if HAS_POLL
    testPollOneoff();
#else
    if (wasi_snapshot_preview1__poll_oneoff(NULL, 0, 0, 0, 0)
        != WASI_ERRNO_NOSYS) {
        fprintf(stderr, "FAIL poll_oneoff fallback\n");
        exit(1);
    }
    fprintf(stderr, "OK poll_oneoff fallback\n");
#endif /* HAS_POLL */

#if defined(WASM_THREAD_TYPE) && (defined(WASM_ATOMICS_MSVC) || defined(WASM_ATOMICS_GCC))
    testThreadSpawnCleanup();
#endif

    return 0;
}
