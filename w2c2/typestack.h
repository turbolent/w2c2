#ifndef W2C2_TYPESTACK_H
#define W2C2_TYPESTACK_H

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

    typeStack->length -= count;
}

static
W2C2_INLINE
void
wasmTypeStackClear(
    WasmTypeStack* typeStack
) {
    typeStack->length = 0;
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
