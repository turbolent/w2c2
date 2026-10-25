#include <stdio.h>

#include "c_file.h"
#include "c_name.h"
#include "output_internal.h"

#define IMPLEMENTATION_SUFFIX_LENGTH 14

char*
wasmCFilePrefix(const char* moduleName, WasmDiagnosticContext* diagnostics) {
    OutputBuffer buffer = emptyOutputBuffer;
    WasmOutput output;
    if (!outputBufferInitialize(&buffer)) {
        wasmDiagnosticReportAllocationFailed(diagnostics);
        return NULL;
    }
    output = wasmOutputForBuffer(&buffer, diagnostics);
    wasmOutputChar(&output, 'm');
    wasmCWriteNameComponent(&output, wasmNameFromBytes(moduleName, strlen(moduleName)), true);
    if (!wasmOutputClose(&output)) {
        outputBufferFree(&buffer);
        return NULL;
    }
    return (char*)buffer.data;
}

static
char
foldASCII(const char c) {
    return c >= 'A' && c <= 'Z' ? (char)(c + ('a' - 'A')) : c;
}

bool
wasmCFileNamesEqual(const char* first, const char* second) {
    while (*first != '\0' && foldASCII(*first) == foldASCII(*second)) {
        first++;
        second++;
    }
    return *first == '\0' && *second == '\0';
}

static
char*
appendSuffix(const char* prefix, const size_t length, const char* suffix) {
    const size_t suffixSize = strlen(suffix) + 1;
    char* name;
    if (length > (size_t)-1 - suffixSize) {
        return NULL;
    }
    name = (char*)malloc(length + suffixSize);
    if (name != NULL) {
        memcpy(name, prefix, length);
        memcpy(name + length, suffix, suffixSize);
    }
    return name;
}

char*
wasmCImplementationFileName(const char* prefix, const char kind, const U32 index) {
    char suffix[IMPLEMENTATION_SUFFIX_LENGTH + 1];
    sprintf(suffix, ".%c%010lu.c", kind, (unsigned long)index);
    return appendSuffix(prefix, strlen(prefix), suffix);
}

bool
wasmCImplementationFileIndex(
    const char* name, const char* prefix, char* kind, U32* index
) {
    size_t offset;
    U32 value = 0;
    for (; *prefix != '\0'; prefix++, name++) {
        if (foldASCII(*name) != *prefix) {
            return false;
        }
    }
    if (strlen(name) != IMPLEMENTATION_SUFFIX_LENGTH
        || name[0] != '.' || (foldASCII(name[1]) != 's' && foldASCII(name[1]) != 'd')
        || name[12] != '.' || foldASCII(name[13]) != 'c') {
        return false;
    }
    for (offset = 2; offset < 12; offset++) {
        U32 digit;
        if (name[offset] < '0' || name[offset] > '9') {
            return false;
        }
        digit = (U32)(name[offset] - '0');
        if (value > (UINT32_MAX - digit) / 10) {
            return false;
        }
        value = value * 10 + digit;
    }
    *kind = foldASCII(name[1]);
    *index = value;
    return true;
}

static
bool
validOutputName(const char* name) {
    size_t index;
    if (name[0] == '\0' || strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
        return false;
    }
    for (index = 0; name[index] != '\0'; index++) {
        const U8 c = (U8)name[index];
        if (c < 32 || c == 127 || c == '"' || c == '/' || c == '\\') {
            return false;
        }
        if (c == '?' && name[index + 1] == '?' && name[index + 2] != '\0'
            && strchr("=/'()!<>-", name[index + 2]) != NULL) {
            return false;
        }
    }
    return true;
}

static
bool
conflictsWithAuxiliary(const WasmCOutputNames* names, const char* name) {
    char kind;
    U32 index;
    if (names->data != NULL && wasmCFileNamesEqual(name, names->data)) {
        return true;
    }
    if (wasmCImplementationFileIndex(name, names->prefix, &kind, &index)) {
        return index < (kind == 's' ? names->staticCount : names->dynamicCount);
    }
    return false;
}

bool
wasmCOutputNamesInitialize(
    WasmCOutputNames* names,
    const WasmModule* module,
    const char* moduleName,
    const WasmCWriteModuleOptions options,
    const WasmFunctionIDs staticIDs,
    const WasmFunctionIDs dynamicIDs,
    WasmDiagnosticContext* diagnostics
) {
    const char* outputName = options.outputName;
    const U32 perFile = options.functionsPerFile == 0 ? UINT32_MAX : options.functionsPerFile;
    const char* extension = strrchr(outputName, '.');
    if (!validOutputName(outputName)) {
        wasmDiagnosticReportOutputName(diagnostics, wasmDiagnosticInvalidOutputName, outputName);
        return false;
    }
    if ((options.dataSegmentMode == wasmDataSegmentModeSectcreate1
            || options.dataSegmentMode == wasmDataSegmentModeSectcreate2)
        && !wasmCModuleNameFits(moduleName, 16)) {
        wasmDiagnosticReportDataSectionNameTooLong(diagnostics);
        return false;
    }

    names->implementation = outputName;
    names->split = options.functionsPerFile < module->functions.count || dynamicIDs.length != 0;
    if (names->split) {
        names->staticCount = staticIDs.length == 0 ? 0 : 1 + (staticIDs.length - 1) / perFile;
        names->dynamicCount = dynamicIDs.length == 0 ? 0 : 1 + (dynamicIDs.length - 1) / perFile;
    }
    names->prefix = wasmCFilePrefix(moduleName, diagnostics);
    if (names->prefix == NULL) {
        goto failure;
    }
    names->header = appendSuffix(outputName,
        extension == NULL ? strlen(outputName) : (size_t)(extension - outputName), ".h");
    if (options.dataSegmentMode != wasmDataSegmentModeArrays) {
        names->data = appendSuffix(names->prefix, strlen(names->prefix), ".data");
    }
    if (names->header == NULL || (options.dataSegmentMode != wasmDataSegmentModeArrays && names->data == NULL)) {
        wasmDiagnosticReportAllocationFailed(diagnostics);
        goto failure;
    }
    /*
     * Static and dynamic filenames are disjoint by construction.
     * Their fixed-width indices are unique within each group.
     * Check both caller-derived names against every emitted group
     * without allocating a list proportional to the number of files.
     */
    if (wasmCFileNamesEqual(outputName, names->header) || conflictsWithAuxiliary(names, outputName)) {
        wasmDiagnosticReportOutputName(diagnostics, wasmDiagnosticOutputNameConflict, outputName);
        goto failure;
    }
    /* The header's .h suffix cannot match a split source or external data file. */
    if (wasmCFileNamesEqual(names->header, "w2c2_base.h")) {
        wasmDiagnosticReportOutputName(diagnostics, wasmDiagnosticOutputNameConflict, names->header);
        goto failure;
    }
    return true;

failure:
    wasmCOutputNamesFree(names);
    return false;
}

void
wasmCOutputNamesFree(WasmCOutputNames* names) {
    free(names->header);
    free(names->prefix);
    free(names->data);
    *names = emptyWasmCOutputNames;
}
