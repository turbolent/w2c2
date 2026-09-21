#include "diagnostic_internal.h"

static
WasmDiagnostic
wasmDiagnosticInitialize(
    WasmDiagnosticCode code,
    WasmDiagnosticSeverity severity
) {
    WasmDiagnostic diagnostic;
    memset(&diagnostic, 0, sizeof(diagnostic));
    diagnostic.code = code;
    diagnostic.severity = severity;
    return diagnostic;
}

static
void
wasmDiagnosticReport(
    WasmDiagnosticContext* context,
    WasmDiagnostic* diagnostic
) {
    void (*const report)(void*, const WasmDiagnostic*) = context->diagnostics.report;
    diagnostic->location = context->location;
    if (diagnostic->severity == wasmDiagnosticError) {
        context->hasError = true;
    }
    if (report != NULL) {
        report(context->diagnostics.context, diagnostic);
    }
}

void
wasmDiagnosticReportReaderFailed(
    WasmDiagnosticContext* context,
    const struct WasmModuleReaderError* error
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticReaderFailed, wasmDiagnosticError
    );
    diagnostic.info.readerFailed.error = error;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportInvalidInstruction(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticInvalidInstruction, wasmDiagnosticError
    );
    diagnostic.info.invalidInstruction.family = family;
    diagnostic.info.invalidInstruction.opcode = opcode;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportInvalidLocalIndex(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode,
    U32 index
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticInvalidLocalIndex, wasmDiagnosticError
    );
    diagnostic.info.invalidLocalIndex.family = family;
    diagnostic.info.invalidLocalIndex.opcode = opcode;
    diagnostic.info.invalidLocalIndex.index = index;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportInvalidGlobalIndex(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode,
    U32 index
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticInvalidGlobalIndex, wasmDiagnosticError
    );
    diagnostic.info.invalidGlobalIndex.family = family;
    diagnostic.info.invalidGlobalIndex.opcode = opcode;
    diagnostic.info.invalidGlobalIndex.index = index;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportUnexpectedMemoryIndex(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode,
    U32 operand,
    U32 expected,
    U32 actual
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticUnexpectedMemoryIndex, wasmDiagnosticError
    );
    diagnostic.info.unexpectedMemoryIndex.family = family;
    diagnostic.info.unexpectedMemoryIndex.opcode = opcode;
    diagnostic.info.unexpectedMemoryIndex.operand = operand;
    diagnostic.info.unexpectedMemoryIndex.expected = expected;
    diagnostic.info.unexpectedMemoryIndex.actual = actual;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportInvalidBlockType(
    WasmDiagnosticContext* context,
    U32 opcode
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticInvalidBlockType, wasmDiagnosticError
    );
    diagnostic.info.invalidBlockType.opcode = opcode;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportInvalidAlignment(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode,
    U32 expected,
    U32 actual
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticInvalidAlignment, wasmDiagnosticError
    );
    diagnostic.info.invalidAlignment.family = family;
    diagnostic.info.invalidAlignment.opcode = opcode;
    diagnostic.info.invalidAlignment.expected = expected;
    diagnostic.info.invalidAlignment.actual = actual;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportUnsupportedOpcode(
    WasmDiagnosticContext* context,
    WasmDiagnosticOpcodeFamily family,
    U32 opcode
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticUnsupportedOpcode, wasmDiagnosticError
    );
    diagnostic.info.unsupportedOpcode.family = family;
    diagnostic.info.unsupportedOpcode.opcode = opcode;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportUnsupportedValueType(
    WasmDiagnosticContext* context,
    WasmValueType valueType
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticUnsupportedValueType, wasmDiagnosticError
    );
    diagnostic.info.unsupportedValueType.valueType = valueType;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportUnsupportedFunctionResults(
    WasmDiagnosticContext* context,
    U32 typeIndex,
    U32 resultCount
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticUnsupportedFunctionResults, wasmDiagnosticError
    );
    diagnostic.info.unsupportedFunctionResults.typeIndex = typeIndex;
    diagnostic.info.unsupportedFunctionResults.resultCount = resultCount;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportUnsupportedExport(
    WasmDiagnosticContext* context,
    WasmName name,
    WasmExportKind kind
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticUnsupportedExport, wasmDiagnosticWarning
    );
    diagnostic.info.unsupportedExport.name = name;
    diagnostic.info.unsupportedExport.kind = kind;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportInvalidDataSegmentMode(
    WasmDiagnosticContext* context,
    WasmDataSegmentMode mode
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticInvalidDataSegmentMode, wasmDiagnosticError
    );
    diagnostic.info.invalidDataSegmentMode.mode = mode;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportInvalidWriterArgument(
    WasmDiagnosticContext* context
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticInvalidWriterArgument, wasmDiagnosticError
    );
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportDataSectionNameTooLong(
    WasmDiagnosticContext* context
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticDataSectionNameTooLong, wasmDiagnosticError
    );
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportOutputName(
    WasmDiagnosticContext* context,
    WasmDiagnosticCode code,
    const char* name
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(code, wasmDiagnosticError);
    diagnostic.info.outputName.name = name;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportOutputFailed(
    WasmDiagnosticContext* context,
    WasmDiagnosticCode code,
    const char* name,
    int systemError
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        code, wasmDiagnosticError
    );
    diagnostic.info.outputFailed.name = name;
    diagnostic.info.outputFailed.systemError = systemError;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportAllocationFailed(
    WasmDiagnosticContext* context
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticAllocationFailed, wasmDiagnosticError
    );
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportThreadFailed(
    WasmDiagnosticContext* context,
    WasmDiagnosticThreadOperation operation,
    int systemError
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticThreadFailed, wasmDiagnosticError
    );
    diagnostic.info.threadFailed.operation = operation;
    diagnostic.info.threadFailed.systemError = systemError;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportSkippedNameSubsection(
    WasmDiagnosticContext* context,
    U32 id,
    U32 size
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticSkippedNameSubsection, wasmDiagnosticInfo
    );
    diagnostic.info.skippedNameSubsection.id = id;
    diagnostic.info.skippedNameSubsection.size = size;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportSkippedCustomSection(
    WasmDiagnosticContext* context,
    WasmName name,
    U32 size
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticSkippedCustomSection, wasmDiagnosticInfo
    );
    diagnostic.info.skippedCustomSection.name = name;
    diagnostic.info.skippedCustomSection.size = size;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportSkippedSection(
    WasmDiagnosticContext* context,
    U32 id
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticSkippedSection, wasmDiagnosticWarning
    );
    diagnostic.info.skippedSection.id = id;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportDwarfFailure(
    WasmDiagnosticContext* context,
    WasmDiagnosticDwarfOperation operation
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticDwarfFailure, wasmDiagnosticWarning
    );
    diagnostic.info.dwarfFailure.operation = operation;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportDwarfVersionUnsupported(
    WasmDiagnosticContext* context,
    const char* version
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticDwarfVersionUnsupported, wasmDiagnosticWarning
    );
    diagnostic.info.dwarfVersionUnsupported.version = version;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportDwarfUnexpectedTag(
    WasmDiagnosticContext* context,
    U32 tag
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticDwarfUnexpectedTag, wasmDiagnosticWarning
    );
    diagnostic.info.dwarfUnexpectedTag.tag = tag;
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportTranslationFailed(
    WasmDiagnosticContext* context
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticTranslationFailed, wasmDiagnosticError
    );
    wasmDiagnosticReport(context, &diagnostic);
}

void
wasmDiagnosticReportInvalidTranslationArgument(
    WasmDiagnosticContext* context
) {
    WasmDiagnostic diagnostic = wasmDiagnosticInitialize(
        wasmDiagnosticInvalidTranslationArgument, wasmDiagnosticError
    );
    wasmDiagnosticReport(context, &diagnostic);
}
