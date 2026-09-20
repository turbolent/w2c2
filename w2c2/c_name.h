#ifndef W2C2_C_NAME_H
#define W2C2_C_NAME_H

#include "output_internal.h"

static
W2C2_INLINE
bool
wasmCNameByteIsLiteral(const U8 c, const bool filename) {
    return c != (filename ? 'x' : 'X')
        && ((c >= 'a' && c <= 'z')
            || (!filename && c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'));
}

static
W2C2_INLINE
void
wasmCWriteNameComponent(
    WasmOutput* file,
    const WasmName name,
    const bool filename
) {
    const char* hex = filename ? "0123456789abcdef" : "0123456789ABCDEF";
    size_t index;
    wasmOutputU64(file, name.length);
    wasmOutputChar(file, '_');
    for (index = 0; index < name.length; index++) {
        const U8 c = (U8)name.data[index];
        if (wasmCNameByteIsLiteral(c, filename)) {
            wasmOutputChar(file, (char)c);
        } else {
            U8 escaped[3];
            escaped[0] = filename ? 'x' : 'X';
            escaped[1] = (U8)hex[c >> 4];
            escaped[2] = (U8)hex[c & 15];
            wasmOutputWrite(file, escaped, sizeof(escaped));
        }
    }
}

static
W2C2_INLINE
bool
wasmCModuleNameFits(const char* moduleName, const size_t limit) {
    size_t digits = strlen(moduleName);
    size_t length = 2; /* m and _ */
    do {
        length++;
        digits /= 10;
    } while (digits != 0);
    for (; *moduleName != '\0'; moduleName++) {
        const size_t width = wasmCNameByteIsLiteral((U8)*moduleName, false) ? 1 : 3;
        if (length > limit || width > limit - length) {
            return false;
        }
        length += width;
    }
    return length <= limit;
}

static
W2C2_INLINE
void
wasmCWriteModuleName(
    WasmOutput* file,
    const char* moduleName
) {
    wasmOutputString(file, "m");
    wasmCWriteNameComponent(file, wasmNameFromBytes((char*)moduleName, strlen(moduleName)), false);
}

static
W2C2_INLINE
void
wasmCWriteDataName(
    WasmOutput* file,
    const char* moduleName
) {
    wasmCWriteModuleName(file, moduleName);
    wasmOutputString(file, "Data");
}

static
W2C2_INLINE
void
wasmCWriteDataSegmentName(
    WasmOutput* file,
    const char* moduleName,
    const U32 dataSegmentIndex
) {
    wasmCWriteDataName(file, moduleName);
    wasmOutputU32(file, dataSegmentIndex);
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
    wasmCWriteNameComponent(file, module, false);
    wasmCWriteNameComponent(file, name, false);
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
    wasmCWriteNameComponent(file, name, false);
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
    wasmCWriteNameComponent(file, name, false);
}

#endif /* W2C2_C_NAME_H */
