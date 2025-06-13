#include <stdio.h>
#include "leb128_test.h"
#include "leb128.h"

void
testReadU32LEB128(void) {
    typedef struct {
        U32 expected;
        U8 data[int32LEB128MaxByteCount];
    } testCase;

    const testCase testCases[] = {
        {0,     {0x00}},
        {1,     {0x01}},
        {2,     {2}},
        {63,    {0x3f}},
        {64,    {0x40}},
        {127,   {127}},
        {128,   {0 + 0x80,  1}},
        {129,   {1 + 0x80,  1}},
        {130,   {2 + 0x80,  1}},
        {0x90,  {0x90,      0x01}},
        {0x100, {0x80,      0x02}},
        {0x101, {0x81,      0x02}},
        {0xff,  {0xff,      0x01}},
        {12857, {57 + 0x80, 100}},
    };

    bool success = true;
    I32 i = 0;
    for (; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        U32 actual;
        size_t count;
        testCase testCase = testCases[i];
        Buffer buffer = {
            NULL,
            int32LEB128MaxByteCount
        };

        buffer.data = testCase.data;

        count = leb128ReadU32(&buffer, &actual);

        if (count == 0 || actual != testCase.expected) {
            fprintf(stderr, "FAIL testReadU32LEB128: %u != %u\n", actual, testCase.expected);
            success = false;

        }
    }

    if (success) {
        fprintf(stderr, "PASS testReadU32LEB128\n");
    } else {
        exit(1);
    }
}

void
testReadI32LEB128(void) {
    typedef struct {
        I32 expected;
        U8 data[int32LEB128MaxByteCount];
    } testCase;

    const testCase testCases[] = {
        {0,      {0x00}},
        {1,      {0x01}},
        {-1,     {0x7f}},
        {2,      {2}},
        {-2,     {0x7e}},
        {63,     {0x3f}},
        {-63,    {0x41}},
        {64,     {0xc0,        0x00}},
        {-64,    {0x40}},
        {-65,    {0xbf,        0x7f}},
        {127,    {127 + 0x80,  0}},
        {-127,   {1 + 0x80,    0x7f}},
        {128,    {0 + 0x80,    1}},
        {-128,   {0 + 0x80,    0x7f}},
        {129,    {1 + 0x80,    1}},
        {-129,   {0x7f + 0x80, 0x7e}},
        {-12345, {0xc7,        0x9f, 0x7f}},
    };

    bool success = true;
    I32 i = 0;
    for (; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        I32 actual;
        size_t count;
        testCase testCase = testCases[i];
        Buffer buffer = {
            NULL,
            int32LEB128MaxByteCount
        };

        buffer.data = testCase.data;

        count = leb128ReadI32(&buffer, &actual);

        if (count == 0 || actual != testCase.expected) {
            fprintf(stderr, "FAIL testReadI32LEB128: %u != %u\n", actual, testCase.expected);
            success = false;
        }
    }

    if (success) {
        fprintf(stderr, "PASS testReadI32LEB128\n");
    } else {
        exit(1);
    }
}
