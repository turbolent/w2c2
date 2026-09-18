#include <errno.h>
#include <stdio.h>

#include "output.h"
#include "path.h"

static
WasmBool
fileOutputWrite(void* context, const U8* bytes, size_t length, int* systemError) {
    if (fwrite(bytes, 1, length, (FILE*)context) != length) {
        *systemError = errno;
        return false;
    }
    return true;
}

static
WasmBool
fileOutputClose(void* context, int* systemError) {
    if (fclose((FILE*)context) != 0) {
        *systemError = errno;
        return false;
    }
    return true;
}

static
void
fileOutputAbort(void* context) {
    fclose((FILE*)context);
}

static
WasmBool
fileOutputOpen(
    void* context,
    const char* name,
    WasmOutputKind kind,
    WasmOutputSink* sink,
    int* systemError
) {
    char* path = wasmPathJoin((const char*)context, name);
    FILE* file;
    if (path == NULL) {
        *systemError = ENOMEM;
        return false;
    }
    file = fopen(path, kind == wasmOutputData ? "wb" : "w");
    if (file == NULL) {
        *systemError = errno;
        free(path);
        return false;
    }
    free(path);
    sink->context = file;
    sink->write = fileOutputWrite;
    sink->close = fileOutputClose;
    sink->abort = fileOutputAbort;
    return true;
}

WasmOutputProvider
wasmFileOutputProvider(const char* directory) {
    WasmOutputProvider provider;
    provider.context = (void*)directory;
    provider.open = fileOutputOpen;
    return provider;
}
