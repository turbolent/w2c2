#include <stdlib.h>

#include "module.h"

static
int
wasmFunctionIDsCompareHashes(
    const void* a,
    const void* b
) {
    const WasmFunctionID* functionIDA = a;
    const WasmFunctionID* functionIDB = b;
    return memcmp(functionIDA->hash, functionIDB->hash, SHA1_DIGEST_LENGTH);
}

WasmBool
WARN_UNUSED_RESULT
wasmFunctionIDsInitialize(
    const WasmFunctions functions,
    const WasmBool sortByHash,
    WasmFunctionIDs* result
) {
    WasmFunctionIDs functionIDs = emptyWasmFunctionIDs;

    U32 functionIndex = 0;
    if (!wasmFunctionIDsEnsureCapacity(&functionIDs, functions.count)) {
        return false;
    }
    functionIDs.length = functions.count;
    for (; functionIndex < functions.count; functionIndex++) {
        WasmFunctionID* functionID = &functionIDs.functionIDs[functionIndex];
        *functionID = emptyWasmFunctionID;
        functionID->functionIndex = functionIndex;
        if (sortByHash) {
            const Buffer body = functions.functions[functionIndex].body;
            /* Hash of the locals (as declared in the binary) and the code */
            SHA1(body.data, body.length, functionID->hash);
        }
    }

    if (sortByHash && functionIDs.length > 1) {
        qsort(
            functionIDs.functionIDs,
            functionIDs.length,
            sizeof(WasmFunctionID),
            wasmFunctionIDsCompareHashes
        );
    }

    *result = functionIDs;
    return true;
}

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
        free(import->module.data);
        free(import->name.data);
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
        free(import->module.data);
        free(import->name.data);
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
        free(import->module.data);
        free(import->name.data);
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
        free(import->module.data);
        free(import->name.data);
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
        free(exports->exports[index].name.data);
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
        free(debugSections->debugSections[index].name.data);
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
        free(functionNames->names[index].data);
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
