#ifndef W2C2_DEBUG_H
#define W2C2_DEBUG_H

#include "w2c2_base.h"
#include "buffer.h"

typedef struct WasmDebugSection {
    char* name;
    Buffer buffer;
} WasmDebugSection;

typedef struct WasmDebugSections {
    WasmDebugSection* debugSections;
    U32 count;
    U32 capacity;
} WasmDebugSections;

typedef struct WasmDebugLine {
    U64 address;
    char *path;
    U64 number;
} WasmDebugLine;

typedef struct WasmDebugLines {
    WasmDebugLine* debugLines;
    size_t length;
    size_t capacity;
} WasmDebugLines;

static const WasmDebugLines emptyWasmDebugLines = {NULL, 0, 0};

bool
WARN_UNUSED_RESULT
wasmDebugLinesEnsureCapacity(
    WasmDebugLines* debugLines,
    size_t length
);

static
__inline__
bool
WARN_UNUSED_RESULT
wasmDebugLinesPush(
    WasmDebugLines* debugLines,
    WasmDebugLine debugLine
) {
    const size_t newLength = debugLines->length + 1;
    MUST (wasmDebugLinesEnsureCapacity(debugLines, newLength))

    debugLines->debugLines[debugLines->length] = debugLine;
    debugLines->length = newLength;

    return true;
}

WasmDebugLines
wasmParseDebugInfo(
    WasmDebugSections sections
);

#endif /* W2C2_DEBUG_H */
