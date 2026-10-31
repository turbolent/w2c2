#include <stdio.h>
#include "valuetype_test.h"
#include "valuetype.h"

void
testBlockSignatures(void) {
    typedef struct {
        U8 data[int33LEB128MaxByteCount];
        size_t length;
        bool valid;
        WasmBlockSignature expected;
    } testCase;
    const testCase testCases[] = {
        {{0x40}, 1, true, {false, 0, wasmValueType_count}},
        {{0x7F}, 1, true, {false, 0, wasmValueTypeI32}},
        {{0x7E}, 1, true, {false, 0, wasmValueTypeI64}},
        {{0x7D}, 1, true, {false, 0, wasmValueTypeF32}},
        {{0x7C}, 1, true, {false, 0, wasmValueTypeF64}},
        {{0x7B}, 1, true, {false, 0, wasmValueTypeV128}},
        {{0xC0, 0x7F}, 2, true, {false, 0, wasmValueType_count}},
        {{0xFF, 0x7F}, 2, true, {false, 0, wasmValueTypeI32}},
        {{0x00}, 1, true, {true, 0, wasmValueType_count}},
        {{0x3F}, 1, true, {true, 63, wasmValueType_count}},
        {{0xC0, 0x00}, 2, true, {true, 64, wasmValueType_count}},
        {{0xFF, 0xFF, 0xFF, 0xFF, 0x0F}, 5, true, {true, UINT32_MAX, wasmValueType_count}},
        {{0x7A}, 1, false, {false, 0, wasmValueType_count}},
        {{0x70}, 1, true, {false, 0, wasmValueTypeFuncRef}},
        {{0x6F}, 1, false, {false, 0, wasmValueType_count}},
        {{0x80, 0x80, 0x80, 0x80, 0x78}, 5, false, {false, 0, wasmValueType_count}},
        {{0xFF, 0xFF, 0xFF, 0xFF, 0x77}, 5, false, {false, 0, wasmValueType_count}},
        {{0x80, 0x80, 0x80, 0x80, 0x70}, 5, false, {false, 0, wasmValueType_count}},
        {{0x00}, 0, false, {false, 0, wasmValueType_count}},
        {{0x80}, 1, false, {false, 0, wasmValueType_count}},
        {{0x80, 0x80, 0x80, 0x80, 0x10}, 5, false, {false, 0, wasmValueType_count}}
    };
    size_t i;
    for (i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        testCase test = testCases[i];
        Buffer buffer;
        WasmBlockSignature actual;
        bool valid;
        buffer.data = test.data;
        buffer.length = test.length;
        valid = wasmReadBlockSignature(&buffer, &actual);
        if (valid != test.valid || (valid &&
            (actual.indexed != test.expected.indexed
            || actual.typeIndex != test.expected.typeIndex
            || actual.type != test.expected.type
            || buffer.length != 0))) {
            fprintf(stderr, "FAIL testBlockSignatures: case %u\n", (unsigned)i);
            exit(1);
        }
    }
    fprintf(stderr, "PASS testBlockSignatures\n");
}
