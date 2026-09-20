#include <stdio.h>
#include "typestack.h"
#include "typestack_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testTypeStack: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

void
testTypeStack(void) {
    WasmTypeStack stack = wasmEmptyTypeStack;
    WasmValueType* values;
    size_t capacity;
    size_t index;

    CHECK(stack.length == 0);
    for (index = 0; index < 1024; index++) {
        CHECK(wasmTypeStackAppend(&stack, (WasmValueType)(index % wasmValueType_count)));
    }
    wasmTypeStackDrop(&stack, 512);
    CHECK(stack.length == 512);
    CHECK(wasmTypeStackAppend(&stack, wasmValueTypeF64));
    for (index = 0; index < 512; index++) {
        CHECK(stack.valueTypes[index] == (WasmValueType)(index % wasmValueType_count));
    }
    CHECK(stack.valueTypes[512] == wasmValueTypeF64);
    CHECK(wasmTypeStackGetTopIndex(&stack, 0) == 512);
    CHECK(wasmTypeStackGetTopIndex(&stack, 512) == 0);

    values = stack.valueTypes;
    capacity = stack.capacity;
    wasmTypeStackClear(&stack);
    CHECK(stack.length == 0 && stack.valueTypes == values && stack.capacity == capacity);
    CHECK(wasmTypeStackAppend(&stack, wasmValueTypeI64));
    CHECK(wasmTypeStackAppend(&stack, wasmValueTypeF32));
    wasmTypeStackDrop(&stack, 1);
    CHECK(wasmTypeStackAppend(&stack, wasmValueTypeF64));
    CHECK(stack.length == 2 && stack.valueTypes[0] == wasmValueTypeI64);
    CHECK(stack.valueTypes[1] == wasmValueTypeF64);
    CHECK(stack.valueTypes == values && stack.capacity == capacity);
    wasmTypeStackFree(&stack);
    CHECK(stack.length == 0 && stack.capacity == 0 && stack.valueTypes == NULL);
    fprintf(stderr, "PASS testTypeStack\n");
}
