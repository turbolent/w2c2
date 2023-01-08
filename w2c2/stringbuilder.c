#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stringbuilder.h"

static
bool
WARN_UNUSED_RESULT
stringBuilderEnsureCapacity(
    StringBuilder* stringBuilder,
    size_t length
) {
    size_t lengthWithNull = length + 1;
    if (lengthWithNull > stringBuilder->capacity) {
        size_t newCapacity = lengthWithNull + (stringBuilder->capacity >> 1U);
        void* newString = realloc(stringBuilder->string, newCapacity);
        MUST (newString != NULL)
        stringBuilder->string = (char*) newString;
        stringBuilder->capacity = newCapacity;
    }
    return true;
}

bool
WARN_UNUSED_RESULT
stringBuilderInitialize(
    StringBuilder* stringBuilder
) {
    static const size_t initialCapacity = sizeof(char) * 8;
    void* newString = NULL;
    MUST (stringBuilder->string == NULL)
    newString = malloc(initialCapacity);
    MUST (newString != NULL)

    stringBuilder->length = 0;
    stringBuilder->capacity = initialCapacity;
    stringBuilder->string = (char*) newString;
    stringBuilder->string[0] = '\0';

    return true;
}

bool
WARN_UNUSED_RESULT
stringBuilderReset(
    StringBuilder* stringBuilder
) {
    if (stringBuilder->capacity < 1) {
        MUST (stringBuilderInitialize(stringBuilder))
    }

    stringBuilder->length = 0;
    stringBuilder->string[0] = '\0';

    return true;
}

void
stringBuilderFree(
    StringBuilder* stringBuilder
) {
    if (stringBuilder->string == NULL) {
        return;
    }

    free(stringBuilder->string);

    stringBuilder->string = NULL;
    stringBuilder->length = 0;
    stringBuilder->capacity = 0;
}

bool
WARN_UNUSED_RESULT
stringBuilderAppendSized(
    StringBuilder* stringBuilder,
    const char* string,
    size_t length
) {
    size_t newLength = stringBuilder->length + length;
    MUST (stringBuilderEnsureCapacity(stringBuilder, newLength))

    strncpy(
        stringBuilder->string + stringBuilder->length,
        string,
        length
    );

    stringBuilder->length = newLength;
    stringBuilder->string[stringBuilder->length] = '\0';

    return true;
}

bool
stringBuilderAppendU32(
    StringBuilder* stringBuilder,
    U32 value
) {
    char temp[10];
    char* tempPointer = temp;
    char* buffer = NULL;

    MUST (stringBuilderEnsureCapacity(stringBuilder, stringBuilder->length + 11))
    buffer = stringBuilder->string + stringBuilder->length;

    do {
        *tempPointer++ = (char)(value % 10) + '0';
        value /= 10;
    } while (value > 0);

    do {
        *buffer++ = *--tempPointer;
        stringBuilder->length++;
    } while (tempPointer != temp);

    *buffer = '\0';

    return true;
}

bool
stringBuilderAppendI32(
    StringBuilder* stringBuilder,
    I32 value
) {
    U32 unsignedValue = (U32)value;
    if (value < 0) {
        MUST (stringBuilderEnsureCapacity(stringBuilder, stringBuilder->length + 1))
        stringBuilder->string[stringBuilder->length] = '-';
        stringBuilder->length++;

        unsignedValue = ~unsignedValue + 1;
    }
    return stringBuilderAppendU32(stringBuilder, unsignedValue);
}

bool
stringBuilderAppendU64(
    StringBuilder* stringBuilder,
    U64 value
) {
    char temp[20];
    char* tempPointer = temp;
    char* buffer = NULL;

    MUST (stringBuilderEnsureCapacity(stringBuilder, stringBuilder->length + 21))
    buffer = stringBuilder->string + stringBuilder->length;

    do {
        *tempPointer++ = (char)(value % 10) + '0';
        value /= 10;
    } while (value > 0);

    do {
        *buffer++ = *--tempPointer;
        stringBuilder->length++;
    } while (tempPointer != temp);

    *buffer = '\0';

    return true;
}

bool
stringBuilderAppendI64(
    StringBuilder* stringBuilder,
    I64 value
) {
    U64 unsignedValue = (U64)value;
    if (value < 0) {
        MUST (stringBuilderEnsureCapacity(stringBuilder, stringBuilder->length + 1))
        stringBuilder->string[stringBuilder->length] = '-';
        stringBuilder->length++;

        unsignedValue = ~unsignedValue + 1;
    }
    return stringBuilderAppendU64(stringBuilder, unsignedValue);
}

bool
stringBuilderAppendF32(
    StringBuilder* stringBuilder,
    F32 value
) {
    char buffer[32];
    /* FLT_DECIMAL_DIG */
    size_t length = sprintf(buffer, "%.9g", value);
    return stringBuilderAppendSized(stringBuilder, buffer, length);
}

bool
stringBuilderAppendF64(
    StringBuilder* stringBuilder,
    F64 value
) {
    char buffer[32];
    /* DBL_DECIMAL_DIG */
    size_t length = sprintf(buffer, "%.17g", value);
    return stringBuilderAppendSized(stringBuilder, buffer, length);
}

bool
stringBuilderAppendU8Hex(
    StringBuilder* stringBuilder,
    U8 value
) {
    char buffer[3];
    size_t length = sprintf(buffer, "%02X", value);
    return stringBuilderAppendSized(stringBuilder, buffer, length);
}

bool
stringBuilderAppendU32Hex(
    StringBuilder* stringBuilder,
    U32 value
) {
    char buffer[9];
    size_t length = sprintf(buffer, "%08X", value);
    return stringBuilderAppendSized(stringBuilder, buffer, length);
}

bool
stringBuilderAppendU64Hex(
    StringBuilder* stringBuilder,
    U64 value
) {
    char buffer[17];
    size_t length = sprintf(buffer, "%016llX", value);
    return stringBuilderAppendSized(stringBuilder, buffer, length);
}
