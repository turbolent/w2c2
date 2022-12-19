#ifndef W2C2_MEMORY_H
#define W2C2_MEMORY_H

#include "w2c2_base.h"
#include "buffer.h"
#include "valuetype.h"

typedef struct WasmMemory {
    U32 min;
    U32 max;
} WasmMemory;

static const WasmMemory wasmEmptyMemory = {0, 0};

#endif /* W2C2_MEMORY_H */
