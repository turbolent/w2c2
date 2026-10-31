#ifndef W2C2_ELEMENTSEGMENT_H
#define W2C2_ELEMENTSEGMENT_H

#include "w2c2_base.h"
#include "buffer.h"
#include "opcode.h"

typedef enum WasmElementSegmentMode {
    wasmElementSegmentActive,
    wasmElementSegmentPassive,
    wasmElementSegmentDeclarative
} WasmElementSegmentMode;

typedef struct WasmElementInitializer {
    WasmOpcode opcode;
    U32 index;
} WasmElementInitializer;

typedef struct WasmElementSegment {
    U32 tableIndex;
    Buffer offset;
    U32 elementCount;
    WasmElementInitializer* elements;
    WasmElementSegmentMode mode;
} WasmElementSegment;

static const WasmElementSegment wasmEmptyElementSegment = {0, {NULL, 0}, 0, NULL, wasmElementSegmentActive};

#endif /* W2C2_ELEMENTSEGMENT_H */
