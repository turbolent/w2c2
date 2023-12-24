#include <stdio.h>
#if HAS_UNISTD
#include <unistd.h>
#endif

#include "futex_test.h"
#include "futex.h"

#ifndef WASM_THREAD_TYPE
#error "Please define a threads implementation to use (WASM_THREADS_*)"
#endif

typedef struct TestThreadArg {
    U8 id;
    wasmMemory* mem;
    U32 initAddress;
    U32 waitAddress;
} TestThreadArg;

void* testThreadFunc(void* arg) {
    TestThreadArg* testArg = (TestThreadArg*)arg;

    /* Indicate that the thread has started */
    i32_atomic_rmw8_add_u(
        testArg->mem,
        testArg->initAddress,
        1
    );

    wasmMemoryAtomicWait(
        testArg->mem,
        testArg->waitAddress,
        0,
        -1,
        false
    );

    return NULL;
}

void
testFutex(void) {
    const U32 initAddress = 0;
    const U32 waitAddress1 = 42;
    const U32 waitAddress2 = 99;

    wasmMemory* mem = NULL;

    WASM_THREAD_TYPE thread1;
    WASM_THREAD_TYPE thread2;
    WASM_THREAD_TYPE thread3;
    WASM_THREAD_TYPE thread4;

    TestThreadArg arg1;
    TestThreadArg arg2;
    TestThreadArg arg3;
    TestThreadArg arg4;

    mem = wasmMemoryAllocate(1, 1, true);

    /* Three threads will wait on waitAddress1,
     * one thread will wait on waitAddress2. */

    arg1.id = 1;
    arg1.mem = mem;
    arg1.initAddress = initAddress;
    arg1.waitAddress = waitAddress1;

    arg2.id = 2;
    arg2.mem = mem;
    arg2.initAddress = initAddress;
    arg2.waitAddress = waitAddress1;

    arg3.id = 3;
    arg3.mem = mem;
    arg3.initAddress = initAddress;
    arg3.waitAddress = waitAddress1;

    arg4.id = 4;
    arg4.mem = mem;
    arg4.initAddress = initAddress;
    arg4.waitAddress = waitAddress2;

    /* Start threads */

    if (!WASM_THREAD_CREATE(&thread1, testThreadFunc, &arg1)) {
        fprintf(stderr, "FAIL testFutex: failed to create thread1\n");
        exit(1);
    }

    if (!WASM_THREAD_CREATE(&thread2, testThreadFunc, &arg2)) {
        fprintf(stderr, "FAIL testFutex: failed to create thread2\n");
        exit(1);
    }

    if (!WASM_THREAD_CREATE(&thread3, testThreadFunc, &arg3)) {
        fprintf(stderr, "FAIL testFutex: failed to create thread3\n");
        exit(1);
    }

    if (!WASM_THREAD_CREATE(&thread4, testThreadFunc, &arg4)) {
        fprintf(stderr, "FAIL testFutex: failed to create thread4\n");
        exit(1);
    }

    /* Wait for all threads to have started */
    while (i32_atomic_load8_u(mem, initAddress) < 4) {
#if HAS_UNISTD
        sleep(1);
#elif _WIN32
        Sleep(1000);
#else
#error "Cannot sleep"
#endif
    }

    wasmMemoryAtomicNotify(mem, waitAddress1, 2);
    wasmMemoryAtomicNotify(mem, waitAddress2, 2);
    wasmMemoryAtomicNotify(mem, waitAddress1, 1);

    WASM_THREAD_JOIN(thread1);
    WASM_THREAD_JOIN(thread2);
    WASM_THREAD_JOIN(thread3);
    WASM_THREAD_JOIN(thread4);

    wasmMemoryFree(mem);

    fprintf(stderr, "PASS testFutex\n");
}
