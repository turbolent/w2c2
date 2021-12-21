#ifndef W2C2_VALUETYPE_H
#define W2C2_VALUETYPE_H

#include "buffer.h"
#include "leb128.h"

typedef enum {
    wasmValueTypeI32,
    wasmValueTypeI64,
    wasmValueTypeF32,
    wasmValueTypeF64,
    wasmValueType_count
} WasmValueType;

const char*
WARN_UNUSED_RESULT
wasmValueTypeDescription(
    WasmValueType valueType
);

static
__inline__
bool
WARN_UNUSED_RESULT
wasmDecodeValueType(
    I32 encodedValueType,
    WasmValueType* result
) {
    switch (encodedValueType) {
        case -0x1: /* 0x7F */
            *result = wasmValueTypeI32;
            return true;
        case -0x2: /* 0x7E */
            *result = wasmValueTypeI64;
            return true;
        case -0x3: /* 0x7D */
            *result = wasmValueTypeF32;
            return true;
        case -0x4: /* 0x7C */
            *result = wasmValueTypeF64;
            return true;
        default: {
            return false;
        }
    }
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasmReadValueType(
    Buffer* buffer,
    WasmValueType* result
) {
    I32 encodedValueType = 0;

    MUST (leb128ReadI32(buffer, &encodedValueType))

    return wasmDecodeValueType(encodedValueType, result);
}


static
__inline__
bool
wasmReadBlockType(
    Buffer* buffer,
    WasmValueType** result
) {
    I32 encodedValueType = 0;

    MUST (leb128ReadI32(buffer, &encodedValueType))

    if (encodedValueType == -64 /* 0x40 */) {
        *result = NULL;
        return true;
    }

    return wasmDecodeValueType(encodedValueType, *result);
}


#endif /* W2C2_VALUETYPE_H */
