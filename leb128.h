#ifndef W2C2_LEB128_H
#define W2C2_LEB128_H

#include "w2c2_base.h"
#include <stddef.h>
#include "buffer.h"

/*
 * int32LEB128MaxByteCount is the maximum number of bytes a 32-bit integer
 * (signed or unsigned) may be encoded as. From
 * https://webassembly.github.io/spec/core/binary/values.html#binary-int:
 *
 * "the total number of bytes encoding a value of type uN must not exceed ceil(N/7) bytes"
 * "the total number of bytes encoding a value of type sN must not exceed ceil(N/7) bytes"
 */
#define int32LEB128MaxByteCount 5

/*
 * leb128ReadU32 reads and decodes an unsigned 32-bit integer
 * from the given buffer and stores the value in result.
 * Returns the number of read bytes.
 */
static
W2C2_INLINE
size_t
leb128ReadU32(
    Buffer* buffer,
    U32* result
) {
    U32 value = 0;
    U32 shift = 0;
    size_t count = 0;
    U8 byte = 0;

    /* Only read up to maximum number of bytes */
    while (count < int32LEB128MaxByteCount && bufferReadByte(buffer, &byte)) {
        count++;

        value |= ((U32) (byte & 0x7F)) << shift;

        shift += 7;

        /* Check the high order bit of byte */
        if ((byte & 0x80) == 0) {
            break;
        }
    }

    *result = value;

    return count;
}

/*
 * leb128ReadI32 reads and decodes a signed 32-bit integer
 * from the given buffer and stores the value in result.
 * Returns the number of read bytes.
 */
static
W2C2_INLINE
size_t
leb128ReadI32(
    Buffer* buffer,
    I32* result
) {
    I32 value = 0;
    U32 shift = 0;
    size_t count = 0;
    U8 byte = 0;

    /* Only read up to maximum number of bytes */
    while (count < int32LEB128MaxByteCount && bufferReadByte(buffer, &byte)) {
        count++;

        value |= (I32) (((U32) (byte & 0x7F)) << shift);

        shift += 7;

        /* Check the high order bit of byte */
        if ((byte & 0x80) == 0) {
            break;
        }
    }

    if ((shift < 8 * sizeof(I32)) && (byte & 0x40)) {
        value |= -((I32) 1 << shift);
    }

    *result = value;

    return count;
}

/*
 * int64LEB128MaxByteCount is the maximum number of bytes a 64-bit integer
 * (signed or unsigned) may be encoded as. From
 * https://webassembly.github.io/spec/core/binary/values.html#binary-int:
 *
 * "the total number of bytes encoding a value of type uN must not exceed ceil(N/7) bytes"
 * "the total number of bytes encoding a value of type sN must not exceed ceil(N/7) bytes"
 */
#define int64LEB128MaxByteCount 10

/*
 * leb128ReadU64 reads and decodes an unsigned 32-bit integer
 * from the given buffer and stores the value in result.
 * Returns the number of read bytes.
 */
static
W2C2_INLINE
size_t
leb128ReadU64(
    Buffer* buffer,
    U64* result
) {
    U64 value = 0;
    U64 shift = 0;
    size_t count = 0;
    U8 byte = 0;

    /* Only read up to maximum number of bytes */
    while (count < int64LEB128MaxByteCount && bufferReadByte(buffer, &byte)) {
        count++;

        value |= ((U64) (byte & 0x7F)) << shift;

        shift += 7;

        /* Check the high order bit of byte */
        if ((byte & 0x80) == 0) {
            break;
        }
    }

    *result = value;

    return count;
}

/*
 * leb128ReadI64 reads and decodes a signed 32-bit integer
 * from the given buffer and stores the value in result.
 * Returns the number of read bytes.
 */
static
W2C2_INLINE
size_t
leb128ReadI64(
    Buffer* buffer,
    I64* result
) {
    I64 value = 0;
    U64 shift = 0;
    size_t count = 0;
    U8 byte = 0;

    /* Only read up to maximum number of bytes */
    while (count < int64LEB128MaxByteCount && bufferReadByte(buffer, &byte)) {
        count++;

        value |= (I64) (((U64) (byte & 0x7F)) << shift);

        shift += 7;

        /* Check the high order bit of byte */
        if ((byte & 0x80) == 0) {
            break;
        }
    }

    if ((shift < 8 * sizeof(I64)) && (byte & 0x40)) {
        value |= -((I64) 1 << shift);
    }

    *result = value;

    return count;
}


#endif /* W2C2_LEB128_H */
