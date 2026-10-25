#include <stdio.h>
#if HAS_PTHREAD
#define WASM_THREADS_PTHREADS
#elif _WIN32
#define WASM_THREADS_WIN32
#endif
#include "w2c2_base.h"
#include "runtime_shared_memory_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testRuntimeSharedMemory: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

#ifdef WASM_THREAD_TYPE

#define THREAD_COUNT 4
#define GROW_COUNT 64
#define MAX_PAGES 129

typedef struct MemoryThread {
    wasmMemory* memory;
    WASM_MUTEX_TYPE* start;
    U32 results[GROW_COUNT];
} MemoryThread;

static void* growMemory(void* argument) {
    MemoryThread* thread = (MemoryThread*)argument;
    U32 previous = 1;
    unsigned int index;
    WASM_MUTEX_LOCK(thread->start);
    WASM_MUTEX_UNLOCK(thread->start);
    for (index = 0; index < GROW_COUNT; index++) {
        U32 pages = wasmMemorySize(thread->memory);
        U32 result;
        CHECK(pages >= previous && pages <= MAX_PAGES);
        previous = wasmMemoryGrow(thread->memory, 0);
        CHECK(previous >= pages && previous <= MAX_PAGES);
        result = wasmMemoryGrow(thread->memory, 1);
        if (result == UINT32_MAX) {
            CHECK(wasmMemorySize(thread->memory) == MAX_PAGES);
            previous = MAX_PAGES;
        } else {
            CHECK(result >= previous && result < MAX_PAGES);
            previous = result + 1;
        }
        thread->results[index] = result;
    }
    return NULL;
}

#endif

void testRuntimeSharedMemory(void) {
#ifdef WASM_THREAD_TYPE
    wasmMemory* memory = wasmMemoryAllocate(1, MAX_PAGES, true);
    U8* data = memory->data;
    WASM_MUTEX_TYPE start;
    WASM_THREAD_TYPE threads[THREAD_COUNT];
    MemoryThread arguments[THREAD_COUNT];
    bool seen[MAX_PAGES] = {false};
    unsigned int thread;
    U32 page;
    memory->data[WASM_PAGE_SIZE - 1] = 42;
    CHECK(WASM_MUTEX_INIT(&start));
    WASM_MUTEX_LOCK(&start);
    for (thread = 0; thread < THREAD_COUNT; thread++) {
        arguments[thread].memory = memory;
        arguments[thread].start = &start;
        CHECK(WASM_THREAD_CREATE(&threads[thread], growMemory, &arguments[thread]));
    }
    WASM_MUTEX_UNLOCK(&start);
    for (thread = 0; thread < THREAD_COUNT; thread++) {
        unsigned int index;
        WASM_THREAD_JOIN(threads[thread]);
        for (index = 0; index < GROW_COUNT; index++) {
            U32 result = arguments[thread].results[index];
            if (result != UINT32_MAX) {
                CHECK(result >= 1 && result < MAX_PAGES && !seen[result]);
                seen[result] = true;
            }
        }
    }
    for (page = 1; page < MAX_PAGES; page++) {
        CHECK(seen[page]);
        CHECK(memory->data[page * WASM_PAGE_SIZE] == 0);
    }
    CHECK(wasmMemorySize(memory) == MAX_PAGES);
    CHECK(memory->size == (U64)MAX_PAGES * WASM_PAGE_SIZE);
    CHECK(memory->data == data && memory->data[WASM_PAGE_SIZE - 1] == 42);
    WASM_MUTEX_FREE(&start);
    wasmMemoryFree(memory);
    fprintf(stderr, "PASS testRuntimeSharedMemory\n");
#else
    fprintf(stderr, "SKIP testRuntimeSharedMemory: threads unavailable\n");
#endif
}
