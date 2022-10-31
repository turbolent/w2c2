#include "../w2c2_base.h"
#include "wasi.h"
#include <stdio.h>
#include <limits.h>

extern char** environ;

extern
bool
resolvePath(
    char* directory,
    char* path,
    U32 pathLength,
    char result[PATH_MAX]
);

void
testResolvePath(
    char* directory,
    char* path,
    char* expected,
    bool valid
) {
    char result[PATH_MAX];
    if (resolvePath(directory, path, strlen(path), result) != valid) {
        fprintf(stderr, "FAIL: resolvePath(%s, %s): should succeed\n", directory, path);
        return;
    }

    if (!valid) {
        return;
    }

    if (strcmp(result, expected) != 0) {
        fprintf(stderr, "FAIL: resolvePath(%s, %s): %s != %s\n", directory, path, result, expected);
        return;
    }

    fprintf(stderr, "OK: resolvePath(%s, %s) == %s\n", directory, path, expected);
}

int
main(int argc, char* argv[]) {
    wasmMemory m;
    wasmAllocateMemory(&m, 2, 65535);
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    testResolvePath("/", "", "", false);
    testResolvePath("/", "/bar", "/bar", true);
    testResolvePath("/", "bar", "/bar", true);
    testResolvePath("/foo", "", "", false);
    testResolvePath("/foo", "/bar", "/bar", true);
    testResolvePath("/foo", "bar", "/foo/bar", true);
    testResolvePath("/foo/bar", "", "", false);
    testResolvePath("/foo/bar", "/baz/qux", "/baz/qux", true);
    testResolvePath("/foo/bar", "baz/qux", "/foo/bar/baz/qux", true);

    return 0;
}
