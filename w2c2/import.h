#ifndef W2C2_IMPORT_H
#define W2C2_IMPORT_H

#include "w2c2_base.h"
#include "api.h"
#include "global.h"
#include "array.h"
#include "name.h"

typedef enum WasmImportKind {
    wasmImportKindFunction,
    wasmImportKindTable,
    wasmImportKindMemory,
    wasmImportKindGlobal,
    wasmImportKind_count
} WasmImportKind;

/* Function imports */

typedef struct WasmFunctionImport {
    WasmName module;
    WasmName name;
    U32 functionTypeIndex;
} WasmFunctionImport;

static const WasmFunctionImport wasmEmptyFunctionImport = {{NULL, 0}, {NULL, 0}, 0};

ARRAY_TYPE(
    WasmFunctionImports,
    WasmFunctionImport,
    wasmFunctionImports,
    imports,
    import
)

/* Global imports */

typedef struct WasmGlobalImport {
    WasmName module;
    WasmName name;
    WasmGlobalType globalType;
} WasmGlobalImport;

static const WasmGlobalImport wasmEmptyGlobalImport = {{NULL, 0}, {NULL, 0}, {0, false}};

ARRAY_TYPE(
    WasmGlobalImports,
    WasmGlobalImport,
    wasmGlobalImports,
    imports,
    import
)

/* Memory imports */

typedef struct WasmMemoryImport {
    WasmName module;
    WasmName name;
    U32 min;
    U32 max;
    WasmBool shared;
} WasmMemoryImport;

static const WasmMemoryImport wasmEmptyMemoryImport = {{NULL, 0}, {NULL, 0}, 0, 0, false};

ARRAY_TYPE(
    WasmMemoryImports,
    WasmMemoryImport,
    wasmMemoryImports,
    imports,
    import
)

/* Table imports */

typedef struct WasmTableImport {
    WasmName module;
    WasmName name;
    U32 min;
    U32 max;
    WasmBool shared;
} WasmTableImport;

static const WasmTableImport wasmEmptyTableImport = {{NULL, 0}, {NULL, 0}, 0, 0, false};

ARRAY_TYPE(
    WasmTableImports,
    WasmTableImport,
    wasmTableImports,
    imports,
    import
)

#endif /* W2C2_IMPORT_H */
