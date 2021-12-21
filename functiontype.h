#ifndef W2C2_FUNCTIONTYPE_H
#define W2C2_FUNCTIONTYPE_H

#include "w2c2_base.h"
#include "valuetype.h"

typedef struct WasmFunctionType {
    U32 parameterCount;
    WasmValueType* parameterTypes;
    U32 resultCount;
    WasmValueType* resultTypes;
} WasmFunctionType;

static const WasmFunctionType wasmEmptyFunctionType = {0, NULL, 0, NULL};

#endif /* W2C2_FUNCTIONTYPE_H */
