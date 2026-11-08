#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test_memory_cache.h"
#include "test_memory_cache_shared.h"
#undef realloc

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL memory cache: line %d: %s\n", __LINE__, #condition); \
            abort(); \
        } \
    } while (0)

static wasmMemory* memory;
static void* retired[16];
static size_t retiredCount;
static bool failAllocation;
static bool reenter;
static U32 sharedResult;

void trap(Trap reason) {
    fprintf(stderr, "FAIL memory cache: unexpected %s\n", trapDescription(reason));
    abort();
}

void* memoryCacheRealloc(void* old, size_t size) {
    void* replacement;
    CHECK(old == memory->data && size > memory->size);
    if (failAllocation) return NULL;
    replacement = malloc(size);
    CHECK(replacement != NULL && retiredCount < 16);
    memcpy(replacement, old, (size_t)memory->size);
    /* Keep the old allocation alive and poison it,
     * so stale pointers fail deterministically without accessing freed storage. */
    memset(old, 0xDD, (size_t)memory->size);
    retired[retiredCount++] = old;
    return replacement;
}

static void* resolve(WasmName module, WasmName name) {
    CHECK(module.length == 3 && memcmp(module.data, "env", 3) == 0);
    CHECK(name.length == 6 && memcmp(name.data, "memory", 6) == 0);
    return memory;
}

U32 m12_memoryX5FcacheImport3_env4_grow(wasmModuleInstance* instance, U32 delta) {
    const U32 previous = wasmMemorySize(memory);
    CHECK(((m12_memoryX5FcacheInstance*)instance)->m0 == memory);
    if (reenter) {
        CHECK(m12_memoryX5FcacheExport4_grow((m12_memoryX5FcacheInstance*)instance, delta) == 17);
    } else {
        CHECK(wasmMemoryGrow(memory, delta) == previous);
    }
    i32_store(memory, 0, 71);
    return previous;
}

static void checkCall(
    U32 (*function)(m12_memoryX5FcacheInstance*, U32),
    U32 argument,
    U32 expected,
    U32 expectedPages
) {
    m12_memoryX5FcacheInstance instance;
    size_t index;
    memory = wasmMemoryAllocate(1, 16, false);
    i32_store(memory, 0, 17);
    m12_memoryX5FcacheInstantiate(&instance, resolve);
    CHECK(function(&instance, argument) == expected);
    CHECK(wasmMemorySize(memory) == expectedPages);
    m12_memoryX5FcacheFreeInstance(&instance);
    wasmMemoryFree(memory);
    for (index = 0; index < retiredCount; index++) free(retired[index]);
    retiredCount = 0;
}

static void* readSharedMemory(void* instance) {
    sharedResult = m19_memoryX5FcacheX5FsharedExport4_read(
        (m19_memoryX5FcacheX5FsharedInstance*)instance
    );
    return NULL;
}

static void checkSharedGrowth(void) {
    m19_memoryX5FcacheX5FsharedInstance instance;
    WASM_THREAD_TYPE reader;
    memory = wasmMemoryAllocate(1, 2, true);
    m19_memoryX5FcacheX5FsharedInstantiate(&instance, resolve);
    CHECK(WASM_THREAD_CREATE(&reader, readSharedMemory, &instance));
    /* Wait until generated code has entered the function,
     * then grow memory without a call on the reader's thread. */
    while (i32_atomic_load(memory, 4) == 0) {}
    CHECK(wasmMemoryGrow(memory, 1) == 1);
    i32_store(memory, WASM_PAGE_SIZE, 83);
    i32_atomic_store(memory, 0, 1);
    WASM_THREAD_JOIN(reader);
    CHECK(sharedResult == 83);
    m19_memoryX5FcacheX5FsharedFreeInstance(&instance);
    wasmMemoryFree(memory);
}

int main(void) {
    checkCall(m12_memoryX5FcacheExport4_grow, 1, 17, 2);
    checkCall(m12_memoryX5FcacheExport4_grow, 0, 17, 1);
    checkCall(m12_memoryX5FcacheExport4_grow, UINT32_MAX, 17, 1);
    failAllocation = true;
    checkCall(m12_memoryX5FcacheExport4_grow, 1, 17, 1);
    failAllocation = false;
    checkCall(m12_memoryX5FcacheExport6_direct, 1, 46, 2);
    checkCall(m12_memoryX5FcacheExport4_host, 1, 100, 2);
    reenter = true;
    checkCall(m12_memoryX5FcacheExport4_host, 1, 100, 2);
    reenter = false;
    checkCall(m12_memoryX5FcacheExport4_late, 1, 71, 2);
    checkCall(m12_memoryX5FcacheExport8_indirect, 0, 46, 2);
    checkCall(m12_memoryX5FcacheExport8_indirect, 1, 100, 2);
    checkCall(m12_memoryX5FcacheExport6_branch, 0, 17, 2);
    checkCall(m12_memoryX5FcacheExport6_branch, 1, 71, 2);
    checkCall(m12_memoryX5FcacheExport5_multi, 1, 17, 2);
    checkCall(m12_memoryX5FcacheExport4_loop, 4, 284, 5);
    checkSharedGrowth();
    fprintf(stderr, "PASS memory cache\n");
    return 0;
}
