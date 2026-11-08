#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if HAS_GLOB
#include <glob.h>
#endif
#include "path.h"
#include "output_buffer.h"
#include "main_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf( \
                stderr, \
                "FAIL testCLI: line %d: %s\n", \
                __LINE__, \
                #condition \
            ); \
            exit(1); \
        } \
    } while (0)

static bool flushFailure;
static bool streamFailure;

static int cliTestFlush(FILE* file) {
    return flushFailure ? EOF : fflush(file);
}

static int cliTestStreamError(FILE* file) {
    return streamFailure ? 1 : ferror(file);
}

#if HAS_GLOB
static int globResult;
static unsigned int globFrees;
static unsigned int removals;
static bool removeFailure;
static unsigned int joinCalls;
static unsigned int failJoin;
static unsigned int appendCalls;
static unsigned int failAppend;
static bool failInitialize;

static int cliTestGlob(
    const char* pattern,
    int flags,
    int (*onError)(const char*, int),
    glob_t* result
) {
    static char first[] = "dir[1]/m1_a.s0000000000.c";
    static char second[] = "dir[1]/unrelated.c";
    static char third[] = "dir[1]/m1_a.d0000000001.c";
    static char* paths[] = {first, second, third, NULL};
    CHECK(strcmp(pattern, "dir\\[1\\]/*.c") == 0);
    CHECK((flags & GLOB_ERR) != 0);
    CHECK(onError == NULL);
    result->gl_pathc = 3;
    result->gl_pathv = paths;
    return globResult;
}

static void cliTestGlobFree(glob_t* result) {
    (void)result;
    globFrees++;
}

static int cliTestRemove(const char* path) {
    CHECK(strcmp(path, "dir[1]/m1_a.s0000000000.c") == 0
        || strcmp(path, "dir[1]/m1_a.d0000000001.c") == 0);
    removals++;
    errno = EACCES;
    return removeFailure ? -1 : 0;
}

static char* cliTestJoin(const char* directory, const char* name) {
    if (++joinCalls == failJoin) return NULL;
    return wasmPathJoin(directory, name);
}

static bool cliTestInitialize(OutputBuffer* buffer) {
    return !failInitialize && outputBufferInitialize(buffer);
}

static bool cliTestAppend(
    OutputBuffer* buffer,
    const U8* bytes,
    size_t length
) {
    if (++appendCalls == failAppend) return false;
    return outputBufferAppend(buffer, bytes, length);
}

#define glob cliTestGlob
#define globfree cliTestGlobFree
#define remove cliTestRemove
#define wasmPathJoin cliTestJoin
#define outputBufferInitialize cliTestInitialize
#define outputBufferAppend cliTestAppend
#endif
#define fflush cliTestFlush
#define ferror cliTestStreamError
#define main cliTestMain
#include "main.c"
#undef main
#undef fflush
#undef ferror
#if HAS_GLOB
#undef glob
#undef globfree
#undef remove
#undef wasmPathJoin
#undef outputBufferInitialize
#undef outputBufferAppend
#endif

static void testCLIOutput(void) {
    CHECK(finishSuccess() == EXIT_SUCCESS);
    flushFailure = true;
    CHECK(finishSuccess() == EXIT_FAILURE);
    flushFailure = false;
    streamFailure = true;
    CHECK(finishSuccess() == EXIT_FAILURE);
    streamFailure = false;
}

#if HAS_GLOB
static void testCLICleanup(void) {
    WasmCOutputNames names = emptyWasmCOutputNames;
    unsigned int variant;
    static const int errors[] = {GLOB_NOMATCH, GLOB_ABORTED, GLOB_NOSPACE};
    names.prefix = "m1_a";
    names.header = "result.h";
    names.implementation = "result.c";
    for (variant = 0; variant < 3; variant++) {
        globFrees = removals = 0;
        removeFailure = variant == 1;
        if (variant == 2) names.implementation = "m1_a.s0000000000.c";
        CHECK(cleanImplementationFiles("dir[1]", &names) == !removeFailure);
        CHECK(globFrees == 1 && removals == (variant == 2 ? 1U : 2U));
    }
    removeFailure = false;
    names.implementation = "result.c";
    for (variant = 0; variant < 3; variant++) {
        globFrees = removals = 0;
        globResult = errors[variant];
        CHECK(cleanImplementationFiles("dir[1]", &names) == (globResult == GLOB_NOMATCH));
        CHECK(removals == 0);
        CHECK(globFrees == 1);
    }
    globResult = 0;
    for (variant = 1; variant <= 3; variant++) {
        globFrees = removals = joinCalls = 0;
        failJoin = variant;
        CHECK(!cleanImplementationFiles("dir[1]", &names));
        CHECK(globFrees == (variant == 1 ? 0U : 1U));
        CHECK(removals == (variant == 1 ? 0U : 1U));
    }
    failJoin = 0;
    failInitialize = true;
    CHECK(!cleanImplementationFiles("dir[1]", &names));
    failInitialize = false;
    for (variant = 1; variant <= 8; variant++) {
        appendCalls = 0;
        failAppend = variant;
        CHECK(!cleanImplementationFiles("dir[1]", &names));
    }
    failAppend = 0;
}
#endif

void testCLI(void) {
    testCLIOutput();
#if HAS_GLOB
    testCLICleanup();
#endif
    fprintf(stderr, "PASS testCLI\n");
}
