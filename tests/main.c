#include <stdio.h>
#include "w2c2_base.h"

static U32 spectest_global_i32 = 666;

static U64 spectest_global_i64 = 666;

void i8_spectest5_print(wasmModuleInstance* instance) {
    UNUSED_PARAMETER(instance);
    printf("spectest.print()\n");
}

void i8_spectest9_printX5Fi32(wasmModuleInstance* instance, U32 l0) {
    UNUSED_PARAMETER(instance);
    printf("spectest.print_i32(%u)\n", l0);
}

static wasmTable spectest_table;
static wasmMemory* spectest_memory;
static wasmMemory* spectest_shared_memory;

void*
resolveTestImports(
    WasmName module,
    WasmName name
) {
    if (module.length != sizeof("spectest") - 1
        || memcmp(module.data, "spectest", module.length) != 0) {
        fprintf(stderr, "FAIL: import of unknown module: %s\n", module.data);
        return NULL;
    }

    if (name.length == sizeof("table") - 1
        && memcmp(name.data, "table", name.length) == 0) {
        return (void*)&spectest_table;
    }

    if (name.length == sizeof("memory") - 1
        && memcmp(name.data, "memory", name.length) == 0) {
        return (void*)spectest_memory;
    }

    if (name.length == sizeof("global_i32") - 1
        && memcmp(name.data, "global_i32", name.length) == 0) {
        return (void*)&spectest_global_i32;
    }

    if (name.length == sizeof("global_i64") - 1
        && memcmp(name.data, "global_i64", name.length) == 0) {
        return (void*)&spectest_global_i64;
    }

    if (name.length == sizeof("shared_memory") - 1
        && memcmp(name.data, "shared_memory", name.length) == 0) {
        return (void*)spectest_shared_memory;
    }

    fprintf(stderr, "FAIL: import of unknown spectest item: %s\n", name.data);

    return NULL;
}

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

void assertEqualU32(
    U32 actual,
    U32 expected,
    const char *description
) {
    if (actual != expected) {
        fprintf(stderr, "FAIL: %s: %u != %u\n", description, actual, expected);
    } else {
        fprintf(stderr, "OK: %s\n", description);
    }
}

void assertEqualU64(
    U64 actual,
    U64 expected,
    const char *description
) {
    if (actual != expected) {
        fprintf(stderr, "FAIL: %s: %llu != %llu\n", description, actual, expected);
    } else {
        fprintf(stderr, "OK: %s\n", description);
    }
}

void printStart(const char* name) {
    fprintf(stderr, "START: %s\n", name);
}

void printOK(const char* description) {
    fprintf(stderr, "OK: %s\n", description);
}

static void initTest() {
    spectest_memory = wasmMemoryAllocate(1, 2, false);
    spectest_shared_memory = WASM_MEMORY_ALLOCATE_SHARED(1, 2);
    wasmTableAllocate(&spectest_table, 10, 20);
}

extern void test(void);

int main() {
    initTest();
    test();
    return 0;
}
