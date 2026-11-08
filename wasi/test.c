#define _DEFAULT_SOURCE 1

#ifdef _WIN32
#include <winsock2.h>
#elif HAS_SOCKETS
#include <sys/socket.h>
#include <netinet/in.h>
#endif

#include "../w2c2/w2c2_base.h"
#include "wasi.h"
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>
#include "mac.h"
#if HAS_UNISTD
#include <unistd.h>
#endif
#ifdef _WIN32
#include <io.h>
#endif
#if HAS_UNISTD && !defined(_WIN32) && defined(_POSIX_VERSION)
#define TEST_PROC_RAISE_POSIX 1
#include <sys/wait.h>
#endif

extern char** environ;

extern
U32
i22_wasiX5FsnapshotX5Fpreview111_schedX5Fyield(
    wasmModuleInstance* instance
);

extern
U32
i13_wasiX5Funstable11_schedX5Fyield(
    wasmModuleInstance* instance
);

extern
U32
i22_wasiX5FsnapshotX5Fpreview111_pollX5Foneoff(
    wasmModuleInstance* instance,
    U32 inPointer,
    U32 outPointer,
    U32 subscriptionCount,
    U32 eventCountPointer
);

#define TEST_MEMORY_SIZE WASM_PAGE_SIZE
#define TEST_SUBSCRIPTION_SIZE 48
#define TEST_EVENT_SIZE 32
#define TEST_IN_POINTER 0
#define TEST_OUT_POINTER 1024
#define TEST_EVENT_COUNT_POINTER 3072

static U8 testMemoryData[TEST_MEMORY_SIZE];
static wasmMemory testMemory;

extern
U32
i4_wasi12_threadX2Dspawn(
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
wasmMemory* wasiMemory(wasmModuleInstance* instance) {
    UNUSED_PARAMETER(instance);
    return &testMemory;
}

static void testSchedYield(void) {
    U32 expected = WASI_ERRNO_SUCCESS;
#if !defined(_WIN32) && !HAS_SCHED_YIELD && defined(WASM_THREAD_TYPE)
    expected = WASI_ERRNO_NOSYS;
#endif

    if (i22_wasiX5FsnapshotX5Fpreview111_schedX5Fyield(NULL) != expected) {
        fprintf(stderr, "FAIL sched_yield: unexpected preview1 result\n");
        exit(1);
    }
    if (i13_wasiX5Funstable11_schedX5Fyield(NULL) != expected) {
        fprintf(stderr, "FAIL sched_yield: unexpected unstable result\n");
        exit(1);
    }
    fprintf(stderr, "OK sched_yield\n");
}

#define CHECK_IO(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL WASI I/O: line %d\n", __LINE__); \
            exit(1); \
        } \
    } while (0)

typedef U32 (*TestProcRaise)(wasmModuleInstance*, U32);

extern U32 i22_wasiX5FsnapshotX5Fpreview110_procX5Fraise(
    wasmModuleInstance*, U32
);
extern U32 i13_wasiX5Funstable10_procX5Fraise(
    wasmModuleInstance*, U32
);

static volatile sig_atomic_t testRaisedSignal;

static void testSignalHandler(int signal) {
    testRaisedSignal = signal;
}

static void testProcRaiseDelivery(
    TestProcRaise raiseSignal,
    U32 wasiSignal,
    int nativeSignal,
    bool ignored
) {
#if TEST_PROC_RAISE_POSIX
    struct sigaction action, previous;
    memset(&action, 0, sizeof(action));
    CHECK_IO(sigemptyset(&action.sa_mask) == 0);
    action.sa_handler = ignored ? SIG_IGN : testSignalHandler;
    CHECK_IO(sigaction(nativeSignal, &action, &previous) == 0);
#else
    void (*previous)(int) = signal(
        nativeSignal,
        ignored ? SIG_IGN : testSignalHandler
    );
    CHECK_IO(previous != SIG_ERR);
#endif
    testRaisedSignal = 0;
    CHECK_IO(raiseSignal(NULL, wasiSignal) == WASI_ERRNO_SUCCESS);
    CHECK_IO(testRaisedSignal == (ignored ? 0 : nativeSignal));
#if TEST_PROC_RAISE_POSIX
    CHECK_IO(sigaction(nativeSignal, &previous, NULL) == 0);
#else
    CHECK_IO(signal(nativeSignal, previous) != SIG_ERR);
#endif
}

static void testProcRaise(TestProcRaise raiseSignal) {
    static const struct {
        U32 wasi;
        int native;
    } signals[] = {
        {WASI_SIGNAL_INT, SIGINT},
        {WASI_SIGNAL_ILL, SIGILL},
        {WASI_SIGNAL_ABRT, SIGABRT},
        {WASI_SIGNAL_FPE, SIGFPE},
        {WASI_SIGNAL_SEGV, SIGSEGV},
        {WASI_SIGNAL_TERM, SIGTERM},
#ifndef _WIN32
#ifdef SIGUSR1
        {WASI_SIGNAL_USR1, SIGUSR1},
#endif
#ifdef SIGUSR2
        {WASI_SIGNAL_USR2, SIGUSR2},
#endif
#ifdef SIGCHLD
        {WASI_SIGNAL_CHLD, SIGCHLD},
#endif
#if defined(SIGPOLL)
        {WASI_SIGNAL_POLL, SIGPOLL},
#elif defined(SIGIO)
        {WASI_SIGNAL_POLL, SIGIO},
#endif
#endif
    };
    static const U32 invalid[] = {
        WASI_SIGNAL_NONE, WASI_SIGNAL_SYS + 1, 255,
        256 + WASI_SIGNAL_TERM, UINT32_MAX
    };
    size_t i;
    for (i = 0; i < sizeof(invalid) / sizeof(invalid[0]); i++) {
        CHECK_IO(raiseSignal(NULL, invalid[i]) == WASI_ERRNO_INVAL);
    }
    for (i = 0; i < sizeof(signals) / sizeof(signals[0]); i++) {
        testProcRaiseDelivery(
            raiseSignal,
            signals[i].wasi,
            signals[i].native,
            false
        );
    }
    testProcRaiseDelivery(raiseSignal, WASI_SIGNAL_TERM, SIGTERM, true);
#ifdef _WIN32
    for (i = WASI_SIGNAL_HUP; i <= WASI_SIGNAL_SYS; i++) {
        if (i != WASI_SIGNAL_INT && i != WASI_SIGNAL_ILL &&
            i != WASI_SIGNAL_ABRT && i != WASI_SIGNAL_FPE &&
            i != WASI_SIGNAL_SEGV && i != WASI_SIGNAL_TERM) {
            CHECK_IO(raiseSignal(NULL, (U32)i) == WASI_ERRNO_NOTSUP);
        }
    }
#else
#ifndef SIGPWR
    CHECK_IO(raiseSignal(NULL, WASI_SIGNAL_PWR) == WASI_ERRNO_NOTSUP);
#endif
#if !defined(SIGPOLL) && !defined(SIGIO)
    CHECK_IO(raiseSignal(NULL, WASI_SIGNAL_POLL) == WASI_ERRNO_NOTSUP);
#endif
#endif
    fprintf(stderr, "OK proc_raise mappings, handlers, and invalid signals\n");
}

static void testProcRaiseTermination(
    TestProcRaise raiseSignal,
    const char* childArgument
) {
#if TEST_PROC_RAISE_POSIX
    pid_t child = fork();
    pid_t result = 0;
    int status = 0;
    unsigned int attempt;
    UNUSED_PARAMETER(childArgument);
    CHECK_IO(child >= 0);
    if (child == 0) {
        sigset_t mask;
        CHECK_IO(sigemptyset(&mask) == 0);
        CHECK_IO(sigprocmask(SIG_SETMASK, &mask, NULL) == 0);
        CHECK_IO(signal(SIGTERM, SIG_DFL) != SIG_ERR);
        raiseSignal(NULL, WASI_SIGNAL_TERM);
        _exit(99);
    }
    for (attempt = 0; attempt < 5; attempt++) {
        result = waitpid(child, &status, WNOHANG);
        if (result == child) {
            break;
        }
        CHECK_IO(result == 0 || (result == -1 && errno == EINTR));
        sleep(1);
    }
    if (result != child) {
        kill(child, SIGKILL);
        while (waitpid(child, &status, 0) < 0 && errno == EINTR) {}
    }
    CHECK_IO(result == child);
    CHECK_IO(WIFSIGNALED(status) && WTERMSIG(status) == SIGTERM);
#elif defined(_WIN32)
    char executable[MAX_PATH];
    char command[MAX_PATH + 64];
    STARTUPINFOA startup;
    PROCESS_INFORMATION process;
    DWORD length, result, code;
    UNUSED_PARAMETER(raiseSignal);
    length = GetModuleFileNameA(NULL, executable, sizeof(executable));
    CHECK_IO(length > 0 && length < sizeof(executable));
    strcpy(command, "\"");
    strcat(command, executable);
    strcat(command, "\" ");
    strcat(command, childArgument);
    memset(&startup, 0, sizeof(startup));
    memset(&process, 0, sizeof(process));
    startup.cb = sizeof(startup);
    CHECK_IO(CreateProcessA(
        executable,
        command,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &startup,
        &process
    ));
    result = WaitForSingleObject(process.hProcess, 5000);
    if (result != WAIT_OBJECT_0) {
        CHECK_IO(TerminateProcess(process.hProcess, 99));
        WaitForSingleObject(process.hProcess, 5000);
    }
    CHECK_IO(GetExitCodeProcess(process.hProcess, &code));
    CHECK_IO(CloseHandle(process.hThread));
    CHECK_IO(CloseHandle(process.hProcess));
    CHECK_IO(result == WAIT_OBJECT_0 && code == 3);
#else
    UNUSED_PARAMETER(raiseSignal);
    UNUSED_PARAMETER(childArgument);
    fprintf(stderr, "SKIP proc_raise termination: child processes unavailable\n");
    return;
#endif
    fprintf(stderr, "OK proc_raise default termination\n");
}

static void testFileDescriptorGet(void) {
    U32 wasiFD;
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;

    CHECK_IO(!wasiFileDescriptorGet(UINT32_MAX, &descriptor));
    CHECK_IO(wasiFileDescriptorGet(0, &descriptor));
    CHECK_IO(descriptor.fd == 0 && descriptor.dir == NULL && descriptor.path == NULL);

    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &wasiFD));
    CHECK_IO(!wasiFileDescriptorGet(wasiFD + 1, &descriptor));
    CHECK_IO(wasiFileDescriptorGet(wasiFD, &descriptor));
    CHECK_IO(descriptor.fd == -1 && descriptor.dir == NULL);
    CHECK_IO(descriptor.path != NULL && strcmp(descriptor.path, ".") == 0);
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(!wasiFileDescriptorGet(wasiFD, &descriptor));

    fprintf(stderr, "OK wasiFileDescriptorGet\n");
}

extern U32 i22_wasiX5FsnapshotX5Fpreview110_fdX5Freaddir(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U64,
    U32
);

static void testFileDescriptorClose(void) {
    U32 wasiFD;
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;

    CHECK_IO(!wasiFileDescriptorClose(UINT32_MAX));
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &wasiFD));
    CHECK_IO(wasiFileDescriptorGet(wasiFD, &descriptor));
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(!wasiFileDescriptorGet(wasiFD, &descriptor));
    CHECK_IO(descriptor.fd == -1 && descriptor.dir == NULL && descriptor.path == NULL);
    CHECK_IO(descriptor.rightsBase == 0 && descriptor.rightsInheriting == 0);
    CHECK_IO(!wasiFileDescriptorClose(wasiFD));

#if HAS_UNISTD
    {
        FILE* file = tmpfile();
        int fd;
        char byte;

        CHECK_IO(file != NULL);
        fd = dup(fileno(file));
        CHECK_IO(fd >= 0);
        CHECK_IO(wasiFileDescriptorAdd(fd, ".", &wasiFD));
        CHECK_IO(wasiFileDescriptorGet(wasiFD, &descriptor));
        CHECK_IO(wasiFileDescriptorClose(wasiFD));
        CHECK_IO(read(fd, &byte, 1) == -1);
        CHECK_IO(errno == EBADF);
        CHECK_IO(!wasiFileDescriptorGet(wasiFD, &descriptor));
        CHECK_IO(descriptor.fd == -1 && descriptor.dir == NULL && descriptor.path == NULL);
        CHECK_IO(!wasiFileDescriptorClose(wasiFD));
        CHECK_IO(fclose(file) == 0);
    }
#endif

    fprintf(stderr, "OK wasiFileDescriptorClose\n");
}

static void testFileDescriptorCloseDirectory(void) {
    U32 wasiFD;
    WasiFileDescriptor descriptor;
#if HAS_UNISTD && !defined(_WIN32)
    int fd = open(".", O_RDONLY);
    CHECK_IO(fd >= 0);
    CHECK_IO(wasiFileDescriptorAdd(fd, ".", &wasiFD));
#else
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &wasiFD));
#endif
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview110_fdX5Freaddir(
        NULL,
        wasiFD,
        128,
        1,
        0,
        512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(wasiFileDescriptorGet(wasiFD, &descriptor));
    CHECK_IO(descriptor.dir != NULL);
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(!wasiFileDescriptorGet(wasiFD, &descriptor));
    CHECK_IO(descriptor.fd == -1 && descriptor.dir == NULL && descriptor.path == NULL);
#if HAS_UNISTD && !defined(_WIN32)
    CHECK_IO(fcntl(fd, F_GETFD) == -1 && errno == EBADF);
#endif
    fprintf(stderr, "OK wasiFileDescriptorClose directory handles\n");
}

#ifdef WASM_THREAD_TYPE

static void* testFileDescriptorsThread(void* argument) {
    WASM_MUTEX_TYPE* start = (WASM_MUTEX_TYPE*)argument;
    unsigned int i;
    WASM_MUTEX_LOCK(start);
    WASM_MUTEX_UNLOCK(start);
    for (i = 0; i < 256; i++) {
        U32 wasiFD;
        WasiFileDescriptor descriptor;
        CHECK_IO(wasiFileDescriptorAdd(-1, ".", &wasiFD));
        CHECK_IO(wasiFileDescriptorGet(wasiFD, &descriptor));
        CHECK_IO(strcmp(descriptor.path, ".") == 0);
        CHECK_IO(descriptor.rightsBase == WASI_RIGHTS_DIRECTORY_BASE);
        CHECK_IO(descriptor.rightsInheriting == WASI_RIGHTS_DIRECTORY_INHERITING);
        CHECK_IO(wasiFileDescriptorSet(wasiFD, -1));
        CHECK_IO(wasiFileDescriptorClose(wasiFD));
        CHECK_IO(!wasiFileDescriptorGet(wasiFD, &descriptor));
    }
    return NULL;
}

static void testFileDescriptorsConcurrent(void) {
    WASM_MUTEX_TYPE start;
    WASM_THREAD_TYPE threads[4];
    size_t i;
    CHECK_IO(WASM_MUTEX_INIT(&start));
    WASM_MUTEX_LOCK(&start);
    for (i = 0; i < sizeof(threads) / sizeof(threads[0]); i++) {
        CHECK_IO(WASM_THREAD_CREATE(
            &threads[i],
            testFileDescriptorsThread,
            &start
        ));
    }
    WASM_MUTEX_UNLOCK(&start);
    for (i = 0; i < sizeof(threads) / sizeof(threads[0]); i++) {
        WASM_THREAD_JOIN(threads[i]);
    }
    WASM_MUTEX_FREE(&start);
    fprintf(stderr, "OK concurrent file descriptor access\n");
}

#endif

typedef U32 (*TestFdRenumber)(
    wasmModuleInstance*,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview111_fdX5Frenumber(
    wasmModuleInstance*,
    U32,
    U32
);
extern U32 i13_wasiX5Funstable11_fdX5Frenumber(
    wasmModuleInstance*,
    U32,
    U32
);

static void testFdRenumberValidation(TestFdRenumber renumber) {
    U32 from, to, closed, added;
    WasiFileDescriptor source, target, descriptor;

    CHECK_IO(renumber(NULL, UINT32_MAX, UINT32_MAX) == WASI_ERRNO_BADF);
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &from));
    CHECK_IO(wasiFileDescriptorAdd(-1, "..", &to));
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &closed));
    CHECK_IO(wasiFileDescriptorClose(closed));
    CHECK_IO(wasiFileDescriptorGet(from, &source));
    CHECK_IO(wasiFileDescriptorGet(to, &target));
    CHECK_IO(renumber(NULL, UINT32_MAX, to) == WASI_ERRNO_BADF);
    CHECK_IO(renumber(NULL, from, UINT32_MAX) == WASI_ERRNO_BADF);
    CHECK_IO(renumber(NULL, closed, to) == WASI_ERRNO_BADF);
    CHECK_IO(renumber(NULL, from, closed) == WASI_ERRNO_BADF);
    CHECK_IO(renumber(NULL, closed, closed) == WASI_ERRNO_BADF);
    CHECK_IO(renumber(NULL, from, from) == WASI_ERRNO_SUCCESS);
    CHECK_IO(wasiFileDescriptorGet(from, &descriptor));
    CHECK_IO(descriptor.path == source.path);
    CHECK_IO(wasiFileDescriptorGet(to, &descriptor));
    CHECK_IO(descriptor.path == target.path);

    CHECK_IO(renumber(NULL, from, to) == WASI_ERRNO_SUCCESS);
    CHECK_IO(!wasiFileDescriptorGet(from, &descriptor));
    CHECK_IO(!wasiFileDescriptorClose(from));
    CHECK_IO(wasiFileDescriptorGet(to, &descriptor));
    CHECK_IO(descriptor.path == source.path && strcmp(descriptor.path, ".") == 0);
    CHECK_IO(descriptor.fd == -1 && descriptor.dir == NULL);
    CHECK_IO(wasiFileDescriptorAdd(-1, "..", &added));
    CHECK_IO(added > closed);
    CHECK_IO(wasiFileDescriptorGet(to, &descriptor));
    CHECK_IO(descriptor.path == source.path);
    CHECK_IO(wasiFileDescriptorClose(added));
    CHECK_IO(wasiFileDescriptorClose(to));
    fprintf(stderr, "OK fd_renumber validation and preopens\n");
}

