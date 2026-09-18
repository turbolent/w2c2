#ifndef W2C2_READER_H
#define W2C2_READER_H

#include "w2c2_base.h"
#include "buffer.h"
#include "module.h"
#include "diagnostic.h"

typedef struct WasmModuleReader {
    Buffer buffer;
    WasmModule* module;
    bool debug;
    WasmDiagnostics diagnostics;
} WasmModuleReader;

static const WasmModuleReader emptyWasmModuleReader = {{NULL, 0}, NULL, false, {NULL, NULL}};

typedef enum WasmModuleReaderErrorCode {
    wasmModuleReaderInvalidMagic,
    wasmModuleReaderAllocationFailed,
    wasmModuleReaderInvalidSectionID,
    wasmModuleReaderInvalidSectionSize,
    wasmModuleReaderIncorrectSectionRead,
    wasmModuleReaderInvalidCustomSectionName,
    wasmModuleReaderDebugSectionAppendFailed,
    wasmModuleReaderInvalidTypeSectionTypeCount,
    wasmModuleReaderInvalidFunctionTypeIndicator,
    wasmModuleReaderInvalidFunctionTypeParameterCount,
    wasmModuleReaderInvalidFunctionTypeResultCount,
    wasmModuleReaderInvalidImportSectionImportCount,
    wasmModuleReaderInvalidImportSectionImportModule,
    wasmModuleReaderInvalidImportSectionImportName,
    wasmModuleReaderInvalidImportSectionImportKind,
    wasmModuleReaderInvalidImportSectionFunctionTypeIndex,
    wasmModuleReaderInvalidValueType,
    wasmModuleReaderInvalidFunctionSectionFunctionCount,
    wasmModuleReaderInvalidFunctionTypeIndex,
    wasmModuleReaderInvalidCodeSectionFunctionCount,
    wasmModuleReaderInvalidCodeSectionCodeSize,
    wasmModuleReaderInvalidCodeSectionLocalsDeclarations,
    wasmModuleReaderInvalidExportSectionExportCount,
    wasmModuleReaderInvalidExportSectionExportName,
    wasmModuleReaderInvalidExportSectionExportKind,
    wasmModuleReaderInvalidExportSectionExportIndex,
    wasmModuleReaderInvalidGlobalSectionGlobalCount,
    wasmModuleReaderInvalidGlobalSectionMutabilityIndicator,
    wasmModuleReaderInvalidGlobalSectionInitExpression,
    wasmModuleReaderInvalidMemorySectionMemoryCount,
    wasmModuleReaderInvalidLimitKind,
    wasmModuleReaderInvalidLimitMinimum,
    wasmModuleReaderInvalidLimitMaximum,
    wasmModuleReaderInvalidDataSectionDataSegmentCount,
    wasmModuleReaderInvalidDataSectionKind,
    wasmModuleReaderInvalidDataSectionMemoryIndex,
    wasmModuleReaderInvalidDataSectionOffsetExpression,
    wasmModuleReaderInvalidDataSectionBytes,
    wasmModuleReaderInvalidDataCountSectionDataCount,
    wasmModuleReaderInvalidTableSectionTableCount,
    wasmModuleReaderInvalidTableSectionTableType,
    wasmModuleReaderInvalidElementSectionElementSegmentCount,
    wasmModuleReaderInvalidElementSectionTableIndex,
    wasmModuleReaderInvalidElementSectionOffsetExpression,
    wasmModuleReaderInvalidElementSectionFunctionIndexCount,
    wasmModuleReaderInvalidElementSectionFunctionIndex,
    wasmModuleReaderInvalidStartSectionFunctionIndex,
    wasmModuleReaderInvalidNameSectionFunctionNameCount,
    wasmModuleReaderInvalidNameSectionFunctionIndex,
    wasmModuleReaderInvalidNameSectionFunctionName,
    wasmModuleReaderInvalidSectionOrder
} WasmModuleReaderErrorCode;

typedef struct WasmModuleReaderError {
    WasmModuleReaderErrorCode code;
} WasmModuleReaderError;

const char*
wasmModuleReaderErrorMessage(
    const WasmModuleReaderError* error
);

/*
 * The function does not modify reader->buffer.
 * On success, it frees any prior reader->module.
 * The caller owns the new module and releases it with wasmModuleFree.
 * On failure, reader->module is unchanged.
 * The input buffer remains caller-owned and must outlive the parsed module.
 */
void
wasmModuleRead(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
);

#endif /* W2C2_READER_H */
