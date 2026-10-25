#include <setjmp.h>
#include <stdio.h>
#include "test_runtime_checks.h"
#include "test_check_segments.h"
#include "test_check_empty_segments.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL runtime checks: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

static jmp_buf expectedTrap;
static bool expectingTrap;
static Trap actualTrap;
static wasmMemory* memory;
static wasmTable table;
static U32 memoryOffset;
static U32 tableOffset;

void trap(Trap reason) {
    if (!expectingTrap) {
        fprintf(stderr, "FAIL unexpected trap: %s\n", trapDescription(reason));
        abort();
    }
    actualTrap = reason;
    longjmp(expectedTrap, 1);
}

#define CHECK_TRAP(expression, reason) \
    do { \
        expectingTrap = true; \
        if (setjmp(expectedTrap) == 0) { \
            (void)(expression); \
            CHECK(false); \
        } \
        expectingTrap = false; \
        CHECK(actualTrap == (reason)); \
    } while (0)

static void* resolve(WasmName module, WasmName name) {
    CHECK(module.length == 3 && memcmp(module.data, "env", 3) == 0);
    if (name.length == 6 && memcmp(name.data, "memory", 6) == 0) { return memory; }
    if (name.length == 5 && memcmp(name.data, "table", 5) == 0) { return &table; }
    if (name.length == 13 && memcmp(name.data, "memory_offset", 13) == 0) { return &memoryOffset; }
    CHECK(name.length == 12 && memcmp(name.data, "table_offset", 12) == 0);
    return &tableOffset;
}

#if W2C2_RUNTIME_CHECKS
#define CHECK_LOAD_BOUNDS(name, width) \
    do { \
        (void)name(memory, memory->size - width); \
        (void)name(memory, 1); \
        CHECK_TRAP(name(memory, memory->size - width + 1), trapMemoryOutOfBounds); \
    } while (0)

#define CHECK_STORE_BOUNDS(name, width) \
    do { \
        name(memory, memory->size - width, 7); \
        name(memory, 1, 7); \
        CHECK_TRAP(name(memory, memory->size - width + 1, 0), trapMemoryOutOfBounds); \
        CHECK(memory->data[memory->size - width] == 7); \
    } while (0)

static void testScalarBounds(void) {
    wasmMemory full = {0};
    full.size = (U64)UINT32_MAX + 1;
    wasmMemoryCheckRange(&full, full.size, 0);
    CHECK_TRAP(wasmMemoryCheckRange(&full, full.size + 1, 0), trapMemoryOutOfBounds);
    CHECK_TRAP(wasmMemoryCheckRange(&full, full.size, 1), trapMemoryOutOfBounds);
    CHECK_TRAP(wasmMemoryCheckRange(&full, 1, UINT64_MAX), trapMemoryOutOfBounds);
    CHECK_LOAD_BOUNDS(i32_load, 4);
    CHECK_LOAD_BOUNDS(i64_load, 8);
    CHECK_LOAD_BOUNDS(f32_load, 4);
    CHECK_LOAD_BOUNDS(f64_load, 8);
    CHECK_LOAD_BOUNDS(i32_load8_s, 1);
    CHECK_LOAD_BOUNDS(i32_load8_u, 1);
    CHECK_LOAD_BOUNDS(i64_load8_s, 1);
    CHECK_LOAD_BOUNDS(i64_load8_u, 1);
    CHECK_LOAD_BOUNDS(i32_load16_s, 2);
    CHECK_LOAD_BOUNDS(i32_load16_u, 2);
    CHECK_LOAD_BOUNDS(i64_load16_s, 2);
    CHECK_LOAD_BOUNDS(i64_load16_u, 2);
    CHECK_LOAD_BOUNDS(i64_load32_s, 4);
    CHECK_LOAD_BOUNDS(i64_load32_u, 4);
    CHECK_STORE_BOUNDS(i32_store, 4);
    CHECK_STORE_BOUNDS(i64_store, 8);
    CHECK_STORE_BOUNDS(i32_store8, 1);
    CHECK_STORE_BOUNDS(i32_store16, 2);
    CHECK_STORE_BOUNDS(i64_store8, 1);
    CHECK_STORE_BOUNDS(i64_store16, 2);
    CHECK_STORE_BOUNDS(i64_store32, 4);
    f32_store(memory, memory->size - 4, 7);
    CHECK_TRAP(f32_store(memory, memory->size - 3, 0), trapMemoryOutOfBounds);
    CHECK(f32_load(memory, memory->size - 4) == 7);
    f64_store(memory, memory->size - 8, 7);
    CHECK_TRAP(f64_store(memory, memory->size - 7, 0), trapMemoryOutOfBounds);
    CHECK(f64_load(memory, memory->size - 8) == 7);
}
#endif

