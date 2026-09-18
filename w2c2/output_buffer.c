#include <stdlib.h>
#include <string.h>

#include "output_buffer.h"

bool
outputBufferInitialize(OutputBuffer* buffer) {
    static const size_t initialCapacity = 8;
    U8* data;
    MUST (buffer->data == NULL)
    data = (U8*)malloc(initialCapacity);
    MUST (data != NULL)
    data[0] = 0;
    buffer->data = data;
    buffer->length = 0;
    buffer->capacity = initialCapacity;
    return true;
}

bool
outputBufferAppend(OutputBuffer* buffer, const U8* bytes, size_t length) {
    size_t newLength;
    size_t requiredCapacity;
    if (length == 0) {
        return true;
    }
    MUST (length < (size_t)-1 - buffer->length)
    newLength = buffer->length + length;
    requiredCapacity = newLength + 1;
    if (requiredCapacity > buffer->capacity) {
        const size_t extra = buffer->capacity >> 1U;
        const size_t capacity = extra <= (size_t)-1 - requiredCapacity
            ? requiredCapacity + extra : requiredCapacity;
        U8* data = (U8*)realloc(buffer->data, capacity);
        MUST (data != NULL)
        buffer->data = data;
        buffer->capacity = capacity;
    }
    memcpy(buffer->data + buffer->length, bytes, length);
    buffer->length = newLength;
    buffer->data[newLength] = 0;
    return true;
}

void
outputBufferFree(OutputBuffer* buffer) {
    free(buffer->data);
    *buffer = emptyOutputBuffer;
}
