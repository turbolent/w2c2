#ifndef W2C2_OUTPUT_BUFFER_H
#define W2C2_OUTPUT_BUFFER_H

#include "w2c2_base.h"

/* Initialized buffers always have a trailing zero at data[length]. */
typedef struct OutputBuffer {
    U8* data;
    size_t length;
    size_t capacity;
} OutputBuffer;

static const OutputBuffer emptyOutputBuffer = {NULL, 0, 0};

bool
WARN_UNUSED_RESULT
outputBufferInitialize(OutputBuffer* buffer);

bool
WARN_UNUSED_RESULT
outputBufferAppend(OutputBuffer* buffer, const U8* bytes, size_t length);

void
outputBufferFree(OutputBuffer* buffer);

#endif /* W2C2_OUTPUT_BUFFER_H */
