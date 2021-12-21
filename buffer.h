#ifndef W2C2_BUFFER_H
#define W2C2_BUFFER_H

#include <string.h>
#include "w2c2_base.h"

typedef struct Buffer {
    U8* data;
    size_t length;
} Buffer;

static
__inline__
void
bufferSkipUnchecked(
    Buffer* buffer,
    const size_t length
) {
    buffer->data += length;
    buffer->length -= length;
}

static
__inline__
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
__inline__
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

static
__inline__
bool
WARN_UNUSED_RESULT
bufferReadF32(
    Buffer* buffer,
    F32* result
) {
    if (buffer->length < sizeof(F32)) {
        return false;
    } else {
        union {
            F32 f32;
            I32 i32;
            U8 bytes[sizeof(F32)];
        } value = {0};

        memcpy(value.bytes, buffer->data, sizeof(F32));

        value.i32 = swap32(value.i32);

        *result = value.f32;

        bufferSkipUnchecked(buffer, sizeof(F32));

        return true;
    }
}

static
__inline__
bool
WARN_UNUSED_RESULT
bufferReadF64(
    Buffer* buffer,
    F64* result
) {
    if (buffer->length < sizeof(F64)) {
        return false;
    } else {
        union {
            F64 f64;
            I64 i64;
            U8 bytes[sizeof(F64)];
        } value = {0};

        memcpy(value.bytes, buffer->data, sizeof(F64));

        value.i64 = swap64(value.i64);

        *result = value.f64;

        bufferSkipUnchecked(buffer, sizeof(F64));

        return true;
    }
}


static
__inline__
bool
WARN_UNUSED_RESULT
bufferAtEnd(
    const Buffer* buffer
) {
    return buffer->length <= 0;
}

static
__inline__
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