static void testFdRenumberDirectory(TestFdRenumber renumber) {
    U32 from, to;
    WasiFileDescriptor source, descriptor;
#if HAS_UNISTD && !defined(_WIN32)
    int fromFD = open(".", O_RDONLY);
    int toFD = open(".", O_RDONLY);
    CHECK_IO(fromFD >= 0 && toFD >= 0);
    CHECK_IO(wasiFileDescriptorAdd(fromFD, ".", &from));
    CHECK_IO(wasiFileDescriptorAdd(toFD, ".", &to));
#else
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &from));
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &to));
#endif
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview110_fdX5Freaddir(
        NULL,
        from,
        128,
        1,
        0,
        512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview110_fdX5Freaddir(
        NULL,
        to,
        128,
        1,
        0,
        512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(wasiFileDescriptorGet(from, &source));
    CHECK_IO(source.dir != NULL);
    CHECK_IO(renumber(NULL, from, from) == WASI_ERRNO_SUCCESS);
    CHECK_IO(renumber(NULL, from, to) == WASI_ERRNO_SUCCESS);
    CHECK_IO(!wasiFileDescriptorGet(from, &descriptor));
    CHECK_IO(wasiFileDescriptorGet(to, &descriptor));
    CHECK_IO(descriptor.fd == source.fd);
    CHECK_IO(descriptor.dir == source.dir && descriptor.path == source.path);
    CHECK_IO(readdir(descriptor.dir) != NULL);
#if HAS_UNISTD && !defined(_WIN32)
    CHECK_IO(fcntl(toFD, F_GETFD) == -1 && errno == EBADF);
    CHECK_IO(fcntl(fromFD, F_GETFD) >= 0);
#endif
    CHECK_IO(wasiFileDescriptorClose(to));
#if HAS_UNISTD && !defined(_WIN32)
    CHECK_IO(fcntl(fromFD, F_GETFD) == -1 && errno == EBADF);
#endif
    fprintf(stderr, "OK fd_renumber directory ownership\n");
}

#if HAS_UNISTD && !defined(_WIN32)

static void testFdRenumberFile(TestFdRenumber renumber) {
    FILE* source = tmpfile();
    FILE* target = tmpfile();
    U32 from, to;
    int fromFD, toFD;
    WasiFileDescriptor descriptor;
    char bytes[3];
    CHECK_IO(source != NULL && target != NULL);
    fromFD = dup(fileno(source));
    toFD = dup(fileno(target));
    CHECK_IO(fromFD >= 0 && toFD >= 0);
    CHECK_IO(wasiFileDescriptorAdd(fromFD, NULL, &from));
    CHECK_IO(wasiFileDescriptorAdd(toFD, NULL, &to));
    CHECK_IO(write(fromFD, "abcdef", 6) == 6);
    CHECK_IO(lseek(fromFD, 2, SEEK_SET) == 2);
    CHECK_IO(renumber(NULL, from, from) == WASI_ERRNO_SUCCESS);
    CHECK_IO(renumber(NULL, from, to) == WASI_ERRNO_SUCCESS);
    CHECK_IO(!wasiFileDescriptorGet(from, &descriptor));
    CHECK_IO(wasiFileDescriptorGet(to, &descriptor));
    CHECK_IO(descriptor.fd == fromFD);
    CHECK_IO(lseek(descriptor.fd, 0, SEEK_CUR) == 2);
    CHECK_IO(read(descriptor.fd, bytes, sizeof(bytes)) == sizeof(bytes));
    CHECK_IO(memcmp(bytes, "cde", sizeof(bytes)) == 0);
    CHECK_IO(fcntl(toFD, F_GETFD) == -1 && errno == EBADF);
    CHECK_IO(wasiFileDescriptorClose(to));
    CHECK_IO(fcntl(fromFD, F_GETFD) == -1 && errno == EBADF);
    CHECK_IO(fclose(source) == 0 && fclose(target) == 0);

    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &from));
    CHECK_IO(wasiFileDescriptorAdd(INT_MAX, "..", &to));
    CHECK_IO(renumber(NULL, from, to) == WASI_ERRNO_BADF);
    CHECK_IO(wasiFileDescriptorGet(from, &descriptor));
    CHECK_IO(strcmp(descriptor.path, ".") == 0);
    CHECK_IO(wasiFileDescriptorSet(to, -1));
    CHECK_IO(wasiFileDescriptorClose(from));
    CHECK_IO(wasiFileDescriptorClose(to));
    fprintf(stderr, "OK fd_renumber file offset and close errors\n");
}

#endif

#ifdef WASM_THREAD_TYPE

typedef struct TestRenumberThread {
    TestFdRenumber renumber;
    U32 from;
    U32 to;
    U32 result;
} TestRenumberThread;

static void* testRenumberThread(void* argument) {
    TestRenumberThread* test = (TestRenumberThread*)argument;
    U32 added;
    WasiFileDescriptor descriptor;
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &added));
    CHECK_IO(wasiFileDescriptorGet(added, &descriptor));
    CHECK_IO(strcmp(descriptor.path, ".") == 0);
    CHECK_IO(wasiFileDescriptorSet(added, -1));
    test->result = test->renumber(NULL, test->from, test->to);
    CHECK_IO(wasiFileDescriptorClose(added));
    return NULL;
}

static void testFdRenumberConcurrent(TestFdRenumber renumber) {
    unsigned int i;
    for (i = 0; i < 32; i++) {
        TestRenumberThread first, second;
        WASM_THREAD_TYPE firstThread, secondThread;
        WasiFileDescriptor descriptor;
        first.renumber = second.renumber = renumber;
        CHECK_IO(wasiFileDescriptorAdd(-1, ".", &first.from));
        second.from = first.from;
        CHECK_IO(wasiFileDescriptorAdd(-1, ".", &first.to));
        CHECK_IO(wasiFileDescriptorAdd(-1, ".", &second.to));
        CHECK_IO(WASM_THREAD_CREATE(
            &firstThread,
            testRenumberThread,
            &first
        ));
        CHECK_IO(WASM_THREAD_CREATE(
            &secondThread,
            testRenumberThread,
            &second
        ));
        WASM_THREAD_JOIN(firstThread);
        WASM_THREAD_JOIN(secondThread);
        CHECK_IO(
            (first.result == WASI_ERRNO_SUCCESS && second.result == WASI_ERRNO_BADF)
            || (first.result == WASI_ERRNO_BADF && second.result == WASI_ERRNO_SUCCESS)
        );
        CHECK_IO(!wasiFileDescriptorGet(first.from, &descriptor));
        CHECK_IO(wasiFileDescriptorClose(first.to));
        CHECK_IO(wasiFileDescriptorClose(second.to));
    }
    fprintf(stderr, "OK fd_renumber concurrent moves\n");
}

#endif

static void testFdRenumber(TestFdRenumber renumber) {
    testFdRenumberValidation(renumber);
    testFdRenumberDirectory(renumber);
#if HAS_UNISTD && !defined(_WIN32)
    testFdRenumberFile(renumber);
#endif
#ifdef WASM_THREAD_TYPE
    testFdRenumberConcurrent(renumber);
#endif
}

extern U32 i22_wasiX5FsnapshotX5Fpreview119_fdX5FfdstatX5FsetX5Fflags(
    wasmModuleInstance*, U32, U32
);
extern U32 i13_wasiX5Funstable19_fdX5FfdstatX5FsetX5Fflags(
    wasmModuleInstance*, U32, U32
);
extern U32 i22_wasiX5FsnapshotX5Fpreview113_fdX5FfdstatX5Fget(
    wasmModuleInstance*, U32, U32
);
extern U32 i13_wasiX5Funstable13_fdX5FfdstatX5Fget(
    wasmModuleInstance*, U32, U32
);

typedef U32 (*TestPathOpen)(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32,
    U64,
    U64,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview19_pathX5Fopen(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32,
    U64,
    U64,
    U32,
    U32
);
extern U32 i13_wasiX5Funstable9_pathX5Fopen(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32,
    U64,
    U64,
    U32,
    U32
);

static void testFdRights(
    U32 wasiFD,
    WasiRights base,
    WasiRights inheriting
) {
    WasiFileDescriptor descriptor;
    CHECK_IO(wasiFileDescriptorGet(wasiFD, &descriptor));
    CHECK_IO(descriptor.rightsBase == base);
    CHECK_IO(descriptor.rightsInheriting == inheriting);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview113_fdX5FfdstatX5Fget(
        NULL,
        wasiFD,
        512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i64_load(&testMemory, 520) == base);
    CHECK_IO(i64_load(&testMemory, 528) == inheriting);
    CHECK_IO(i13_wasiX5Funstable13_fdX5FfdstatX5Fget(
        NULL,
        wasiFD,
        512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i64_load(&testMemory, 520) == base);
    CHECK_IO(i64_load(&testMemory, 528) == inheriting);
}

static U32 testOpenWithRights(
    TestPathOpen openPath,
    U32 directory,
    const char* path,
    U32 flags,
    WasiRights base,
    WasiRights inheriting
) {
    size_t length = strlen(path);
    memcpy(testMemory.data + 1024, path, length);
    CHECK_IO(openPath(
        NULL,
        directory,
        WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW,
        1024,
        (U32)length,
        flags,
        base,
        inheriting,
        0,
        512
    ) == WASI_ERRNO_SUCCESS);
    return i32_load(&testMemory, 512);
}

static void testDirectoryRights(
    TestPathOpen openPath,
    TestFdRenumber renumber
) {
    U32 parent, child, target;
    WasiFileDescriptor descriptor;
    WasiRights base = WASI_RIGHTS_PATH_OPEN | WASI_RIGHTS_FD_READDIR;
    WasiRights inheriting = WASI_RIGHTS_FD_READ | WASI_RIGHTS_FD_FILESTAT_GET;

    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &parent));
    testFdRights(
        parent,
        WASI_RIGHTS_DIRECTORY_BASE,
        WASI_RIGHTS_DIRECTORY_INHERITING
    );
    child = testOpenWithRights(
        openPath,
        parent,
        ".",
        WASI_OFLAGS_DIRECTORY,
        base | WASI_RIGHTS_FD_READ,
        inheriting
    );
    testFdRights(child, base, inheriting);
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &target));
    CHECK_IO(renumber(NULL, child, child) == WASI_ERRNO_SUCCESS);
    testFdRights(child, base, inheriting);
    CHECK_IO(renumber(NULL, child, target) == WASI_ERRNO_SUCCESS);
    testFdRights(target, base, inheriting);
    CHECK_IO(!wasiFileDescriptorGet(child, &descriptor));
    CHECK_IO(descriptor.rightsBase == 0 && descriptor.rightsInheriting == 0);
    CHECK_IO(wasiFileDescriptorClose(target));
    CHECK_IO(!wasiFileDescriptorGet(target, &descriptor));
    CHECK_IO(descriptor.rightsBase == 0 && descriptor.rightsInheriting == 0);
    CHECK_IO(wasiFileDescriptorClose(parent));
    fprintf(stderr, "OK directory rights and renumbering\n");
}

typedef U32 (*TestFdSetTimes)(
    wasmModuleInstance*,
    U32,
    U64,
    U64,
    U32
);
typedef U32 (*TestPathSetTimes)(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U64,
    U64,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview121_fdX5FfilestatX5FsetX5Ftimes(
    wasmModuleInstance*,
    U32,
    U64,
    U64,
    U32
);
extern U32 i13_wasiX5Funstable21_fdX5FfilestatX5FsetX5Ftimes(
    wasmModuleInstance*,
    U32,
    U64,
    U64,
    U32
);
extern U32 i22_wasiX5FsnapshotX5Fpreview123_pathX5FfilestatX5FsetX5Ftimes(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U64,
    U64,
    U32
);
extern U32 i13_wasiX5Funstable23_pathX5FfilestatX5FsetX5Ftimes(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U64,
    U64,
    U32
);

static void testFilestatSetTimesValidation(
    TestFdSetTimes setFD,
    TestPathSetTimes setPath
) {
    U32 wasiFD;
    size_t i;
    static const U32 invalidFlags[] = {
        WASI_FSTFLAGS_ATIM | WASI_FSTFLAGS_ATIM_NOW,
        WASI_FSTFLAGS_MTIM | WASI_FSTFLAGS_MTIM_NOW,
        0x10, 0x10000
    };

    CHECK_IO(setFD(
        NULL,
        UINT32_MAX,
        0,
        0,
        0
    ) == WASI_ERRNO_BADF);
    CHECK_IO(setPath(
        NULL,
        UINT32_MAX,
        0,
        128,
        1,
        0,
        0,
        0
    ) == WASI_ERRNO_BADF);
    CHECK_IO(setPath(
        NULL,
        0,
        0,
        128,
        1,
        0,
        0,
        0
    ) == WASI_ERRNO_BADF);
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &wasiFD));
    testMemory.data[128] = '.';
    for (i = 0; i < sizeof(invalidFlags) / sizeof(invalidFlags[0]); i++) {
        CHECK_IO(setFD(
            NULL,
            wasiFD,
            0,
            0,
            invalidFlags[i]
        ) == WASI_ERRNO_INVAL);
        CHECK_IO(setPath(
            NULL,
            wasiFD,
            0,
            128,
            1,
            0,
            0,
            invalidFlags[i]
        ) == WASI_ERRNO_INVAL);
    }
    CHECK_IO(setPath(
        NULL,
        wasiFD,
        2,
        128,
        1,
        0,
        0,
        0
    ) == WASI_ERRNO_INVAL);
    CHECK_IO(setPath(
        NULL,
        wasiFD,
        0,
        128,
        0,
        0,
        0,
        0
    ) == WASI_ERRNO_INVAL);
    CHECK_IO(setPath(
        NULL,
        wasiFD,
        0,
        UINT32_MAX,
        1,
        0,
        0,
        0
    ) == WASI_ERRNO_FAULT);
    CHECK_IO(setPath(
        NULL,
        wasiFD,
        0,
        TEST_MEMORY_SIZE - 1,
        2,
        0,
        0,
        0
    ) == WASI_ERRNO_FAULT);
    testMemory.data[129] = '\0';
    CHECK_IO(setPath(
        NULL,
        wasiFD,
        0,
        128,
        2,
        0,
        0,
        0
    ) == WASI_ERRNO_INVAL);
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(setFD(
        NULL,
        wasiFD,
        0,
        0,
        0
    ) == WASI_ERRNO_BADF);
    CHECK_IO(setPath(
        NULL,
        wasiFD,
        0,
        128,
        1,
        0,
        0,
        0
    ) == WASI_ERRNO_BADF);
    fprintf(stderr, "OK filestat_set_times validation\n");
}

#if HAS_UNISTD && !defined(_WIN32)

static U64 testStatTime(struct stat* st, bool modification) {
    U64 seconds;
    long nanoseconds;
#if defined(__APPLE__) && defined(__MACH__)
    seconds = (U64)(modification ? st->st_mtimespec.tv_sec : st->st_atimespec.tv_sec);
    nanoseconds = modification ? st->st_mtimespec.tv_nsec : st->st_atimespec.tv_nsec;
#elif (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200809L)) || \
    (defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE >= 700))
    seconds = (U64)(modification ? st->st_mtim.tv_sec : st->st_atim.tv_sec);
    nanoseconds = modification ? st->st_mtim.tv_nsec : st->st_atim.tv_nsec;
#else
    seconds = (U64)(modification ? st->st_mtime : st->st_atime);
    nanoseconds = 0;
#endif
    return seconds * W2C2_LL(1000000000) + (U64)nanoseconds;
}

#if HAS_FUTIMENS

static void testNativeFileTimes(int fd, U64* atime, U64* mtime) {
    struct timespec times[2];
    struct stat st;
    times[0].tv_sec = (time_t)(*atime / W2C2_LL(1000000000));
    times[0].tv_nsec = (long)(*atime % W2C2_LL(1000000000));
    times[1].tv_sec = (time_t)(*mtime / W2C2_LL(1000000000));
    times[1].tv_nsec = (long)(*mtime % W2C2_LL(1000000000));
    /* Measure the precision exposed by the native filesystem and stat API.
     * QEMU 8.2's s390x stat emulation discards nanoseconds.
     */
    CHECK_IO(futimens(fd, times) == 0);
    CHECK_IO(fstat(fd, &st) == 0);
    *atime = testStatTime(&st, false);
    *mtime = testStatTime(&st, true);
    /* Clear the baseline
     * so a WASI implementation that does nothing fails.
     */
    memset(times, 0, sizeof(times));
    CHECK_IO(futimens(fd, times) == 0);
}

#endif

