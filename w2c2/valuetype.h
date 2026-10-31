#ifndef W2C2_VALUETYPE_H
#define W2C2_VALUETYPE_H

#include "buffer.h"
#include "leb128.h"
#include "w2c2_base.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum WasmValueType {
    wasmValueTypeI32,
    wasmValueTypeI64,
    wasmValueTypeF32,
    wasmValueTypeF64,
    wasmValueTypeV128,
    wasmValueTypeFuncRef,
    wasmValueTypeExternRef,
    wasmValueType_count
} WasmValueType;

/*
 * Indexed signatures refer to immutable module types.
 * Inline signatures store their result type by value,
 * so they remain valid when the control stack grows.
 */
typedef struct WasmBlockSignature {
    bool indexed;
    U32 typeIndex;
    WasmValueType type;
} WasmBlockSignature;

static const WasmBlockSignature wasmEmptyBlockSignature = {false, 0, wasmValueType_count};

/* The empty block type byte (0x40) decodes to -64 as signed LEB128. */
static const I32 wasmEmptyBlockTypeEncoding = -0x40;

const char*
WARN_UNUSED_RESULT
wasmValueTypeDescription(
    WasmValueType valueType
);

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmDecodeValueType(
    const I32 encodedValueType,
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
        case -0x5: /* 0x7B */
            *result = wasmValueTypeV128;
            return true;
        case -0x10: /* 0x70 */
            *result = wasmValueTypeFuncRef;
            return true;
        case -0x11: /* 0x6F */
            *result = wasmValueTypeExternRef;
            return true;
        default: {
            return false;
        }
    }
}

static
W2C2_INLINE
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
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmReadReferenceType(
    Buffer* buffer,
    WasmValueType* result
) {
    U8 encodedType;
    MUST (bufferReadByte(buffer, &encodedType))
    switch (encodedType) {
        case 0x70:
            *result = wasmValueTypeFuncRef;
            return true;
        case 0x6F:
            *result = wasmValueTypeExternRef;
            return true;
        default:
            return false;
    }
}

static
W2C2_INLINE
bool
wasmReadBlockType(
    Buffer* buffer,
    WasmValueType** result
) {
    I32 encodedValueType = 0;

    MUST (leb128ReadI32(buffer, &encodedValueType))

    if (encodedValueType == wasmEmptyBlockTypeEncoding) {
        *result = NULL;
        return true;
    }

    return wasmDecodeValueType(encodedValueType, *result);
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmReadBlockSignature(
    Buffer* buffer,
    WasmBlockSignature* result
) {
    I64 encoded = 0;

    *result = wasmEmptyBlockSignature;
    MUST (leb128ReadI33(buffer, &encoded))

    if (encoded >= 0) {
        result->indexed = true;
        result->typeIndex = (U32)encoded;
        return true;
    }
    if (encoded == wasmEmptyBlockTypeEncoding) {
        return true;
    }
    if (encoded < INT32_MIN) {
        return false;
    }

    return wasmDecodeValueType((I32)encoded, &result->type);
}


#ifdef __cplusplus
}
#endif

#endif /* W2C2_VALUETYPE_H */
