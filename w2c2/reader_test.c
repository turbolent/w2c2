#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reader.h"
#include "reader_test.h"

#define CHECK_NAME(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testReadNames: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

typedef struct LimitsTest {
    const char* name;
    U8 bytes[7];
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
            0, 65536, UINT32_MAX, false, true},
        {"absent maximum with nonzero minimum", {0, 1}, 2,
            1, 65536, UINT32_MAX, false, true},
        {"full memory without maximum", {0, 0x80, 0x80, 0x04}, 4,
            65536, 65536, UINT32_MAX, false, true},
        {"full memory with maximum", {1, 0x80, 0x80, 0x04, 0x80, 0x80, 0x04}, 7,
            65536, 65536, 65536, false, true},
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

static
void
testReadNameCase(const U8* name, size_t length, unsigned int kind) {
    static const U8 prefix[] = {
        0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00
    };
    static const U8 body[] = {
        0x03, 0x02, 0x01, 0x00,
        0x06, 0x06, 0x01, 0x7F, 0x00, 0x41, 0x00, 0x0B,
        0x0A, 0x04, 0x01, 0x02, 0x00, 0x0B
    };
    U8 bytes[128];
    size_t offset = 0;
    size_t sectionSize;
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    WasmName actual = emptyWasmName;
    memcpy(bytes, prefix, sizeof(prefix));
    offset += sizeof(prefix);
    if (kind == 1 || kind == 2) {
        bytes[offset++] = 2;
        bytes[offset++] = (U8)(length + 6);
        bytes[offset++] = 1;
        if (kind == 2) {
            bytes[offset++] = 0;
        }
        bytes[offset++] = (U8)length;
        memcpy(bytes + offset, name, length);
        offset += length;
        if (kind == 1) {
            bytes[offset++] = 0;
        }
        bytes[offset++] = 3;
        bytes[offset++] = 0x7F;
        bytes[offset++] = 0;
    }
    memcpy(bytes + offset, body, sizeof(body) - 6);
    offset += sizeof(body) - 6;
    if (kind == 3) {
        bytes[offset++] = 7;
        bytes[offset++] = (U8)(length + 4);
        bytes[offset++] = 1;
        bytes[offset++] = (U8)length;
        memcpy(bytes + offset, name, length);
        offset += length;
        bytes[offset++] = 3;
        bytes[offset++] = 0;
    }
    memcpy(bytes + offset, body + sizeof(body) - 6, 6);
    offset += 6;
    if (kind == 0 || kind == 4) {
        bytes[offset++] = 0;
        sectionSize = offset++;
        if (kind == 4) {
            static const U8 nameHeader[] = {4, 'n', 'a', 'm', 'e', 1};
            memcpy(bytes + offset, nameHeader, sizeof(nameHeader));
            offset += sizeof(nameHeader);
            bytes[offset++] = (U8)(length + 3);
            bytes[offset++] = 1;
            bytes[offset++] = 0;
        }
        bytes[offset++] = (U8)length;
        memcpy(bytes + offset, name, length);
        offset += length;
        bytes[sectionSize] = (U8)(offset - sectionSize - 1);
    }
    reader.buffer.data = bytes;
    reader.buffer.length = offset;
    reader.debug = true;
    wasmModuleRead(&reader, &error);
    CHECK_NAME(error == NULL && reader.module != NULL);
    if (kind == 1) {
        actual = reader.module->globalImports.imports[0].module;
    } else if (kind == 2) {
        actual = reader.module->globalImports.imports[0].name;
    } else if (kind == 3) {
        actual = reader.module->exports.exports[0].name;
    } else if (kind == 4) {
        actual = reader.module->functionNames.names[0];
    }
    if (kind != 0) {
        memset(bytes, 0, sizeof(bytes));
        CHECK_NAME(actual.length == length);
        CHECK_NAME(memcmp(actual.data, name, length) == 0);
        CHECK_NAME(actual.data[length] == 0);
    }
    wasmModuleFree(reader.module);
}

static
void
testBinaryFunctionNames(void) {
    static U8 bytes[] = {
        0x00, 0x61, 0x73, 0x6D, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00,
        0x03, 0x05, 0x04, 0x00, 0x00, 0x00, 0x00,
        0x0A, 0x0D, 0x04,
        0x02, 0x00, 0x0B, 0x02, 0x00, 0x0B,
        0x02, 0x00, 0x0B, 0x02, 0x00, 0x0B,
        0x00, 0x1A, 0x04, 'n', 'a', 'm', 'e', 0x01, 0x13, 0x04,
        0x00, 0x03, 'f', 0x00, 'a',
        0x01, 0x03, 'f', 0x00, 'b',
        0x02, 0x03, 'f', 0x00, 'a',
        0x03, 0x01, 'f',
        /* These custom section names must not alias recognized sections. */
        0x00, 0x0B, 0x09, 'n', 'a', 'm', 'e', 0x00, 't', 'a', 'i', 'l', 0xFF,
        0x00, 0x12, 0x10, '.', 'd', 'e', 'b', 'u', 'g', '_', 'i', 'n', 'f', 'o',
        0x00, 't', 'a', 'i', 'l', 0xFF
    };
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    reader.buffer.data = bytes;
    reader.buffer.length = sizeof(bytes);
    reader.debug = true;
    wasmModuleRead(&reader, &error);
    CHECK_NAME(error == NULL && reader.module != NULL);
    CHECK_NAME(reader.module->debugSections.length == 0);
    CHECK_NAME(reader.module->functionNames.length == 4);
    CHECK_NAME(reader.module->functionNames.names[0].data == NULL);
    CHECK_NAME(reader.module->functionNames.names[2].data == NULL);
    CHECK_NAME(reader.module->functionNames.names[1].length == 3);
    CHECK_NAME(memcmp(reader.module->functionNames.names[1].data, "f\0b", 3) == 0);
    CHECK_NAME(reader.module->functionNames.names[3].length == 1);
    CHECK_NAME(reader.module->functionNames.names[3].data[0] == 'f');
    wasmModuleFree(reader.module);
}

void
testReadNames(void) {
    static const struct {
        U8 bytes[8];
        size_t length;
    } cases[] = {
        {{0}, 0},
        {{0}, 1},
        {{'a', 0, 'b', 0}, 4},
        {{'f', 'o', 'o'}, 3},
        {{0xC3, 0xA9, 0, 0xE2, 0x82, 0xAC}, 6},
        {{0, 0xF0, 0x9F, 0x98, 0x80, 0}, 6}
    };
    size_t index;
    for (index = 0; index < sizeof(cases) / sizeof(cases[0]); index++) {
        unsigned int kind;
        for (kind = 0; kind < 5; kind++) {
            testReadNameCase(cases[index].bytes, cases[index].length, kind);
        }
    }
    testBinaryFunctionNames();
    fprintf(stderr, "PASS testReadNames\n");
}
