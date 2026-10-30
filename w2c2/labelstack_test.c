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
    WasmBlockSignature signature = {false, 0, wasmValueTypeF64};
    WasmLabel label;
    WasmLabel* labels;
    size_t capacity;
    U32 index;

    for (index = 0; index < 1024; index++) {
        CHECK(wasmLabelStackPush(&stack, index, signature, false, &label));
        CHECK(label.index == index && label.typeStackLength == index);
        CHECK(!label.signature.indexed && label.signature.type == signature.type);
        CHECK(!label.parameters && !label.branched);
    }
    signature.type = wasmValueTypeI32;
    CHECK(stack.labels.labels[0].signature.type == wasmValueTypeF64);
    wasmLabelStackPop(&stack);
    CHECK(stack.labels.length == 1023);
    CHECK(wasmLabelStackPush(&stack, 3, wasmEmptyBlockSignature, false, &label));
    CHECK(label.index == 1024 && label.typeStackLength == 3);
    CHECK(!label.signature.indexed && label.signature.type == wasmValueType_count);
    CHECK(wasmLabelStackGetTopIndex(&stack, 0) == 1023);
    CHECK(wasmLabelStackGetTopIndex(&stack, 1023) == 0);

    labels = stack.labels.labels;
    capacity = stack.labels.capacity;
    stack.labels.labels[0].branched = true;
    wasmLabelStackClear(&stack);
    CHECK(stack.labels.length == 0 && stack.nextLabelIndex == 0);
    CHECK(wasmLabelStackPush(&stack, 0, wasmEmptyBlockSignature, false, &label));
    CHECK(stack.labels.labels[0].index == 0);
    CHECK(stack.labels.labels[0].typeStackLength == 0);
    CHECK(stack.labels.labels[0].signature.type == wasmValueType_count);
    CHECK(!stack.labels.labels[0].branched);
    signature.indexed = true;
    signature.typeIndex = 7;
    CHECK(wasmLabelStackPush(&stack, 5, signature, true, &label));
    CHECK(stack.labels.labels[1].index == 1);
    CHECK(stack.labels.labels[1].typeStackLength == 5);
    CHECK(stack.labels.labels[1].signature.indexed && stack.labels.labels[1].signature.typeIndex == 7);
    CHECK(stack.labels.labels[1].parameters);
    CHECK(stack.labels.labels == labels && stack.labels.capacity == capacity);
    wasmLabelsFree(&stack.labels);
    fprintf(stderr, "PASS testLabelStack\n");
}
