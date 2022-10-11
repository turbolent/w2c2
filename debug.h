#ifndef W2C2_DEBUG_H
#define W2C2_DEBUG_H

#include "w2c2_base.h"
#include "buffer.h"
#include "array.h"

typedef struct WasmDebugSection {
    char* name;
    Buffer buffer;
} WasmDebugSection;

ARRAY_TYPE(
    WasmDebugSections,
    WasmDebugSection,
    wasmDebugSections,
    debugSections,
    debugSection
)

typedef struct WasmDebugLine {
    U64 address;
    char *path;
    U64 number;
} WasmDebugLine;

ARRAY_TYPE(
    WasmDebugLines,
    WasmDebugLine,
    wasmDebugLines,
    debugLines,
    debugLine
)

static const WasmDebugLines emptyWasmDebugLines = {0, 0, NULL};

WasmDebugLines
wasmParseDebugInfo(
    WasmDebugSections sections
);

#endif /* W2C2_DEBUG_H */
