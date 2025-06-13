#ifndef W2C2_IMPORT_H
#define W2C2_IMPORT_H

#include "w2c2_base.h"
#include "global.h"
#include "array.h"

typedef enum WasmImportKind {
    wasmImportKindFunction,
    wasmImportKindTable,
    wasmImportKindMemory,
    wasmImportKindGlobal,
    wasmImportKind_count
} WasmImportKind;

/* Function imports */

typedef struct WasmFunctionImport {
    char* module;
    char* name;
    U32 functionTypeIndex;
} WasmFunctionImport;

static const WasmFunctionImport wasmEmptyFunctionImport = {NULL, NULL, 0};

ARRAY_TYPE(
    WasmFunctionImports,
    WasmFunctionImport,
    wasmFunctionImports,
    imports,
    import
)

/* Global imports */

typedef struct WasmGlobalImport {
    char* module;
    char* name;
    WasmGlobalType globalType;
} WasmGlobalImport;

static const WasmGlobalImport wasmEmptyGlobalImport = {NULL, NULL, {0, false}};

ARRAY_TYPE(
    WasmGlobalImports,
    WasmGlobalImport,
    wasmGlobalImports,
    imports,
    import
)

/* Memory imports */

typedef struct WasmMemoryImport {
    char* module;
    char* name;
    U32 min;
    U32 max;
    bool shared;
} WasmMemoryImport;

static const WasmMemoryImport wasmEmptyMemoryImport = {NULL, NULL, 0, 0, false};

ARRAY_TYPE(
    WasmMemoryImports,
    WasmMemoryImport,
    wasmMemoryImports,
    imports,
    import
)

/* Table imports */

typedef struct WasmTableImport {
    char* module;
    char* name;
    U32 min;
    U32 max;
    bool shared;
} WasmTableImport;

static const WasmTableImport wasmEmptyTableImport = {NULL, NULL, 0, 0, false};

ARRAY_TYPE(
    WasmTableImports,
    WasmTableImport,
    wasmTableImports,
    imports,
    import
)

#endif /* W2C2_IMPORT_H */
