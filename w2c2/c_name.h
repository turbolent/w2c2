#ifndef W2C2_C_NAME_H
#define W2C2_C_NAME_H

#include "output_internal.h"

static
W2C2_INLINE
void
wasmCWriteNameComponent(
    WasmOutput* file,
    const WasmName name
) {
    size_t index;
    wasmOutputU64(file, name.length);
    wasmOutputChar(file, '_');
    for (index = 0; index < name.length; index++) {
        const U8 c = (U8)name.data[index];
        if ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z' && c != 'X')
            || (c >= '0' && c <= '9')) {
            wasmOutputChar(file, (char)c);
        } else {
            wasmOutputChar(file, 'X');
            wasmOutputHex(file, c, wasmOutputHexUpperPadded);
        }
    }
}

static
W2C2_INLINE
void
wasmCWriteModuleName(
    WasmOutput* file,
    const char* moduleName
) {
    wasmOutputString(file, "m");
    wasmCWriteNameComponent(file, wasmNameFromBytes((char*)moduleName, strlen(moduleName)));
}

static
W2C2_INLINE
void
wasmCWriteFunctionImportName(
    WasmOutput* file,
    const char* moduleName,
    const WasmName module,
    const WasmName name
) {
    if (moduleName != NULL) {
        wasmCWriteModuleName(file, moduleName);
        wasmOutputString(file, "Import");
    } else {
        wasmOutputString(file, "i");
    }
    wasmCWriteNameComponent(file, module);
    wasmCWriteNameComponent(file, name);
}

static
W2C2_INLINE
void
wasmCWriteExportName(
    WasmOutput* file,
    const char* moduleName,
    const WasmName name
) {
    wasmCWriteModuleName(file, moduleName);
    wasmOutputString(file, "Export");
    wasmCWriteNameComponent(file, name);
}

static
W2C2_INLINE
void
wasmCWriteFunctionName(
    WasmOutput* file,
    const char* moduleName,
    const U32 functionIndex
) {
    if (moduleName != NULL) {
        wasmCWriteModuleName(file, moduleName);
        wasmOutputString(file, "Function");
    } else {
        wasmOutputString(file, "f");
    }
    wasmOutputU32(file, functionIndex);
}

static
W2C2_INLINE
void
wasmCWriteDebugName(
    WasmOutput* file,
    const char* moduleName,
    const U32 functionIndex,
    const WasmName name
) {
    wasmCWriteModuleName(file, moduleName);
    wasmOutputString(file, "Debug");
    wasmOutputU32(file, functionIndex);
    wasmOutputString(file, "Name");
    wasmCWriteNameComponent(file, name);
}

#endif /* W2C2_C_NAME_H */
