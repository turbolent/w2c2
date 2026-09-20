#ifndef W2C2_DIAGNOSTIC_H
#define W2C2_DIAGNOSTIC_H

#include "api.h"
#include "opcode.h"
#include "export.h"
#include "datasegment.h"

struct WasmModuleReaderError;

typedef enum WasmDiagnosticSeverity {
    wasmDiagnosticInfo,
    wasmDiagnosticWarning,
    wasmDiagnosticError
} WasmDiagnosticSeverity;

typedef enum WasmDiagnosticOpcodeFamily {
    wasmDiagnosticOpcodeUnprefixed,
    wasmDiagnosticOpcodeMisc,
    wasmDiagnosticOpcodeThreads
} WasmDiagnosticOpcodeFamily;

typedef enum WasmDiagnosticThreadOperation {
    wasmDiagnosticThreadMutexInitialize,
    wasmDiagnosticThreadConditionInitialize,
    wasmDiagnosticThreadCreate,
    wasmDiagnosticThreadJoin
} WasmDiagnosticThreadOperation;

typedef enum WasmDiagnosticDwarfOperation {
    wasmDiagnosticDwarfAllocate,
    wasmDiagnosticDwarfInitialize,
    wasmDiagnosticDwarfChild,
    wasmDiagnosticDwarfSibling,
    wasmDiagnosticDwarfTag,
    wasmDiagnosticDwarfFiles,
    wasmDiagnosticDwarfLines,
    wasmDiagnosticDwarfLineContext,
    wasmDiagnosticDwarfLineAddress,
    wasmDiagnosticDwarfLineSource,
    wasmDiagnosticDwarfLineNumber,
    wasmDiagnosticDwarfFinish,
    wasmDiagnosticDwarfNextUnit,
    wasmDiagnosticDwarfAttribute
} WasmDiagnosticDwarfOperation;

typedef enum WasmDiagnosticCode {
    wasmDiagnosticReaderFailed,
    wasmDiagnosticInvalidInstruction,
    wasmDiagnosticInvalidLocalIndex,
    wasmDiagnosticInvalidGlobalIndex,
    wasmDiagnosticUnexpectedMemoryIndex,
    wasmDiagnosticInvalidBlockType,
    wasmDiagnosticInvalidAlignment,
    wasmDiagnosticUnsupportedOpcode,
    wasmDiagnosticUnsupportedValueType,
    wasmDiagnosticUnsupportedFunctionResults,
    wasmDiagnosticUnsupportedExport,
    wasmDiagnosticInvalidDataSegmentMode,
    wasmDiagnosticInvalidWriterArgument,
    wasmDiagnosticOutputOpenFailed,
    wasmDiagnosticOutputWriteFailed,
    wasmDiagnosticOutputCloseFailed,
    wasmDiagnosticAllocationFailed,
    wasmDiagnosticThreadFailed,
    wasmDiagnosticDuplicateFunctionName,
    wasmDiagnosticSkippedNameSubsection,
    wasmDiagnosticSkippedCustomSection,
    wasmDiagnosticSkippedSection,
    wasmDiagnosticDwarfFailure,
    wasmDiagnosticDwarfVersionUnsupported,
    wasmDiagnosticDwarfUnexpectedTag,
    wasmDiagnosticTranslationFailed,
    wasmDiagnosticInvalidTranslationArgument,
    wasmDiagnosticDataSectionNameTooLong
} WasmDiagnosticCode;

typedef struct WasmDiagnosticReaderFailedInfo {
    const struct WasmModuleReaderError* error;
} WasmDiagnosticReaderFailedInfo;

typedef struct WasmDiagnosticInvalidInstructionInfo {
    WasmDiagnosticOpcodeFamily family;
    U32 opcode;
} WasmDiagnosticInvalidInstructionInfo;

typedef struct WasmDiagnosticInvalidLocalIndexInfo {
    WasmDiagnosticOpcodeFamily family;
    U32 opcode;
    U32 index;
} WasmDiagnosticInvalidLocalIndexInfo;

typedef struct WasmDiagnosticInvalidGlobalIndexInfo {
    WasmDiagnosticOpcodeFamily family;
    U32 opcode;
    U32 index;
} WasmDiagnosticInvalidGlobalIndexInfo;

typedef struct WasmDiagnosticUnexpectedMemoryIndexInfo {
    WasmDiagnosticOpcodeFamily family;
    U32 opcode;
    U32 operand;
    U32 expected;
    U32 actual;
} WasmDiagnosticUnexpectedMemoryIndexInfo;

typedef struct WasmDiagnosticInvalidBlockTypeInfo {
    U32 opcode;
} WasmDiagnosticInvalidBlockTypeInfo;

typedef struct WasmDiagnosticInvalidAlignmentInfo {
    WasmDiagnosticOpcodeFamily family;
    U32 opcode;
    U32 expected;
    U32 actual;
} WasmDiagnosticInvalidAlignmentInfo;

typedef struct WasmDiagnosticUnsupportedOpcodeInfo {
    WasmDiagnosticOpcodeFamily family;
    U32 opcode;
} WasmDiagnosticUnsupportedOpcodeInfo;

