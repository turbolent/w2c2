#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "w2c2_base.h"
#include "file.h"

Buffer
readFile(
    const char* path
) {
    FILE* file = NULL;
    Buffer buffer = emptyBuffer;
    U8* data = NULL;
    long length;
    size_t size = 0;
    int error = 0;

    if (path == NULL) {
        errno = EINVAL;
        return buffer;
    }
    errno = 0;
    file = fopen(path, "rb");
    if (file == NULL) {
        if (errno == 0) errno = EIO;
        return buffer;
    }
    errno = 0;
    if (fseek(file, 0, SEEK_END) != 0) {
        error = errno != 0 ? errno : EIO;
        goto end;
    }
    errno = 0;
    length = ftell(file);
    if (length < 0) {
        error = errno != 0 ? errno : EIO;
        goto end;
    }
    size = (size_t)length;
    if ((unsigned long)size != (unsigned long)length) {
        error = ERANGE;
        goto end;
    }
    errno = 0;
    if (fseek(file, 0, SEEK_SET) != 0) {
        error = errno != 0 ? errno : EIO;
        goto end;
    }

    /* A non-NULL buffer distinguishes an empty file from a failed read. */
    data = malloc(size == 0 ? 1 : size);
    if (data == NULL) {
        error = ENOMEM;
        goto end;
    }
    errno = 0;
    if (fread(data, 1, size, file) != size || ferror(file)) {
        error = errno != 0 ? errno : EIO;
    }

end:
    errno = 0;
    if (fclose(file) != 0 && error == 0) {
        error = errno != 0 ? errno : EIO;
    }
    if (error == 0) {
        buffer.data = data;
        buffer.length = size;
    } else {
        free(data);
    }
    errno = error;
    return buffer;
}