static void testMemory(void) {
    m14_runtimeX5FchecksInstance instance;
    m14_runtimeX5FchecksInstance second;
    m14_runtimeX5FchecksInstance* child;
    wasmMemory empty = {0};
    m14_runtimeX5FchecksInstantiate(&instance, resolve);
    m14_runtimeX5FchecksInstantiate(&second, resolve);
    CHECK(memcmp(memory->data, "ABC", 3) == 0);
    m14_runtimeX5FchecksExport5_store(&instance, 0, 0x12345678);
    CHECK(m14_runtimeX5FchecksExport4_load(&instance, 0) == 0x12345678);
    m14_runtimeX5FchecksExport12_atomicX5Fstore(&instance, 8, 0);
    CHECK(m14_runtimeX5FchecksExport3_add(&instance, 8) == 0);
    CHECK(m14_runtimeX5FchecksExport11_atomicX5Fload(&instance, 8) == 1);
    CHECK(m14_runtimeX5FchecksExport7_cmpxchg(&instance, 8) == 1);
    m14_runtimeX5FchecksExport4_init(&instance, 16, 0, 4);
    CHECK(memcmp(memory->data + 16, "abcd", 4) == 0);
    m14_runtimeX5FchecksExport4_copy(&instance, 17, 16, 4);
    CHECK(memcmp(memory->data + 16, "aabcd", 5) == 0);
    m14_runtimeX5FchecksExport4_fill(&instance, 32, 0x1234, 4);
    CHECK(memory->data[35] == 0x34);
    m14_runtimeX5FchecksExport4_init(&instance, WASM_PAGE_SIZE, 4, 0);
    m14_runtimeX5FchecksExport4_copy(&instance, WASM_PAGE_SIZE, WASM_PAGE_SIZE, 0);
    m14_runtimeX5FchecksExport4_fill(&instance, WASM_PAGE_SIZE, 0, 0);
    wasmMemoryCopy(&empty, &empty, 0, 0, 0);
    wasmMemoryFill(&empty, 0, 0, 0);
    LOAD_DATA(empty, 0, NULL, 0);
    wasmMemoryInit(&empty, 0, NULL, 0, 0, 0);
#if W2C2_RUNTIME_CHECKS
    CHECK_TRAP(m14_runtimeX5FchecksExport4_load(&instance, UINT32_MAX), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport5_store(&instance, UINT32_MAX, 0), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport11_atomicX5Fload(&instance, UINT32_MAX - 7), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport12_atomicX5Fstore(&instance, UINT32_MAX - 7, 0), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport3_add(&instance, UINT32_MAX - 7), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport7_cmpxchg(&instance, UINT32_MAX - 7), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport4_init(&instance, 0, 3, 2), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport4_init(&instance, WASM_PAGE_SIZE - 1, 0, 2), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport4_init(&instance, 0, 5, 0), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport4_copy(&instance, 0, WASM_PAGE_SIZE - 1, 2), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport4_copy(&instance, WASM_PAGE_SIZE - 1, 0, 2), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport4_copy(&instance, 0, WASM_PAGE_SIZE + 1, 0), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport4_fill(&instance, WASM_PAGE_SIZE - 1, 0, 2), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport4_fill(&instance, WASM_PAGE_SIZE + 1, 0, 0), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport6_active(&instance, 0, 0, 1), trapMemoryOutOfBounds);
    CHECK(memory->data[0] == 'A' && memory->data[WASM_PAGE_SIZE - 1] == 0);
#endif
    m14_runtimeX5FchecksExport4_drop(&instance);
    m14_runtimeX5FchecksExport4_drop(&instance);
    m14_runtimeX5FchecksExport4_init(&instance, 0, 0, 0);
    m14_runtimeX5FchecksExport4_init(&second, 16, 0, 4);
    child = (m14_runtimeX5FchecksInstance*)instance.common.newChild(&instance.common);
    m14_runtimeX5FchecksExport4_init(child, 16, 0, 4);
    child->common.freeChild(&child->common);
#if W2C2_RUNTIME_CHECKS
    CHECK_TRAP(m14_runtimeX5FchecksExport4_init(&instance, 0, 0, 1), trapMemoryOutOfBounds);
    CHECK_TRAP(m14_runtimeX5FchecksExport4_init(&instance, 0, 1, 0), trapMemoryOutOfBounds);
#endif
    CHECK(wasmMemoryGrow(memory, 1) == 1);
    m14_runtimeX5FchecksExport5_store(&instance, WASM_PAGE_SIZE - 1, 42);
    CHECK(m14_runtimeX5FchecksExport4_load(&instance, WASM_PAGE_SIZE - 1) == 42);
    m14_runtimeX5FchecksFreeInstance(&second);
    m14_runtimeX5FchecksFreeInstance(&instance);
}

