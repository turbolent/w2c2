#include <errno.h>
#include <stdio.h>

#include "output_internal.h"

static
bool
wasmOutputAppend(void* context, const U8* bytes, size_t length, int* systemError) {
    if (!stringBuilderAppendSized((StringBuilder*)context, (const char*)bytes, length)) {
        *systemError = ENOMEM;
        return false;
    }
    return true;
}

static
bool
wasmOutputBufferClose(void* context, int* systemError) {
    (void)context;
    (void)systemError;
    return true;
}

static
void
wasmOutputBufferAbort(void* context) {
    (void)context;
}

WasmOutput
wasmOutputForStringBuilder(StringBuilder* builder, WasmDiagnosticContext* diagnostics) {
    WasmOutput output;
    memset(&output, 0, sizeof(output));
    output.diagnostics = diagnostics;
    output.name = diagnostics->location.outputName;
    output.sink.context = builder;
    output.sink.write = wasmOutputAppend;
    output.sink.close = wasmOutputBufferClose;
    output.sink.abort = wasmOutputBufferAbort;
    return output;
}

static
void
wasmOutputReport(
    WasmOutput* output,
    WasmDiagnosticCode code,
    int systemError
) {
    WasmDiagnosticContext* diagnostics = output->diagnostics;
    const char* previousName = diagnostics->location.outputName;
    diagnostics->location.outputName = output->name;
    if (!diagnostics->hasError) {
        wasmDiagnosticReportOutputFailed(diagnostics, code, output->name, systemError);
    }
    diagnostics->location.outputName = previousName;
}

bool
wasmOutputOpen(
    WasmOutput* output,
    WasmOutputProvider provider,
    const char* name,
    WasmOutputKind kind,
    WasmDiagnosticContext* diagnostics
) {
    int systemError = 0;
    memset(output, 0, sizeof(*output));
    output->provider = provider;
    output->diagnostics = diagnostics;
    output->name = name;
    if (!provider.open(provider.context, name, kind, &output->sink, &systemError)) {
        wasmOutputReport(output, wasmDiagnosticOutputOpenFailed, systemError);
        return false;
    }
    if (output->sink.write == NULL || output->sink.close == NULL || output->sink.abort == NULL) {
        if (output->sink.abort != NULL) {
            output->sink.abort(output->sink.context);
        }
        wasmDiagnosticReportInvalidWriterArgument(diagnostics);
        return false;
    }
    return true;
}

void
wasmOutputWrite(WasmOutput* output, const U8* bytes, size_t length) {
    int systemError = 0;
    if (output->failed || length == 0) {
        return;
    }
    if (!output->sink.write(output->sink.context, bytes, length, &systemError)) {
        output->failed = true;
        wasmOutputReport(output, wasmDiagnosticOutputWriteFailed, systemError);
    }
}

void
wasmOutputAbort(WasmOutput* output) {
    output->sink.abort(output->sink.context);
}

bool
wasmOutputClose(WasmOutput* output) {
    int systemError = 0;
    if (output->failed) {
        wasmOutputAbort(output);
        return false;
    }
    if (!output->sink.close(output->sink.context, &systemError)) {
        wasmOutputReport(output, wasmDiagnosticOutputCloseFailed, systemError);
        return false;
    }
    return true;
}

void
wasmOutputString(WasmOutput* output, const char* string) {
    wasmOutputWrite(output, (const U8*)string, strlen(string));
}

void
wasmOutputChar(WasmOutput* output, char value) {
    wasmOutputWrite(output, (const U8*)&value, 1);
}

void
wasmOutputU32(WasmOutput* output, U32 value) {
    char buffer[11];
    const int length = sprintf(buffer, "%u", value);
    wasmOutputWrite(output, (const U8*)buffer, (size_t)length);
}

void
wasmOutputU64(WasmOutput* output, U64 value) {
    char buffer[21];
    const int length = sprintf(buffer, "%llu", value);
    wasmOutputWrite(output, (const U8*)buffer, (size_t)length);
}

void
wasmOutputHex(WasmOutput* output, unsigned int value, WasmOutputHexFormat format) {
    char buffer[sizeof(value) * 2 + 1];
    const int length = sprintf(buffer, format == wasmOutputHexUpperPadded ? "%02X" : "%x", value);
    wasmOutputWrite(output, (const U8*)buffer, (size_t)length);
}
