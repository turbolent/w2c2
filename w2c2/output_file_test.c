#if !defined(_WIN32) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200112L
#endif

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include "output.h"
#include "output_file_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testFileOutputs: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

#if HAS_UNISTD || defined(_WIN32)
#ifdef _WIN32
#include <direct.h>
#include <io.h>
#include <windows.h>
#define nativeOpen _open
#define nativeFdopen _fdopen
#define makeDirectory(path) _mkdir(path)
#define removeDirectory(path) _rmdir(path)
#else
#include <dirent.h>
#include <unistd.h>
#define nativeOpen open
#define nativeFdopen fdopen
#define makeDirectory(path) mkdir(path, 0700)
#define removeDirectory(path) rmdir(path)
#endif

static const char* directory = "file-output-test";
static const char* destination = "file-output-test/result";
static const U8 original[] = {'o', 'l', 'd'};
static const U8 replacement[] = {'n', 0, '\n', 0xFF};

static enum FileFailure {
    fileSuccess, fileOpenFailure, fileStreamFailure,
    fileWriteFailure, fileCloseFailure, fileReplaceFailure, fileCollision
} failure;
static char collisionPath[256];

static int injectedOpen(const char* path, int flags, int mode) {
#ifdef _WIN32
    CHECK((flags & (_O_CREAT | _O_EXCL)) == (_O_CREAT | _O_EXCL));
#else
    CHECK((flags & (O_CREAT | O_EXCL)) == (O_CREAT | O_EXCL));
#endif
    if (failure == fileOpenFailure) {
        errno = ENOSPC;
        return -1;
    }
    if (failure == fileCollision && collisionPath[0] == '\0') {
        FILE* file = fopen(path, "wb");
        CHECK(file != NULL && strlen(path) < sizeof(collisionPath));
        CHECK(fwrite(original, 1, sizeof(original), file) == sizeof(original));
        CHECK(fclose(file) == 0);
        strcpy(collisionPath, path);
    }
    return nativeOpen(path, flags, mode);
}

static FILE* injectedFdopen(int descriptor, const char* mode) {
    if (failure == fileStreamFailure) {
        errno = ENOMEM;
        return NULL;
    }
    return nativeFdopen(descriptor, mode);
}

static size_t injectedWrite(const void* bytes, size_t size, size_t count, FILE* file) {
    if (failure == fileWriteFailure) {
        const size_t written = fwrite(bytes, size, count / 2, file);
        errno = ENOSPC;
        return written;
    }
    return fwrite(bytes, size, count, file);
}

static int injectedClose(FILE* file) {
    const int result = fclose(file);
    if (failure == fileCloseFailure) {
        errno = ENOSPC;
        return EOF;
    }
    return result;
}

static int injectedRemove(const char* path) {
    const int result = remove(path);
    errno = EBADF;
    return result;
}

#ifdef _WIN32
static BOOL injectedMove(const char* from, const char* to, DWORD flags) {
    if (failure == fileReplaceFailure) {
        SetLastError(ERROR_ACCESS_DENIED);
        return FALSE;
    }
    return MoveFileExA(from, to, flags);
}
#define _open injectedOpen
#define _fdopen injectedFdopen
#define MoveFileExA injectedMove
#else
static int injectedRename(const char* from, const char* to) {
    if (failure == fileReplaceFailure) {
        errno = EACCES;
        return -1;
    }
    return rename(from, to);
}
#define open(path, flags, mode) injectedOpen(path, flags, mode)
#define fdopen injectedFdopen
#define rename injectedRename
#endif
/*
 * Compile the provider with local I/O fault injection,
 * without adding mutable hooks to the production library.
 */
#define fwrite injectedWrite
#define fclose injectedClose
#define remove injectedRemove
#define time(value) ((time_t)0)
#define clock() ((clock_t)0)
#define wasmFileOutputProvider injectedFileOutputProvider
#include "output_file.c"
#undef wasmFileOutputProvider
#undef fwrite
#undef fclose
#undef remove
#undef time
#undef clock
#ifdef _WIN32
#undef _open
#undef _fdopen
#undef MoveFileExA
#else
#undef open
#undef fdopen
#undef rename
#endif

static void checkContents(const char* path, WasmOutputKind kind, const U8* bytes, size_t length) {
    FILE* file = fopen(path, kind == wasmOutputData ? "rb" : "r");
    size_t index;
    CHECK(file != NULL);
    for (index = 0; index < length; index++) {
        CHECK(fgetc(file) == bytes[index]);
    }
    CHECK(fgetc(file) == EOF && !ferror(file));
    CHECK(fclose(file) == 0);
}

static void checkOriginal(bool exists) {
    if (exists) {
        checkContents(destination, wasmOutputData, original, sizeof(original));
    } else {
        CHECK(fopen(destination, "rb") == NULL && errno == ENOENT);
    }
}

static void createOriginal(bool exists) {
    if (exists) {
        FILE* file = fopen(destination, "wb");
        CHECK(file != NULL);
        CHECK(fwrite(original, 1, sizeof(original), file) == sizeof(original));
        CHECK(fclose(file) == 0);
    }
}

static void checkFileCount(size_t expected) {
    size_t count = 0;
#ifdef _WIN32
    WIN32_FIND_DATAA entry;
    HANDLE search = FindFirstFileA("file-output-test/*", &entry);
    CHECK(search != INVALID_HANDLE_VALUE);
    do {
        if (strcmp(entry.cFileName, ".") != 0 && strcmp(entry.cFileName, "..") != 0) {
            count++;
        }
    } while (FindNextFileA(search, &entry));
    CHECK(GetLastError() == ERROR_NO_MORE_FILES);
    CHECK(FindClose(search));
#else
    DIR* search = opendir(directory);
    struct dirent* entry;
    CHECK(search != NULL);
    while ((entry = readdir(search)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            count++;
        }
    }
    CHECK(closedir(search) == 0);
#endif
    CHECK(count == expected);
}

