#ifndef W2C2_STRINGBUILDER_H
#define W2C2_STRINGBUILDER_H

#include "w2c2_base.h"
#include <stdarg.h>

typedef struct StringBuilder {
    char* string;
    size_t length;
    size_t capacity;
} StringBuilder;

static const StringBuilder emptyStringBuilder = {NULL, 0, 0};

bool
WARN_UNUSED_RESULT
stringBuilderInitialize(
    StringBuilder* stringBuilder
);

bool
WARN_UNUSED_RESULT
stringBuilderReset(
    StringBuilder* stringBuilder
);

void
stringBuilderFree(
    StringBuilder* stringBuilder
);


bool
WARN_UNUSED_RESULT
stringBuilderAppendSized(
    StringBuilder* stringBuilder,
    const char* string,
    size_t length
);

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
stringBuilderAppend(
    StringBuilder* stringBuilder,
    const char* string
) {
    return stringBuilderAppendSized(
        stringBuilder,
        string,
        strlen(string)
    );
}

bool
WARN_UNUSED_RESULT
stringBuilderAppendChar(
    StringBuilder* stringBuilder,
    char c
);

bool
WARN_UNUSED_RESULT
stringBuilderAppendCharHex(
    StringBuilder* stringBuilder,
    char value
);

bool
WARN_UNUSED_RESULT
stringBuilderAppendU32(
    StringBuilder* stringBuilder,
    U32 value
);

bool
WARN_UNUSED_RESULT
stringBuilderAppendI32(
    StringBuilder* stringBuilder,
    I32 value
);

bool
WARN_UNUSED_RESULT
stringBuilderAppendU64(
    StringBuilder* stringBuilder,
    U64 value
);


bool
WARN_UNUSED_RESULT
stringBuilderAppendI64(
    StringBuilder* stringBuilder,
    I64 value
);

bool
WARN_UNUSED_RESULT
stringBuilderAppendF32(
    StringBuilder* stringBuilder,
    F32 value
);

bool
WARN_UNUSED_RESULT
stringBuilderAppendF64(
    StringBuilder* stringBuilder,
    F64 value
);

bool
WARN_UNUSED_RESULT
stringBuilderAppendU32Hex(
    StringBuilder* stringBuilder,
    U32 value
);

bool
WARN_UNUSED_RESULT
stringBuilderAppendU64Hex(
    StringBuilder* stringBuilder,
    U64 value
);

#endif /* W2C2_STRINGBUILDER_H */
