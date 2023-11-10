#ifndef W2C2_EXPORT_H
#define W2C2_EXPORT_H

#include "w2c2_base.h"

typedef enum WasmExportKind {
    wasmExportKindFunction,
    wasmExportKindTable,
    wasmExportKindMemory,
    wasmExportKindGlobal,
    wasmExportKind_count
} WasmExportKind;

const char*
wasmExportKindDescription(
    WasmExportKind exportKind
);

typedef struct WasmExport {
    char* name;
    WasmExportKind kind;
    U32 index;
} WasmExport;

static const WasmExport wasmEmptyExport = {NULL, 0, 0};

#endif /* W2C2_EXPORT_H */
