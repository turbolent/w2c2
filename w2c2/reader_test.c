#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reader.h"
#include "reader_test.h"

typedef struct LimitsTest {
    const char* name;
    U8 bytes[5];
    size_t length;
    U32 min;
    U32 memoryMax;
    U32 tableMax;
    WasmBool shared;
    WasmBool valid;
} LimitsTest;

static
WasmBool
testReadLimitCase(
    const LimitsTest* test,
    WasmBool memory,
    WasmBool imported
) {
    U8 bytes[32] = {0x00, 0x61, 0x73, 0x6d, 0x01, 0x00, 0x00, 0x00, 0, 0, 1};
    size_t length = 11;
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    U32 min = 0;
    U32 max = 0;
    WasmBool shared = false;
    WasmBool passed;

    bytes[8] = imported ? 2 : memory ? 5 : 4;
    if (imported) {
        /* Empty module and field names. */
        bytes[length++] = 0;
        bytes[length++] = 0;
        bytes[length++] = memory ? 2 : 1;
    }
    if (!memory) {
        bytes[length++] = 0x70;
    }
    memcpy(bytes + length, test->bytes, test->length);
    length += test->length;
    bytes[9] = (U8)(length - 10);
    reader.buffer.data = bytes;
    reader.buffer.length = length;
    wasmModuleRead(&reader, &error);

    if (!test->valid) {
        passed = error != NULL
            && error->code == wasmModuleReaderInvalidLimitMaximum
            && reader.module == NULL;
    } else if (error != NULL || reader.module == NULL) {
        passed = false;
    } else {
        if (memory && imported) {
            const WasmMemoryImport* value = reader.module->memoryImports.imports;
            min = value->min;
            max = value->max;
            shared = value->shared;
        } else if (memory) {
            const WasmMemory* value = reader.module->memories.memories;
            min = value->min;
            max = value->max;
            shared = value->shared;
        } else if (imported) {
            const WasmTableImport* value = reader.module->tableImports.imports;
            min = value->min;
            max = value->max;
            shared = value->shared;
        } else {
            const WasmTable* value = reader.module->tables.tables;
            min = value->min;
            max = value->max;
            shared = value->shared;
        }
        passed = min == test->min
            && max == (memory ? test->memoryMax : test->tableMax)
            && shared == test->shared;
    }

    wasmModuleFree(reader.module);
    if (!passed) {
        fprintf(
            stderr,
            "FAIL testReadLimits: %s %s: %s\n",
            imported ? "imported" : "defined",
            memory ? "memory" : "table",
            test->name
        );
    }
    return passed;
}

void
testReadLimits(void) {
    static const LimitsTest tests[] = {
        {"absent maximum", {0, 0}, 2,
            0, UINT32_MAX / WASM_PAGE_SIZE, UINT32_MAX, false, true},
        {"absent maximum with nonzero minimum", {0, 1}, 2,
            1, UINT32_MAX / WASM_PAGE_SIZE, UINT32_MAX, false, true},
        {"zero maximum", {1, 0, 0}, 3, 0, 0, 0, false, true},
        {"positive maximum", {1, 0, 1}, 3, 0, 1, 1, false, true},
        {"equal bounds", {1, 1, 1}, 3, 1, 1, 1, false, true},
        {"multibyte bounds", {1, 0x80, 1, 0x81, 1}, 5,
            128, 129, 129, false, true},
        {"minimum above zero maximum", {1, 1, 0}, 3,
            0, 0, 0, false, false},
        {"minimum above positive maximum", {1, 2, 1}, 3,
            0, 0, 0, false, false},
        {"truncated maximum", {1, 0}, 2, 0, 0, 0, false, false},
        {"shared zero maximum", {3, 0, 0}, 3, 0, 0, 0, true, true},
        {"shared positive maximum", {3, 1, 2}, 3, 1, 2, 2, true, true},
        {"shared equal bounds", {3, 1, 1}, 3, 1, 1, 1, true, true},
        {"shared minimum above zero maximum", {3, 1, 0}, 3,
            0, 0, 0, true, false},
        {"shared minimum above positive maximum", {3, 2, 1}, 3,
            0, 0, 0, true, false},
        {"shared truncated maximum", {3, 0}, 2, 0, 0, 0, true, false}
    };
    size_t index;
    WasmBool passed = true;

    for (index = 0; index < sizeof(tests) / sizeof(tests[0]); index++) {
        const LimitsTest* test = &tests[index];
        if (!testReadLimitCase(test, true, false)) {
            passed = false;
        }
        if (!testReadLimitCase(test, true, true)) {
            passed = false;
        }
        if (!test->shared) {
            if (!testReadLimitCase(test, false, false)) {
                passed = false;
            }
            if (!testReadLimitCase(test, false, true)) {
                passed = false;
            }
        }
    }
    if (!passed) {
        exit(1);
    }
    fprintf(stderr, "PASS testReadLimits\n");
}
