#ifndef W2C2_TABLE_H
#define W2C2_TABLE_H

#include "w2c2_base.h"
#include "api.h"
#include "valuetype.h"

typedef struct WasmTable {
    U32 min;
    U32 max;
    WasmBool shared;
    WasmValueType elementType;
} WasmTable;

static const WasmTable wasmEmptyTable = {0, 0, false, wasmValueTypeFuncRef};

#endif /* W2C2_TABLE_H */