static void testSegments(void) {
    /* Static instances retain defined values after a trap returns through longjmp. */
    static m14_checkX5FsegmentsInstance instance;
    static m20_checkX5FemptyX5FsegmentsInstance emptyInstance;
    memoryOffset = 2 * WASM_PAGE_SIZE - 4;
    tableOffset = 0;
    wasmTableAllocate(&table, 2, 2);
    m14_checkX5FsegmentsInstantiate(&instance, resolve);
    CHECK(memcmp(memory->data + memoryOffset, "abcd", 4) == 0);
    m14_checkX5FsegmentsFreeInstance(&instance);
    memoryOffset = 2 * WASM_PAGE_SIZE;
    tableOffset = 2;
    m20_checkX5FemptyX5FsegmentsInstantiate(&emptyInstance, resolve);
    m20_checkX5FemptyX5FsegmentsFreeInstance(&emptyInstance);
#if W2C2_RUNTIME_CHECKS
    memoryOffset = 2 * WASM_PAGE_SIZE - 2;
    CHECK_TRAP(m14_checkX5FsegmentsInstantiate(&instance, resolve), trapMemoryOutOfBounds);
    CHECK(memcmp(memory->data + memoryOffset, "cd", 2) == 0);
    memoryOffset = 0;
    tableOffset = 1;
    table.data[1].func = NULL;
    CHECK_TRAP(m14_checkX5FsegmentsInstantiate(&instance, resolve), trapTableOutOfBounds);
    CHECK(table.data[1].func == NULL);
    tableOffset = UINT32_MAX;
    CHECK_TRAP(m14_checkX5FsegmentsInstantiate(&instance, resolve), trapTableOutOfBounds);
    tableOffset = 2;
    memoryOffset = 2 * WASM_PAGE_SIZE + 1;
    CHECK_TRAP(m20_checkX5FemptyX5FsegmentsInstantiate(&emptyInstance, resolve), trapMemoryOutOfBounds);
    memoryOffset = 0;
    tableOffset = 3;
    CHECK_TRAP(m20_checkX5FemptyX5FsegmentsInstantiate(&emptyInstance, resolve), trapTableOutOfBounds);
#endif
    wasmTableFree(&table);
    {
        wasmMemory* saved = memory;
        wasmMemory empty = {0};
        memory = &empty;
        memoryOffset = 0;
        tableOffset = 0;
        m20_checkX5FemptyX5FsegmentsInstantiate(&emptyInstance, resolve);
        m20_checkX5FemptyX5FsegmentsFreeInstance(&emptyInstance);
        memory = saved;
    }
}

int main(void) {
    memory = wasmMemoryAllocate(1, 2, false);
    testMemory();
    testSegments();
#if W2C2_RUNTIME_CHECKS
    testScalarBounds();
#endif
    wasmMemoryFree(memory);
    fprintf(stderr, "PASS runtime checks (%s)\n", W2C2_RUNTIME_CHECKS ? "checked" : "unchecked");
    return 0;
}
