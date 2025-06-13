#ifndef W2C2_READER_H
#define W2C2_READER_H

#include "w2c2_base.h"
#include "buffer.h"
#include "module.h"

typedef struct WasmModuleReader {
    Buffer buffer;
    WasmModule* module;
    bool debug;
} WasmModuleReader;

static const WasmModuleReader emptyWasmModuleReader = {{NULL, 0}, NULL, false};

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
    wasmModuleReaderInvalidNameSectionFunctionName
} WasmModuleReaderErrorCode;

typedef struct WasmModuleReaderError {
    WasmModuleReaderErrorCode code;
} WasmModuleReaderError;

const char*
wasmModuleReaderErrorMessage(
    const WasmModuleReaderError* error
);

void
wasmModuleRead(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
);

#endif /* W2C2_READER_H */
