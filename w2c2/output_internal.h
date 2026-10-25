#ifndef W2C2_OUTPUT_INTERNAL_H
#define W2C2_OUTPUT_INTERNAL_H

#include "output.h"
#include "diagnostic_internal.h"
#include "output_buffer.h"

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
 * Borrows the buffer;
 * close and abort leave it intact.
 */
WasmOutput
wasmOutputForBuffer(OutputBuffer* buffer, WasmDiagnosticContext* diagnostics);

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

void
wasmOutputI32(WasmOutput* output, I32 value);

void
wasmOutputI64(WasmOutput* output, I64 value);

void
wasmOutputF32(WasmOutput* output, F32 value);

void
wasmOutputF64(WasmOutput* output, F64 value);

void
wasmOutputU32Hex(WasmOutput* output, U32 value);

void
wasmOutputU64Hex(WasmOutput* output, U64 value);

#endif /* W2C2_OUTPUT_INTERNAL_H */
