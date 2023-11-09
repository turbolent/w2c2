/*
 * SHA-1 in C
 * By Steve Reid <steve@edmweb.com>
 * 100% Public Domain
 */

#ifndef W2C2_SHA1_H
#define W2C2_SHA1_H

#include "w2c2_base.h"

#define SHA1_DIGEST_LENGTH 20

#define SHA1_DIGEST_EMPTY { \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
}

void SHA1(const unsigned char *data, size_t count, unsigned char *result);

#endif /* W2C2_SHA1_H */
