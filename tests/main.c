#include <stdio.h>
#include "w2c2_base.h"

static U32 spectest_global_i32 = 666;

U32 *g_spectest_globalX5Fi32 = &spectest_global_i32;

static U64 spectest_global_i64 = 666;

U64 *g_spectest_globalX5Fi64 = &spectest_global_i64;

static void spectest_print() {
    printf("spectest.print()\n");
}

void (*f_spectest_print)(void) = &spectest_print;

static void spectest_printX5Fi32(U32 l0) {
    printf("spectest.print_i32(%d)\n", l0);
}

void (*f_spectest_printX5Fi32)(U32 l0) = &spectest_printX5Fi32;

static wasmTable spectest_table;
static wasmMemory spectest_memory;

wasmTable* t_spectest_table = &spectest_table;
wasmMemory* m_spectest_memory = &spectest_memory;

void trap(Trap trap) {}

void assertEqualU32(
    U32 actual,
    U32 expected,
    const char *description
) {
    if (actual != expected) {
        fprintf(stderr, "FAIL: %s: %d != %d\n", description, actual, expected);
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
        fprintf(stderr, "FAIL: %s: %lld != %lld\n", description, actual, expected);
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
    wasmAllocateMemory(&spectest_memory, 1, 2);
    wasmAllocateTable(&spectest_table, 10, 20);
}

extern void init(void);
extern void test(void);

int main() {
    initTest();
    init();
    test();
    return 0;
}
