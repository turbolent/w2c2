#include <stdio.h>
#include <stdlib.h>
#include "w2c2_base.h"
#include "file.h"

Buffer
readFile(
    const char* path
) {
    FILE* file = NULL;
    Buffer buffer = {NULL, 0};
    U8* data = NULL;
    U32 size = 0;

    file = fopen(path, "rb");
    if (file == NULL) {
        return buffer;
    }
    fseek(file, 0, SEEK_END);

    size = ftell(file);
    rewind(file);

    data = malloc(size);
    if (data == NULL) {
        return buffer;
    }
    fread(data, 1, size, file);
    fclose(file);

    buffer.data = data;
    buffer.length = size;

    return buffer;
}