static void testFileLifecycle(void) {
    WasmOutputProvider provider = injectedFileOutputProvider(directory);
    unsigned int variant;
    for (variant = 0; variant < 12; variant++) {
        const bool exists = variant % 2 != 0;
        const bool publish = variant % 4 >= 2;
        const WasmOutputKind kind = (WasmOutputKind)(variant / 4);
        WasmOutputSink sink;
        int error = 0;
        failure = fileSuccess;
        createOriginal(exists);
        CHECK(provider.open(provider.context, "result", kind, &sink, &error));
        checkOriginal(exists);
        checkFileCount(exists ? 2 : 1);
        CHECK(sink.write(sink.context, replacement, sizeof(replacement), &error));
        checkOriginal(exists);
        if (publish) {
            CHECK(sink.close(sink.context, &error));
            checkContents(destination, kind, replacement, sizeof(replacement));
        } else {
            sink.abort(sink.context);
            checkOriginal(exists);
        }
        checkFileCount(publish || exists ? 1 : 0);
        if (publish || exists) {
            CHECK(remove(destination) == 0);
        }
    }
}

static void testFileFailures(void) {
    WasmOutputProvider provider = injectedFileOutputProvider(directory);
    unsigned int variant;
    for (variant = 0; variant < 10; variant++) {
        const bool exists = variant % 2 != 0;
        const enum FileFailure selected = (enum FileFailure)(fileOpenFailure + variant / 2);
        WasmOutputSink sink;
        int error = 0;
        failure = selected;
        createOriginal(exists);
        if (selected == fileOpenFailure || selected == fileStreamFailure) {
            CHECK(!provider.open(provider.context, "result", wasmOutputData, &sink, &error));
        } else {
            CHECK(provider.open(provider.context, "result", wasmOutputData, &sink, &error));
            CHECK(sink.write(sink.context, replacement, sizeof(replacement), &error)
                == (selected != fileWriteFailure));
            if (selected == fileWriteFailure) {
                failure = fileSuccess;
                CHECK(!sink.write(sink.context, replacement, sizeof(replacement), &error));
            }
            CHECK(!sink.close(sink.context, &error));
        }
        CHECK(error == (selected == fileStreamFailure ? ENOMEM
            : selected == fileReplaceFailure ? EACCES : ENOSPC));
        checkOriginal(exists);
        checkFileCount(exists ? 1 : 0);
        if (exists) {
            CHECK(remove(destination) == 0);
        }
    }
    failure = fileSuccess;
}

static void testFileCollision(void) {
    WasmOutputProvider provider = injectedFileOutputProvider(directory);
    WasmOutputSink sink;
    int error = 0;
    failure = fileCollision;
    collisionPath[0] = '\0';
    CHECK(provider.open(provider.context, "result", wasmOutputData, &sink, &error));
    CHECK(collisionPath[0] != '\0');
    CHECK(sink.write(sink.context, replacement, sizeof(replacement), &error));
    CHECK(sink.close(sink.context, &error));
    checkContents(collisionPath, wasmOutputData, original, sizeof(original));
    checkContents(destination, wasmOutputData, replacement, sizeof(replacement));
    checkFileCount(2);
    CHECK(remove(collisionPath) == 0);
    CHECK(remove(destination) == 0);
    failure = fileSuccess;
}

static void testFilePublication(void) {
    WasmOutputProvider provider = injectedFileOutputProvider(directory);
    WasmOutputSink first;
    WasmOutputSink second;
    int error = 0;
    CHECK(provider.open(provider.context, "result", wasmOutputData, &first, &error));
    CHECK(provider.open(provider.context, "result", wasmOutputData, &second, &error));
    CHECK(first.write(first.context, original, sizeof(original), &error));
    CHECK(second.write(second.context, replacement, sizeof(replacement), &error));
    CHECK(first.close(first.context, &error));
    checkOriginal(true);
    failure = fileReplaceFailure;
    CHECK(!second.close(second.context, &error));
    CHECK(error == EACCES);
    checkOriginal(true);
    checkFileCount(1);
    CHECK(remove(destination) == 0);
    failure = fileSuccess;

    CHECK(provider.open(provider.context, "result", wasmOutputData, &first, &error));
    CHECK(first.write(first.context, replacement, sizeof(replacement), &error));
    CHECK(makeDirectory(destination) == 0);
    CHECK(!first.close(first.context, &error));
    CHECK(error != 0);
    checkFileCount(1);
    CHECK(removeDirectory(destination) == 0);
    provider = injectedFileOutputProvider("file-output-test/missing");
    CHECK(!provider.open(provider.context, "result", wasmOutputData, &first, &error));
    CHECK(error == ENOENT);
    checkFileCount(0);

    provider = injectedFileOutputProvider(directory);
    CHECK(provider.open(provider.context, ".w2c2-00000000.tmp", wasmOutputData, &first, &error));
    CHECK(fopen("file-output-test/.w2c2-00000000.tmp", "rb") == NULL && errno == ENOENT);
    first.abort(first.context);
    checkFileCount(0);
}

#endif

void testFileOutputs(void) {
#if HAS_UNISTD || defined(_WIN32)
    CHECK(makeDirectory(directory) == 0);
    testFileLifecycle();
    testFileFailures();
    testFileCollision();
    testFilePublication();
    CHECK(removeDirectory(directory) == 0);
    fprintf(stderr, "PASS testFileOutputs\n");
#else
    fprintf(stderr, "SKIP testFileOutputs: directory operations unavailable\n");
#endif
}
