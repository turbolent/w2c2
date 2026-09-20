#ifndef W2C2_LOCALS_H
#define W2C2_LOCALS_H

#include "valuetype.h"
#include "w2c2_base.h"

typedef struct WasmLocalsDeclaration {
    WasmValueType type;
    /* Exclusive cumulative local index, excluding parameters. */
    U32 endIndex;
} WasmLocalsDeclaration;

typedef struct WasmLocalsDeclarations {
    WasmLocalsDeclaration* declarations;
    U32 declarationCount;
} WasmLocalsDeclarations;

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmLocalsDeclarationsGetType(
    const WasmLocalsDeclarations localsDeclarations,
    const U32 localIndex,
    WasmValueType* result
) {
    U32 low = 0;
    U32 high = localsDeclarations.declarationCount;

    /* Find the first declaration ending after this local,
     * skipping any zero-length groups.
     */
    while (low < high) {
        const U32 middle = low + (high - low) / 2;
        if (localIndex < localsDeclarations.declarations[middle].endIndex) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }

    if (low == localsDeclarations.declarationCount) {
        return false;
    }
    *result = localsDeclarations.declarations[low].type;
    return true;
}

#endif /* W2C2_LOCALS_H */
