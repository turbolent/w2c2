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

ARRAY_TYPE(
    WasmLabels,
    WasmLabel,
    wasmLabels,
    labels,
    label
)

typedef struct WasmLabelStack {
    WasmLabels labels;
    U32 nextLabelIndex;
} WasmLabelStack;

static const WasmLabelStack wasmEmptyLabelStack = {{0, 0, NULL}, 0};

static
W2C2_INLINE
void
wasmLabelStackClear(
    WasmLabelStack* labelStack
) {
    U32 index = 0;
    for (; index < labelStack->labels.capacity; index++) {
        labelStack->labels.labels[index] = wasmEmptyLabel;
    }

    labelStack->labels.length = 0;
    labelStack->nextLabelIndex = 0;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmLabelStackPush(
    WasmLabelStack* labelStack,
    const size_t typeStackLength,
    WasmValueType* type,
    WasmLabel* result
) {
    result->index = labelStack->nextLabelIndex;
    result->typeStackLength = typeStackLength;
    result->type = type;

    MUST (wasmLabelsAppend(&labelStack->labels, *result))

    labelStack->nextLabelIndex++;

    return true;
}

static
W2C2_INLINE
void
wasmLabelStackPop(
    WasmLabelStack* labelStack
) {
    if (!labelStack->labels.length) {
        return;
    }

    labelStack->labels.length--;
}

static
W2C2_INLINE
U32
wasmLabelStackGetTopIndex(
    const WasmLabelStack* labelStack,
    const U32 index
) {
    return assertSizeU32(labelStack->labels.length - 1 - index);
}

#endif /* W2C2_LABELSTACK_H */
