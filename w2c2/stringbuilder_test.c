#include <stdio.h>
#include <string.h>
#include "stringbuilder_test.h"
#include "stringbuilder.h"

void
testStringBuilder(void) {
    StringBuilder builder = emptyStringBuilder;
    if (!stringBuilderInitialize(&builder)) {
        fprintf(stderr, "FAIL testStringBuilder: failed to initialize\n");
        exit(1);
    }

    {
        const size_t actualLength = builder.length;
        if (actualLength != 0) {
            fprintf(stderr, "FAIL testStringBuilder: incorrect length after initialize: %ld != %d\n", actualLength, 0);
            exit(1);
        }
    }

    {
        const size_t actualSize = strlen(builder.string);
        if (actualSize != 0) {
            fprintf(stderr, "FAIL testStringBuilder: strlen after initialize failed: %ld != %d\n", actualSize, 0);
            exit(1);
        }
    }

    if (!(
        stringBuilderAppend(&builder, "this")
        && stringBuilderAppend(&builder, " is")
        && stringBuilderAppend(&builder, " a ")
        && stringBuilderAppend(&builder, "test")
    )) {
        fprintf(stderr, "FAIL testStringBuilder: failed to append\n");
        exit(1);
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
            exit(1);
        }

        if (memcmp(builder.string, expected, actualLength) != 0) {
            fprintf(
                stderr,
                "FAIL testStringBuilder: incorrect contents after appends: \"%s\" != \"%s\"\n",
                builder.string,
                expected
            );
            exit(1);
        }
    }

    if (!(
        stringBuilderAppend(&builder, ". max U32: ")
        && stringBuilderAppendU32(&builder, UINT32_MAX)
        && stringBuilderAppend(&builder, ". max I32: ")
        && stringBuilderAppendI32(&builder, INT32_MAX)
        && stringBuilderAppend(&builder, ". min I32 + 1: ")
        && stringBuilderAppendI32(&builder, INT32_MIN + 1)
        && stringBuilderAppend(&builder, ". min I32: ")
        && stringBuilderAppendI32(&builder, INT32_MIN)
        && stringBuilderAppend(&builder, ". max U32 hex: ")
        && stringBuilderAppendU32Hex(&builder, UINT32_MAX)

        && stringBuilderAppend(&builder, ". max U64: ")
        && stringBuilderAppendU64(&builder, UINT64_MAX)
        && stringBuilderAppend(&builder, ". max I64: ")
        && stringBuilderAppendI64(&builder, INT64_MAX)
        && stringBuilderAppend(&builder, ". min I64 + 1: ")
        && stringBuilderAppendI64(&builder, INT64_MIN + 1)
        && stringBuilderAppend(&builder, ". min I64: ")
        && stringBuilderAppendI64(&builder, INT64_MIN)
        && stringBuilderAppend(&builder, ". max U64 hex: ")
        && stringBuilderAppendU64Hex(&builder, UINT64_MAX)
    )) {
        fprintf(stderr, "FAIL testStringBuilder: failed to append\n");
        exit(1);
    }

    {
        const char* expected =
            "this is a test. "

            "max U32: 4294967295. "
            "max I32: 2147483647. "
            "min I32 + 1: -2147483647. "
            "min I32: -2147483648. "
            "max U32 hex: FFFFFFFF. "

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
            exit(1);
        }

        if (memcmp(builder.string, expected, actualLength) != 0) {
            fprintf(
                stderr,
                "FAIL testStringBuilder: incorrect contents after appends: \"%s\" != \"%s\"\n",
                builder.string,
                expected
            );
            exit(1);
        }
    }

    fprintf(stderr, "PASS testStringBuilder\n");
}
