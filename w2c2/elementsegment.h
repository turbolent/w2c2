#ifndef W2C2_ELEMENTSEGMENT_H
#define W2C2_ELEMENTSEGMENT_H

#include "w2c2_base.h"
#include "buffer.h"
#include "opcode.h"
#include "reference.h"

typedef enum WasmElementSegmentMode {
    wasmElementSegmentActive,
    wasmElementSegmentPassive,
    wasmElementSegmentDeclarative
} WasmElementSegmentMode;

typedef struct WasmElementInitializer {
    WasmOpcode opcode;
    WasmReferenceImmediate immediate;
} WasmElementInitializer;

typedef struct WasmElementSegment {
    U32 tableIndex;
    Buffer offset;
    U32 elementCount;
    WasmElementInitializer* elements;
    WasmElementSegmentMode mode;
    WasmValueType elementType;
} WasmElementSegment;

static const WasmElementSegment wasmEmptyElementSegment = {0, {NULL, 0}, 0, NULL, wasmElementSegmentActive, wasmValueTypeFuncRef};

#endif /* W2C2_ELEMENTSEGMENT_H */
