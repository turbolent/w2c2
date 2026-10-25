#include <stdio.h>
#include "reader.h"
#include "function_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testFunctionIDs: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

void
testFunctionIDs(void) {
    static U8 bytes[] = {
        0, 97, 115, 109, 1, 0, 0, 0,
        1, 4, 1, 96, 0, 0,
        3, 6, 5, 0, 0, 0, 0, 0,
        10, 40, 5,
        5, 0, 0x41, 0, 0x1A, 0x0B,
        7, 1, 1, 0x7F, 0x20, 0, 0x1A, 0x0B,
        /* The same local and instructions with an extra zero-length group. */
        9, 2, 0, 0x7F, 1, 0x7F, 0x20, 0, 0x1A, 0x0B,
        7, 1, 1, 0x7F, 0x20, 0, 0x1A, 0x0B,
        /* The first function with a padded local-declaration count. */
        6, 0x80, 0, 0x41, 0, 0x1A, 0x0B
    };
    static const size_t offsets[] = {26, 32, 40, 50, 58};
    static const size_t lengths[] = {5, 7, 9, 7, 6};
    static const size_t starts[] = {3, 11, 21, 29, 36};
    static const U8 hashes[][SHA1_DIGEST_LENGTH] = {
        {0x88, 0x4D, 0x6F, 0xC2, 0xEC, 0xBF, 0xAC, 0xD6, 0x9F, 0x00,
         0xC5, 0x79, 0xF5, 0xAE, 0x04, 0xB9, 0xBE, 0x48, 0x18, 0x16},
        {0x04, 0x0B, 0x23, 0x76, 0x2A, 0x97, 0xEC, 0x11, 0x11, 0x39,
         0xF4, 0x6D, 0xFE, 0x1B, 0xA6, 0xF6, 0x5B, 0x93, 0xEF, 0x5C},
        {0x1D, 0xBD, 0x8B, 0x27, 0x37, 0xC4, 0x0B, 0x32, 0x59, 0x92,
         0x2F, 0x88, 0x9F, 0xA5, 0xF8, 0xFB, 0x2F, 0xB6, 0xDD, 0x5F},
        {0xE4, 0x06, 0xB5, 0xAA, 0x18, 0x96, 0x54, 0xC6, 0xB2, 0xD7,
         0x9D, 0x92, 0xF2, 0x07, 0xB4, 0xD5, 0xB2, 0x3F, 0x23, 0x64}
    };
    static const U32 hashIndices[] = {0, 1, 2, 1, 3};
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    unsigned int sorted;
    U32 index;

    reader.buffer.data = bytes;
    reader.buffer.length = sizeof(bytes);
    wasmModuleRead(&reader, &error);
    CHECK(error == NULL && reader.module->functions.count == 5);
    for (index = 0; index < 5; index++) {
        const WasmFunction function = reader.module->functions.functions[index];
        CHECK(function.body.data == bytes + offsets[index]);
        CHECK(function.body.length == lengths[index]);
        CHECK(function.code.data == function.body.data + lengths[index] - 4);
        CHECK(function.code.length == 4 && function.start == starts[index]);
    }

    for (sorted = 0; sorted < 2; sorted++) {
        WasmFunctionIDs ids = emptyWasmFunctionIDs;
        U32 seen = 0;
        CHECK(wasmFunctionIDsInitialize(reader.module->functions, sorted != 0, &ids));
        CHECK(ids.length == 5);
        for (index = 0; index < 5; index++) {
            const WasmFunctionID id = ids.functionIDs[index];
            CHECK(id.functionIndex < 5 && !(seen & (1U << id.functionIndex)));
            seen |= 1U << id.functionIndex;
            if (sorted) {
                CHECK(memcmp(id.hash, hashes[hashIndices[id.functionIndex]], SHA1_DIGEST_LENGTH) == 0);
                if (index > 0) {
                    CHECK(memcmp(ids.functionIDs[index - 1].hash, id.hash, SHA1_DIGEST_LENGTH) <= 0);
                    if (memcmp(ids.functionIDs[index - 1].hash, id.hash, SHA1_DIGEST_LENGTH) == 0) {
                        CHECK(ids.functionIDs[index - 1].functionIndex < id.functionIndex);
                    }
                }
            } else {
                CHECK(id.functionIndex == index);
                CHECK(memcmp(id.hash, emptyWasmFunctionID.hash, SHA1_DIGEST_LENGTH) == 0);
            }
        }
        wasmFunctionIDsFree(&ids);
        {
            const WasmFunctions emptyFunctions = {NULL, 0};
            CHECK(wasmFunctionIDsInitialize(emptyFunctions, sorted != 0, &ids));
            CHECK(ids.length == 0 && ids.capacity == 0 && ids.functionIDs == NULL);
            wasmFunctionIDsFree(&ids);
        }
    }
    wasmModuleFree(reader.module);
    fprintf(stderr, "PASS testFunctionIDs\n");
}
