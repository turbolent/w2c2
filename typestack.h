#ifndef W2C2_TYPESTACK_H
#define W2C2_TYPESTACK_H

#include <stdio.h>
#include "w2c2_base.h"
#include "valuetype.h"

typedef struct WasmTypeStack {
    WasmValueType* valueTypes;
    size_t length;
    size_t capacity;
} WasmTypeStack;

static const WasmTypeStack wasmEmptyTypeStack = {NULL, 0, 0};

void
wasmTypeStackFree(
    WasmTypeStack typeStack
);

bool
WARN_UNUSED_RESULT
wasmTypeStackEnsureCapacity(
    WasmTypeStack* typeStack,
    size_t length
);

static
__inline__
bool
WARN_UNUSED_RESULT
wasmTypeStackPush(
    WasmTypeStack* typeStack,
    const WasmValueType valueType
) {
    const size_t newLength = typeStack->length + 1;
    MUST (wasmTypeStackEnsureCapacity(typeStack, newLength))

    typeStack->valueTypes[typeStack->length] = valueType;
    typeStack->length = newLength;

    return true;
}

static
__inline__
void
wasmTypeStackDrop(
    WasmTypeStack* typeStack,
    size_t count
) {
    if (count > typeStack->length) {
        count = typeStack->length;
    }

    {
        size_t newLength = typeStack->length - count;

        U32 index = newLength;
        for (; index < typeStack->length; index++) {
            typeStack->valueTypes[index] = 0;
        }

        typeStack->length = newLength;
    }
}

static
__inline__
void
wasmTypeStackClear(
    WasmTypeStack* typeStack
) {
    U32 index = 0;
    for (; index < typeStack->capacity; index++) {
        typeStack->valueTypes[index] = 0;
    }

    typeStack->length = 0;
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmTypeStackSet(
    WasmTypeStack* typeStack,
    const U32 index,
    const WasmValueType valueType
) {
    const size_t currentLength = typeStack->length;
    const size_t newLength = index + 1;

    if (currentLength < newLength) {
        U32 newIndex = currentLength;
        MUST (wasmTypeStackEnsureCapacity(typeStack, newLength))
        for (; newIndex < newLength; newIndex++) {
            typeStack->valueTypes[newIndex] = 0;
        }
        typeStack->length = newLength;
    }

    typeStack->valueTypes[index] |= (1 << valueType);

    return true;
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmTypeStackIsSet(
    const WasmTypeStack* typeStack,
    const U32 index,
    const WasmValueType valueType
) {
    MUST (index < typeStack->length)
    {
        const WasmValueType entry = typeStack->valueTypes[index];
        return (entry & (1 << valueType)) != 0;
    }
}

static
__inline__
size_t
wasmTypeStackGetTopIndex(
    const WasmTypeStack* typeStack,
    const U32 index
) {
    return typeStack->length - 1 - index;
}

#endif /* W2C2_TYPESTACK_H */
