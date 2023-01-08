#ifndef W2C2_GLOBAL_H
#define W2C2_GLOBAL_H

#include "w2c2_base.h"
#include "buffer.h"
#include "valuetype.h"

typedef struct WasmGlobalType {
    WasmValueType valueType;
    bool mutable;
} WasmGlobalType;

typedef struct WasmGlobal {
    WasmGlobalType type;
    Buffer init;
} WasmGlobal;

static const WasmGlobal wasmEmptyGlobal = {{0, false}, {NULL, 0}};

#endif /* W2C2_GLOBAL_H */
