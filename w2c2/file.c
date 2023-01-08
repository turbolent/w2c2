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
    size_t size = 0;
    size_t read = 0;

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
    read = fread(data, 1, size, file);
    if (read == size) {
        buffer.data = data;
        buffer.length = size;
    } else {
        free(data);
    }
    fclose(file);

    return buffer;
}
