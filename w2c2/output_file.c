#if !defined(_WIN32) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200112L
#endif

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#ifdef _WIN32
#include <io.h>
#include <windows.h>
#define outputOpen _open
#define outputFdopen _fdopen
#define outputClose _close
#ifndef S_ISDIR
#define S_ISDIR(mode) (((mode) & _S_IFMT) == _S_IFDIR)
#endif
#else
#if HAS_UNISTD || defined(__unix__) || defined(__APPLE__) || defined(__wasi__)
#include <unistd.h>
#else
#include <io.h>
#endif
#define outputOpen open
#define outputFdopen fdopen
#define outputClose close
#endif

#include "output.h"
#include "path.h"

typedef struct FileOutput {
    FILE* file;
    char* path;
    char* temporary;
    int error;
} FileOutput;

static
void
fileOutputFree(FileOutput* output) {
    free(output->temporary);
    free(output->path);
    free(output);
}

static
int
fileOutputReplace(const char* temporary, const char* path) {
#ifdef _WIN32
    if (MoveFileExA(temporary, path, MOVEFILE_REPLACE_EXISTING)) {
        return 0;
    }
    switch (GetLastError()) {
        case ERROR_FILE_NOT_FOUND:
        case ERROR_PATH_NOT_FOUND:
            errno = ENOENT;
            break;
        case ERROR_ACCESS_DENIED:
        case ERROR_SHARING_VIOLATION:
            errno = EACCES;
            break;
        case ERROR_DISK_FULL:
            errno = ENOSPC;
            break;
        default:
            errno = EIO;
            break;
    }
    return -1;
#else
    return rename(temporary, path);
#endif
}

static
WasmBool
fileOutputWrite(
    void* context,
    const U8* bytes,
    size_t length,
    int* systemError
) {
    FileOutput* output = (FileOutput*)context;
    if (output->error == 0) {
        errno = 0;
        if (fwrite(bytes, 1, length, output->file) != length || ferror(output->file)) {
            output->error = errno != 0 ? errno : EIO;
        }
    }
    *systemError = output->error;
    return output->error == 0;
}

static
WasmBool
fileOutputClose(void* context, int* systemError) {
    FileOutput* output = (FileOutput*)context;
    errno = 0;
    if (fclose(output->file) != 0 && output->error == 0) {
        output->error = errno != 0 ? errno : EIO;
    }
    if (output->error == 0) {
        errno = 0;
        if (fileOutputReplace(output->temporary, output->path) != 0) {
            output->error = errno != 0 ? errno : EIO;
        }
    }
    *systemError = output->error;
    if (output->error != 0) {
        /* Preserve the write, close, or replacement error if removal also fails. */
        remove(output->temporary);
    }
    fileOutputFree(output);
    return *systemError == 0;
}

static
void
fileOutputAbort(void* context) {
    FileOutput* output = (FileOutput*)context;
    /*
     * Translation has already failed.
     * Attempt both cleanup operations, even if either fails.
     */
    fclose(output->file);
    remove(output->temporary);
    fileOutputFree(output);
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
    FileOutput* output = (FileOutput*)calloc(1, sizeof(FileOutput));
    struct stat status;
    unsigned int attempt;
    U32 candidate = (U32)time(NULL) ^ (U32)clock();
    int descriptor = -1;
    char* suffix;
    if (output == NULL) {
        *systemError = ENOMEM;
        return false;
    }
    output->path = wasmPathJoin((const char*)context, name);
    /* A different first byte keeps the temporary distinct from the destination. */
    output->temporary = wasmPathJoin(
        (const char*)context,
        name[0] == '.' ? "_w2c2-00000000.tmp" : ".w2c2-00000000.tmp"
    );
    if (output->path == NULL || output->temporary == NULL) {
        *systemError = ENOMEM;
        goto fail;
    }
    /*
     * A symlink's target may be inaccessible,
     * even when the symlink itself can be replaced.
     */
    if (stat(output->path, &status) == 0 && S_ISDIR(status.st_mode)) {
        *systemError = EISDIR;
        goto fail;
    }
    suffix = output->temporary + strlen(output->temporary) - (sizeof("00000000.tmp") - 1);
    /* Exclusive creation resolves collisions between concurrent writers. */
    for (attempt = 0; attempt < 1024; attempt++, candidate++) {
        sprintf(suffix, "%08X.tmp", candidate);
        errno = 0;
#ifdef _WIN32
        descriptor = outputOpen(
            output->temporary,
            _O_WRONLY | _O_CREAT | _O_EXCL | (kind == wasmOutputData ? _O_BINARY : _O_TEXT),
            _S_IREAD | _S_IWRITE
        );
#else
        descriptor = outputOpen(
            output->temporary,
            O_WRONLY | O_CREAT | O_EXCL,
            0666
        );
#endif
        if (descriptor >= 0) {
            break;
        }
        if (errno != EEXIST) {
            *systemError = errno != 0 ? errno : EIO;
            goto fail;
        }
    }
    if (descriptor < 0) {
        *systemError = EEXIST;
        goto fail;
    }
    errno = 0;
    output->file = outputFdopen(descriptor, kind == wasmOutputData ? "wb" : "w");
    if (output->file == NULL) {
        *systemError = errno != 0 ? errno : EIO;
        /* Preserve the stream-open error if descriptor or file cleanup also fails. */
        outputClose(descriptor);
        remove(output->temporary);
        goto fail;
    }
    sink->context = output;
    sink->write = fileOutputWrite;
    sink->close = fileOutputClose;
    sink->abort = fileOutputAbort;
    return true;

fail:
    fileOutputFree(output);
    return false;
}

WasmOutputProvider
wasmFileOutputProvider(const char* outputDirectory) {
    WasmOutputProvider provider;
    provider.context = (void*)outputDirectory;
    provider.open = fileOutputOpen;
    return provider;
}
