#include <stdio.h>
#include "sha1_test.h"
#include "sha1.h"

void
testSHA1(void) {

    {
        unsigned char actual[SHA1_DIGEST_LENGTH] = SHA1_DIGEST_EMPTY;
        const char* test = "abc";
        SHA1((unsigned char *)test, strlen(test), actual);

        unsigned char expected[SHA1_DIGEST_LENGTH] = {
            0xa9, 0x99, 0x3e, 0x36,
            0x47, 0x06, 0x81, 0x6a,
            0xba, 0x3e, 0x25, 0x71,
            0x78, 0x50, 0xc2, 0x6c,
            0x9c, 0xd0, 0xd8, 0x9d,
        };

        if (memcmp(actual, expected, SHA1_DIGEST_LENGTH) != 0) {
            fprintf(stderr, "FAIL testSHA1\n");
            return;
        }
    }

    {
        unsigned char actual[SHA1_DIGEST_LENGTH] = SHA1_DIGEST_EMPTY;
        const char* test = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
        SHA1((unsigned char *)test, strlen(test), actual);

        unsigned char expected[SHA1_DIGEST_LENGTH] = {
            0x84, 0x98, 0x3e, 0x44,
            0x1c, 0x3b, 0xd2, 0x6e,
            0xba, 0xae, 0x4a, 0xa1,
            0xf9, 0x51, 0x29, 0xe5,
            0xe5, 0x46, 0x70, 0xf1
        };

        if (memcmp(actual, expected, SHA1_DIGEST_LENGTH) != 0) {
            fprintf(stderr, "FAIL testSHA1\n");
            return;
        }
    }

    fprintf(stderr, "PASS testSHA1\n");
}
