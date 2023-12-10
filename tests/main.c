#include <stdio.h>
#include "w2c2_base.h"

static U32 spectest_global_i32 = 666;

static U64 spectest_global_i64 = 666;

void spectest__print() {
    printf("spectest.print()\n");
}

void spectest__print_i32(U32 l0) {
    printf("spectest.print_i32(%u)\n", l0);
}

static wasmTable spectest_table;
static wasmMemory* spectest_memory;
static wasmMemory* spectest_shared_memory;

void*
resolveTestImports(
    const char* module,
    const char* name
) {
    if (strcmp(module, "spectest") != 0) {
        fprintf(stderr, "FAIL: import of unknown module: %s\n", module);
        return NULL;
    }

    if (strcmp(name, "table") == 0) {
        return (void*)&spectest_table;
    }

    if (strcmp(name, "memory") == 0) {
        return (void*)&spectest_memory;
    }

    if (strcmp(name, "global_i32") == 0) {
        return (void*)&spectest_global_i32;
    }

    if (strcmp(name, "global_i64") == 0) {
        return (void*)&spectest_global_i64;
    }

    if (strcmp(name, "shared_memory") == 0) {
        return (void*)&spectest_shared_memory;
    }

    fprintf(stderr, "FAIL: import of unknown spectest item: %s\n", name);

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

void assertEqualF32(
    F32 actual,
    F32 expected,
    const char *description
) {
    if (actual != expected) {
        fprintf(stderr, "FAIL: %s: %f != %f\n", description, actual, expected);
    } else {
        fprintf(stderr, "OK: %s\n", description);
    }
}

void assertEqualF64(
    F64 actual,
    F64 expected,
    const char *description
) {
    if (actual != expected) {
        fprintf(stderr, "FAIL: %s: %f != %f\n", description, actual, expected);
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
