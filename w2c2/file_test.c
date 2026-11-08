#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "file_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf( \
                stderr, \
                "FAIL testReadFile: line %d: %s\n", \
                __LINE__, \
                #condition \
            ); \
            exit(1); \
        } \
    } while (0)

static enum ReadFailure {
    readSuccess, readOpenFailure, readEndFailure, readTellFailure,
    readStartFailure, readAllocationFailure, readShort, readError,
    readStreamError, readCloseFailure
} failure;
static const U8 contents[] = {0, 1, 2, 0xFF};
static size_t contentSize;
static int injectedError;
static unsigned int closes;
static unsigned int allocations;
static unsigned int frees;
static unsigned int reads;

static FILE* readTestOpen(const char* path, const char* mode) {
    FILE* file;
    (void)path;
    CHECK(strcmp(mode, "rb") == 0);
    if (failure == readOpenFailure) {
        errno = injectedError;
        return NULL;
    }
    file = tmpfile();
    CHECK(file != NULL);
    CHECK(fwrite(contents, 1, contentSize, file) == contentSize);
    return file;
}

static int readTestSeek(FILE* file, long offset, int origin) {
    if ((origin == SEEK_END && failure == readEndFailure)
        || (origin == SEEK_SET && failure == readStartFailure)) {
        errno = injectedError;
        return -1;
    }
    return fseek(file, offset, origin);
}

static long readTestTell(FILE* file) {
    if (failure == readTellFailure) {
        errno = injectedError;
        return -1;
    }
    return ftell(file);
}

static void* readTestAllocate(size_t size) {
    allocations++;
    CHECK(size == (contentSize == 0 ? 1 : contentSize));
    if (failure == readAllocationFailure) {
        errno = 0;
        return NULL;
    }
    return malloc(size);
}

static void readTestFree(void* data) {
    if (data != NULL) frees++;
    free(data);
    errno = EDOM;
}

static size_t readTestRead(
    void* data,
    size_t size,
    size_t count,
    FILE* file
) {
    reads++;
    if (failure == readShort || failure == readError) {
        CHECK(count != 0);
        errno = failure == readShort ? 0 : injectedError;
        return 0;
    }
    return fread(data, size, count, file);
}

static int readTestError(FILE* file) {
    if (failure == readStreamError) {
        errno = injectedError;
        return 1;
    }
    return ferror(file);
}

static int readTestClose(FILE* file) {
    closes++;
    CHECK(fclose(file) == 0);
    /* Closing must not replace an earlier failure, even if it also fails. */
    errno = failure == readCloseFailure ? injectedError : EBADF;
    return failure == readSuccess ? 0 : EOF;
}

#define fopen readTestOpen
#define fseek readTestSeek
#define ftell readTestTell
#define malloc readTestAllocate
#define free readTestFree
#define fread readTestRead
#define ferror readTestError
#define fclose readTestClose
#define readFile injectedReadFile
#include "file.c"
#undef readFile
#undef fopen
#undef fseek
#undef ftell
#undef malloc
#undef free
#undef fread
#undef ferror
#undef fclose

void testReadFile(void) {
    unsigned int variant;
    Buffer buffer;
    CHECK(readFile(NULL).data == NULL && errno == EINVAL);
    for (variant = 0; variant < 2; variant++) {
        contentSize = variant == 0 ? 0 : sizeof(contents);
        failure = readSuccess;
        closes = allocations = frees = reads = 0;
        errno = EDOM;
        buffer = injectedReadFile("input");
        CHECK(buffer.data != NULL && buffer.length == contentSize);
        CHECK(memcmp(buffer.data, contents, contentSize) == 0);
        CHECK(errno == 0 && closes == 1 && allocations == 1 && frees == 0 && reads == 1);
        bufferFree(&buffer);
    }
    contentSize = sizeof(contents);
    for (variant = 0; variant < 2; variant++) {
        injectedError = variant == 0 ? 0 : EACCES;
        for (failure = readOpenFailure; failure <= readCloseFailure; failure++) {
            int expected = injectedError == 0 ? EIO : injectedError;
            closes = allocations = frees = reads = 0;
            errno = EDOM;
            buffer = injectedReadFile("input");
            if (failure == readAllocationFailure) expected = ENOMEM;
            if (failure == readShort) expected = EIO;
            CHECK(buffer.data == NULL && buffer.length == 0 && errno == expected);
            CHECK(closes == (failure == readOpenFailure ? 0U : 1U));
            CHECK(allocations == (failure >= readAllocationFailure ? 1U : 0U));
            CHECK(frees == (failure > readAllocationFailure ? 1U : 0U));
            CHECK(reads == (failure > readAllocationFailure ? 1U : 0U));
        }
    }
    fprintf(stderr, "PASS testReadFile\n");
}
