#ifndef W2C2_FUNCTION_H
#define W2C2_FUNCTION_H

#include "w2c2_base.h"
#include "buffer.h"
#include "locals.h"

typedef struct WasmFunction {
    U32 functionTypeIndex;
    WasmLocalsDeclarations localsDeclarations;
    Buffer code;
} WasmFunction;

static const WasmFunction wasmEmptyFunction = {0, {NULL, 0}, {NULL, 0}};

#endif /* W2C2_FUNCTION_H */
