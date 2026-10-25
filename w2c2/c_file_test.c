#include <stdio.h>

#include "c_file.h"
#include "c_file_test.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testCFileNames: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

void
testCFileNames(void) {
    static const struct {
        const char* module;
        const char* prefix;
    } prefixes[] = {
        {"", "m0_"},
        {"fac", "m3_fac"},
        {"Fac", "m3_x46ac"},
        {"FAC", "m3_x46x41x43"},
        {"x", "m1_x78"},
        {"X", "m1_x58"},
        {"x58", "m3_x7858"},
        {"../", "m3_x2ex2ex2f"},
        {"a-b", "m3_ax2db"},
        {"a_b", "m3_ax5fb"},
        {"\303\251", "m2_xc3xa9"},
        {"\303\211", "m2_xc3x89"},
        {"\360\237\230\200", "m4_xf0x9fx98x80"},
        {".x2e", "m4_x2ex782e"},
        {"x2e.", "m4_x782ex2e"}
    };
    static const struct {
        const char* name;
        char kind;
        U32 index;
    } files[] = {
        {"m3_fac.s0000000000.c", 's', 0},
        {"m3_fac.d0000000012.c", 'd', 12},
        {"m3_fac.s4294967295.c", 's', UINT32_MAX},
        {"M3_FAC.D0000000001.C", 'd', 1},
        {"m3_fac.s4294967296.c", 0, 0},
        {"m3_fac.s00000000000.c", 0, 0},
        {"m3_fac.s000000000.c", 0, 0},
        {"m3_fac.s000000000x.c", 0, 0},
        {"m3_fac.s0000000000.h", 0, 0},
        {"m3_fac.t0000000000.c", 0, 0},
        {"m4_fac2.s0000000000.c", 0, 0},
        {"m3_x46ac.s0000000000.c", 0, 0},
        {"m3_fac.s0000000000.c.bak", 0, 0},
        {"m3_fac.data", 0, 0},
        {"s0000000000.c", 0, 0},
        {"", 0, 0}
    };
    WasmDiagnosticContext diagnostics = emptyWasmDiagnosticContext;
    size_t index;
    for (index = 0; index < sizeof(prefixes) / sizeof(prefixes[0]); index++) {
        char* prefix = wasmCFilePrefix(prefixes[index].module, &diagnostics);
        size_t previous;
        CHECK(prefix != NULL && strcmp(prefix, prefixes[index].prefix) == 0);
        for (previous = 0; previous < index; previous++) {
            CHECK(!wasmCFileNamesEqual(prefix, prefixes[previous].prefix));
        }
        free(prefix);
    }
    for (index = 0; index < sizeof(files) / sizeof(files[0]); index++) {
        char kind = 0;
        U32 fileIndex = 0;
        CHECK(wasmCImplementationFileIndex(files[index].name, "m3_fac", &kind, &fileIndex)
            == (files[index].kind != 0));
        if (files[index].kind != 0) {
            char* name;
            CHECK(kind == files[index].kind && fileIndex == files[index].index);
            name = wasmCImplementationFileName("m3_fac", kind, fileIndex);
            CHECK(name != NULL && wasmCFileNamesEqual(name, files[index].name));
            free(name);
        }
    }
    CHECK(!wasmCFileNamesEqual("fac.c", "fac.c.bak"));
    CHECK(!wasmCFileNamesEqual("fac.c.bak", "fac.c"));
    CHECK(!diagnostics.hasError);
    fprintf(stderr, "PASS testCFileNames\n");
}
