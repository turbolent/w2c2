#ifndef W2C2_TABLE_H
#define W2C2_TABLE_H

#include "w2c2_base.h"

static const U8 wasmTableTypeFuncRef = 0x70;

typedef struct WasmTable {
    U32 min;
    U32 max;
    bool shared;
} WasmTable;

static const WasmTable wasmEmptyTable = {0, 0, false};

#endif /* W2C2_TABLE_H */
