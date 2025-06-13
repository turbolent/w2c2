#ifndef W2C2_ELEMENTSEGMENT_H
#define W2C2_ELEMENTSEGMENT_H

#include "w2c2_base.h"
#include "buffer.h"

typedef struct WasmElementSegment {
    U32 tableIndex;
    Buffer offset;
    U32 functionIndexCount;
    U32* functionIndices;
} WasmElementSegment;

static const WasmElementSegment wasmEmptyElementSegment = {0, {NULL, 0}, 0, NULL};

#endif /* W2C2_ELEMENTSEGMENT_H */
