#ifndef W2C2_DIAGNOSTIC_INTERNAL_H
#define W2C2_DIAGNOSTIC_INTERNAL_H

#include "diagnostic.h"

/* Each reader, writer, or worker owns its error-reporting state. */
typedef struct WasmDiagnosticContext {
    WasmDiagnostics diagnostics;
    bool hasError;
    WasmDiagnosticLocation location;
} WasmDiagnosticContext;

static const WasmDiagnosticContext emptyWasmDiagnosticContext = {
    {NULL, NULL}, false, {NULL, false, 0}
};

void
wasmDiagnosticReportReaderFailed(
    WasmDiagnosticContext* context,
    const struct WasmModuleReaderError* error
);

void
wasmDiagnosticReportInvalidInstruction(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode
);

void
wasmDiagnosticReportInvalidLocalIndex(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode,
    U32 index
);

void
wasmDiagnosticReportInvalidGlobalIndex(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode,
    U32 index
);

void
wasmDiagnosticReportUnexpectedMemoryIndex(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode,
    U32 operand,
    U32 expected,
    U32 actual
);

void
wasmDiagnosticReportInvalidBlockType(
    WasmDiagnosticContext* context,
    U32 opcode
);

void
wasmDiagnosticReportInvalidAlignment(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode,
    U32 expected,
    U32 actual
);

void
wasmDiagnosticReportUnsupportedOpcode(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode
);

void
wasmDiagnosticReportUnsupportedValueType(
    WasmDiagnosticContext* context,
    WasmValueType valueType
);

void
wasmDiagnosticReportUnsupportedFunctionResults(
    WasmDiagnosticContext* context,
    U32 typeIndex,
    U32 resultCount
);

void
wasmDiagnosticReportUnsupportedExport(
    WasmDiagnosticContext* context,
    WasmName name,
    WasmExportKind kind
);

void
wasmDiagnosticReportInvalidDataSegmentMode(
    WasmDiagnosticContext* context,
    WasmDataSegmentMode mode
);

void
wasmDiagnosticReportInvalidWriterArgument(
    WasmDiagnosticContext* context
);

void
wasmDiagnosticReportOutputFailed(
    WasmDiagnosticContext* context,
    WasmDiagnosticCode code,
    const char* name,
    int systemError
);

void
wasmDiagnosticReportAllocationFailed(
    WasmDiagnosticContext* context
);

void
wasmDiagnosticReportThreadFailed(
    WasmDiagnosticContext* context,
    WasmDiagnosticThreadOperation operation,
    int systemError
);

void
wasmDiagnosticReportDuplicateFunctionName(
    WasmDiagnosticContext* context,
    WasmName name,
    U32 previousIndex,
    U32 currentIndex
);

void
wasmDiagnosticReportSkippedNameSubsection(
    WasmDiagnosticContext* context,
    U32 id,
    U32 size
);

void
wasmDiagnosticReportSkippedCustomSection(
    WasmDiagnosticContext* context,
    WasmName name,
    U32 size
);

void
wasmDiagnosticReportSkippedSection(
    WasmDiagnosticContext* context,
    U32 id
);

void
wasmDiagnosticReportDwarfFailure(
    WasmDiagnosticContext* context,
    WasmDiagnosticDwarfOperation operation
);

void
wasmDiagnosticReportDwarfVersionUnsupported(
    WasmDiagnosticContext* context,
    const char* version
);

void
wasmDiagnosticReportDwarfUnexpectedTag(
    WasmDiagnosticContext* context,
    U32 tag
);

void
wasmDiagnosticReportTranslationFailed(
    WasmDiagnosticContext* context
);

void
wasmDiagnosticReportInvalidTranslationArgument(
    WasmDiagnosticContext* context
);

#endif /* W2C2_DIAGNOSTIC_INTERNAL_H */
