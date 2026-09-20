#include "w2c2.h"
#include "c.h"
#include "diagnostic_internal.h"
#include "reader.h"

WasmBool
wasmTranslate(
    const U8* bytes,
    size_t length,
    const char* moduleName,
    const WasmCWriteModuleOptions* options
) {
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    WasmFunctionIDs functionIDs = emptyWasmFunctionIDs;
    WasmDiagnosticContext diagnostics = emptyWasmDiagnosticContext;
    WasmCWriteModuleOptions writeOptions;
    WasmBool result = false;

    if (options == NULL) {
        return false;
    }
    diagnostics.diagnostics = options->diagnostics;
    if (bytes == NULL || moduleName == NULL || moduleName[0] == '\0'
        || options->outputName == NULL || options->outputName[0] == '\0'
        || options->output.open == NULL) {
        wasmDiagnosticReportInvalidTranslationArgument(&diagnostics);
        return false;
    }

    reader.buffer.data = (U8*)bytes;
    reader.buffer.length = length;
    reader.debug = options->debug;
    reader.diagnostics = options->diagnostics;
    wasmModuleRead(&reader, &error);
    if (error != NULL) {
        goto cleanup;
    }
    writeOptions = *options;
    if (writeOptions.functionsPerFile == 0) {
        writeOptions.functionsPerFile = reader.module->functions.count;
    }
    if (!wasmFunctionIDsInitialize(
        reader.module->functions,
        writeOptions.functionsPerFile < reader.module->functions.count,
        &functionIDs
    )) {
        wasmDiagnosticReportAllocationFailed(&diagnostics);
        goto cleanup;
    }
    result = wasmCWriteModule(
        reader.module, moduleName, writeOptions,
        functionIDs, emptyWasmFunctionIDs
    );

cleanup:
    wasmFunctionIDsFree(&functionIDs);
    wasmModuleFree(reader.module);
    return result;
}
