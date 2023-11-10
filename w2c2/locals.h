#ifndef W2C2_LOCALS_H
#define W2C2_LOCALS_H

#include "valuetype.h"
#include "w2c2_base.h"

typedef struct WasmLocalsDeclaration {
    WasmValueType type;
    U32 count;
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
    U32 localsCount = 0;
    U32 localsDeclarationIndex = 0;
    for (; localsDeclarationIndex < localsDeclarations.declarationCount; localsDeclarationIndex++) {
        const WasmLocalsDeclaration localsDeclaration = localsDeclarations.declarations[localsDeclarationIndex];
        if (localIndex < localsCount + localsDeclaration.count) {
            *result = localsDeclaration.type;
            return true;
        }
        localsCount += localsDeclaration.count;
    }

    return false;
}

#endif /* W2C2_LOCALS_H */
