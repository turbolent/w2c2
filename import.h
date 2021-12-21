#ifndef W2C2_IMPORT_H
#define W2C2_IMPORT_H

#include "w2c2_base.h"
#include "valuetype.h"
#include "global.h"

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

typedef struct WasmFunctionImports {
    WasmFunctionImport* imports;
    size_t length;
    size_t capacity;
} WasmFunctionImports;

bool
WARN_UNUSED_RESULT
wasmFunctionImportsEnsureCapacity(
    WasmFunctionImports* functionImports,
    size_t length
);

/* Global imports */

typedef struct WasmGlobalImport {
    char* module;
    char* name;
    WasmGlobalType globalType;
} WasmGlobalImport;

static const WasmGlobalImport wasmEmptyGlobalImport = {NULL, NULL, {0, false}};

typedef struct WasmGlobalImports {
    WasmGlobalImport* imports;
    size_t length;
    size_t capacity;
} WasmGlobalImports;

bool
WARN_UNUSED_RESULT
wasmGlobalImportsEnsureCapacity(
    WasmGlobalImports* globalImports,
    size_t length
);

/* Memory imports */

typedef struct WasmMemoryImport {
    char* module;
    char* name;
    U32 min;
    U32 max;
} WasmMemoryImport;

static const WasmMemoryImport wasmEmptyMemoryImport = {NULL, NULL, 0, 0};

typedef struct WasmMemoryImports {
    WasmMemoryImport* imports;
    size_t length;
    size_t capacity;
} WasmMemoryImports;

bool
WARN_UNUSED_RESULT
wasmMemoryImportsEnsureCapacity(
    WasmMemoryImports* memoryImports,
    size_t length
);

/* Table imports */

typedef struct WasmTableImport {
    char* module;
    char* name;
    U32 min;
    U32 max;
} WasmTableImport;

static const WasmTableImport wasmEmptyTableImport = {NULL, NULL, 0, 0};

typedef struct WasmTableImports {
    WasmTableImport* imports;
    size_t length;
    size_t capacity;
} WasmTableImports;

bool
WARN_UNUSED_RESULT
wasmTableImportsEnsureCapacity(
    WasmTableImports* tableImports,
    size_t length
);

#endif /* W2C2_IMPORT_H */
