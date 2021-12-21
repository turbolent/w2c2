#ifndef W2C2_READER_H
#define W2C2_READER_H

#include "w2c2_base.h"
#include "buffer.h"
#include "module.h"

typedef struct {
    Buffer buffer;
    WasmModule* module;
} WasmModuleReader;

typedef enum {
    wasmModuleReaderInvalidMagic,
    wasmModuleReaderAllocationFailed,
    wasmModuleReaderInvalidSectionID,
    wasmModuleReaderInvalidSectionSize,
    wasmModuleReaderIncorrectSectionRead,
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
    wasmModuleReaderInvalidExportSectionIndex,
    wasmModuleReaderInvalidGlobalSectionGlobalCount,
    wasmModuleReaderInvalidGlobalSectionMutabilityIndicator,
    wasmModuleReaderInvalidGlobalSectionInitExpression,
    wasmModuleReaderInvalidMemorySectionMemoryCount,
    wasmModuleReaderInvalidLimitKind,
    wasmModuleReaderInvalidLimitMinimum,
    wasmModuleReaderInvalidLimitMaximum,
    wasmModuleReaderInvalidDataSectionDataSegmentCount,
    wasmModuleReaderInvalidDataSectionMemoryIndex,
    wasmModuleReaderInvalidDataSectionOffsetExpression,
    wasmModuleReaderInvalidDataSectionBytes,
    wasmModuleReaderInvalidTableSectionTableCount,
    wasmModuleReaderInvalidTableSectionTableType,
    wasmModuleReaderInvalidElementSectionElementSegmentCount,
    wasmModuleReaderInvalidElementSectionTableIndex,
    wasmModuleReaderInvalidElementSectionOffsetExpression,
    wasmModuleReaderInvalidElementSectionFunctionIndexCount,
    wasmModuleReaderInvalidElementSectionFunctionIndex,
    wasmModuleReaderInvalidStartSectionFunctionIndex
} WasmModuleReaderErrorCode;

typedef struct WasmModuleReaderError {
    WasmModuleReaderErrorCode code;
} WasmModuleReaderError;

const char*
wasmModuleReaderErrorMessage(
    WasmModuleReaderError* error
);

void
wasmModuleRead(
    WasmModuleReader* reader,
    WasmModuleReaderError** error
);

#endif /* W2C2_READER_H */
