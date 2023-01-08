#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "stringbuilder_test.h"
#include "stringbuilder.h"

void
testStringBuilder(void) {
    StringBuilder builder = emptyStringBuilder;
    if (!stringBuilderInitialize(&builder)) {
        fprintf(stderr, "FAIL testStringBuilder: failed to initialize\n");
    }

    {
        const size_t actualLength = builder.length;
        if (actualLength != 0) {
            fprintf(stderr, "FAIL testStringBuilder: incorrect length after initialize: %ld != %d\n", actualLength, 0);
            return;
        }
    }

    {
        const size_t actualSize = strlen(builder.string);
        if (actualSize != 0) {
            fprintf(stderr, "FAIL testStringBuilder: strlen after initialize failed: %ld != %d\n", actualSize, 0);
            return;
        }
    }

    if (!(
        stringBuilderAppend(&builder, "this")
        && stringBuilderAppend(&builder, " is")
        && stringBuilderAppend(&builder, " a ")
        && stringBuilderAppend(&builder, "test")
    )) {
        fprintf(stderr, "FAIL testStringBuilder: failed to append\n");
        return;
    }

    {
        const char* expected = "this is a test";
        const size_t expectedLength = strlen(expected);
        const size_t actualLength = builder.length;

        if (actualLength != expectedLength) {
            fprintf(
                stderr,
                "FAIL testStringBuilder: incorrect length after appends: %ld != %ld\n",
                actualLength,
                expectedLength
            );
            return;
        }

        if (memcmp(builder.string, expected, actualLength) != 0) {
            fprintf(
                stderr,
                "FAIL testStringBuilder: incorrect contents after appends: \"%s\" != \"%s\"\n",
                builder.string,
                expected
            );
            return;
        }
    }

    if (!(
        stringBuilderAppend(&builder, ". max U32: ")
        && stringBuilderAppendU32(&builder, ULONG_MAX)
        && stringBuilderAppend(&builder, ". max I32: ")
        && stringBuilderAppendI32(&builder, LONG_MAX)
        && stringBuilderAppend(&builder, ". min I32 + 1: ")
        && stringBuilderAppendI32(&builder, LONG_MIN + 1)
        && stringBuilderAppend(&builder, ". min I32: ")
        && stringBuilderAppendI32(&builder, LONG_MIN)
        && stringBuilderAppend(&builder, ". max U32 hex: ")
        && stringBuilderAppendU32Hex(&builder, ULONG_MAX)

        && stringBuilderAppend(&builder, ". max U64: ")
        && stringBuilderAppendU64(&builder, ULLONG_MAX)
        && stringBuilderAppend(&builder, ". max I64: ")
        && stringBuilderAppendI64(&builder, LLONG_MAX)
        && stringBuilderAppend(&builder, ". min I64 + 1: ")
        && stringBuilderAppendI64(&builder, LLONG_MIN + 1)
        && stringBuilderAppend(&builder, ". min I64: ")
        && stringBuilderAppendI64(&builder, LLONG_MIN)
        && stringBuilderAppend(&builder, ". max U64 hex: ")
        && stringBuilderAppendU64Hex(&builder, ULLONG_MAX)
    )) {
        fprintf(stderr, "FAIL testStringBuilder: failed to append\n");
        return;
    }

    {
        const char* expected =
            "this is a test. "

            "max U32: 4294967295. "
            "max I32: 2147483647. "
            "min I32 + 1: -2147483647. "
            "min I32: -2147483648. "
            "max U32 hex: FFFFFFFF"

            "max U64: 18446744073709551615. "
            "max I64: 9223372036854775807. "
            "min I64 + 1: -9223372036854775807. "
            "min I64: -9223372036854775808. "
            "max U64 hex: FFFFFFFFFFFFFFFF";

        const size_t expectedLength = strlen(expected);
        const size_t actualLength = builder.length;

        if (actualLength != expectedLength) {
            fprintf(
                stderr,
                "FAIL testStringBuilder: incorrect length after appends: %ld != %ld\n",
                actualLength,
                expectedLength
            );
            return;
        }

        if (memcmp(builder.string, expected, actualLength) != 0) {
            fprintf(
                stderr,
                "FAIL testStringBuilder: incorrect contents after appends: \"%s\" != \"%s\"\n",
                builder.string,
                expected
            );
            return;
        }
    }

    fprintf(stderr, "PASS testStringBuilder\n");
}
