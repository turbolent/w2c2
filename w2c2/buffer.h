#ifndef W2C2_BUFFER_H
#define W2C2_BUFFER_H

#include <string.h>
#include "w2c2_base.h"

typedef struct Buffer {
    U8* data;
    size_t length;
} Buffer;

static
W2C2_INLINE
void
bufferSkipUnchecked(
    Buffer* buffer,
    const size_t length
) {
    buffer->data += length;
    buffer->length -= length;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
bufferReadEqual(
    Buffer* buffer,
    const U8* data,
    const size_t length
) {
    if (buffer->length < length) {
        return false;
    }
    if (memcmp(buffer->data, data, length) != 0) {
        return false;
    }

    bufferSkipUnchecked(buffer, length);

    return true;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
bufferReadByte(
    Buffer* buffer,
    U8* result
) {
    if (buffer->length < sizeof(U8)) {
        return false;
    }

    *result = *buffer->data;

    bufferSkipUnchecked(buffer, sizeof(U8));

    return true;
}

/* Read a 32-bit float as an I32, which prevents x87 NaN canonicalization */
static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
bufferReadF32(
    Buffer* buffer,
    I32* result
) {
    if (buffer->length < sizeof(I32)) {
        return false;
    } else {
        union {
            I32 i32;
            U8 bytes[sizeof(I32)];
        } value = {0};

        memcpy(value.bytes, buffer->data, sizeof(I32));

#if WASM_ENDIAN == WASM_BIG_ENDIAN
        value.i32 = (I32) swapU32((U32) value.i32);
#endif

        *result = value.i32;

        bufferSkipUnchecked(buffer, sizeof(I32));

        return true;
    }
}

/* Read a 64-bit float as an I64, which prevents x87 NaN canonicalization */
static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
bufferReadF64(
    Buffer* buffer,
    I64* result
) {
    if (buffer->length < sizeof(I64)) {
        return false;
    } else {
        union {
            I64 i64;
            U8 bytes[sizeof(I64)];
        } value = {0};

        memcpy(value.bytes, buffer->data, sizeof(I64));

#if WASM_ENDIAN == WASM_BIG_ENDIAN
        value.i64 = (I64) swapU64((U64) value.i64);
#endif
        *result = value.i64;

        bufferSkipUnchecked(buffer, sizeof(I64));

        return true;
    }
}


static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
bufferAtEnd(
    const Buffer* buffer
) {
    return buffer->length <= 0;
}

static
W2C2_INLINE
void
bufferSkip(
    Buffer* buffer,
    size_t length
) {
    if (buffer->length < length) {
        length = buffer->length;
    }

    bufferSkipUnchecked(buffer, length);
}

#endif /* W2C2_BUFFER_H */
