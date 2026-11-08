#ifndef W2C2_FILE_H
#define W2C2_FILE_H

#include "buffer.h"

/*
 * Returns owned bytes, including a non-NULL allocation for an empty file.
 * On failure, returns emptyBuffer and preserves the first error in errno.
 */
Buffer
WARN_UNUSED_RESULT
readFile(
    const char* path
);

#endif /* W2C2_FILE_H */
