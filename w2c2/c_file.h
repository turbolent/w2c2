#ifndef W2C2_C_FILE_H
#define W2C2_C_FILE_H

#include "c.h"
#include "diagnostic_internal.h"

typedef struct WasmCOutputNames {
    const char* implementation;
    char* header;
    char* prefix;
    char* data;
    size_t staticCount;
    size_t dynamicCount;
    bool split;
} WasmCOutputNames;

static const WasmCOutputNames emptyWasmCOutputNames = {NULL, NULL, NULL, NULL, 0, 0, false};

/*
 * File prefixes use m<original byte length>_ followed by encoded bytes.
 * Lowercase ASCII letters and digits remain literal except x;
 * other bytes become xhh with lowercase hex digits.
 * The encoding remains distinct on case-insensitive filesystems.
 */
char*
wasmCFilePrefix(const char* moduleName, WasmDiagnosticContext* diagnostics);

bool
WARN_UNUSED_RESULT
wasmCOutputNamesInitialize(
    WasmCOutputNames* names,
    const WasmModule* module,
    const char* moduleName,
    WasmCWriteModuleOptions options,
    WasmFunctionIDs staticIDs,
    WasmFunctionIDs dynamicIDs,
    WasmDiagnosticContext* diagnostics
);

void
wasmCOutputNamesFree(WasmCOutputNames* names);

char*
wasmCImplementationFileName(const char* prefix, char kind, U32 index);

bool
wasmCImplementationFileIndex(const char* name, const char* prefix, char* kind, U32* index);

bool
wasmCFileNamesEqual(const char* first, const char* second);

#endif /* W2C2_C_FILE_H */
