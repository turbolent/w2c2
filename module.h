#ifndef W2C2_MODULE_H
#define W2C2_MODULE_H

#include "w2c2_base.h"
#include "functiontype.h"
#include "function.h"
#include "export.h"
#include "global.h"
#include "import.h"
#include "memory.h"
#include "datasegment.h"
#include "table.h"
#include "elementsegment.h"
#include "debug.h"

typedef struct WasmFunctionTypes {
    WasmFunctionType* functionTypes;
    U32 count;
} WasmFunctionTypes;

typedef struct WasmFunctions {
    WasmFunction* functions;
    U32 count;
} WasmFunctions;

typedef struct WasmExports {
    WasmExport* exports;
    U32 count;
} WasmExports;

typedef struct WasmGlobals {
    WasmGlobal* globals;
    U32 count;
} WasmGlobals;

typedef struct WasmMemories {
    WasmMemory* memories;
    U32 count;
} WasmMemories;

typedef struct WasmDataSegments {
    WasmDataSegment* dataSegments;
    U32 count;
} WasmDataSegments;

typedef struct WasmTables {
    WasmTable* tables;
    U32 count;
} WasmTables;

typedef struct WasmElementSegments {
    WasmElementSegment* elementSegments;
    U32 count;
} WasmElementSegments;

typedef struct WasmModule {
    size_t length;
    WasmFunctionTypes functionTypes;
    WasmFunctions functions;
    WasmExports exports;
    WasmGlobals globals;
    WasmFunctionImports functionImports;
    WasmGlobalImports globalImports;
    WasmMemoryImports memoryImports;
    WasmMemories memories;
    WasmDataSegments dataSegments;
    WasmTableImports tableImports;
    WasmTables tables;
    WasmElementSegments elementSegments;
    U32 startFunctionIndex;
    bool hasStartFunction;
    WasmDebugSections debugSections;
    WasmDebugLines debugLines;
} WasmModule;

static
__inline__
bool
WARN_UNUSED_RESULT
wasmModuleFunctionGetLocalType(
    const WasmModule* module,
    const WasmFunction function,
    U32 localIndex,
    WasmValueType* result
) {
    const WasmFunctionType functionType =
        module->functionTypes.functionTypes[function.functionTypeIndex];

    if (localIndex < functionType.parameterCount) {
        *result = functionType.parameterTypes[localIndex];
        return true;
    }

    return wasmLocalsDeclarationsGetType(
        function.localsDeclarations,
        localIndex - functionType.parameterCount,
        result
    );
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmModuleGetGlobalType(
    const WasmModule* module,
    U32 globalIndex,
    WasmValueType* result
) {
    if (globalIndex < module->globalImports.length) {
        WasmGlobalImport import = module->globalImports.imports[globalIndex];
        *result = import.globalType.valueType;
    } else {
        globalIndex -= module->globalImports.length;
        MUST (globalIndex < module->globals.count)
        {
            WasmGlobal global = module->globals.globals[globalIndex];
            *result = global.type.valueType;
        }
    }
    return true;
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmModuleGetFunctionType(
    const WasmModule* module,
    U32 functionIndex,
    WasmFunctionType* result
) {
    if (functionIndex < module->functionImports.length) {
        WasmFunctionImport import = module->functionImports.imports[functionIndex];
        *result = module->functionTypes.functionTypes[import.functionTypeIndex];
    } else {
        functionIndex -= module->functionImports.length;
        MUST (functionIndex < module->functions.count)
        {
            const WasmFunction function = module->functions.functions[functionIndex];
            *result = module->functionTypes.functionTypes[function.functionTypeIndex];
        }
    }
    return true;
}

bool
WARN_UNUSED_RESULT
wasmDebugSectionsEnsureCapacity(
    WasmDebugSections* debugSections,
    size_t count
);

static
__inline__
bool
WARN_UNUSED_RESULT
wasmDebugSectionsAppend(
    WasmDebugSections* debugSections,
    WasmDebugSection debugSection
) {
    const size_t newCount = debugSections->count + 1;
    MUST (wasmDebugSectionsEnsureCapacity(debugSections, newCount))

    debugSections->debugSections[debugSections->count] = debugSection;
    debugSections->count = newCount;

    return true;
}

#endif /* W2C2_MODULE_H */
