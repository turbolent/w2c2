#include <stdio.h>
#include "stackdeclarations.h"
#include "stackdeclarations_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testStackDeclarations: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

void
testStackDeclarations(void) {
    static const U8 expected[] = {
        1 << wasmValueTypeF64,
        (1 << wasmValueTypeI64) | (1 << wasmValueTypeI32),
        0,
        1 << wasmValueTypeF32,
        0,
        1 << wasmValueTypeI32
    };
    WasmStackDeclarations declarations = wasmEmptyStackDeclarations;
    U8* masks;
    size_t capacity;
    U32 index;

    CHECK(declarations.length == 0);
    CHECK(!wasmStackDeclarationsIsSet(&declarations, 0, wasmValueTypeI32));
    CHECK(wasmStackDeclarationsSet(&declarations, 1, wasmValueTypeI64));
    CHECK(wasmStackDeclarationsSet(&declarations, 5, wasmValueTypeI32));
    CHECK(wasmStackDeclarationsSet(&declarations, 0, wasmValueTypeF64));
    CHECK(wasmStackDeclarationsSet(&declarations, 3, wasmValueTypeF32));
    CHECK(wasmStackDeclarationsSet(&declarations, 1, wasmValueTypeI32));
    CHECK(declarations.length == sizeof(expected));
    for (index = 0; index < sizeof(expected); index++) {
        WasmValueType type;
        CHECK(declarations.typeMasks[index] == expected[index]);
        for (type = 0; type < wasmValueType_count; type++) {
            CHECK(wasmStackDeclarationsIsSet(&declarations, index, type)
                == ((expected[index] & (1U << type)) != 0));
        }
    }

    CHECK(wasmStackDeclarationsSet(&declarations, 4095, wasmValueTypeF64));
    CHECK(memcmp(declarations.typeMasks, expected, sizeof(expected)) == 0);
    for (index = sizeof(expected); index < 4095; index++) {
        CHECK(declarations.typeMasks[index] == 0);
    }
    masks = declarations.typeMasks;
    capacity = declarations.capacity;
    wasmStackDeclarationsClear(&declarations);
    CHECK(declarations.length == 0);
    CHECK(!wasmStackDeclarationsIsSet(&declarations, 4095, wasmValueTypeF64));

    /* A short function followed by a large one must not inherit any masks. */
    CHECK(wasmStackDeclarationsSet(&declarations, 1, wasmValueTypeF32));
    CHECK(declarations.length == 2 && declarations.typeMasks[0] == 0);
    CHECK(declarations.typeMasks[1] == (1 << wasmValueTypeF32));
    wasmStackDeclarationsClear(&declarations);
    CHECK(wasmStackDeclarationsSet(&declarations, 4095, wasmValueTypeI64));
    CHECK(declarations.length == 4096);
    for (index = 0; index < 4095; index++) {
        CHECK(declarations.typeMasks[index] == 0);
    }
    CHECK(declarations.typeMasks[4095] == (1 << wasmValueTypeI64));
    CHECK(declarations.typeMasks == masks && declarations.capacity == capacity);
    wasmStackDeclarationsFree(&declarations);
    CHECK(declarations.length == 0 && declarations.capacity == 0 && declarations.typeMasks == NULL);
    fprintf(stderr, "PASS testStackDeclarations\n");
}
