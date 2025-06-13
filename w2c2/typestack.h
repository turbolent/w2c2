#ifndef W2C2_TYPESTACK_H
#define W2C2_TYPESTACK_H

#include <assert.h>
#include "w2c2_base.h"
#include "valuetype.h"
#include "array.h"

ARRAY_TYPE(
    WasmTypeStack,
    WasmValueType,
    wasmTypeStack,
    valueTypes,
    valueType
)

static const WasmTypeStack wasmEmptyTypeStack = {0, 0, NULL};

static
W2C2_INLINE
void
wasmTypeStackDrop(
    WasmTypeStack* typeStack,
    size_t count
) {
    if (count > typeStack->length) {
        count = typeStack->length;
    }

    {
        const size_t newLength = typeStack->length - count;

        size_t index = newLength;
        for (; index < typeStack->length; index++) {
            typeStack->valueTypes[index] = 0;
        }

        typeStack->length = newLength;
    }
}

static
W2C2_INLINE
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
W2C2_INLINE
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
        size_t newIndex = currentLength;
        MUST (wasmTypeStackEnsureCapacity(typeStack, newLength))
        for (; newIndex < newLength; newIndex++) {
            typeStack->valueTypes[newIndex] = 0;
        }
        typeStack->length = newLength;
    }

    typeStack->valueTypes[index] |= (WasmValueType)(1 << valueType);

    return true;
}

static
W2C2_INLINE
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
W2C2_INLINE
U32
wasmTypeStackGetTopIndex(
    const WasmTypeStack* typeStack,
    const U32 index
) {
    return assertSizeU32(typeStack->length - 1 - index);
}

#endif /* W2C2_TYPESTACK_H */
