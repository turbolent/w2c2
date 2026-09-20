#include <stdio.h>
#include "reader.h"
#include "locals_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testLocals: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

void
testLocals(void) {
    static U8 bytes[] = {
        0, 97, 115, 109, 1, 0, 0, 0,
        1, 11, 2, 96, 0, 0, 96, 4, 0x7F, 0x7E, 0x7D, 0x7C, 0,
        3, 5, 4, 0, 1, 1, 0,
        10, 33, 4,
        2, 0, 0x0B,
        2, 0, 0x0B,
        /* Zero-length groups precede, separate, and follow nonempty groups. */
        18, 8, 0, 0x7C, 2, 0x7F, 0, 0x7D, 3, 0x7E,
        1, 0x7D, 0, 0x7F, 2, 0x7C, 0, 0x7E, 0x0B,
        6, 2, 0, 0x7F, 0, 0x7C, 0x0B
    };
    static const WasmValueType types[] = {
        wasmValueTypeI32, wasmValueTypeI64, wasmValueTypeF32, wasmValueTypeF64,
        wasmValueTypeI32, wasmValueTypeI32,
        wasmValueTypeI64, wasmValueTypeI64, wasmValueTypeI64,
        wasmValueTypeF32, wasmValueTypeF64, wasmValueTypeF64
    };
    static const U32 ends[] = {0, 2, 2, 5, 6, 6, 8, 8};
    static WasmLocalsDeclaration largeRanges[] = {
        {wasmValueTypeI32, 1},
        {wasmValueTypeI64, 0x80000000U},
        {wasmValueTypeF32, 0x80000001U},
        {wasmValueTypeF64, UINT32_MAX}
    };
    static const U32 indices[] = {
        0, 1, 0x7FFFFFFFU, 0x80000000U, 0x80000001U, UINT32_MAX - 1
    };
    static const WasmValueType largeTypes[] = {
        wasmValueTypeI32, wasmValueTypeI64, wasmValueTypeI64,
        wasmValueTypeF32, wasmValueTypeF64, wasmValueTypeF64
    };
    const WasmLocalsDeclarations largeLocals = {largeRanges, 4};
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    U32 index;

    reader.buffer.data = bytes;
    reader.buffer.length = sizeof(bytes);
    wasmModuleRead(&reader, &error);
    CHECK(error == NULL && reader.module->functions.count == 4);
    CHECK(reader.module->functions.functions[0].localsDeclarations.declarationCount == 0);
    CHECK(reader.module->functions.functions[1].localsDeclarations.declarationCount == 0);
    CHECK(reader.module->functions.functions[2].localsDeclarations.declarationCount == 8);
    for (index = 0; index < 8; index++) {
        CHECK(reader.module->functions.functions[2].localsDeclarations.declarations[index].endIndex == ends[index]);
    }
    for (index = 0; index < 12; index++) {
        WasmValueType type;
        CHECK(wasmModuleFunctionGetLocalType(reader.module, reader.module->functions.functions[2], index, &type));
        CHECK(type == types[index]);
        if (index < 4) {
            CHECK(wasmModuleFunctionGetLocalType(reader.module, reader.module->functions.functions[1], index, &type));
            CHECK(type == types[index]);
        }
    }
    CHECK(reader.module->functions.functions[3].localsDeclarations.declarationCount == 2);
    for (index = 0; index < 2; index++) {
        CHECK(reader.module->functions.functions[3].localsDeclarations.declarations[index].endIndex == 0);
    }
    wasmModuleFree(reader.module);

    for (index = 0; index < sizeof(indices) / sizeof(indices[0]); index++) {
        WasmValueType type;
        CHECK(wasmLocalsDeclarationsGetType(largeLocals, indices[index], &type));
        CHECK(type == largeTypes[index]);
    }
    fprintf(stderr, "PASS testLocals\n");
}