typedef struct WasmDiagnosticUnsupportedValueTypeInfo {
    WasmValueType valueType;
} WasmDiagnosticUnsupportedValueTypeInfo;

typedef struct WasmDiagnosticUnsupportedFunctionResultsInfo {
    U32 typeIndex;
    U32 resultCount;
} WasmDiagnosticUnsupportedFunctionResultsInfo;

typedef struct WasmDiagnosticUnsupportedExportInfo {
    WasmName name;
    WasmExportKind kind;
} WasmDiagnosticUnsupportedExportInfo;

typedef struct WasmDiagnosticInvalidDataSegmentModeInfo {
    WasmDataSegmentMode mode;
} WasmDiagnosticInvalidDataSegmentModeInfo;

typedef struct WasmDiagnosticOutputFailedInfo {
    const char* name;
    int systemError;
} WasmDiagnosticOutputFailedInfo;

typedef struct WasmDiagnosticThreadFailedInfo {
    WasmDiagnosticThreadOperation operation;
    int systemError;
} WasmDiagnosticThreadFailedInfo;

typedef struct WasmDiagnosticDuplicateFunctionNameInfo {
    WasmName name;
    U32 previousIndex;
    U32 currentIndex;
} WasmDiagnosticDuplicateFunctionNameInfo;

typedef struct WasmDiagnosticSkippedNameSubsectionInfo {
    U32 id;
    U32 size;
} WasmDiagnosticSkippedNameSubsectionInfo;

typedef struct WasmDiagnosticSkippedCustomSectionInfo {
    WasmName name;
    U32 size;
} WasmDiagnosticSkippedCustomSectionInfo;

typedef struct WasmDiagnosticSkippedSectionInfo {
    U32 id;
} WasmDiagnosticSkippedSectionInfo;

typedef struct WasmDiagnosticDwarfFailureInfo {
    WasmDiagnosticDwarfOperation operation;
} WasmDiagnosticDwarfFailureInfo;

typedef struct WasmDiagnosticDwarfVersionUnsupportedInfo {
    const char* version;
} WasmDiagnosticDwarfVersionUnsupportedInfo;

typedef struct WasmDiagnosticDwarfUnexpectedTagInfo {
    U32 tag;
} WasmDiagnosticDwarfUnexpectedTagInfo;

typedef struct WasmDiagnosticLocation {
    const char* outputName;
    WasmBool hasFunctionIndex;
    U32 functionIndex;
} WasmDiagnosticLocation;

typedef struct WasmDiagnostic {
    WasmDiagnosticSeverity severity;
    WasmDiagnosticCode code;
    WasmDiagnosticLocation location;
    union {
        WasmDiagnosticReaderFailedInfo readerFailed;
        WasmDiagnosticInvalidInstructionInfo invalidInstruction;
        WasmDiagnosticInvalidLocalIndexInfo invalidLocalIndex;
        WasmDiagnosticInvalidGlobalIndexInfo invalidGlobalIndex;
        WasmDiagnosticUnexpectedMemoryIndexInfo unexpectedMemoryIndex;
        WasmDiagnosticInvalidBlockTypeInfo invalidBlockType;
        WasmDiagnosticInvalidAlignmentInfo invalidAlignment;
        WasmDiagnosticUnsupportedOpcodeInfo unsupportedOpcode;
        WasmDiagnosticUnsupportedValueTypeInfo unsupportedValueType;
        WasmDiagnosticUnsupportedFunctionResultsInfo unsupportedFunctionResults;
        WasmDiagnosticUnsupportedExportInfo unsupportedExport;
        WasmDiagnosticInvalidDataSegmentModeInfo invalidDataSegmentMode;
        WasmDiagnosticOutputFailedInfo outputFailed;
        WasmDiagnosticThreadFailedInfo threadFailed;
        WasmDiagnosticDuplicateFunctionNameInfo duplicateFunctionName;
        WasmDiagnosticSkippedNameSubsectionInfo skippedNameSubsection;
        WasmDiagnosticSkippedCustomSectionInfo skippedCustomSection;
        WasmDiagnosticSkippedSectionInfo skippedSection;
        WasmDiagnosticDwarfFailureInfo dwarfFailure;
        WasmDiagnosticDwarfVersionUnsupportedInfo dwarfVersionUnsupported;
        WasmDiagnosticDwarfUnexpectedTagInfo dwarfUnexpectedTag;
    } info;
} WasmDiagnostic;

/*
 * Callbacks may run concurrently on writer threads.
 * The context must remain valid until the reader or writer returns.
 * All callbacks complete before the operation returns.
 * A NULL callback disables reporting without changing failure results.
 */
typedef struct WasmDiagnostics {
    void (*report)(void* context, const WasmDiagnostic* diagnostic);
    void* context;
} WasmDiagnostics;

static const WasmDiagnostics emptyWasmDiagnostics = {NULL, NULL};

#endif /* W2C2_DIAGNOSTIC_H */
