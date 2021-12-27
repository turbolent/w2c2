#include <stdio.h>
#include "buffer.h"
#include "file.h"
#include "reader.h"
#include "c.h"

static
bool
readWasmBinary(
    const char* path,
    WasmModuleReader* wasmModuleReaderResult
) {
    WasmModuleReaderError* error = NULL;

    wasmModuleReaderResult->buffer = readFile(path);
    if (wasmModuleReaderResult->buffer.data == NULL) {
        fprintf(stderr, "w2c2: failed to read file %s\n", path);
        return false;
    }

    wasmModuleRead(wasmModuleReaderResult, &error);
    if (error != NULL) {
        fprintf(stderr, "w2c2: failed to read module: %s\n", wasmModuleReaderErrorMessage(error));
        return false;
    }

    return true;
}

int
main(
    int argc,
    char* argv[]
) {
    if (argc < 2) {
        fprintf(stderr, "missing file name\n");
        return 1;
    }

    {
        WasmModuleReader wasmModuleReader;
        if (!readWasmBinary(argv[1], &wasmModuleReader)) {
            return 1;
        }

        if (!wasmCWriteModule(stdout, wasmModuleReader.module)) {
            return 1;
        }
    }
    return 0;
}
