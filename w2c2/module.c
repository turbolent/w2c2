#include <stdlib.h>

#include "module.h"

static
void
wasmModuleFunctionTypesFree(
    WasmFunctionTypes* functionTypes
) {
    U32 index = 0;

    for (; index < functionTypes->count; index++) {
        WasmFunctionType* functionType = &functionTypes->functionTypes[index];
        free(functionType->parameterTypes);
        free(functionType->resultTypes);
    }
    free(functionTypes->functionTypes);
    functionTypes->functionTypes = NULL;
    functionTypes->count = 0;
}

static
void
wasmModuleFunctionImportsFree(
    WasmFunctionImports* functionImports
) {
    size_t index = 0;

    for (; index < functionImports->length; index++) {
        WasmFunctionImport* import = &functionImports->imports[index];
        free(import->module);
        free(import->name);
    }
    wasmFunctionImportsFree(functionImports);
}

static
void
wasmModuleGlobalImportsFree(
    WasmGlobalImports* globalImports
) {
    size_t index = 0;

    for (; index < globalImports->length; index++) {
        WasmGlobalImport* import = &globalImports->imports[index];
        free(import->module);
        free(import->name);
    }
    wasmGlobalImportsFree(globalImports);
}

static
void
wasmModuleMemoryImportsFree(
    WasmMemoryImports* memoryImports
) {
    size_t index = 0;

    for (; index < memoryImports->length; index++) {
        WasmMemoryImport* import = &memoryImports->imports[index];
        free(import->module);
        free(import->name);
    }
    wasmMemoryImportsFree(memoryImports);
}

static
void
wasmModuleTableImportsFree(
    WasmTableImports* tableImports
) {
    size_t index = 0;

    for (; index < tableImports->length; index++) {
        WasmTableImport* import = &tableImports->imports[index];
        free(import->module);
        free(import->name);
    }
    wasmTableImportsFree(tableImports);
}

static
void
wasmModuleFunctionsFree(
    WasmFunctions* functions
) {
    U32 index = 0;

    for (; index < functions->count; index++) {
        free(functions->functions[index].localsDeclarations.declarations);
    }
    free(functions->functions);
    functions->functions = NULL;
    functions->count = 0;
}

static
void
wasmModuleExportsFree(
    WasmExports* exports
) {
    U32 index = 0;

    for (; index < exports->count; index++) {
        free(exports->exports[index].name);
    }
    free(exports->exports);
    exports->exports = NULL;
    exports->count = 0;
}

static
void
wasmModuleGlobalsFree(
    WasmGlobals* globals
) {
    free(globals->globals);
    globals->globals = NULL;
    globals->count = 0;
}

static
void
wasmModuleMemoriesFree(
    WasmMemories* memories
) {
    free(memories->memories);
    memories->memories = NULL;
    memories->count = 0;
}

static
void
wasmModuleDataSegmentsFree(
    WasmDataSegments* dataSegments
) {
    U32 index = 0;

    for (; index < dataSegments->count; index++) {
        bufferFree(&dataSegments->dataSegments[index].bytes);
    }
    free(dataSegments->dataSegments);
    dataSegments->dataSegments = NULL;
    dataSegments->count = 0;
}

static
void
wasmModuleTablesFree(
    WasmTables* tables
) {
    free(tables->tables);
    tables->tables = NULL;
    tables->count = 0;
}

static
void
wasmModuleElementSegmentsFree(
    WasmElementSegments* elementSegments
) {
    U32 index = 0;

    for (; index < elementSegments->count; index++) {
        free(elementSegments->elementSegments[index].functionIndices);
    }
    free(elementSegments->elementSegments);
    elementSegments->elementSegments = NULL;
    elementSegments->count = 0;
}

static
void
wasmModuleDebugSectionsFree(
    WasmDebugSections* debugSections
) {
    size_t index = 0;

    for (; index < debugSections->length; index++) {
        free(debugSections->debugSections[index].name);
    }
    wasmDebugSectionsFree(debugSections);
}

static
void
wasmModuleDebugLinesFree(
    WasmDebugLines* debugLines
) {
    size_t index = 0;

    for (; index < debugLines->length; index++) {
        free(debugLines->debugLines[index].path);
    }
    wasmDebugLinesFree(debugLines);
}

static
void
wasmModuleFunctionNamesFree(
    WasmNames* functionNames
) {
    size_t index = 0;

    for (; index < functionNames->length; index++) {
        free(functionNames->names[index]);
    }
    wasmNamesFree(functionNames);
}

void
wasmModuleFree(
    WasmModule* module
) {
    if (module == NULL) {
        return;
    }

    wasmModuleFunctionTypesFree(&module->functionTypes);
    wasmModuleFunctionImportsFree(&module->functionImports);
    wasmModuleGlobalImportsFree(&module->globalImports);
    wasmModuleMemoryImportsFree(&module->memoryImports);
    wasmModuleTableImportsFree(&module->tableImports);
    wasmModuleFunctionsFree(&module->functions);
    wasmModuleExportsFree(&module->exports);
    wasmModuleGlobalsFree(&module->globals);
    wasmModuleMemoriesFree(&module->memories);
    wasmModuleDataSegmentsFree(&module->dataSegments);
    wasmModuleTablesFree(&module->tables);
    wasmModuleElementSegmentsFree(&module->elementSegments);
    wasmModuleDebugSectionsFree(&module->debugSections);
    wasmModuleDebugLinesFree(&module->debugLines);
    wasmModuleFunctionNamesFree(&module->functionNames);

    free(module);
}
