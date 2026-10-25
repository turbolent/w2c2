#include <stdio.h>
#include "labelstack.h"
#include "labelstack_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testLabelStack: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

void
testLabelStack(void) {
    WasmLabelStack stack = wasmEmptyLabelStack;
    WasmValueType type = wasmValueTypeF64;
    WasmLabel label;
    WasmLabel* labels;
    size_t capacity;
    U32 index;

    for (index = 0; index < 1024; index++) {
        CHECK(wasmLabelStackPush(&stack, index, type, &label));
        CHECK(label.index == index && label.typeStackLength == index && label.type == type);
    }
    type = wasmValueTypeI32;
    CHECK(stack.labels.labels[0].type == wasmValueTypeF64);
    type = wasmValueTypeF64;
    wasmLabelStackPop(&stack);
    CHECK(stack.labels.length == 1023);
    CHECK(wasmLabelStackPush(&stack, 3, wasmValueType_count, &label));
    CHECK(label.index == 1024 && label.typeStackLength == 3 && label.type == wasmValueType_count);
    CHECK(wasmLabelStackGetTopIndex(&stack, 0) == 1023);
    CHECK(wasmLabelStackGetTopIndex(&stack, 1023) == 0);
    CHECK(stack.labels.labels[0].type == type);

    labels = stack.labels.labels;
    capacity = stack.labels.capacity;
    wasmLabelStackClear(&stack);
    CHECK(stack.labels.length == 0 && stack.nextLabelIndex == 0);
    CHECK(wasmLabelStackPush(&stack, 0, wasmValueType_count, &label));
    CHECK(stack.labels.labels[0].index == 0);
    CHECK(stack.labels.labels[0].typeStackLength == 0 && stack.labels.labels[0].type == wasmValueType_count);
    CHECK(wasmLabelStackPush(&stack, 5, type, &label));
    CHECK(stack.labels.labels[1].index == 1);
    CHECK(stack.labels.labels[1].typeStackLength == 5 && stack.labels.labels[1].type == type);
    CHECK(stack.labels.labels == labels && stack.labels.capacity == capacity);
    wasmLabelsFree(&stack.labels);
    fprintf(stderr, "PASS testLabelStack\n");
}
