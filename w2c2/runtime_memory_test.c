#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runtime_memory_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testRuntimeMemory: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

static void* memoryTestCalloc(size_t count, size_t size);
static void* memoryTestRealloc(void* pointer, size_t size);
static void* memoryTestMemset(void* pointer, int value, size_t size);
static void memoryTestAbort(void);

/* These tests exercise serial shared-memory behavior on hosts without threads. */
#define WASM_MUTEX_TYPE int
#define WASM_MUTEX_INIT(mutex) (*(mutex) = 0, true)
#define WASM_MUTEX_FREE(mutex) ((void)(mutex))
#define WASM_MUTEX_LOCK(mutex) ((void)(mutex))
#define WASM_MUTEX_UNLOCK(mutex) ((void)(mutex))

/* Keep allocation fault injection local to this copy of the runtime helpers. */
#define calloc memoryTestCalloc
#define realloc memoryTestRealloc
#ifdef memset
#undef memset
#endif
#define memset memoryTestMemset
#define abort memoryTestAbort
#include "w2c2_base.h"
#undef calloc
#undef realloc
#undef memset
#undef abort

static jmp_buf allocationFailure;
static bool expectAbort;
static bool simulateLargeAllocation;
static unsigned int allocationCalls;
static unsigned int failAllocation;
static size_t allocationBytes;
static size_t zeroedBytes;

static bool memoryTestAllocate(size_t size) {
    allocationCalls++;
    allocationBytes = size;
    return allocationCalls != failAllocation;
}

static void* memoryTestCalloc(size_t count, size_t size) {
    CHECK(size != 0 && count <= (size_t)-1 / size);
    size *= count;
    if (!memoryTestAllocate(size) || size == 0) {
        return NULL;
    }
    CHECK(simulateLargeAllocation || size <= 3 * WASM_PAGE_SIZE);
    return calloc(simulateLargeAllocation && size > 3 * WASM_PAGE_SIZE ? 1 : size, 1);
}

static void* memoryTestRealloc(void* pointer, size_t size) {
    if (!memoryTestAllocate(size)) {
        return NULL;
    }
    CHECK(simulateLargeAllocation || size <= 3 * WASM_PAGE_SIZE);
    return realloc(pointer, simulateLargeAllocation && size > 3 * WASM_PAGE_SIZE ? 1 : size);
}

static void* memoryTestMemset(void* pointer, int value, size_t size) {
    zeroedBytes = size;
    if (simulateLargeAllocation && size > 3 * WASM_PAGE_SIZE) {
        return pointer;
    }
    return memset(pointer, value, size);
}

static void memoryTestAbort(void) {
    CHECK(expectAbort);
    longjmp(allocationFailure, 1);
}

static void checkAllocationFailure(U32 pages, U32 maximum, bool shared, unsigned int failAt) {
    allocationCalls = 0;
    failAllocation = failAt;
    expectAbort = true;
    if (setjmp(allocationFailure) == 0) {
        wasmMemoryAllocate(pages, maximum, shared);
        CHECK(false);
    }
    expectAbort = false;
    CHECK(allocationCalls == failAt);
    failAllocation = 0;
}

static void testMemoryAllocation(void) {
    wasmMemory* memory = wasmMemoryAllocate(0, 0, false);
    CHECK(memory->data == NULL && memory->size == 0 && memory->pages == 0);
    CHECK(wasmMemoryGrow(memory, 0) == 0);
    CHECK(wasmMemoryGrow(memory, 1) == UINT32_MAX);
    wasmMemoryFree(memory);

    memory = wasmMemoryAllocate(1, 3, true);
    CHECK(allocationBytes == 3 * WASM_PAGE_SIZE);
    CHECK(memory->size == WASM_PAGE_SIZE && memory->pages == 1);
    CHECK(memory->maxPages == 3 && memory->shared);
    CHECK(wasmMemoryGrow(memory, 2) == 1);
    CHECK(memory->size == 3 * WASM_PAGE_SIZE && memory->pages == 3);
    CHECK(memory->data[3 * WASM_PAGE_SIZE - 1] == 0);
    wasmMemoryFree(memory);

    checkAllocationFailure(1, 1, false, 1);
    checkAllocationFailure(1, 1, false, 2);
    checkAllocationFailure(1, 2, true, 2);
}

