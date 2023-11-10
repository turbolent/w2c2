#ifndef W2C2_MEMORY_H
#define W2C2_MEMORY_H

#include "w2c2_base.h"

typedef struct WasmMemory {
    U32 min;
    U32 max;
    bool shared;
} WasmMemory;

static const WasmMemory wasmEmptyMemory = {0, 0, false};

#endif /* W2C2_MEMORY_H */
