#ifndef W2C2_STACKDECLARATIONS_H
#define W2C2_STACKDECLARATIONS_H

#include <string.h>
#include "array.h"
#include "valuetype.h"

/* Each stack slot records the types used there across the entire function. */
ARRAY_TYPE(
    WasmStackDeclarations,
    U8,
    wasmStackDeclarations,
    typeMasks,
    typeMask
)

static const WasmStackDeclarations wasmEmptyStackDeclarations = {0, 0, NULL};

static
W2C2_INLINE
void
wasmStackDeclarationsClear(WasmStackDeclarations* declarations) {
    declarations->length = 0;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmStackDeclarationsSet(
    WasmStackDeclarations* declarations,
    const U32 index,
    const WasmValueType valueType
) {
    size_t newLength;
    MUST (arrayLengthAdd(index, 1, &newLength))
    if (newLength > declarations->length) {
        MUST (wasmStackDeclarationsEnsureCapacity(declarations, newLength))
        /* Clear newly active slots,
         * including storage retained from a previous function.
         */
        memset(declarations->typeMasks + declarations->length, 0, newLength - declarations->length);
        declarations->length = newLength;
    }
    declarations->typeMasks[index] |= (U8)(1U << valueType);
    return true;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmStackDeclarationsIsSet(
    const WasmStackDeclarations* declarations,
    const U32 index,
    const WasmValueType valueType
) {
    return index < declarations->length
        && (declarations->typeMasks[index] & (1U << valueType)) != 0;
}

#endif /* W2C2_STACKDECLARATIONS_H */