static void checkGrowthFailure(wasmMemory* memory, U32 delta) {
    U8* data = memory->data;
    const U32 pages = memory->pages;
    const U64 size = memory->size;
    CHECK(wasmMemoryGrow(memory, delta) == UINT32_MAX);
    CHECK(memory->data == data && memory->pages == pages && memory->size == size);
}

static void testMemoryGrowth(void) {
    wasmMemory* memory = wasmMemoryAllocate(0, 3, false);
    unsigned int calls;
    size_t index;
    U8* data;
    CHECK(wasmMemoryGrow(memory, 1) == 0);
    CHECK(memory->size == WASM_PAGE_SIZE && memory->pages == 1);
    for (index = 0; index < WASM_PAGE_SIZE; index++) {
        CHECK(memory->data[index] == 0);
    }
    memory->data[0] = 42;
    memory->data[WASM_PAGE_SIZE - 1] = 99;

    calls = allocationCalls;
    checkGrowthFailure(memory, UINT32_MAX);
    checkGrowthFailure(memory, 3);
    CHECK(allocationCalls == calls);

    data = memory->data;
    failAllocation = allocationCalls + 1;
    CHECK(wasmMemoryGrow(memory, 0) == 1);
    CHECK(memory->data == data && allocationCalls == calls);
    checkGrowthFailure(memory, 1);
    CHECK(memory->data[0] == 42 && memory->data[WASM_PAGE_SIZE - 1] == 99);
    failAllocation = 0;

    CHECK(wasmMemoryGrow(memory, 1) == 1);
    CHECK(memory->size == 2 * WASM_PAGE_SIZE && memory->pages == 2);
    CHECK(memory->data[0] == 42 && memory->data[WASM_PAGE_SIZE - 1] == 99);
    for (index = WASM_PAGE_SIZE; index < 2 * WASM_PAGE_SIZE; index++) {
        CHECK(memory->data[index] == 0);
    }
    wasmMemoryFree(memory);
}

static void testMemorySizeBoundary(void) {
    const U64 fullSize = (U64)1 << 32;
    wasmMemory memory = {0};
    U8 saved = 42;
    memory.data = &saved;
    memory.pages = 65535;
    memory.maxPages = 65536;
    memory.size = fullSize - WASM_PAGE_SIZE;
    allocationCalls = 0;
    allocationBytes = 0;
    failAllocation = 1;
    checkGrowthFailure(&memory, 1);
    CHECK(saved == 42);
    if (fullSize > (size_t)-1) {
        CHECK(allocationCalls == 0);
        checkAllocationFailure(65536, 65536, false, 0);
        checkAllocationFailure(1, 65536, true, 0);
    } else {
        wasmMemory* allocated;
        CHECK(allocationCalls == 1 && (U64)allocationBytes == fullSize);
        failAllocation = 0;

        /*
         * Large requests use one backing byte and a recording memset.
         * Growth starts at zero so pointer arithmetic stays within that byte.
         */
        simulateLargeAllocation = true;
        allocated = wasmMemoryAllocate(0, 65536, false);
        CHECK(wasmMemoryGrow(allocated, 65536) == 0);
        CHECK((U64)allocationBytes == fullSize && (U64)zeroedBytes == fullSize);
        CHECK(allocated->size == fullSize && allocated->pages == 65536);
        CHECK(wasmMemoryGrow(allocated, 0) == 65536);
        checkGrowthFailure(allocated, 1);
        wasmMemoryFree(allocated);

        allocated = wasmMemoryAllocate(65536, 65536, false);
        CHECK((U64)allocationBytes == fullSize && allocated->size == fullSize);
        CHECK(allocated->pages == 65536);
        wasmMemoryFree(allocated);

        allocated = wasmMemoryAllocate(1, 65536, true);
        CHECK((U64)allocationBytes == fullSize && allocated->size == WASM_PAGE_SIZE);
        CHECK(wasmMemoryGrow(allocated, 65535) == 1);
        CHECK(allocated->size == fullSize && allocated->pages == 65536);
        wasmMemoryFree(allocated);
        simulateLargeAllocation = false;
    }
    failAllocation = 0;
}

void testRuntimeMemory(void) {
    CHECK(sizeof(WasmPtr) == 4);
    testMemoryAllocation();
    testMemoryGrowth();
    testMemorySizeBoundary();
    fprintf(stderr, "PASS testRuntimeMemory\n");
}
