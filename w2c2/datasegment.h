#ifndef W2C2_DATASEGMENT_H
#define W2C2_DATASEGMENT_H

#include "w2c2_base.h"
#include "buffer.h"

typedef struct WasmDataSegment {
    U32 memoryIndex;
    Buffer offset;
    Buffer bytes;
} WasmDataSegment;

static const WasmDataSegment wasmEmptyDataSegment = {0, {0, false}, {0, false}};

typedef enum WasmDataSegmentMode {
    wasmDataSegmentModeArrays,
    wasmDataSegmentModeGNULD,
    wasmDataSegmentModeSectcreate1,
    wasmDataSegmentModeSectcreate2
} WasmDataSegmentMode;

#endif /* W2C2_DATASEGMENT_H */