static void testFdFilestatSetTimes(TestFdSetTimes setTimes) {
    FILE* file = tmpfile();
    int fd;
    U32 wasiFD;
#if HAS_FUTIMENS || HAS_FUTIMES
    struct stat st;
    time_t before;
    U64 atime = W2C2_LL(1000000000123456789);
    U64 mtime = W2C2_LL(1000000000987654321);
    U64 expectedAtime = atime;
    U64 expectedMtime = mtime;
#endif
    CHECK_IO(file != NULL);
    fd = dup(fileno(file));
    CHECK_IO(fd >= 0);
    CHECK_IO(wasiFileDescriptorAdd(fd, NULL, &wasiFD));
#if HAS_FUTIMENS || HAS_FUTIMES
#if HAS_FUTIMENS
    testNativeFileTimes(fd, &expectedAtime, &expectedMtime);
#else
    expectedAtime -= expectedAtime % 1000;
    expectedMtime -= expectedMtime % 1000;
#endif
    CHECK_IO(setTimes(
        NULL,
        wasiFD,
        atime,
        mtime,
        WASI_FSTFLAGS_ATIM | WASI_FSTFLAGS_MTIM
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(
        testStatTime(&st, false) == expectedAtime
        && testStatTime(&st, true) == expectedMtime
    );
    CHECK_IO(setTimes(
        NULL,
        wasiFD,
        0,
        (U64)-1,
        WASI_FSTFLAGS_ATIM
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(testStatTime(&st, false) == 0 && testStatTime(&st, true) == expectedMtime);
    CHECK_IO(setTimes(
        NULL,
        wasiFD,
        (U64)-1,
        0,
        WASI_FSTFLAGS_MTIM
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(setTimes(
        NULL,
        wasiFD,
        (U64)-1,
        (U64)-1,
        0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(setTimes(
        NULL,
        wasiFD,
        atime,
        mtime,
        WASI_FSTFLAGS_ATIM | WASI_FSTFLAGS_ATIM_NOW
    ) == WASI_ERRNO_INVAL);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(testStatTime(&st, false) == 0 && testStatTime(&st, true) == 0);

    before = time(NULL);
    CHECK_IO(setTimes(
        NULL,
        wasiFD,
        (U64)-1,
        (U64)-1,
        WASI_FSTFLAGS_ATIM_NOW
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(st.st_atime >= before && st.st_atime <= time(NULL));
    CHECK_IO(testStatTime(&st, true) == 0);
    CHECK_IO(setTimes(
        NULL,
        wasiFD,
        atime,
        (U64)-1,
        WASI_FSTFLAGS_ATIM | WASI_FSTFLAGS_MTIM_NOW
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(testStatTime(&st, false) == expectedAtime);
    CHECK_IO(st.st_mtime >= before && st.st_mtime <= time(NULL));
    CHECK_IO(setTimes(
        NULL,
        wasiFD,
        (U64)-1,
        (U64)-1,
        WASI_FSTFLAGS_ATIM_NOW | WASI_FSTFLAGS_MTIM_NOW
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(st.st_atime >= before && st.st_atime <= time(NULL));
    CHECK_IO(st.st_mtime >= before && st.st_mtime <= time(NULL));
    if (sizeof(time_t) < sizeof(U64)) {
        CHECK_IO(setTimes(
            NULL,
            wasiFD,
            (U64)-1,
            0,
            WASI_FSTFLAGS_ATIM
        ) == WASI_ERRNO_OVERFLOW);
    }
#else
    CHECK_IO(setTimes(
        NULL,
        wasiFD,
        0,
        0,
        WASI_FSTFLAGS_ATIM
    ) == WASI_ERRNO_NOSYS);
#endif
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(fclose(file) == 0);
    fprintf(stderr, "OK fd_filestat_set_times\n");
}

static void testPathFilestatSetTimes(
    TestFdSetTimes setFD,
    TestPathSetTimes setPath
) {
    char directory[] = "wasi-times-XXXXXX";
    char filePath[PATH_MAX];
    char linkPath[PATH_MAX];
    U32 dirFD, fileFD;
    int fd;
    U32 follow = WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW;
    U32 both = WASI_FSTFLAGS_ATIM | WASI_FSTFLAGS_MTIM;
    U64 atime = W2C2_LL(1000000000123456789);
    U64 mtime = W2C2_LL(1000000000987654321);
#if HAS_UTIMENSAT || HAS_UTIMES || HAS_UTIME || HAS_FUTIMENS || HAS_FUTIMES
    struct stat st;
#endif
#if HAS_UTIMENSAT || HAS_UTIMES || HAS_UTIME
    time_t before;
    U64 expectedAtime = atime;
    U64 expectedMtime = mtime;
#else
    UNUSED_PARAMETER(setFD);
#endif

    CHECK_IO(mkdtemp(directory) != NULL);
    strcpy(filePath, directory);
    strcat(filePath, "/file");
    strcpy(linkPath, directory);
    strcat(linkPath, "/link");
    fd = open(filePath, O_CREAT | O_EXCL | O_RDWR, 0600);
    CHECK_IO(fd >= 0);
    CHECK_IO(wasiFileDescriptorAdd(fd, filePath, &fileFD));
    CHECK_IO(wasiFileDescriptorAdd(-1, directory, &dirFD));
    memcpy(testMemory.data + 128, "file", 4);
#if HAS_UTIMENSAT || HAS_UTIMES || HAS_UTIME
#if !HAS_UTIMENSAT
#if HAS_UTIMES
    expectedAtime -= expectedAtime % 1000;
    expectedMtime -= expectedMtime % 1000;
#else
    expectedAtime -= expectedAtime % W2C2_LL(1000000000);
    expectedMtime -= expectedMtime % W2C2_LL(1000000000);
#endif
#endif
#if HAS_FUTIMENS
    testNativeFileTimes(fd, &expectedAtime, &expectedMtime);
#endif
    CHECK_IO(setPath(
        NULL,
        dirFD,
        follow,
        128,
        4,
        atime,
        mtime,
        both
    ) == WASI_ERRNO_SUCCESS);
    atime = expectedAtime;
    mtime = expectedMtime;
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(
        testStatTime(&st, false) == expectedAtime
        && testStatTime(&st, true) == expectedMtime
    );
    CHECK_IO(setPath(
        NULL,
        dirFD,
        follow,
        128,
        4,
        (U64)-1,
        (U64)-1,
        0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(
        testStatTime(&st, false) == expectedAtime
        && testStatTime(&st, true) == expectedMtime
    );
    before = time(NULL);
    CHECK_IO(setPath(
        NULL,
        dirFD,
        follow,
        128,
        4,
        (U64)-1,
        (U64)-1,
        WASI_FSTFLAGS_MTIM_NOW
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(testStatTime(&st, false) == expectedAtime);
    CHECK_IO(st.st_mtime >= before && st.st_mtime <= time(NULL));
    CHECK_IO(setFD(
        NULL,
        dirFD,
        atime,
        mtime,
        both
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(stat(directory, &st) == 0);
    CHECK_IO(
        testStatTime(&st, false) == expectedAtime
        && testStatTime(&st, true) == expectedMtime
    );

#if HAS_LSTAT
    CHECK_IO(symlink("file", linkPath) == 0);
    memcpy(testMemory.data + 128, "link", 4);
    CHECK_IO(setPath(
        NULL,
        dirFD,
        follow,
        128,
        4,
        atime,
        mtime,
        both
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(
        testStatTime(&st, false) == expectedAtime
        && testStatTime(&st, true) == expectedMtime
    );
#if HAS_UTIMENSAT || HAS_LUTIMES
    CHECK_IO(setPath(
        NULL,
        dirFD,
        0,
        128,
        4,
        0,
        0,
        both
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(lstat(linkPath, &st) == 0);
    CHECK_IO(testStatTime(&st, false) == 0 && testStatTime(&st, true) == 0);
#else
    CHECK_IO(setPath(
        NULL,
        dirFD,
        0,
        128,
        4,
        0,
        0,
        both
    ) == WASI_ERRNO_NOTSUP);
#endif
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(
        testStatTime(&st, false) == expectedAtime
        && testStatTime(&st, true) == expectedMtime
    );
    CHECK_IO(unlink(filePath) == 0);
#if HAS_UTIMENSAT || HAS_LUTIMES
    CHECK_IO(setPath(
        NULL,
        dirFD,
        0,
        128,
        4,
        0,
        0,
        both
    ) == WASI_ERRNO_SUCCESS);
#endif
    CHECK_IO(setPath(
        NULL,
        dirFD,
        follow,
        128,
        4,
        0,
        0,
        both
    ) == WASI_ERRNO_NOENT);
    CHECK_IO(unlink(linkPath) == 0);
#else
    CHECK_IO(unlink(filePath) == 0);
#endif
    memcpy(testMemory.data + 128, "file", 4);
    CHECK_IO(setPath(
        NULL,
        dirFD,
        follow,
        128,
        4,
        0,
        0,
        both
    ) == WASI_ERRNO_NOENT);
#else
    CHECK_IO(setPath(
        NULL,
        dirFD,
        follow,
        128,
        4,
        atime,
        mtime,
        both
    ) == WASI_ERRNO_NOSYS);
    CHECK_IO(unlink(filePath) == 0);
#endif
#if HAS_FUTIMENS || HAS_FUTIMES
    CHECK_IO(setFD(
        NULL,
        fileFD,
        0,
        0,
        both
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &st) == 0);
    CHECK_IO(testStatTime(&st, false) == 0 && testStatTime(&st, true) == 0);
#endif
    CHECK_IO(wasiFileDescriptorClose(fileFD));
    CHECK_IO(wasiFileDescriptorClose(dirFD));
    CHECK_IO(rmdir(directory) == 0);
    fprintf(stderr, "OK path_filestat_set_times\n");
}

#endif /* HAS_UNISTD && !_WIN32 */

#ifdef _WIN32

static U64 testWindowsFileTime(FILETIME value) {
    return ((U64)value.dwHighDateTime << 32) | value.dwLowDateTime;
}

static void testWindowsFilestatSetTimes(
    TestFdSetTimes setFD,
    TestPathSetTimes setPath
) {
    char directory[MAX_PATH];
    char path[MAX_PATH];
    char* name;
    int fd;
    U32 wasiFD, dirFD;
    HANDLE handle;
    FILETIME creation, access, modification, before, after;
    U64 atime = W2C2_LL(1000000000123456789);
    U64 mtime = W2C2_LL(1000000000987654321);
    U64 epoch = W2C2_LL(116444736000000000);

    CHECK_IO(GetTempPathA(sizeof(directory), directory) != 0);
    CHECK_IO(GetTempFileNameA(
        directory,
        "w2c",
        0,
        path
    ) != 0);
    fd = _open(path, _O_RDWR | _O_BINARY);
    CHECK_IO(fd >= 0);
    handle = (HANDLE)_get_osfhandle(fd);
    CHECK_IO(wasiFileDescriptorAdd(fd, NULL, &wasiFD));
    CHECK_IO(setFD(
        NULL,
        wasiFD,
        atime,
        mtime,
        WASI_FSTFLAGS_ATIM | WASI_FSTFLAGS_MTIM
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(GetFileTime(
        handle,
        &creation,
        &access,
        &modification
    ));
    CHECK_IO(testWindowsFileTime(access) == atime / 100 + epoch);
    CHECK_IO(testWindowsFileTime(modification) == mtime / 100 + epoch);
    CHECK_IO(setFD(
        NULL,
        wasiFD,
        (U64)-1,
        (U64)-1,
        0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(setFD(
        NULL,
        wasiFD,
        0,
        (U64)-1,
        WASI_FSTFLAGS_ATIM
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(GetFileTime(
        handle,
        &creation,
        &access,
        &modification
    ));
    CHECK_IO(testWindowsFileTime(access) == epoch);
    CHECK_IO(testWindowsFileTime(modification) == mtime / 100 + epoch);

    CHECK_IO(wasiFileDescriptorAdd(-1, directory, &dirFD));
    name = strrchr(path, '\\');
    CHECK_IO(name != NULL);
    name++;
    memcpy(testMemory.data + 128, name, strlen(name));
    CHECK_IO(setPath(
        NULL,
        dirFD,
        0,
        128,
        (U32)strlen(name),
        atime,
        (U64)-1,
        WASI_FSTFLAGS_ATIM
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(GetFileTime(
        handle,
        &creation,
        &access,
        &modification
    ));
    CHECK_IO(testWindowsFileTime(access) == atime / 100 + epoch);
    CHECK_IO(testWindowsFileTime(modification) == mtime / 100 + epoch);

    GetSystemTimeAsFileTime(&before);
    CHECK_IO(setFD(
        NULL,
        wasiFD,
        (U64)-1,
        (U64)-1,
        WASI_FSTFLAGS_ATIM_NOW | WASI_FSTFLAGS_MTIM_NOW
    ) == WASI_ERRNO_SUCCESS);
    GetSystemTimeAsFileTime(&after);
    CHECK_IO(GetFileTime(
        handle,
        &creation,
        &access,
        &modification
    ));
    CHECK_IO(testWindowsFileTime(access) >= testWindowsFileTime(before));
    CHECK_IO(testWindowsFileTime(access) <= testWindowsFileTime(after));
    CHECK_IO(testWindowsFileTime(access) == testWindowsFileTime(modification));
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(DeleteFileA(path));
    CHECK_IO(setPath(
        NULL,
        dirFD,
        0,
        128,
        (U32)strlen(name),
        0,
        0,
        WASI_FSTFLAGS_ATIM
    ) == WASI_ERRNO_NOENT);
    CHECK_IO(wasiFileDescriptorClose(dirFD));
    fprintf(stderr, "OK Windows filestat_set_times\n");
}

#endif /* _WIN32 */

static void testFilestatSetTimes(
    TestFdSetTimes setFD,
    TestPathSetTimes setPath
) {
    testFilestatSetTimesValidation(setFD, setPath);
#if HAS_UNISTD && !defined(_WIN32)
    testFdFilestatSetTimes(setFD);
    testPathFilestatSetTimes(setFD, setPath);
#endif
#ifdef _WIN32
    testWindowsFilestatSetTimes(setFD, setPath);
#endif
}

typedef U32 (*TestPathLinkFunction)(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview19_pathX5Flink(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32,
    U32,
    U32
);
extern U32 i13_wasiX5Funstable9_pathX5Flink(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32,
    U32,
    U32
);

typedef struct TestPathLink {
    TestPathLinkFunction call;
    U32 oldFD;
    U32 newFD;
} TestPathLink;

static U32 callTestPathLink(
    TestPathLink* test,
    const char* oldPath,
    const char* newPath,
    U32 flags
) {
    size_t oldLength = strlen(oldPath);
    size_t newLength = strlen(newPath);
    CHECK_IO(oldLength < PATH_MAX && newLength < PATH_MAX);
    memcpy(testMemory.data, oldPath, oldLength);
    memcpy(testMemory.data + PATH_MAX, newPath, newLength);
    return test->call(
        NULL,
        test->oldFD,
        flags,
        0,
        (U32)oldLength,
        test->newFD,
        PATH_MAX,
        (U32)newLength
    );
}

static void testPathLinkValidation(TestPathLinkFunction link) {
    TestPathLink test;
    U32 dirFD;
    int i;
    test.call = link;
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &dirFD));
    test.oldFD = dirFD;
    test.newFD = dirFD;
    CHECK_IO(callTestPathLink(
        &test,
        "source",
        "target",
        2
    ) == WASI_ERRNO_INVAL);
    CHECK_IO(callTestPathLink(
        &test,
        "",
        "target",
        0
    ) == WASI_ERRNO_INVAL);
    CHECK_IO(callTestPathLink(
        &test,
        "source",
        "",
        0
    ) == WASI_ERRNO_INVAL);
    for (i = 0; i < 2; i++) {
        test.oldFD = i == 0 ? UINT32_MAX : dirFD;
        test.newFD = i == 1 ? UINT32_MAX : dirFD;
        CHECK_IO(callTestPathLink(
            &test,
            "source",
            "target",
            0
        ) == WASI_ERRNO_BADF);
        test.oldFD = i == 0 ? 0 : dirFD;
        test.newFD = i == 1 ? 0 : dirFD;
        CHECK_IO(callTestPathLink(
            &test,
            "source",
            "target",
            0
        ) == WASI_ERRNO_BADF);
        CHECK_IO(link(
            NULL,
            dirFD,
            0,
            i == 0 ? UINT32_MAX : 0,
            2,
            dirFD,
            i == 1 ? TEST_MEMORY_SIZE - 1 : PATH_MAX,
            2
        ) == WASI_ERRNO_FAULT);
        testMemory.data[0] = 'a';
        testMemory.data[1] = i == 0 ? '\0' : 'b';
        testMemory.data[PATH_MAX] = 'a';
        testMemory.data[PATH_MAX + 1] = i == 1 ? '\0' : 'b';
        CHECK_IO(link(
            NULL,
            dirFD,
            0,
            0,
            2,
            dirFD,
            PATH_MAX,
            2
        ) == WASI_ERRNO_INVAL);
    }
    CHECK_IO(wasiFileDescriptorClose(dirFD));
    test.oldFD = dirFD;
    test.newFD = dirFD;
    CHECK_IO(callTestPathLink(
        &test,
        "source",
        "target",
        0
    ) == WASI_ERRNO_BADF);
    fprintf(stderr, "OK path_link validation\n");
}

#if HAS_UNISTD && !defined(_WIN32)

static void testNativePathLink(TestPathLinkFunction link) {
    char directory[] = "wasi-link-XXXXXX";
    char destination[PATH_MAX];
    char source[PATH_MAX];
    char target[PATH_MAX];
    char symlinkPath[PATH_MAX];
    TestPathLink test;
    int fd;
#if HAS_LINKAT || (HAS_LINK && HAS_LSTAT)
    struct stat original, linked;
    char bytes[5];
    int linkedFD;
    U32 follow = WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW;
#elif HAS_LINK
    U32 expected = WASI_ERRNO_NOTSUP;
#else
    U32 expected = WASI_ERRNO_NOSYS;
#endif
    test.call = link;
    CHECK_IO(mkdtemp(directory) != NULL);
    strcpy(destination, directory);
    strcat(destination, "/destination");
    CHECK_IO(mkdir(destination, 0700) == 0);
    strcpy(source, directory);
    strcat(source, "/source");
    strcpy(target, destination);
    strcat(target, "/linked");
    strcpy(symlinkPath, directory);
    strcat(symlinkPath, "/symbolic");
    fd = open(source, O_CREAT | O_EXCL | O_RDWR, 0600);
    CHECK_IO(fd >= 0);
    CHECK_IO(write(fd, "hello", 5) == 5);
    CHECK_IO(wasiFileDescriptorAdd(-1, directory, &test.oldFD));
    CHECK_IO(wasiFileDescriptorAdd(-1, destination, &test.newFD));
#if HAS_LINKAT || (HAS_LINK && HAS_LSTAT)
    CHECK_IO(callTestPathLink(
        &test,
        "source",
        "linked",
        0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fstat(fd, &original) == 0);
    CHECK_IO(stat(target, &linked) == 0);
    CHECK_IO(original.st_dev == linked.st_dev && original.st_ino == linked.st_ino);
    CHECK_IO(original.st_nlink == 2 && linked.st_nlink == 2);
    CHECK_IO(callTestPathLink(
        &test,
        "source",
        "linked",
        follow
    ) == WASI_ERRNO_EXIST);
    CHECK_IO(callTestPathLink(
        &test,
        "missing",
        "missing",
        0
    ) == WASI_ERRNO_NOENT);
    CHECK_IO(callTestPathLink(
        &test,
        ".",
        "directory",
        0
    ) == WASI_ERRNO_PERM);
    CHECK_IO(unlink(target) == 0);
    CHECK_IO(callTestPathLink(
        &test,
        "source",
        "linked",
        follow
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(stat(target, &linked) == 0);
    CHECK_IO(original.st_dev == linked.st_dev && original.st_ino == linked.st_ino);

#if HAS_LSTAT
    CHECK_IO(symlink("source", symlinkPath) == 0);
    CHECK_IO(unlink(target) == 0);
#if HAS_LINKAT || HAS_REALPATH
    CHECK_IO(callTestPathLink(
        &test,
        "symbolic",
        "linked",
        follow
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(stat(target, &linked) == 0);
    CHECK_IO(original.st_dev == linked.st_dev && original.st_ino == linked.st_ino);
    CHECK_IO(unlink(target) == 0);
#else
    CHECK_IO(callTestPathLink(
        &test,
        "symbolic",
        "linked",
        follow
    ) == WASI_ERRNO_NOTSUP);
#endif
#if HAS_LINKAT
    CHECK_IO(callTestPathLink(
        &test,
        "symbolic",
        "linked",
        0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(lstat(symlinkPath, &original) == 0);
    CHECK_IO(lstat(target, &linked) == 0);
    CHECK_IO(S_ISLNK(linked.st_mode));
    CHECK_IO(original.st_dev == linked.st_dev && original.st_ino == linked.st_ino);
    CHECK_IO(original.st_nlink == 2 && linked.st_nlink == 2);
    CHECK_IO(unlink(target) == 0);
#else
    CHECK_IO(callTestPathLink(
        &test,
        "symbolic",
        "linked",
        0
    ) == WASI_ERRNO_NOTSUP);
#endif
    CHECK_IO(unlink(symlinkPath) == 0);
    CHECK_IO(symlink("missing", symlinkPath) == 0);
#if HAS_LINKAT || HAS_REALPATH
    CHECK_IO(callTestPathLink(
        &test,
        "symbolic",
        "linked",
        follow
    ) == WASI_ERRNO_NOENT);
#endif
#if HAS_LINKAT
    CHECK_IO(callTestPathLink(
        &test,
        "symbolic",
        "linked",
        0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(lstat(target, &linked) == 0 && S_ISLNK(linked.st_mode));
    CHECK_IO(unlink(target) == 0);
#endif
    CHECK_IO(unlink(symlinkPath) == 0);
    CHECK_IO(symlink("symbolic", symlinkPath) == 0);
#if HAS_LINKAT || HAS_REALPATH
    CHECK_IO(callTestPathLink(
        &test,
        "symbolic",
        "linked",
        follow
    ) == WASI_ERRNO_LOOP);
#endif
    CHECK_IO(unlink(symlinkPath) == 0);
    CHECK_IO(callTestPathLink(
        &test,
        "source",
        "linked",
        0
    ) == WASI_ERRNO_SUCCESS);
#endif

    CHECK_IO(unlink(source) == 0);
    linkedFD = open(target, O_RDONLY);
    CHECK_IO(linkedFD >= 0);
    CHECK_IO(read(linkedFD, bytes, sizeof(bytes)) == (ssize_t)sizeof(bytes));
    CHECK_IO(memcmp(bytes, "hello", sizeof(bytes)) == 0);
    CHECK_IO(fstat(linkedFD, &linked) == 0 && linked.st_nlink == 1);
    CHECK_IO(close(linkedFD) == 0);
    CHECK_IO(unlink(target) == 0);
#else
    CHECK_IO(callTestPathLink(
        &test,
        "source",
        "linked",
        0
    ) == expected);
    CHECK_IO(unlink(source) == 0);
#endif
    CHECK_IO(close(fd) == 0);
    CHECK_IO(wasiFileDescriptorClose(test.oldFD));
    CHECK_IO(wasiFileDescriptorClose(test.newFD));
    CHECK_IO(rmdir(destination) == 0);
    CHECK_IO(rmdir(directory) == 0);
    fprintf(stderr, "OK path_link native\n");
}

#endif /* HAS_UNISTD && !_WIN32 */

#ifdef _WIN32

static void testWindowsPathLink(TestPathLinkFunction link) {
    char directory[MAX_PATH];
    char source[MAX_PATH];
    char target[MAX_PATH];
    char* name;
    TestPathLink test;
    int fd, linkedFD;
    char bytes[5];
    BY_HANDLE_FILE_INFORMATION original, linked;
    test.call = link;
    CHECK_IO(GetTempPathA(sizeof(directory), directory) != 0);
    CHECK_IO(GetTempFileNameA(
        directory,
        "w2c",
        0,
        source
    ) != 0);
    CHECK_IO(strlen(source) + 5 < sizeof(target));
    strcpy(target, source);
    strcat(target, ".link");
    fd = _open(source, _O_RDWR | _O_BINARY);
    CHECK_IO(fd >= 0);
    CHECK_IO(_write(fd, "hello", 5) == 5);
    name = strrchr(source, '\\');
    CHECK_IO(name != NULL);
    name++;
    CHECK_IO(wasiFileDescriptorAdd(-1, directory, &test.oldFD));
    CHECK_IO(wasiFileDescriptorAdd(-1, directory, &test.newFD));
    CHECK_IO(callTestPathLink(
        &test,
        name,
        strrchr(target, '\\') + 1,
        0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(callTestPathLink(
        &test,
        name,
        strrchr(target, '\\') + 1,
        WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW
    ) == WASI_ERRNO_EXIST);
    linkedFD = _open(target, _O_RDONLY | _O_BINARY);
    CHECK_IO(linkedFD >= 0);
    CHECK_IO(GetFileInformationByHandle(
        (HANDLE)_get_osfhandle(fd),
        &original
    ));
    CHECK_IO(GetFileInformationByHandle(
        (HANDLE)_get_osfhandle(linkedFD),
        &linked
    ));
    CHECK_IO(original.dwVolumeSerialNumber == linked.dwVolumeSerialNumber);
    CHECK_IO(original.nFileIndexHigh == linked.nFileIndexHigh);
    CHECK_IO(original.nFileIndexLow == linked.nFileIndexLow);
    CHECK_IO(original.nNumberOfLinks == 2 && linked.nNumberOfLinks == 2);
    CHECK_IO(_close(fd) == 0);
    CHECK_IO(_close(linkedFD) == 0);
    CHECK_IO(DeleteFileA(source));
    linkedFD = _open(target, _O_RDONLY | _O_BINARY);
    CHECK_IO(linkedFD >= 0);
    CHECK_IO(_read(linkedFD, bytes, sizeof(bytes)) == (int)sizeof(bytes));
    CHECK_IO(memcmp(bytes, "hello", sizeof(bytes)) == 0);
    CHECK_IO(_close(linkedFD) == 0);
    CHECK_IO(DeleteFileA(target));
    CHECK_IO(callTestPathLink(
        &test,
        name,
        strrchr(target, '\\') + 1,
        WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW
    ) == WASI_ERRNO_NOENT);
    CHECK_IO(wasiFileDescriptorClose(test.oldFD));
    CHECK_IO(wasiFileDescriptorClose(test.newFD));
    fprintf(stderr, "OK path_link Windows\n");
}

#endif /* _WIN32 */

static void testPathLink(TestPathLinkFunction link) {
    testPathLinkValidation(link);
#if HAS_UNISTD && !defined(_WIN32)
    testNativePathLink(link);
#endif
#ifdef _WIN32
    testWindowsPathLink(link);
#endif
}

typedef U32 (*TestFdAllocate)(
    wasmModuleInstance*,
    U32,
    U64,
    U64
);
typedef U32 (*TestFdAdvise)(
    wasmModuleInstance*,
    U32,
    U64,
    U64,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview111_fdX5Fallocate(
    wasmModuleInstance*,
    U32,
    U64,
    U64
);
extern U32 i13_wasiX5Funstable11_fdX5Fallocate(
    wasmModuleInstance*,
    U32,
    U64,
    U64
);
extern U32 i22_wasiX5FsnapshotX5Fpreview19_fdX5Fadvise(
    wasmModuleInstance*,
    U32,
    U64,
    U64,
    U32
);
extern U32 i13_wasiX5Funstable9_fdX5Fadvise(
    wasmModuleInstance*,
    U32,
    U64,
    U64,
    U32
);

static void testFdStorageValidation(
    TestFdAllocate allocate,
    TestFdAdvise advise
) {
    U32 wasiFD;
    CHECK_IO(allocate(
        NULL,
        UINT32_MAX,
        0,
        1
    ) == WASI_ERRNO_BADF);
    CHECK_IO(advise(
        NULL,
        UINT32_MAX,
        0,
        1,
        WASI_ADVICE_NORMAL
    ) == WASI_ERRNO_BADF);
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &wasiFD));
    CHECK_IO(allocate(
        NULL,
        wasiFD,
        0,
        1
    ) == WASI_ERRNO_NOTCAPABLE);
    CHECK_IO(advise(
        NULL,
        wasiFD,
        0,
        1,
        WASI_ADVICE_NORMAL
    ) == WASI_ERRNO_ISDIR);
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(allocate(
        NULL,
        wasiFD,
        0,
        1
    ) == WASI_ERRNO_BADF);
    CHECK_IO(advise(
        NULL,
        wasiFD,
        0,
        1,
        WASI_ADVICE_NORMAL
    ) == WASI_ERRNO_BADF);
    fprintf(stderr, "OK fd_allocate and fd_advise validation\n");
}

#if HAS_UNISTD || defined(_WIN32)

#ifdef _WIN32
#define testNativeDup _dup
#define testNativeFileno _fileno
#define testNativeRead _read
#define testNativeWrite _write
#define testNativeSeek _lseek
#define testNativeStat _fstat
#define testNativeStatType _stat
#else
#define testNativeDup dup
#define testNativeFileno fileno
#define testNativeRead read
#define testNativeWrite write
#define testNativeSeek lseek
#define testNativeStat fstat
#define testNativeStatType stat
#endif

static void testFdStorage(
    TestFdAllocate allocate,
    TestFdAdvise advise
) {
    FILE* file = tmpfile();
    U32 wasiFD;
    U32 advice;
    U32 allocationError;
    int fd;
    struct testNativeStatType st;
    char bytes[6];
    size_t i;
#if HAS_F_PREALLOCATE && !defined(_WIN32)
    U64 blocks;
#endif
    CHECK_IO(file != NULL);
    fd = testNativeDup(testNativeFileno(file));
    CHECK_IO(fd >= 0);
    CHECK_IO(wasiFileDescriptorAdd(fd, NULL, &wasiFD));
    CHECK_IO(testNativeWrite(fd, "abcdef", 6) == 6);
    CHECK_IO(testNativeSeek(fd, 2, SEEK_SET) == 2);

    CHECK_IO(allocate(
        NULL,
        wasiFD,
        0,
        0
    ) == WASI_ERRNO_INVAL);
    CHECK_IO(allocate(
        NULL,
        wasiFD,
        UINT64_MAX,
        1
    ) == WASI_ERRNO_OVERFLOW);
    CHECK_IO(allocate(
        NULL,
        wasiFD,
        (U64)INT64_MAX,
        1
    ) == WASI_ERRNO_OVERFLOW);
    CHECK_IO(advise(
        NULL,
        wasiFD,
        0,
        1,
        6
    ) == WASI_ERRNO_INVAL);
    CHECK_IO(advise(
        NULL,
        wasiFD,
        0,
        1,
        0x100
    ) == WASI_ERRNO_INVAL);
    CHECK_IO(advise(
        NULL,
        wasiFD,
        UINT64_MAX,
        1,
        WASI_ADVICE_NORMAL
    ) == WASI_ERRNO_OVERFLOW);
    CHECK_IO(advise(
        NULL,
        wasiFD,
        (U64)INT64_MAX,
        1,
        WASI_ADVICE_NORMAL
    ) == WASI_ERRNO_OVERFLOW);
    for (advice = WASI_ADVICE_NORMAL; advice <= WASI_ADVICE_NOREUSE; advice++) {
        CHECK_IO(advise(
            NULL,
            wasiFD,
            0,
            0,
            advice
        ) == WASI_ERRNO_SUCCESS);
        CHECK_IO(advise(
            NULL,
            wasiFD,
            4096,
            4096,
            advice
        ) == WASI_ERRNO_SUCCESS);
    }
    CHECK_IO(testNativeSeek(fd, 0, SEEK_CUR) == 2);
    CHECK_IO(testNativeStat(fd, &st) == 0 && st.st_size == 6);

    allocationError = allocate(
        NULL,
        wasiFD,
        8192,
        8192
    );
#if HAS_POSIX_FALLOCATE || HAS_F_PREALLOCATE || defined(_WIN32)
#ifdef _WIN32
    if (allocationError == WASI_ERRNO_NOSYS || allocationError == WASI_ERRNO_NOTSUP) {
        CHECK_IO(testNativeStat(fd, &st) == 0 && st.st_size == 6);
        CHECK_IO(testNativeSeek(fd, 0, SEEK_CUR) == 2);
        fprintf(
            stderr,
            "SKIP fd_allocate growth: native allocation unavailable (%u)\n",
            allocationError
        );
    } else
#endif
    {
        CHECK_IO(allocationError == WASI_ERRNO_SUCCESS);
        CHECK_IO(testNativeSeek(fd, 0, SEEK_CUR) == 2);
        CHECK_IO(testNativeStat(fd, &st) == 0 && st.st_size == 16384);
#if HAS_F_PREALLOCATE && !defined(_WIN32)
        blocks = (U64)st.st_blocks;
        CHECK_IO(blocks * 512 >= 16384);
#endif
        CHECK_IO(allocate(
            NULL,
            wasiFD,
            8192,
            8192
        ) == WASI_ERRNO_SUCCESS);
        CHECK_IO(allocate(
            NULL,
            wasiFD,
            0,
            3
        ) == WASI_ERRNO_SUCCESS);
        CHECK_IO(testNativeStat(fd, &st) == 0 && st.st_size == 16384);
#if HAS_F_PREALLOCATE && !defined(_WIN32)
        CHECK_IO((U64)st.st_blocks == blocks);
#endif
        CHECK_IO(testNativeSeek(fd, 0, SEEK_CUR) == 2);
        CHECK_IO(testNativeSeek(fd, 8192, SEEK_SET) == 8192);
        CHECK_IO(testNativeRead(fd, bytes, sizeof(bytes)) == (int)sizeof(bytes));
        for (i = 0; i < sizeof(bytes); i++) {
            CHECK_IO(bytes[i] == 0);
        }
        CHECK_IO(testNativeSeek(fd, 16383, SEEK_SET) == 16383);
        CHECK_IO(testNativeRead(fd, bytes, 1) == 1 && bytes[0] == 0);
    }
#else
    UNUSED_PARAMETER(i);
    CHECK_IO(allocationError == WASI_ERRNO_NOSYS);
    CHECK_IO(testNativeStat(fd, &st) == 0 && st.st_size == 6);
    CHECK_IO(testNativeSeek(fd, 0, SEEK_CUR) == 2);
#endif
    CHECK_IO(testNativeSeek(fd, 0, SEEK_SET) == 0);
    CHECK_IO(testNativeRead(fd, bytes, sizeof(bytes)) == (int)sizeof(bytes));
    CHECK_IO(memcmp(bytes, "abcdef", sizeof(bytes)) == 0);
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(fclose(file) == 0);
    fprintf(stderr, "OK fd_allocate and fd_advise file contents and offsets\n");
}

#undef testNativeStat
#undef testNativeStatType

#endif /* HAS_UNISTD || _WIN32 */

#if HAS_UNISTD && !defined(_WIN32)

static void testFdStorageErrors(
    TestFdAllocate allocate,
    TestFdAdvise advise
) {
    int pipeFDs[2];
    U32 wasiFD;
    CHECK_IO(pipe(pipeFDs) == 0);
    CHECK_IO(wasiFileDescriptorAdd(pipeFDs[0], NULL, &wasiFD));
    CHECK_IO(allocate(
        NULL,
        wasiFD,
        0,
        1
    ) == WASI_ERRNO_NODEV);
    CHECK_IO(advise(
        NULL,
        wasiFD,
        0,
        1,
        WASI_ADVICE_NORMAL
    ) == WASI_ERRNO_SPIPE);
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(close(pipeFDs[1]) == 0);
#if HAS_POSIX_FALLOCATE || HAS_F_PREALLOCATE
    {
        char path[] = "wasi-allocate-XXXXXX";
        int fd = mkstemp(path);
        struct stat st;
        CHECK_IO(fd >= 0);
        CHECK_IO(close(fd) == 0);
        fd = open(path, O_RDONLY);
        CHECK_IO(unlink(path) == 0);
        CHECK_IO(fd >= 0);
        CHECK_IO(wasiFileDescriptorAdd(fd, NULL, &wasiFD));
        CHECK_IO(allocate(
            NULL,
            wasiFD,
            0,
            4096
        ) == WASI_ERRNO_BADF);
        CHECK_IO(fstat(fd, &st) == 0 && st.st_size == 0);
        CHECK_IO(advise(
            NULL,
            wasiFD,
            0,
            0,
            WASI_ADVICE_NORMAL
        ) == WASI_ERRNO_SUCCESS);
        CHECK_IO(wasiFileDescriptorClose(wasiFD));
    }
#endif
    fprintf(stderr, "OK fd_allocate and fd_advise native errors\n");
}

#endif /* HAS_UNISTD && !_WIN32 */

static void testFdAllocateAndAdvise(
    TestFdAllocate allocate,
    TestFdAdvise advise
) {
    testFdStorageValidation(allocate, advise);
#if HAS_UNISTD || defined(_WIN32)
    testFdStorage(allocate, advise);
#endif
#if HAS_UNISTD && !defined(_WIN32)
    testFdStorageErrors(allocate, advise);
#endif
}

#if HAS_UNISTD || defined(_WIN32)

static void testFileRights(
    TestPathOpen openPath,
    TestFdRenumber renumber
) {
    U32 parent, directory, file, target;
    WasiFileDescriptor descriptor;
    WasiRights base = WASI_RIGHTS_FD_READ | WASI_RIGHTS_FD_FILESTAT_GET;
    int fd, replacement;
#ifdef _WIN32
    char path[MAX_PATH];
    char* separator;
    CHECK_IO(GetTempFileNameA(".", "w2c", 0, path) != 0);
    for (separator = path; *separator != '\0'; separator++) {
        if (*separator == '\\') {
            *separator = '/';
        }
    }
    fd = _open(path, _O_RDWR | _O_BINARY);
#else
    char path[] = "wasi-rights-XXXXXX";
    fd = mkstemp(path);
#endif
    CHECK_IO(fd >= 0);
    CHECK_IO(wasiFileDescriptorAdd(fd, ".", &file));
    testFdRights(
        file,
        WASI_RIGHTS_REGULAR_FILE_BASE,
        WASI_RIGHTS_REGULAR_FILE_INHERITING
    );
    CHECK_IO(wasiFileDescriptorClose(file));

    CHECK_IO(wasiFileDescriptorAdd(-1, path, &file));
    testFdRights(
        file,
        WASI_RIGHTS_REGULAR_FILE_BASE,
        WASI_RIGHTS_REGULAR_FILE_INHERITING
    );
    CHECK_IO(wasiFileDescriptorClose(file));

    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &parent));
    directory = testOpenWithRights(
        openPath,
        parent,
        ".",
        WASI_OFLAGS_DIRECTORY,
        WASI_RIGHTS_PATH_OPEN,
        base
    );
    testFdRights(directory, WASI_RIGHTS_PATH_OPEN, base);
    file = testOpenWithRights(openPath, directory, path, 0, base, 0);
    testFdRights(file, base, 0);

    CHECK_IO(wasiFileDescriptorGet(file, &descriptor));
#ifdef _WIN32
    replacement = _dup(descriptor.fd);
#else
    replacement = dup(descriptor.fd);
#endif
    CHECK_IO(replacement >= 0);
    CHECK_IO(wasiFileDescriptorSet(file, replacement));
#ifdef _WIN32
    CHECK_IO(_close(descriptor.fd) == 0);
#else
    CHECK_IO(close(descriptor.fd) == 0);
#endif
    testFdRights(file, base, 0);
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &target));
    CHECK_IO(renumber(NULL, file, target) == WASI_ERRNO_SUCCESS);
    testFdRights(target, base, 0);
    CHECK_IO(!wasiFileDescriptorGet(file, &descriptor));
    CHECK_IO(descriptor.rightsBase == 0 && descriptor.rightsInheriting == 0);
    CHECK_IO(wasiFileDescriptorClose(target));
    CHECK_IO(wasiFileDescriptorClose(directory));

    file = testOpenWithRights(
        openPath,
        parent,
        path,
        0,
        base | WASI_RIGHTS_PATH_OPEN,
        WASI_RIGHTS_DIRECTORY_INHERITING
    );
    testFdRights(file, base, 0);
    CHECK_IO(wasiFileDescriptorClose(file));
    file = testOpenWithRights(openPath, parent, path, 0, 0, 0);
    testFdRights(file, 0, 0);
    CHECK_IO(wasiFileDescriptorClose(file));
    CHECK_IO(wasiFileDescriptorClose(parent));
    CHECK_IO(remove(path) == 0);
    fprintf(stderr, "OK file rights, inheritance, and handle replacement\n");
}

#endif

static void testFdFlags(U32 (*setFlags)(wasmModuleInstance*, U32, U32)) {
    U32 wasiFD;

    CHECK_IO(setFlags(NULL, UINT32_MAX, 0) == WASI_ERRNO_BADF);
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &wasiFD));
    CHECK_IO(setFlags(NULL, wasiFD, 0) == WASI_ERRNO_SUCCESS);
    CHECK_IO(setFlags(NULL, wasiFD, WASI_FDFLAGS_APPEND) == WASI_ERRNO_NOTSUP);
    CHECK_IO(setFlags(NULL, wasiFD, 0x10000) == WASI_ERRNO_INVAL);
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(setFlags(NULL, wasiFD, 0) == WASI_ERRNO_BADF);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview113_fdX5FfdstatX5Fget(NULL, wasiFD, 512)
        == WASI_ERRNO_BADF);

#if HAS_UNISTD
    {
        FILE* file = tmpfile();
        int fd;
#if HAS_FCNTL
        int originalFlags;
        char bytes[2];
        size_t i;
        static const U32 syncFlags[] = {
            WASI_FDFLAGS_DSYNC, WASI_FDFLAGS_RSYNC, WASI_FDFLAGS_SYNC
        };
#endif
        CHECK_IO(file != NULL);
        fd = dup(fileno(file));
        CHECK_IO(fd >= 0);
        CHECK_IO(wasiFileDescriptorAdd(fd, ".", &wasiFD));
        CHECK_IO(setFlags(NULL, wasiFD, 0x20) == WASI_ERRNO_INVAL);
#if HAS_FCNTL
        CHECK_IO(write(fd, "a", 1) == 1);
        originalFlags = fcntl(fd, F_GETFL);
        CHECK_IO(originalFlags >= 0);
        CHECK_IO(setFlags(NULL, wasiFD, WASI_FDFLAGS_APPEND) == WASI_ERRNO_SUCCESS);
        CHECK_IO(fcntl(fd, F_GETFL) == (originalFlags | O_APPEND));
        CHECK_IO(i22_wasiX5FsnapshotX5Fpreview113_fdX5FfdstatX5Fget(NULL, wasiFD, 512)
            == WASI_ERRNO_SUCCESS);
        CHECK_IO(i32_load16_u(&testMemory, 514) == WASI_FDFLAGS_APPEND);
        CHECK_IO(lseek(fd, 0, SEEK_SET) == 0);
        CHECK_IO(write(fd, "b", 1) == 1);
        CHECK_IO(lseek(fd, 0, SEEK_SET) == 0);
        CHECK_IO(read(fd, bytes, sizeof(bytes)) == (ssize_t)sizeof(bytes));
        CHECK_IO(memcmp(bytes, "ab", sizeof(bytes)) == 0);
        CHECK_IO(setFlags(NULL, wasiFD, 0) == WASI_ERRNO_SUCCESS);
        CHECK_IO(fcntl(fd, F_GETFL) == originalFlags);
        CHECK_IO(i22_wasiX5FsnapshotX5Fpreview113_fdX5FfdstatX5Fget(NULL, wasiFD, 512)
            == WASI_ERRNO_SUCCESS);
        CHECK_IO(i32_load16_u(&testMemory, 514) == 0);
        for (i = 0; i < sizeof(syncFlags) / sizeof(syncFlags[0]); i++) {
            CHECK_IO(setFlags(NULL, wasiFD, WASI_FDFLAGS_APPEND | syncFlags[i])
                == WASI_ERRNO_NOTSUP);
            CHECK_IO(fcntl(fd, F_GETFL) == originalFlags);
        }
#else
        CHECK_IO(setFlags(NULL, wasiFD, WASI_FDFLAGS_APPEND) == WASI_ERRNO_NOSYS);
#endif
        CHECK_IO(wasiFileDescriptorClose(wasiFD));
        CHECK_IO(setFlags(NULL, wasiFD, 0) == WASI_ERRNO_BADF);
        CHECK_IO(fclose(file) == 0);
    }
#endif

#if HAS_UNISTD && HAS_FCNTL && defined(O_NONBLOCK)
    {
        int pipeFDs[2];
        int originalFlags;
        char byte;
        CHECK_IO(pipe(pipeFDs) == 0);
        originalFlags = fcntl(pipeFDs[0], F_GETFL);
        CHECK_IO(originalFlags >= 0);
        CHECK_IO(wasiFileDescriptorAdd(pipeFDs[0], NULL, &wasiFD));
        CHECK_IO(setFlags(NULL, wasiFD, WASI_FDFLAGS_NONBLOCK) == WASI_ERRNO_SUCCESS);
        CHECK_IO(fcntl(pipeFDs[0], F_GETFL) == (originalFlags | O_NONBLOCK));
        CHECK_IO(i22_wasiX5FsnapshotX5Fpreview113_fdX5FfdstatX5Fget(NULL, wasiFD, 512)
            == WASI_ERRNO_SUCCESS);
        CHECK_IO(i32_load16_u(&testMemory, 514) == WASI_FDFLAGS_NONBLOCK);
        CHECK_IO(read(pipeFDs[0], &byte, 1) == -1);
        CHECK_IO(errno == EAGAIN || errno == EWOULDBLOCK);
        CHECK_IO(setFlags(NULL, wasiFD, 0) == WASI_ERRNO_SUCCESS);
        CHECK_IO(fcntl(pipeFDs[0], F_GETFL) == originalFlags);
        CHECK_IO(wasiFileDescriptorClose(wasiFD));
        CHECK_IO(close(pipeFDs[1]) == 0);
    }
#endif

    fprintf(stderr, "OK fd_fdstat_set_flags\n");
}

#if HAS_UNISTD && HAS_FCNTL && defined(O_DSYNC) && defined(O_SYNC)

static void testFdSyncFlags(int syncFlag) {
    char path[] = "wasi-flags-XXXXXX";
    int fd = mkstemp(path);
    int nativeFlags;
    U32 wasiFD;
    U32 flags;
    CHECK_IO(fd >= 0);
    CHECK_IO(close(fd) == 0);
    fd = open(path, O_RDWR | syncFlag);
    CHECK_IO(unlink(path) == 0);
    CHECK_IO(fd >= 0);
    nativeFlags = fcntl(fd, F_GETFL);
    CHECK_IO(nativeFlags >= 0);
    CHECK_IO(wasiFileDescriptorAdd(fd, NULL, &wasiFD));
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview113_fdX5FfdstatX5Fget(NULL, wasiFD, 512)
        == WASI_ERRNO_SUCCESS);
    flags = i32_load16_u(&testMemory, 514);
    if (syncFlag == O_DSYNC) {
        CHECK_IO(flags & WASI_FDFLAGS_DSYNC);
        if (O_DSYNC != O_SYNC) {
            CHECK_IO(!(flags & WASI_FDFLAGS_SYNC));
        }
    }
    if (syncFlag == O_SYNC) {
        CHECK_IO(flags & WASI_FDFLAGS_SYNC);
    }
#ifndef O_RSYNC
    CHECK_IO(!(flags & WASI_FDFLAGS_RSYNC));
#endif
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview119_fdX5FfdstatX5FsetX5Fflags(
        NULL, wasiFD, flags | WASI_FDFLAGS_APPEND
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(fcntl(fd, F_GETFL) == (nativeFlags | O_APPEND));
    CHECK_IO(i13_wasiX5Funstable19_fdX5FfdstatX5FsetX5Fflags(NULL, wasiFD, flags)
        == WASI_ERRNO_SUCCESS);
    CHECK_IO(fcntl(fd, F_GETFL) == nativeFlags);
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    fprintf(stderr, "OK synchronization flags preserved\n");
}

#endif

#if HAS_UNISTD || defined(_WIN32)

extern U32 i22_wasiX5FsnapshotX5Fpreview18_fdX5Fpread(
    wasmModuleInstance*, U32, U32, U32, U64, U32
);
extern U32 i22_wasiX5FsnapshotX5Fpreview19_fdX5Fpwrite(
    wasmModuleInstance*, U32, U32, U32, U64, U32
);

static void testPositionalIO(void) {
    static const U64 offsets[] = {(U64)-1, W2C2_LL(4294967296)};
    FILE* file = tmpfile();
    U32 wasiFD;
    int fd;
    char bytes[6];
    size_t index;
    CHECK_IO(file != NULL);
    fd = testNativeDup(testNativeFileno(file));
    CHECK_IO(fd >= 0);
    CHECK_IO(testNativeWrite(fd, "abcdef", 6) == 6);
    CHECK_IO(testNativeSeek(fd, 4, SEEK_SET) == 4);
    CHECK_IO(wasiFileDescriptorAdd(fd, NULL, &wasiFD));
    i32_store(&testMemory, 0, 128);
    i32_store(&testMemory, 4, 2);
    i32_store(&testMemory, 8, 256);
    i32_store(&testMemory, 12, 3);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview18_fdX5Fpread(NULL, wasiFD, 0, 2, 1, 512)
        == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 5);
    CHECK_IO(memcmp(testMemory.data + 128, "bc", 2) == 0);
    CHECK_IO(memcmp(testMemory.data + 256, "def", 3) == 0);
    CHECK_IO(testNativeSeek(fd, 0, SEEK_CUR) == 4);
    memcpy(testMemory.data + 128, "12", 2);
    memcpy(testMemory.data + 256, "345", 3);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview19_fdX5Fpwrite(NULL, wasiFD, 0, 2, 1, 512)
        == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 5);
    CHECK_IO(testNativeSeek(fd, 0, SEEK_CUR) == 4);
    for (index = 0; index < sizeof(offsets) / sizeof(offsets[0]); index++) {
        if (index == 1 && sizeof(off_t) >= sizeof(U64)) {
            continue;
        }
        i32_store(&testMemory, 512, 0x12345678);
        CHECK_IO(i22_wasiX5FsnapshotX5Fpreview18_fdX5Fpread(
            NULL,
            wasiFD,
            0,
            2,
            offsets[index],
            512
        ) == WASI_ERRNO_OVERFLOW);
        CHECK_IO(i32_load(&testMemory, 512) == 0x12345678);
        CHECK_IO(memcmp(testMemory.data + 128, "12", 2) == 0);
        CHECK_IO(memcmp(testMemory.data + 256, "345", 3) == 0);
        CHECK_IO(testNativeSeek(fd, 0, SEEK_CUR) == 4);
        CHECK_IO(i22_wasiX5FsnapshotX5Fpreview19_fdX5Fpwrite(
            NULL,
            wasiFD,
            0,
            2,
            offsets[index],
            512
        ) == WASI_ERRNO_OVERFLOW);
        CHECK_IO(i32_load(&testMemory, 512) == 0x12345678);
        CHECK_IO(testNativeSeek(fd, 0, SEEK_CUR) == 4);
    }
    CHECK_IO(testNativeSeek(fd, 0, SEEK_SET) == 0);
    CHECK_IO(testNativeRead(fd, bytes, sizeof(bytes)) == (int)sizeof(bytes));
    CHECK_IO(memcmp(bytes, "a12345", sizeof(bytes)) == 0);
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    CHECK_IO(fclose(file) == 0);
    fprintf(stderr, "OK positional I/O preserves file offset\n");
}

#undef testNativeDup
#undef testNativeFileno
#undef testNativeRead
#undef testNativeWrite
#undef testNativeSeek

#ifdef PLAN9
static void testPlan9DirectoryCookies(void) {
    static const U64 cookies[] = {0, 1, 0, 1};
    U32 wasiFD;
    size_t i;
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &wasiFD));
    for (i = 0; i < sizeof(cookies) / sizeof(cookies[0]); i++) {
        /* A header-only buffer forces the caller to retry a truncated entry. */
        CHECK_IO(i22_wasiX5FsnapshotX5Fpreview110_fdX5Freaddir(
            NULL, wasiFD, 0, 24, cookies[i], 512
        ) == WASI_ERRNO_SUCCESS);
        CHECK_IO(i32_load(&testMemory, 512) == 24);
        CHECK_IO(i64_load(&testMemory, 0) == cookies[i] + 1);
    }
    CHECK_IO(wasiFileDescriptorClose(wasiFD));
    fprintf(stderr, "OK Plan 9 directory cookies\n");
}
#endif

#endif

#if HAS_POLL || defined(_WIN32)

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
    memset(testMemory.data, 0, TEST_MEMORY_SIZE);
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
    return i22_wasiX5FsnapshotX5Fpreview111_pollX5Foneoff(
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

    error = i22_wasiX5FsnapshotX5Fpreview111_pollX5Foneoff(
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
        WASI_ERRNO_SUCCESS,
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

#endif /* HAS_POLL || _WIN32 */

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
    wasmModuleInstance* instance,
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
testUnexpectedThreadStart(wasmModuleInstance* instance, U32 threadID, U32 startArg) {
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
    U32 (*spawn)(wasmModuleInstance*, U32) = i4_wasi12_threadX2Dspawn;

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

    threadID = spawn(&root.common, 42);
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


typedef U32 (*TestFdSetRights)(
    wasmModuleInstance*,
    U32,
    U64,
    U64
);

extern U32 i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights(
    wasmModuleInstance*,
    U32,
    U64,
    U64
);

extern U32 i13_wasiX5Funstable20_fdX5FfdstatX5FsetX5Frights(
    wasmModuleInstance*,
    U32,
    U64,
    U64
);

extern U32 i22_wasiX5FsnapshotX5Fpreview17_fdX5Fread(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview18_fdX5Fwrite(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview18_fdX5Fpread(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U64,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview19_fdX5Fpwrite(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U64,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview17_fdX5Fseek(
    wasmModuleInstance*,
    U32,
    U64,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview17_fdX5Ftell(
    wasmModuleInstance*,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview111_fdX5Fdatasync(
    wasmModuleInstance*,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview17_fdX5Fsync(
    wasmModuleInstance*,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview115_fdX5FfilestatX5Fget(
    wasmModuleInstance*,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview120_fdX5FfilestatX5FsetX5Fsize(
    wasmModuleInstance*,
    U32,
    U64
);

extern U32 i22_wasiX5FsnapshotX5Fpreview114_fdX5FprestatX5Fget(
    wasmModuleInstance*,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview119_fdX5FprestatX5FdirX5Fname(
    wasmModuleInstance*,
    U32,
    U32,
    U32
);

static void testPreopenDirectory(void) {
    U32 directory, opened, target;
    char name[] = "/fixture";
    WasiFileDescriptor descriptor;
    CHECK_IO(wasiPreopenDirectory(".", name, &directory));
    name[1] = 'x';
    CHECK_IO(wasiFileDescriptorGet(directory, &descriptor));
    CHECK_IO(strcmp(descriptor.path, ".") == 0);
    CHECK_IO(strcmp(descriptor.preopenName, "/fixture") == 0);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview114_fdX5FprestatX5Fget(
        NULL, directory, 512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 516) == 8);
    memset(testMemory.data + 512, 0xaa, 9);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview119_fdX5FprestatX5FdirX5Fname(
        NULL, directory, 512, 7
    ) == WASI_ERRNO_NAMETOOLONG);
    CHECK_IO(testMemory.data[512] == 0xaa);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview119_fdX5FprestatX5FdirX5Fname(
        NULL, directory, TEST_MEMORY_SIZE, 8
    ) == WASI_ERRNO_FAULT);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview119_fdX5FprestatX5FdirX5Fname(
        NULL, directory, 512, 8
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(memcmp(testMemory.data + 512, "/fixture", 8) == 0);
    CHECK_IO(testMemory.data[520] == 0xaa);

    opened = testOpenWithRights(
        i22_wasiX5FsnapshotX5Fpreview19_pathX5Fopen,
        directory, ".", WASI_OFLAGS_DIRECTORY,
        WASI_RIGHTS_DIRECTORY_BASE, WASI_RIGHTS_DIRECTORY_INHERITING
    );
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview114_fdX5FprestatX5Fget(
        NULL, opened, 512
    ) == WASI_ERRNO_BADF);
    CHECK_IO(wasiFileDescriptorClose(opened));
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &target));
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview111_fdX5Frenumber(
        NULL, directory, target
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(wasiFileDescriptorGet(target, &descriptor));
    CHECK_IO(strcmp(descriptor.path, ".") == 0);
    CHECK_IO(strcmp(descriptor.preopenName, "/fixture") == 0);
    CHECK_IO(wasiFileDescriptorClose(target));
    fprintf(stderr, "OK preopen host paths, guest names, and ownership\n");
}

extern U32 i22_wasiX5FsnapshotX5Fpreview121_pathX5FcreateX5Fdirectory(
    wasmModuleInstance*,
    U32,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview121_pathX5FremoveX5Fdirectory(
    wasmModuleInstance*,
    U32,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview116_pathX5FunlinkX5Ffile(
    wasmModuleInstance*,
    U32,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview113_pathX5Freadlink(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview117_pathX5FfilestatX5Fget(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview111_pathX5Frename(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32,
    U32
);

extern U32 i22_wasiX5FsnapshotX5Fpreview112_pathX5Fsymlink(
    wasmModuleInstance*,
    U32,
    U32,
    U32,
    U32,
    U32
);

static U32 testFileRightsOperation(U32 fd, WasiRights operation) {
    switch (operation) {
        case WASI_RIGHTS_FD_READ:
            return i22_wasiX5FsnapshotX5Fpreview17_fdX5Fread(
                NULL,
                fd,
                0,
                1,
                512
            );
        case WASI_RIGHTS_FD_WRITE:
            return i22_wasiX5FsnapshotX5Fpreview18_fdX5Fwrite(
                NULL,
                fd,
                0,
                1,
                512
            );
        case WASI_RIGHTS_FD_READ | WASI_RIGHTS_FD_SEEK:
            return i22_wasiX5FsnapshotX5Fpreview18_fdX5Fpread(
                NULL,
                fd,
                0,
                1,
                0,
                512
            );
        case WASI_RIGHTS_FD_WRITE | WASI_RIGHTS_FD_SEEK:
            return i22_wasiX5FsnapshotX5Fpreview19_fdX5Fpwrite(
                NULL,
                fd,
                0,
                1,
                0,
                512
            );
        case WASI_RIGHTS_FD_SEEK:
            return i22_wasiX5FsnapshotX5Fpreview17_fdX5Fseek(
                NULL,
                fd,
                1,
                0,
                512
            );
        case WASI_RIGHTS_FD_TELL:
            return i22_wasiX5FsnapshotX5Fpreview17_fdX5Ftell(NULL, fd, 512);
        case WASI_RIGHTS_FD_DATASYNC:
            return i22_wasiX5FsnapshotX5Fpreview111_fdX5Fdatasync(NULL, fd);
        case WASI_RIGHTS_FD_SYNC:
            return i22_wasiX5FsnapshotX5Fpreview17_fdX5Fsync(NULL, fd);
        case WASI_RIGHTS_FD_FDSTAT_SET_FLAGS:
            return i22_wasiX5FsnapshotX5Fpreview119_fdX5FfdstatX5FsetX5Fflags(
                NULL, fd, 0
            );
        case WASI_RIGHTS_FD_FILESTAT_GET:
            return i22_wasiX5FsnapshotX5Fpreview115_fdX5FfilestatX5Fget(
                NULL, fd, 512
            );
        case WASI_RIGHTS_FD_FILESTAT_SET_SIZE:
            return i22_wasiX5FsnapshotX5Fpreview120_fdX5FfilestatX5FsetX5Fsize(
                NULL, fd, 8
            );
        case WASI_RIGHTS_FD_FILESTAT_SET_TIMES:
            return i22_wasiX5FsnapshotX5Fpreview121_fdX5FfilestatX5FsetX5Ftimes(
                NULL,
                fd,
                0,
                0,
                WASI_FSTFLAGS_MTIM
            );
        case WASI_RIGHTS_FD_ALLOCATE:
            return i22_wasiX5FsnapshotX5Fpreview111_fdX5Fallocate(
                NULL, fd, 0, 8
            );
        case WASI_RIGHTS_FD_ADVISE:
            return i22_wasiX5FsnapshotX5Fpreview19_fdX5Fadvise(
                NULL,
                fd,
                0,
                1,
                WASI_ADVICE_NORMAL
            );
        default:
            abort();
    }
}

#if HAS_UNISTD || defined(_WIN32)

static void testFileRightsEnforcement(TestFdSetRights setRights) {
    static const WasiRights operations[] = {
        WASI_RIGHTS_FD_READ, WASI_RIGHTS_FD_WRITE,
        WASI_RIGHTS_FD_READ | WASI_RIGHTS_FD_SEEK,
        WASI_RIGHTS_FD_WRITE | WASI_RIGHTS_FD_SEEK,
        WASI_RIGHTS_FD_SEEK, WASI_RIGHTS_FD_TELL,
        WASI_RIGHTS_FD_DATASYNC, WASI_RIGHTS_FD_SYNC,
        WASI_RIGHTS_FD_FDSTAT_SET_FLAGS, WASI_RIGHTS_FD_FILESTAT_GET,
        WASI_RIGHTS_FD_FILESTAT_SET_SIZE, WASI_RIGHTS_FD_FILESTAT_SET_TIMES,
        WASI_RIGHTS_FD_ALLOCATE, WASI_RIGHTS_FD_ADVISE
    };
    size_t i;
    for (i = 0; i < sizeof(operations) / sizeof(operations[0]); i++) {
        WasiRights removed;
        for (removed = 1; removed <= WASI_RIGHTS_FD_FILESTAT_SET_TIMES; removed <<= 1) {
            FILE* file;
            U32 fd, result;
            int nativeFD;
            U8 snapshot[1024];
            char bytes[4];
            WasiRights base;
            if (!(removed & operations[i])) {
                continue;
            }
            file = tmpfile();
            CHECK_IO(file != NULL);
            CHECK_IO(fwrite("abcd", 1, 4, file) == 4);
            CHECK_IO(fflush(file) == 0);
#ifdef _WIN32
            nativeFD = _dup(_fileno(file));
#else
            nativeFD = dup(fileno(file));
#endif
            CHECK_IO(nativeFD >= 0);
            CHECK_IO(wasiFileDescriptorAdd(nativeFD, NULL, &fd));
            memset(testMemory.data, 0xa5, sizeof(snapshot));
            i32_store(&testMemory, 0, 128);
            i32_store(&testMemory, 4, 1);
            testMemory.data[128] = 'x';
            CHECK_IO(fseek(file, 0, SEEK_SET) == 0);
            result = testFileRightsOperation(fd, operations[i]);
            CHECK_IO(result == WASI_ERRNO_SUCCESS || result == WASI_ERRNO_NOSYS
                     || result == WASI_ERRNO_NOTSUP);
            CHECK_IO(fseek(file, 0, SEEK_SET) == 0);
            CHECK_IO(fwrite("abcd", 1, 4, file) == 4);
            CHECK_IO(fflush(file) == 0);
            CHECK_IO(fseek(file, 2, SEEK_SET) == 0);
            base = WASI_RIGHTS_REGULAR_FILE_BASE & ~removed;
            if (removed == WASI_RIGHTS_FD_TELL) {
                base &= ~((WasiRights)WASI_RIGHTS_FD_SEEK);
            }
            CHECK_IO(setRights(NULL, fd, base, 0) == WASI_ERRNO_SUCCESS);
            memcpy(snapshot, testMemory.data, sizeof(snapshot));
            CHECK_IO(testFileRightsOperation(fd, operations[i]) == WASI_ERRNO_NOTCAPABLE);
            CHECK_IO(memcmp(snapshot, testMemory.data, sizeof(snapshot)) == 0);
            CHECK_IO(ftell(file) == 2);
            CHECK_IO(fseek(file, 0, SEEK_SET) == 0);
            CHECK_IO(fread(bytes, 1, sizeof(bytes), file) == sizeof(bytes));
            CHECK_IO(memcmp(bytes, "abcd", sizeof(bytes)) == 0);
            CHECK_IO(wasiFileDescriptorClose(fd));
            CHECK_IO(fclose(file) == 0);
        }
    }
    fprintf(stderr, "OK file rights enforcement and rejected I/O side effects\n");
}

static void testSeekRights(TestFdSetRights setRights) {
    FILE* file = tmpfile();
    U32 fd;
    int nativeFD;
    CHECK_IO(file != NULL);
#ifdef _WIN32
    nativeFD = _dup(_fileno(file));
#else
    nativeFD = dup(fileno(file));
#endif
    CHECK_IO(nativeFD >= 0);
    CHECK_IO(wasiFileDescriptorAdd(nativeFD, NULL, &fd));
    CHECK_IO(setRights(NULL, fd, WASI_RIGHTS_FD_TELL, 0) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview17_fdX5Ftell(NULL, fd, 512)
        == WASI_ERRNO_SUCCESS);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview17_fdX5Fseek(
        NULL,
        fd,
        0,
        1,
        512
    )
        == WASI_ERRNO_SUCCESS);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview17_fdX5Fseek(
        NULL,
        fd,
        1,
        1,
        512
    )
        == WASI_ERRNO_NOTCAPABLE);
    CHECK_IO(wasiFileDescriptorClose(fd));
#ifdef _WIN32
    nativeFD = _dup(_fileno(file));
#else
    nativeFD = dup(fileno(file));
#endif
    CHECK_IO(nativeFD >= 0);
    CHECK_IO(wasiFileDescriptorAdd(nativeFD, NULL, &fd));
    CHECK_IO(setRights(NULL, fd, WASI_RIGHTS_FD_SEEK, 0) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview17_fdX5Ftell(NULL, fd, 512)
        == WASI_ERRNO_SUCCESS);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview17_fdX5Fseek(
        NULL,
        fd,
        1,
        0,
        512
    )
        == WASI_ERRNO_SUCCESS);
    CHECK_IO(wasiFileDescriptorClose(fd));
    CHECK_IO(fclose(file) == 0);
    fprintf(stderr, "OK seek and tell rights\n");
}

#endif

static U32 testPathRightsOperation(U32 fd, U32 other, WasiRights operation) {
    switch (operation) {
        case WASI_RIGHTS_FD_READDIR:
            return i22_wasiX5FsnapshotX5Fpreview110_fdX5Freaddir(
                NULL,
                fd,
                512,
                128,
                0,
                768
            );
        case WASI_RIGHTS_PATH_CREATE_DIRECTORY:
            return i22_wasiX5FsnapshotX5Fpreview121_pathX5FcreateX5Fdirectory(
                NULL, fd, 256, 3
            );
        case WASI_RIGHTS_PATH_REMOVE_DIRECTORY:
            memcpy(testMemory.data + 128, "empty", 5);
            return i22_wasiX5FsnapshotX5Fpreview121_pathX5FremoveX5Fdirectory(
                NULL, fd, 128, 5
            );
        case WASI_RIGHTS_PATH_UNLINK_FILE:
            return i22_wasiX5FsnapshotX5Fpreview116_pathX5FunlinkX5Ffile(
                NULL, fd, 128, 4
            );
        case WASI_RIGHTS_PATH_FILESTAT_GET:
            return i22_wasiX5FsnapshotX5Fpreview117_pathX5FfilestatX5Fget(
                NULL,
                fd,
                0,
                128,
                4,
                512
            );
        case WASI_RIGHTS_PATH_FILESTAT_SET_TIMES:
            return i22_wasiX5FsnapshotX5Fpreview123_pathX5FfilestatX5FsetX5Ftimes(
                NULL,
                fd,
                0,
                128,
                4,
                0,
                0,
                WASI_FSTFLAGS_MTIM
            );
        case WASI_RIGHTS_PATH_READLINK:
            return i22_wasiX5FsnapshotX5Fpreview113_pathX5Freadlink(
                NULL,
                fd,
                128,
                4,
                512,
                128,
                768
            );
        case WASI_RIGHTS_PATH_SYMLINK:
            return i22_wasiX5FsnapshotX5Fpreview112_pathX5Fsymlink(
                NULL,
                128,
                4,
                fd,
                256,
                3
            );
        case WASI_RIGHTS_PATH_RENAME_SOURCE:
        case WASI_RIGHTS_PATH_RENAME_TARGET:
            return i22_wasiX5FsnapshotX5Fpreview111_pathX5Frename(
                NULL,
                operation == WASI_RIGHTS_PATH_RENAME_SOURCE ? fd : other,
                128,
                4,
                operation == WASI_RIGHTS_PATH_RENAME_TARGET ? fd : other,
                256,
                3
            );
        case WASI_RIGHTS_PATH_LINK_SOURCE:
        case WASI_RIGHTS_PATH_LINK_TARGET:
            return i22_wasiX5FsnapshotX5Fpreview19_pathX5Flink(
                NULL,
                operation == WASI_RIGHTS_PATH_LINK_SOURCE ? fd : other,
                0,
                128,
                4,
                operation == WASI_RIGHTS_PATH_LINK_TARGET ? fd : other,
                256,
                3
            );
        default:
            abort();
    }
}

#if HAS_UNISTD || defined(_WIN32)

static void testPathRightsEnforcement(TestFdSetRights setRights) {
    static const WasiRights operations[] = {
        WASI_RIGHTS_FD_READDIR, WASI_RIGHTS_PATH_CREATE_DIRECTORY,
        WASI_RIGHTS_PATH_REMOVE_DIRECTORY, WASI_RIGHTS_PATH_UNLINK_FILE,
        WASI_RIGHTS_PATH_FILESTAT_GET, WASI_RIGHTS_PATH_FILESTAT_SET_TIMES,
        WASI_RIGHTS_PATH_READLINK, WASI_RIGHTS_PATH_SYMLINK,
        WASI_RIGHTS_PATH_RENAME_SOURCE, WASI_RIGHTS_PATH_RENAME_TARGET,
        WASI_RIGHTS_PATH_LINK_SOURCE, WASI_RIGHTS_PATH_LINK_TARGET
    };
    char directory[PATH_MAX];
    char path[PATH_MAX];
    FILE* file;
    U32 other;
    size_t i;
#ifdef _WIN32
    CHECK_IO(GetTempFileNameA(".", "w2c", 0, directory) != 0);
    CHECK_IO(DeleteFileA(directory));
    CHECK_IO(CreateDirectoryA(directory, NULL));
    for (i = 0; directory[i] != '\0'; i++) {
        if (directory[i] == '\\') {
            directory[i] = '/';
        }
    }
#else
    strcpy(directory, "wasi-rights-paths-XXXXXX");
    CHECK_IO(mkdtemp(directory) != NULL);
#endif
    strcpy(path, directory);
    strcat(path, "/empty");
#ifdef _WIN32
    CHECK_IO(CreateDirectoryA(path, NULL));
#else
    CHECK_IO(mkdir(path, 0700) == 0);
#endif
    strcpy(path, directory);
    strcat(path, "/file");
    file = fopen(path, "wb");
    CHECK_IO(file != NULL);
    CHECK_IO(fwrite("abcd", 1, 4, file) == 4);
    CHECK_IO(fclose(file) == 0);
    CHECK_IO(wasiFileDescriptorAdd(-1, directory, &other));
    for (i = 0; i < sizeof(operations) / sizeof(operations[0]); i++) {
        U32 fd;
        U8 snapshot[256];
        CHECK_IO(wasiFileDescriptorAdd(-1, directory, &fd));
        CHECK_IO(setRights(
            NULL,
            fd,
            WASI_RIGHTS_DIRECTORY_BASE & ~operations[i],
            WASI_RIGHTS_DIRECTORY_INHERITING
        ) == WASI_ERRNO_SUCCESS);
        memset(testMemory.data, 0xa5, 1024);
        memcpy(testMemory.data + 128, "file", 4);
        memcpy(testMemory.data + 256, "new", 3);
        memcpy(snapshot, testMemory.data + 512, sizeof(snapshot));
        CHECK_IO(testPathRightsOperation(fd, other, operations[i])
            == WASI_ERRNO_NOTCAPABLE);
        CHECK_IO(memcmp(snapshot, testMemory.data + 512, sizeof(snapshot)) == 0);
        CHECK_IO(wasiFileDescriptorClose(fd));
    }

    for (i = 0; i < 8; i++) {
        U32 fd, oflags = 0, flags = 0;
        WasiRights base = WASI_RIGHTS_DIRECTORY_BASE;
        WasiRights inheriting = WASI_RIGHTS_DIRECTORY_INHERITING;
        WasiRights childBase = WASI_RIGHTS_FD_READ;
        WasiRights childInheriting = 0;
        memcpy(testMemory.data + 128, "file", 4);
        switch (i) {
            case 0: base &= ~((WasiRights)WASI_RIGHTS_PATH_OPEN); break;
            case 1:
                base &= ~((WasiRights)WASI_RIGHTS_PATH_CREATE_FILE);
                oflags = WASI_OFLAGS_CREAT;
                memcpy(testMemory.data + 128, "newf", 4);
                break;
            case 2:
                base &= ~((WasiRights)WASI_RIGHTS_PATH_FILESTAT_SET_SIZE);
                oflags = WASI_OFLAGS_TRUNC;
                childBase = WASI_RIGHTS_FD_WRITE;
                break;
            case 3: inheriting &= ~((WasiRights)WASI_RIGHTS_FD_READ); break;
            case 4:
                inheriting &= ~((WasiRights)WASI_RIGHTS_FD_WRITE);
                childInheriting = WASI_RIGHTS_FD_WRITE;
                break;
            case 5:
                inheriting &= ~((WasiRights)WASI_RIGHTS_FD_DATASYNC);
                flags = WASI_FDFLAGS_DSYNC;
                break;
            case 6:
                inheriting &= ~((WasiRights)WASI_RIGHTS_FD_SYNC);
                flags = WASI_FDFLAGS_SYNC;
                break;
            case 7:
                inheriting &= ~((WasiRights)WASI_RIGHTS_FD_SYNC);
                flags = WASI_FDFLAGS_RSYNC;
                break;
        }
        CHECK_IO(wasiFileDescriptorAdd(-1, directory, &fd));
        CHECK_IO(setRights(NULL, fd, base, inheriting) == WASI_ERRNO_SUCCESS);
        i32_store(&testMemory, 512, 0x12345678);
        CHECK_IO(i22_wasiX5FsnapshotX5Fpreview19_pathX5Fopen(
            NULL,
            fd,
            0,
            128,
            4,
            oflags,
            childBase,
            childInheriting,
            flags,
            512
        ) == WASI_ERRNO_NOTCAPABLE);
        CHECK_IO(i32_load(&testMemory, 512) == 0x12345678);
        CHECK_IO(wasiFileDescriptorClose(fd));
    }
    {
        U32 child = testOpenWithRights(
            i22_wasiX5FsnapshotX5Fpreview19_pathX5Fopen,
            other, "file", 0, WASI_RIGHTS_FD_READ, 0
        );
        char bytes[4];
        CHECK_IO(setRights(NULL, other, 0, 0) == WASI_ERRNO_SUCCESS);
        i32_store(&testMemory, 0, 128);
        i32_store(&testMemory, 4, 4);
        CHECK_IO(i22_wasiX5FsnapshotX5Fpreview17_fdX5Fread(
            NULL,
            child,
            0,
            1,
            512
        ) == WASI_ERRNO_SUCCESS);
        CHECK_IO(i32_load(&testMemory, 512) == 4);
        CHECK_IO(memcmp(testMemory.data + 128, "abcd", 4) == 0);
        CHECK_IO(wasiFileDescriptorClose(child));
        file = fopen(path, "rb");
        CHECK_IO(file != NULL);
        CHECK_IO(fread(bytes, 1, sizeof(bytes), file) == sizeof(bytes));
        CHECK_IO(memcmp(bytes, "abcd", sizeof(bytes)) == 0);
        CHECK_IO(fgetc(file) == EOF);
        CHECK_IO(fclose(file) == 0);
    }
    CHECK_IO(wasiFileDescriptorClose(other));
    CHECK_IO(remove(path) == 0);
    strcpy(path, directory);
    strcat(path, "/empty");
#ifdef _WIN32
    CHECK_IO(RemoveDirectoryA(path));
    CHECK_IO(RemoveDirectoryA(directory));
#else
    CHECK_IO(rmdir(path) == 0);
    CHECK_IO(rmdir(directory) == 0);
#endif
    fprintf(stderr, "OK path rights, open permissions, and child independence\n");
}

#endif

#if HAS_POLL && HAS_UNISTD

static void testPollRights(TestFdSetRights setRights) {
    static const WasiRights rights[] = {
        WASI_RIGHTS_FD_READ,
        WASI_RIGHTS_FD_WRITE,
        WASI_RIGHTS_POLL_FD_READWRITE,
        WASI_RIGHTS_POLL_FD_READWRITE | WASI_RIGHTS_FD_READ,
        WASI_RIGHTS_POLL_FD_READWRITE | WASI_RIGHTS_FD_WRITE
    };
    FILE* file = tmpfile();
    size_t i;
    CHECK_IO(file != NULL);
    for (i = 0; i < sizeof(rights) / sizeof(rights[0]); i++) {
        U32 fd;
        int nativeFD = dup(fileno(file));
        WasiRights readRights = WASI_RIGHTS_POLL_FD_READWRITE | WASI_RIGHTS_FD_READ;
        WasiRights writeRights = WASI_RIGHTS_POLL_FD_READWRITE | WASI_RIGHTS_FD_WRITE;
        CHECK_IO(nativeFD >= 0);
        CHECK_IO(wasiFileDescriptorAdd(nativeFD, NULL, &fd));
        CHECK_IO(setRights(NULL, fd, rights[i], 0) == WASI_ERRNO_SUCCESS);
        resetPollMemory();
        setPollClockSubscription(
            0,
            10,
            WASI_CLOCK_MONOTONIC,
            0,
            0
        );
        setPollFDSubscription(1, 11, WASI_EVENT_TYPE_FD_READ, fd);
        setPollFDSubscription(2, 12, WASI_EVENT_TYPE_FD_WRITE, fd);
        CHECK_IO(callPollOneoff(3) == WASI_ERRNO_SUCCESS);
        CHECK_IO(i32_load(&testMemory, TEST_EVENT_COUNT_POINTER) == 3);
        expectPollEvent("rights clock", 0, 10, 0, WASI_EVENT_TYPE_CLOCK, 0);
        expectPollEvent(
            "read rights",
            1,
            11,
            (rights[i] & readRights) == readRights
                ? WASI_ERRNO_SUCCESS : WASI_ERRNO_NOTCAPABLE,
            WASI_EVENT_TYPE_FD_READ,
            0
        );
        expectPollEvent(
            "write rights",
            2,
            12,
            (rights[i] & writeRights) == writeRights
                ? WASI_ERRNO_SUCCESS : WASI_ERRNO_NOTCAPABLE,
            WASI_EVENT_TYPE_FD_WRITE,
            0
        );
        CHECK_IO(wasiFileDescriptorClose(fd));
    }
    CHECK_IO(fclose(file) == 0);
    fprintf(stderr, "OK poll rights and independent clock events\n");
}

#endif

static void testSetRights(TestFdSetRights setRights) {
    U32 fd, target;
    WasiRights base = WASI_RIGHTS_DIRECTORY_BASE;
    WasiRights inheriting = WASI_RIGHTS_DIRECTORY_INHERITING;
    WasiRights highBit = (U64)1 << 63;

    CHECK_IO(setRights(NULL, UINT32_MAX, 0, 0) == WASI_ERRNO_BADF);
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &fd));
    CHECK_IO(setRights(NULL, fd, base, inheriting) == WASI_ERRNO_SUCCESS);
    CHECK_IO(setRights(NULL, fd, 0, inheriting | highBit) == WASI_ERRNO_NOTCAPABLE);
    testFdRights(fd, base, inheriting);
    CHECK_IO(setRights(NULL, fd, base | highBit, 0) == WASI_ERRNO_NOTCAPABLE);
    testFdRights(fd, base, inheriting);

    base &= ~((WasiRights)WASI_RIGHTS_PATH_CREATE_FILE);
    CHECK_IO(setRights(NULL, fd, base, inheriting) == WASI_ERRNO_SUCCESS);
    inheriting &= ~((WasiRights)WASI_RIGHTS_FD_WRITE);
    CHECK_IO(setRights(NULL, fd, base, inheriting) == WASI_ERRNO_SUCCESS);
    testFdRights(fd, base, inheriting);
    CHECK_IO(setRights(NULL, fd, WASI_RIGHTS_DIRECTORY_BASE, inheriting)
        == WASI_ERRNO_NOTCAPABLE);
    CHECK_IO(setRights(NULL, fd, base, WASI_RIGHTS_DIRECTORY_INHERITING)
        == WASI_ERRNO_NOTCAPABLE);
    CHECK_IO(setRights(NULL, fd, 0, 0) == WASI_ERRNO_SUCCESS);
    CHECK_IO(setRights(NULL, fd, 0, 0) == WASI_ERRNO_SUCCESS);
    testFdRights(fd, 0, 0);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview114_fdX5FprestatX5Fget(
        NULL, fd, 512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview119_fdX5FprestatX5FdirX5Fname(
        NULL, fd, 512, 16
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &target));
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview111_fdX5Frenumber(
        NULL, fd, target
    ) == WASI_ERRNO_SUCCESS);
    testFdRights(target, 0, 0);
    CHECK_IO(setRights(NULL, fd, 0, 0) == WASI_ERRNO_BADF);
    CHECK_IO(wasiFileDescriptorClose(target));
    CHECK_IO(setRights(NULL, target, 0, 0) == WASI_ERRNO_BADF);
    fprintf(stderr, "OK fd_fdstat_set_rights reductions and validation\n");
}

#ifdef WASM_THREAD_TYPE

typedef struct TestRightsThread {
    WASM_MUTEX_TYPE* start;
    TestFdSetRights setRights;
    U32 fd;
    U32 result;
    WasiRights base;
    WasiRights inheriting;
} TestRightsThread;

static void* testRightsThread(void* argument) {
    TestRightsThread* test = (TestRightsThread*)argument;
    WASM_MUTEX_LOCK(test->start);
    WASM_MUTEX_UNLOCK(test->start);
    test->result = test->setRights(
        NULL, test->fd, test->base, test->inheriting
    );
    return NULL;
}

static void testSetRightsConcurrent(TestFdSetRights setRights) {
    WASM_MUTEX_TYPE start;
    unsigned int i;
    CHECK_IO(WASM_MUTEX_INIT(&start));
    for (i = 0; i < 64; i++) {
        U32 fd;
        WASM_THREAD_TYPE threads[2];
        TestRightsThread first, second;
        WasiFileDescriptor descriptor;
        CHECK_IO(wasiFileDescriptorAdd(-1, ".", &fd));
        first.start = &start;
        first.setRights = setRights;
        first.fd = fd;
        first.base = WASI_RIGHTS_PATH_OPEN;
        first.inheriting = WASI_RIGHTS_FD_READ;
        second = first;
        second.base = WASI_RIGHTS_FD_READDIR;
        second.inheriting = WASI_RIGHTS_FD_WRITE;
        WASM_MUTEX_LOCK(&start);
        CHECK_IO(WASM_THREAD_CREATE(&threads[0], testRightsThread, &first));
        CHECK_IO(WASM_THREAD_CREATE(&threads[1], testRightsThread, &second));
        WASM_MUTEX_UNLOCK(&start);
        WASM_THREAD_JOIN(threads[0]);
        WASM_THREAD_JOIN(threads[1]);
        CHECK_IO(wasiFileDescriptorGet(fd, &descriptor));
        if (first.result == WASI_ERRNO_SUCCESS) {
            CHECK_IO(second.result == WASI_ERRNO_NOTCAPABLE);
            CHECK_IO(descriptor.rightsBase == first.base);
            CHECK_IO(descriptor.rightsInheriting == first.inheriting);
        } else {
            CHECK_IO(first.result == WASI_ERRNO_NOTCAPABLE);
            CHECK_IO(second.result == WASI_ERRNO_SUCCESS);
            CHECK_IO(descriptor.rightsBase == second.base);
            CHECK_IO(descriptor.rightsInheriting == second.inheriting);
        }
        CHECK_IO(wasiFileDescriptorClose(fd));
    }
    WASM_MUTEX_FREE(&start);
    fprintf(stderr, "OK atomic concurrent rights reductions\n");
}

#endif

typedef U32 (*TestSockAccept)(wasmModuleInstance*, U32, U32, U32);
typedef U32 (*TestSockRecv)(
    wasmModuleInstance*, U32, U32, U32, U32, U32, U32
);
typedef U32 (*TestSockSend)(wasmModuleInstance*, U32, U32, U32, U32, U32);
typedef U32 (*TestSockShutdown)(wasmModuleInstance*, U32, U32);

#define DECLARE_SOCKET_IMPORTS(prefix) \
    extern U32 prefix ## 11_sockX5Faccept(wasmModuleInstance*, U32, U32, U32); \
    extern U32 prefix ## 9_sockX5Frecv( \
        wasmModuleInstance*, U32, U32, U32, U32, U32, U32 \
    ); \
    extern U32 prefix ## 9_sockX5Fsend( \
        wasmModuleInstance*, U32, U32, U32, U32, U32 \
    ); \
    extern U32 prefix ## 13_sockX5Fshutdown(wasmModuleInstance*, U32, U32)
DECLARE_SOCKET_IMPORTS(i22_wasiX5FsnapshotX5Fpreview1);
DECLARE_SOCKET_IMPORTS(i13_wasiX5Funstable);
#undef DECLARE_SOCKET_IMPORTS

#if HAS_SOCKETS || defined(_WIN32)

#ifdef _WIN32
typedef int TestSocketLength;
#else
typedef socklen_t TestSocketLength;
#endif

static void testSocketTimeout(WasiNativeSocket fd) {
#ifdef _WIN32
    DWORD timeout = 2000;
#else
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;
#endif
    CHECK_IO(setsockopt(
        fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)
    ) == 0);
    CHECK_IO(setsockopt(
        fd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout)
    ) == 0);
}

static void testSocketReady(WasiNativeSocket fd) {
    fd_set reads;
    struct timeval timeout;
    FD_ZERO(&reads);
    FD_SET(fd, &reads);
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;
#ifdef _WIN32
    CHECK_IO(select(0, &reads, NULL, NULL, &timeout) == 1);
#else
    CHECK_IO(select(fd + 1, &reads, NULL, NULL, &timeout) == 1);
#endif
}

static WasiNativeSocket testSocketBound(int type, struct sockaddr_in* address) {
    WasiNativeSocket fd = socket(AF_INET, type, 0);
    TestSocketLength length = sizeof(*address);
    CHECK_IO(fd != WASI_INVALID_SOCKET);
    testSocketTimeout(fd);
    memset(address, 0, sizeof(*address));
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    CHECK_IO(bind(fd, (struct sockaddr*)address, sizeof(*address)) == 0);
    CHECK_IO(getsockname(fd, (struct sockaddr*)address, &length) == 0);
    return fd;
}

static void testSocketVectors(U32 length) {
    i32_store(&testMemory, 0, 128);
    i32_store(&testMemory, 4, length);
    i32_store(&testMemory, 8, 256);
    i32_store(&testMemory, 12, length);
}

static void testSocketPoll(U32 fd, WasiEventType type, U16 error) {
#if HAS_POLL || defined(_WIN32)
    resetPollMemory();
    setPollClockSubscription(0, 11, WASI_CLOCK_MONOTONIC, 2000000000, 0);
    setPollFDSubscription(1, 22, type, fd);
    CHECK_IO(callPollOneoff(2) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, TEST_EVENT_COUNT_POINTER) == 1);
    CHECK_IO(i64_load(&testMemory, TEST_OUT_POINTER) == 22);
    CHECK_IO(i32_load16_u(&testMemory, TEST_OUT_POINTER + 8) == error);
#else
    UNUSED_PARAMETER(fd);
    UNUSED_PARAMETER(type);
    UNUSED_PARAMETER(error);
#endif
}

static void testSocketStream(
    TestSockAccept sockAccept,
    TestSockRecv sockRecv,
    TestSockSend sockSend,
    TestSockShutdown sockShutdown
) {
    struct sockaddr_in address;
    WasiNativeSocket listener = testSocketBound(SOCK_STREAM, &address);
    WasiNativeSocket client = socket(AF_INET, SOCK_STREAM, 0);
    WasiNativeSocket target;
    WasiFileDescriptor descriptor;
    WasiRights inherited = WASI_RIGHTS_SOCKET_BASE & ~WASI_RIGHTS_SOCK_ACCEPT;
    U32 listenerFD, clientFD, serverFD, targetFD;
    int type;
    TestSocketLength length = sizeof(type);
    CHECK_IO(client != WASI_INVALID_SOCKET);
    testSocketTimeout(client);
    CHECK_IO(listen(listener, 1) == 0);
    CHECK_IO(wasiSocketAdd(listener, WASI_FDFLAGS_NONBLOCK, &listenerFD));
    CHECK_IO(sockAccept(NULL, listenerFD, 0, 512) == WASI_ERRNO_AGAIN);
    CHECK_IO(sockAccept(NULL, listenerFD, 256, 512) == WASI_ERRNO_INVAL);
    CHECK_IO(sockAccept(NULL, listenerFD, WASI_FDFLAGS_APPEND, 512)
        == WASI_ERRNO_NOTSUP);
    CHECK_IO(sockAccept(NULL, listenerFD, 0, UINT32_MAX) == WASI_ERRNO_FAULT);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights(
        NULL, listenerFD, WASI_RIGHTS_SOCKET_BASE, inherited
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(connect(client, (struct sockaddr*)&address, sizeof(address)) == 0);
    CHECK_IO(wasiSocketAdd(client, WASI_FDFLAGS_NONBLOCK, &clientFD));
    testSocketPoll(listenerFD, WASI_EVENT_TYPE_FD_READ, WASI_ERRNO_SUCCESS);
    CHECK_IO(sockAccept(NULL, listenerFD, WASI_FDFLAGS_NONBLOCK, 512)
        == WASI_ERRNO_SUCCESS);
    serverFD = i32_load(&testMemory, 512);
    CHECK_IO(wasiFileDescriptorGet(serverFD, &descriptor));
    CHECK_IO(descriptor.rightsBase == inherited);
    CHECK_IO(descriptor.rightsInheriting == inherited);
    CHECK_IO(descriptor.socketFlags == WASI_FDFLAGS_NONBLOCK);
    CHECK_IO(!wasiFileDescriptorSet(serverFD, -1));
    testSocketTimeout(descriptor.socket);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview113_fdX5FfdstatX5Fget(
        NULL, serverFD, 512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load8_u(&testMemory, 512) == WASI_FILE_TYPE_SOCKET_STREAM);
    CHECK_IO(i32_load16_u(&testMemory, 514) == WASI_FDFLAGS_NONBLOCK);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview115_fdX5FfilestatX5Fget(
        NULL, serverFD, 512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load8_u(&testMemory, 528) == WASI_FILE_TYPE_SOCKET_STREAM);

#if HAS_POLL || defined(_WIN32)
    resetPollMemory();
    setPollClockSubscription(0, 33, WASI_CLOCK_MONOTONIC, 1000000, 0);
    setPollFDSubscription(1, 44, WASI_EVENT_TYPE_FD_READ, serverFD);
    CHECK_IO(callPollOneoff(2) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, TEST_EVENT_COUNT_POINTER) == 1);
    CHECK_IO(i64_load(&testMemory, TEST_OUT_POINTER) == 33);
#endif
    testSocketVectors(2);
    CHECK_IO(sockRecv(NULL, serverFD, 0, 0, 0, 512, 516) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 0);
    CHECK_IO(sockSend(NULL, clientFD, 0, 0, 0, 512) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 0);
    CHECK_IO(sockRecv(NULL, serverFD, 0, 2, 0, 512, 516) == WASI_ERRNO_AGAIN);
    CHECK_IO(sockRecv(NULL, serverFD, 0, 2, 4, 512, 516) == WASI_ERRNO_INVAL);
    CHECK_IO(sockRecv(NULL, serverFD, 0, 2, 0, 512, UINT32_MAX)
        == WASI_ERRNO_FAULT);
    CHECK_IO(sockSend(NULL, clientFD, 0, 2, 1, 512) == WASI_ERRNO_INVAL);
    CHECK_IO(sockSend(NULL, clientFD, UINT32_MAX, 2, 0, 512) == WASI_ERRNO_FAULT);
    CHECK_IO(sockSend(NULL, clientFD, 0, UINT32_MAX, 0, 512) == WASI_ERRNO_FAULT);
    CHECK_IO(sockSend(NULL, clientFD, 0, 2, 0, TEST_MEMORY_SIZE - 1)
        == WASI_ERRNO_FAULT);
    CHECK_IO(sockRecv(NULL, serverFD, 0, 2, 0, TEST_MEMORY_SIZE - 1, 516)
        == WASI_ERRNO_FAULT);
    i32_store(&testMemory, 8, TEST_MEMORY_SIZE - 1);
    CHECK_IO(sockSend(NULL, clientFD, 0, 2, 0, 512) == WASI_ERRNO_FAULT);
    testSocketVectors(2);
    memcpy(testMemory.data + 128, "ab", 2);
    memcpy(testMemory.data + 256, "cd", 2);
    CHECK_IO(sockSend(NULL, clientFD, 0, 2, 0, 512) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 4);
    testSocketReady(descriptor.socket);
    i32_store(&testMemory, 516, UINT32_MAX);
    CHECK_IO(sockRecv(
        NULL, serverFD, 0, 2, WASI_RIFLAGS_RECV_PEEK, 512, 516
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 4);
    CHECK_IO(i32_load16_u(&testMemory, 516) == 0);
    CHECK_IO(i32_load16_u(&testMemory, 518) == UINT16_MAX);
    CHECK_IO(memcmp(testMemory.data + 128, "ab", 2) == 0);
    CHECK_IO(memcmp(testMemory.data + 256, "cd", 2) == 0);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview119_fdX5FfdstatX5FsetX5Fflags(
        NULL, serverFD, 0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview113_fdX5FfdstatX5Fget(
        NULL, serverFD, 512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load16_u(&testMemory, 514) == 0);
    CHECK_IO(sockRecv(
        NULL, serverFD, 0, 2, WASI_RIFLAGS_RECV_WAITALL, 512, 516
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 4);

    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview18_fdX5Fwrite(
        NULL, clientFD, 0, 2, 512
    ) == WASI_ERRNO_SUCCESS);
    testSocketPoll(serverFD, WASI_EVENT_TYPE_FD_READ, WASI_ERRNO_SUCCESS);
    testSocketVectors(2);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview17_fdX5Fread(
        NULL, serverFD, 0, 2, 512
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 4);
    CHECK_IO(memcmp(testMemory.data + 128, "ab", 2) == 0);
    CHECK_IO(memcmp(testMemory.data + 256, "cd", 2) == 0);
    testSocketPoll(clientFD, WASI_EVENT_TYPE_FD_WRITE, WASI_ERRNO_SUCCESS);

    target = socket(AF_INET, SOCK_DGRAM, 0);
    CHECK_IO(target != WASI_INVALID_SOCKET);
    CHECK_IO(wasiSocketAdd(target, 0, &targetFD));
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview111_fdX5Frenumber(
        NULL, serverFD, targetFD
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(!wasiFileDescriptorGet(serverFD, &descriptor));
    CHECK_IO(getsockopt(target, SOL_SOCKET, SO_TYPE, (char*)&type, &length) != 0);
    serverFD = targetFD;
    CHECK_IO(wasiFileDescriptorGet(serverFD, &descriptor));
    CHECK_IO(descriptor.rightsBase == inherited);
    CHECK_IO(sockShutdown(NULL, clientFD, 0) == WASI_ERRNO_INVAL);
    CHECK_IO(sockShutdown(NULL, clientFD, 256 | WASI_SDFLAGS_WR)
        == WASI_ERRNO_INVAL);
    CHECK_IO(sockShutdown(NULL, clientFD, WASI_SDFLAGS_WR) == WASI_ERRNO_SUCCESS);
    testSocketVectors(2);
    CHECK_IO(sockSend(NULL, clientFD, 0, 1, 0, 512) == WASI_ERRNO_PIPE);
    testSocketPoll(serverFD, WASI_EVENT_TYPE_FD_READ, WASI_ERRNO_SUCCESS);
    testSocketVectors(2);
    CHECK_IO(sockRecv(NULL, serverFD, 0, 2, 0, 512, 516) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 0);
    memcpy(testMemory.data + 128, "ok", 2);
    CHECK_IO(sockSend(NULL, serverFD, 0, 1, 0, 512) == WASI_ERRNO_SUCCESS);
    testSocketReady(client);
    CHECK_IO(sockRecv(NULL, clientFD, 0, 1, 0, 512, 516) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 2);
    CHECK_IO(memcmp(testMemory.data + 128, "ok", 2) == 0);

    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights(
        NULL, serverFD, 0, 0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(sockRecv(NULL, serverFD, 0, 1, 0, 512, 516)
        == WASI_ERRNO_NOTCAPABLE);
    CHECK_IO(sockSend(NULL, serverFD, 0, 1, 0, 512) == WASI_ERRNO_NOTCAPABLE);
    CHECK_IO(sockShutdown(NULL, serverFD, WASI_SDFLAGS_WR)
        == WASI_ERRNO_NOTCAPABLE);
    testSocketPoll(serverFD, WASI_EVENT_TYPE_FD_READ, WASI_ERRNO_NOTCAPABLE);
    CHECK_IO(i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights(
        NULL, listenerFD, 0, 0
    ) == WASI_ERRNO_SUCCESS);
    CHECK_IO(sockAccept(NULL, listenerFD, 0, 512) == WASI_ERRNO_NOTCAPABLE);
    CHECK_IO(wasiFileDescriptorClose(serverFD));
    length = sizeof(type);
    CHECK_IO(getsockopt(
        descriptor.socket, SOL_SOCKET, SO_TYPE, (char*)&type, &length
    ) != 0);
    CHECK_IO(wasiFileDescriptorClose(clientFD));
    CHECK_IO(wasiFileDescriptorClose(listenerFD));
    fprintf(stderr, "OK sockets: streams, flags, rights, polling, and ownership\n");
}

static void testSocketDatagram(TestSockRecv sockRecv, TestSockSend sockSend) {
    struct sockaddr_in address;
    WasiNativeSocket receiver = testSocketBound(SOCK_DGRAM, &address);
    WasiNativeSocket sender = socket(AF_INET, SOCK_DGRAM, 0);
    U32 receiverFD, senderFD;
    CHECK_IO(sender != WASI_INVALID_SOCKET);
    CHECK_IO(connect(sender, (struct sockaddr*)&address, sizeof(address)) == 0);
    CHECK_IO(wasiSocketAdd(receiver, WASI_FDFLAGS_NONBLOCK, &receiverFD));
    CHECK_IO(wasiSocketAdd(sender, 0, &senderFD));
    testSocketVectors(2);
    memcpy(testMemory.data + 128, "ab", 2);
    memcpy(testMemory.data + 256, "cd", 2);
    CHECK_IO(sockSend(NULL, senderFD, 0, 2, 0, 512) == WASI_ERRNO_SUCCESS);
    testSocketReady(receiver);
    CHECK_IO(sockRecv(NULL, receiverFD, 0, 1, 0, 512, 516) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 2);
    CHECK_IO(i32_load16_u(&testMemory, 516) == WASI_ROFLAGS_RECV_DATA_TRUNCATED);
    CHECK_IO(memcmp(testMemory.data + 128, "ab", 2) == 0);
    CHECK_IO(sockRecv(NULL, receiverFD, 0, 2, 0, 512, 516) == WASI_ERRNO_AGAIN);
    CHECK_IO(sockSend(NULL, senderFD, 0, 2, 0, 512) == WASI_ERRNO_SUCCESS);
    testSocketReady(receiver);
    CHECK_IO(sockRecv(NULL, receiverFD, 0, 2, 0, 512, 516) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 4);
    CHECK_IO(i32_load16_u(&testMemory, 516) == 0);
    CHECK_IO(memcmp(testMemory.data + 256, "cd", 2) == 0);
    CHECK_IO(sockSend(NULL, senderFD, 0, 0, 0, 512) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 0);
    testSocketReady(receiver);
    CHECK_IO(sockRecv(NULL, receiverFD, 0, 2, 0, 512, 516) == WASI_ERRNO_SUCCESS);
    CHECK_IO(i32_load(&testMemory, 512) == 0);
    CHECK_IO(i32_load16_u(&testMemory, 516) == 0);
    CHECK_IO(wasiFileDescriptorClose(receiverFD));
    CHECK_IO(wasiFileDescriptorClose(senderFD));
    fprintf(stderr, "OK sockets: datagram truncation and empty messages\n");
}

#endif

static void testSockets(
    TestSockAccept sockAccept,
    TestSockRecv sockRecv,
    TestSockSend sockSend,
    TestSockShutdown sockShutdown
) {
#if HAS_SOCKETS || defined(_WIN32)
    U32 file;
#ifdef _WIN32
    WSADATA data;
    CHECK_IO(WSAStartup(MAKEWORD(2, 2), &data) == 0);
#endif
#ifdef _WIN32
    {
        FILE* stream = tmpfile();
        int nativeFD;
        CHECK_IO(stream != NULL);
        nativeFD = _dup(_fileno(stream));
        CHECK_IO(nativeFD >= 0);
        CHECK_IO(wasiFileDescriptorAdd(nativeFD, NULL, &file));
        testSocketPoll(file, WASI_EVENT_TYPE_FD_READ, WASI_ERRNO_SUCCESS);
        CHECK_IO(wasiFileDescriptorClose(file));
        CHECK_IO(fclose(stream) == 0);
    }
#endif
    CHECK_IO(wasiFileDescriptorAdd(-1, ".", &file));
    CHECK_IO(sockAccept(NULL, UINT32_MAX, 0, 512) == WASI_ERRNO_BADF);
    CHECK_IO(sockRecv(NULL, UINT32_MAX, 0, 0, 0, 512, 516) == WASI_ERRNO_BADF);
    CHECK_IO(sockSend(NULL, UINT32_MAX, 0, 0, 0, 512) == WASI_ERRNO_BADF);
    CHECK_IO(sockShutdown(NULL, UINT32_MAX, 1) == WASI_ERRNO_BADF);
    CHECK_IO(sockAccept(NULL, file, 0, 512) == WASI_ERRNO_NOTSOCK);
    CHECK_IO(sockRecv(NULL, file, 0, 0, 0, 512, 516) == WASI_ERRNO_NOTSOCK);
    CHECK_IO(sockSend(NULL, file, 0, 0, 0, 512) == WASI_ERRNO_NOTSOCK);
    CHECK_IO(sockShutdown(NULL, file, 1) == WASI_ERRNO_NOTSOCK);
    CHECK_IO(wasiFileDescriptorClose(file));
    CHECK_IO(!wasiSocketAdd(WASI_INVALID_SOCKET, 0, NULL));
    testSocketStream(sockAccept, sockRecv, sockSend, sockShutdown);
    testSocketDatagram(sockRecv, sockSend);
#ifdef _WIN32
    CHECK_IO(WSACleanup() == 0);
#endif
#else
    CHECK_IO(sockAccept(NULL, 0, 0, 0) == WASI_ERRNO_NOSYS);
    CHECK_IO(sockRecv(NULL, 0, 0, 0, 0, 0, 0) == WASI_ERRNO_NOSYS);
    CHECK_IO(sockSend(NULL, 0, 0, 0, 0, 0) == WASI_ERRNO_NOSYS);
    CHECK_IO(sockShutdown(NULL, 0, 0) == WASI_ERRNO_NOSYS);
    CHECK_IO(!wasiSocketAdd(WASI_INVALID_SOCKET, 0, NULL));
    fprintf(stderr, "OK sockets: unsupported host\n");
#endif
}

int
main(int argc, char* argv[]) {
#ifdef _WIN32
    if (argc == 2) {
        TestProcRaise raiseSignal = NULL;
        if (strcmp(argv[1], "--raise-preview1") == 0) {
            raiseSignal = i22_wasiX5FsnapshotX5Fpreview110_procX5Fraise;
        } else if (strcmp(argv[1], "--raise-unstable") == 0) {
            raiseSignal = i13_wasiX5Funstable10_procX5Fraise;
        }
        if (raiseSignal != NULL) {
            CHECK_IO(signal(SIGABRT, SIG_DFL) != SIG_ERR);
            raiseSignal(NULL, WASI_SIGNAL_ABRT);
            return 99;
        }
    }
#endif
    memset(&testMemory, 0, sizeof(testMemory));
    testMemory.data = testMemoryData;
    testMemory.size = TEST_MEMORY_SIZE;
    testMemory.pages = TEST_MEMORY_SIZE / WASM_PAGE_SIZE;
    testMemory.maxPages = testMemory.pages;

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        exit(1);
    }

    testSockets(
        i22_wasiX5FsnapshotX5Fpreview111_sockX5Faccept,
        i22_wasiX5FsnapshotX5Fpreview19_sockX5Frecv,
        i22_wasiX5FsnapshotX5Fpreview19_sockX5Fsend,
        i22_wasiX5FsnapshotX5Fpreview113_sockX5Fshutdown
    );
    testSockets(
        i13_wasiX5Funstable11_sockX5Faccept,
        i13_wasiX5Funstable9_sockX5Frecv,
        i13_wasiX5Funstable9_sockX5Fsend,
        i13_wasiX5Funstable13_sockX5Fshutdown
    );
    testSchedYield();
    testProcRaise(i22_wasiX5FsnapshotX5Fpreview110_procX5Fraise);
    testProcRaise(i13_wasiX5Funstable10_procX5Fraise);
    testProcRaiseTermination(
        i22_wasiX5FsnapshotX5Fpreview110_procX5Fraise,
        "--raise-preview1"
    );
    testProcRaiseTermination(
        i13_wasiX5Funstable10_procX5Fraise,
        "--raise-unstable"
    );
    testSetRights(i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights);
    testSetRights(i13_wasiX5Funstable20_fdX5FfdstatX5FsetX5Frights);
#if HAS_POLL && HAS_UNISTD
    testPollRights(i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights);
#endif
#if HAS_UNISTD || defined(_WIN32)
    testFileRightsEnforcement(
        i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights
    );
    testSeekRights(i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights);
    testPathRightsEnforcement(
        i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights
    );
#endif
#ifdef WASM_THREAD_TYPE
    testSetRightsConcurrent(
        i22_wasiX5FsnapshotX5Fpreview120_fdX5FfdstatX5FsetX5Frights
    );
#endif
    testFileDescriptorGet();
    testPreopenDirectory();
    testFileDescriptorClose();
    testFileDescriptorCloseDirectory();
#ifdef WASM_THREAD_TYPE
    testFileDescriptorsConcurrent();
#endif
    testFdRenumber(i22_wasiX5FsnapshotX5Fpreview111_fdX5Frenumber);
    testFdRenumber(i13_wasiX5Funstable11_fdX5Frenumber);
    testDirectoryRights(
        i22_wasiX5FsnapshotX5Fpreview19_pathX5Fopen,
        i22_wasiX5FsnapshotX5Fpreview111_fdX5Frenumber
    );
    testDirectoryRights(
        i13_wasiX5Funstable9_pathX5Fopen,
        i13_wasiX5Funstable11_fdX5Frenumber
    );
#if HAS_UNISTD || defined(_WIN32)
    testFileRights(
        i22_wasiX5FsnapshotX5Fpreview19_pathX5Fopen,
        i22_wasiX5FsnapshotX5Fpreview111_fdX5Frenumber
    );
    testFileRights(
        i13_wasiX5Funstable9_pathX5Fopen,
        i13_wasiX5Funstable11_fdX5Frenumber
    );
#endif
    testFdAllocateAndAdvise(
        i22_wasiX5FsnapshotX5Fpreview111_fdX5Fallocate,
        i22_wasiX5FsnapshotX5Fpreview19_fdX5Fadvise
    );
    testFdAllocateAndAdvise(
        i13_wasiX5Funstable11_fdX5Fallocate,
        i13_wasiX5Funstable9_fdX5Fadvise
    );
    testPathLink(i22_wasiX5FsnapshotX5Fpreview19_pathX5Flink);
    testPathLink(i13_wasiX5Funstable9_pathX5Flink);
    testFilestatSetTimes(
        i22_wasiX5FsnapshotX5Fpreview121_fdX5FfilestatX5FsetX5Ftimes,
        i22_wasiX5FsnapshotX5Fpreview123_pathX5FfilestatX5FsetX5Ftimes
    );
    testFilestatSetTimes(
        i13_wasiX5Funstable21_fdX5FfilestatX5FsetX5Ftimes,
        i13_wasiX5Funstable23_pathX5FfilestatX5FsetX5Ftimes
    );
    testFdFlags(i22_wasiX5FsnapshotX5Fpreview119_fdX5FfdstatX5FsetX5Fflags);
    testFdFlags(i13_wasiX5Funstable19_fdX5FfdstatX5FsetX5Fflags);
#if HAS_UNISTD && HAS_FCNTL && defined(O_DSYNC) && defined(O_SYNC)
    testFdSyncFlags(O_DSYNC);
    testFdSyncFlags(O_SYNC);
#endif

#if HAS_UNISTD || defined(_WIN32)
    testPositionalIO();
#ifdef PLAN9
    testPlan9DirectoryCookies();
#endif
#endif

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

#if HAS_POLL || defined(_WIN32)
    testPollOneoff();
#else
    if (i22_wasiX5FsnapshotX5Fpreview111_pollX5Foneoff(
        NULL,
        0,
        0,
        0,
        0
    )
        != WASI_ERRNO_NOSYS) {
        fprintf(stderr, "FAIL poll_oneoff fallback\n");
        exit(1);
    }
    fprintf(stderr, "OK poll_oneoff fallback\n");
#endif /* HAS_POLL || _WIN32 */

#if defined(WASM_THREAD_TYPE) && (defined(WASM_ATOMICS_MSVC) || defined(WASM_ATOMICS_GCC))
    testThreadSpawnCleanup();
#endif

    return 0;
}
