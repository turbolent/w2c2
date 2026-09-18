#ifndef W2C2_OUTPUT_INTERNAL_H
#define W2C2_OUTPUT_INTERNAL_H

#include "output.h"
#include "diagnostic_internal.h"
#include "stringbuilder.h"

typedef enum WasmOutputHexFormat {
    wasmOutputHexLower,
    wasmOutputHexUpperPadded
} WasmOutputHexFormat;

typedef struct WasmOutput {
    WasmOutputProvider provider;
    WasmOutputSink sink;
    WasmDiagnosticContext* diagnostics;
    const char* name;
    bool failed;
} WasmOutput;

/*
 * Borrows the builder;
 * close and abort leave it intact.
 */
WasmOutput
wasmOutputForStringBuilder(StringBuilder* builder, WasmDiagnosticContext* diagnostics);

bool
WARN_UNUSED_RESULT
wasmOutputOpen(
    WasmOutput* output,
    WasmOutputProvider provider,
    const char* name,
    WasmOutputKind kind,
    WasmDiagnosticContext* diagnostics
);

bool
WARN_UNUSED_RESULT
wasmOutputClose(WasmOutput* output);

void
wasmOutputAbort(WasmOutput* output);

void
wasmOutputWrite(WasmOutput* output, const U8* bytes, size_t length);

void
wasmOutputString(WasmOutput* output, const char* string);

void
wasmOutputChar(WasmOutput* output, char value);

void
wasmOutputU32(WasmOutput* output, U32 value);

void
wasmOutputU64(WasmOutput* output, U64 value);

void
wasmOutputHex(WasmOutput* output, unsigned int value, WasmOutputHexFormat format);

#endif /* W2C2_OUTPUT_INTERNAL_H */
