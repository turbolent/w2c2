#ifndef W2C2_EXPORT_H
#define W2C2_EXPORT_H

#include "w2c2_base.h"
#include "name.h"

#ifdef __cplusplus
extern "C" {
#endif

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
    WasmName name;
    WasmExportKind kind;
    U32 index;
} WasmExport;

static const WasmExport wasmEmptyExport = {{NULL, 0}, wasmExportKindFunction, 0};

#ifdef __cplusplus
}
#endif

#endif /* W2C2_EXPORT_H */
