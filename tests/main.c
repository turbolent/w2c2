#include <stdio.h>
#include "test.h"

jmp_buf testTrapTarget;
int testTrapExpected;

typedef struct TestImport {
    const char* module;
    const char* name;
    void* value;
    struct TestImport* next;
} TestImport;

static TestImport* testImports;

typedef struct TestExternRef {
    U32 id;
    struct TestExternRef* next;
} TestExternRef;

static TestExternRef* testExternRefs;

wasmExternRef
testExternRef(const U32 id) {
    TestExternRef* ref;
    for (ref = testExternRefs; ref != NULL; ref = ref->next) {
        if (ref->id == id) {
            return ref;
        }
    }
    ref = (TestExternRef*)malloc(sizeof(TestExternRef));
    if (ref == NULL) {
        abort();
    }
    ref->id = id;
    ref->next = testExternRefs;
    testExternRefs = ref;
    return ref;
}

void
bindTestImport(const char* module, const char* name, void* value) {
    TestImport* binding = (TestImport*)malloc(sizeof(TestImport));
    if (binding == NULL) {
        abort();
    }
    binding->module = module;
    binding->name = name;
    binding->value = value;
    binding->next = testImports;
    testImports = binding;
}

static U32 spectest_global_i32 = 666;

static U64 spectest_global_i64 = 666;

static F32 spectest_global_f32 = 666.6f;

static F64 spectest_global_f64 = 666.6;

static wasmExternRef spectest_global_externref;

void i8_spectest5_print(wasmModuleInstance* instance) {
    UNUSED_PARAMETER(instance);
    printf("spectest.print()\n");
}

void i8_spectest9_printX5Fi32(wasmModuleInstance* instance, U32 l0) {
    UNUSED_PARAMETER(instance);
    printf("spectest.print_i32(%u)\n", l0);
}

void i8_spectest9_printX5Fi64(wasmModuleInstance* instance, U64 l0) {
    UNUSED_PARAMETER(instance);
    printf("spectest.print_i64(%llu)\n", l0);
}

void i8_spectest9_printX5Ff32(wasmModuleInstance* instance, F32 l0) {
    UNUSED_PARAMETER(instance);
    printf("spectest.print_f32(%g)\n", l0);
}

void i8_spectest9_printX5Ff64(wasmModuleInstance* instance, F64 l0) {
    UNUSED_PARAMETER(instance);
    printf("spectest.print_f64(%g)\n", l0);
}

void i8_spectest13_printX5Fi32X5Ff32(wasmModuleInstance* instance, U32 l0, F32 l1) {
    UNUSED_PARAMETER(instance);
    printf("spectest.print_i32_f32(%u, %g)\n", l0, l1);
}

void i8_spectest13_printX5Ff64X5Ff64(wasmModuleInstance* instance, F64 l0, F64 l1) {
    UNUSED_PARAMETER(instance);
    printf("spectest.print_f64_f64(%g, %g)\n", l0, l1);
}

static wasmTable spectest_table;
static wasmMemory* spectest_memory;
static wasmMemory* spectest_shared_memory;

void*
resolveTestImports(
    WasmName module,
    WasmName name
) {
    TestImport* binding;
    for (binding = testImports; binding != NULL; binding = binding->next) {
        if (strlen(binding->module) == module.length
            && memcmp(binding->module, module.data, module.length) == 0
            && strlen(binding->name) == name.length
            && memcmp(binding->name, name.data, name.length) == 0) {
            return binding->value;
        }
    }
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

    if (name.length == sizeof("global_f32") - 1
        && memcmp(name.data, "global_f32", name.length) == 0) {
        return (void*)&spectest_global_f32;
    }

    if (name.length == sizeof("global_f64") - 1
        && memcmp(name.data, "global_f64", name.length) == 0) {
        return (void*)&spectest_global_f64;
    }

    if (name.length == sizeof("global_externref") - 1
        && memcmp(name.data, "global_externref", name.length) == 0) {
        spectest_global_externref = testExternRef(0);
        return &spectest_global_externref;
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
    if (testTrapExpected) {
        longjmp(testTrapTarget, 1);
    }
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

void printFail(const char* description) {
    fprintf(stderr, "FAIL: %s\n", description);
}

#ifdef W2C2_SIMDE_HEADER
void assertEqualV128(
    V128 actual,
    const U8* expected,
    const U8* masks,
    const char* description
) {
    U8 bytes[16];
    wasmMemory memory;
    size_t index;
    memory.data = bytes;
    memory.size = sizeof(bytes);
    w2c2_v128_store(&memory, 0, actual);
    for (index = 0; index < sizeof(bytes); index++) {
        if ((bytes[index] & masks[index]) != expected[index]) {
            printFail(description);
            return;
        }
    }
    printOK(description);
}
#endif

static void initTest() {
    spectest_memory = wasmMemoryAllocate(1, 2, false);
#if defined(WASM_THREADS_PTHREADS) || defined(WASM_THREADS_WIN32)
    spectest_shared_memory = WASM_MEMORY_ALLOCATE_SHARED(1, 2);
#endif
    wasmTableAllocate(&spectest_table, 10, 20);
}

extern void test(void);

int main() {
    initTest();
    test();
    while (testImports != NULL) {
        TestImport* binding = testImports;
        testImports = binding->next;
        free(binding);
    }
    while (testExternRefs != NULL) {
        TestExternRef* ref = testExternRefs;
        testExternRefs = ref->next;
        free(ref);
    }
    return 0;
}
