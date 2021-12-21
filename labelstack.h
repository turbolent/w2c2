#ifndef W2C2_LABELSTACK_H
#define W2C2_LABELSTACK_H

#include <stdio.h>
#include "w2c2_base.h"
#include "valuetype.h"

typedef struct WasmLabel {
    U32 index;
    size_t typeStackLength;
    WasmValueType* type;
} WasmLabel;

static const WasmLabel wasmEmptyLabel = {0, 0, NULL};

typedef struct WasmLabelStack {
    WasmLabel* labels;
    U32 nextLabelIndex;
    size_t length;
    size_t capacity;
} WasmLabelStack;

static const WasmLabelStack wasmEmptyLabelStack = {NULL, 0, 0, 0};

void
wasmLabelStackFree(
    WasmLabelStack labelStack
);

bool
WARN_UNUSED_RESULT
wasmLabelStackEnsureCapacity(
    WasmLabelStack* labelStack,
    size_t length
);

static
__inline__
void
wasmLabelStackClear(
    WasmLabelStack* labelStack
) {
    U32 index = 0;
    for (; index < labelStack->capacity; index++) {
        labelStack->labels[index] = wasmEmptyLabel;
    }

    labelStack->length = 0;
    labelStack->nextLabelIndex = 0;
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmLabelStackPush(
    WasmLabelStack* labelStack,
    size_t typeStackLength,
    WasmValueType* type,
    WasmLabel* result
) {
    const size_t currentLength = labelStack->length;
    const size_t newLength = currentLength + 1;

    MUST (wasmLabelStackEnsureCapacity(labelStack, newLength))
    {
        const size_t labelIndex = labelStack->nextLabelIndex++;

        result->index = labelIndex;
        result->typeStackLength = typeStackLength;
        result->type = type;

        labelStack->labels[currentLength] = *result;
        labelStack->length = newLength;
    }
    return true;
}

static
__inline__
void
wasmLabelStackPop(
    WasmLabelStack* labelStack
) {
    if (!labelStack->length) {
        return;
    }

    labelStack->length--;
}

static
__inline__
size_t
wasmLabelStackGetTopIndex(
    const WasmLabelStack* labelStack,
    const U32 index
) {
    return labelStack->length - 1 - index;
}

#endif /* W2C2_LABELSTACK_H */
