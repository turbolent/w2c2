#include <stdlib.h>
#include "import.h"

/* TODO: refactor */

bool
wasmFunctionImportsEnsureCapacity(
    WasmFunctionImports* functionImports,
    size_t length
) {
    if (length > functionImports->capacity) {
        size_t newCapacity = length + (functionImports->capacity >> 1u);
        void* newFunctionImports = NULL;
        if (functionImports->imports == NULL) {
            newFunctionImports = calloc(newCapacity * sizeof(WasmFunctionImport), 1);
        } else {
            newFunctionImports = realloc(functionImports->imports, newCapacity * sizeof(WasmFunctionImport));
        }
        if (newFunctionImports == NULL) {
            return false;
        }

        functionImports->imports = (WasmFunctionImport*) newFunctionImports;
        functionImports->capacity = newCapacity;
    }
    return true;
}

bool
wasmGlobalImportsEnsureCapacity(
    WasmGlobalImports* globalImports,
    size_t length
) {
    if (length > globalImports->capacity) {
        size_t newCapacity = length + (globalImports->capacity >> 1u);
        void* newGlobalImports = NULL;
        if (globalImports->imports == NULL) {
            newGlobalImports = calloc(newCapacity * sizeof(WasmGlobalImport), 1);
        } else {
            newGlobalImports = realloc(globalImports->imports, newCapacity * sizeof(WasmGlobalImport));
        }
        if (newGlobalImports == NULL) {
            return false;
        }

        globalImports->imports = (WasmGlobalImport*) newGlobalImports;
        globalImports->capacity = newCapacity;
    }
    return true;
}

bool
wasmMemoryImportsEnsureCapacity(
    WasmMemoryImports* memoryImports,
    size_t length
) {
    if (length > memoryImports->capacity) {
        size_t newCapacity = length + (memoryImports->capacity >> 1u);
        void* newMemoryImports = NULL;
        if (memoryImports->imports == NULL) {
            newMemoryImports = calloc(newCapacity * sizeof(WasmMemoryImport), 1);
        } else {
            newMemoryImports = realloc(memoryImports->imports, newCapacity * sizeof(WasmMemoryImport));
        }
        if (newMemoryImports == NULL) {
            return false;
        }

        memoryImports->imports = (WasmMemoryImport*) newMemoryImports;
        memoryImports->capacity = newCapacity;
    }
    return true;
}

bool
wasmTableImportsEnsureCapacity(
    WasmTableImports* tableImports,
    size_t length
) {
    if (length > tableImports->capacity) {
        size_t newCapacity = length + (tableImports->capacity >> 1u);
        void* newTableImports = NULL;
        if (tableImports->imports == NULL) {
            newTableImports = calloc(newCapacity * sizeof(WasmTableImport), 1);
        } else {
            newTableImports = realloc(tableImports->imports, newCapacity * sizeof(WasmTableImport));
        }
        if (newTableImports == NULL) {
            return false;
        }

        tableImports->imports = (WasmTableImport*) newTableImports;
        tableImports->capacity = newCapacity;
    }
    return true;
}
