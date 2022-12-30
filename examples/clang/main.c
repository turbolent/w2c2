#include <stdio.h>
#include "../../w2c2_base.h"
#include "../../wasi/wasi.h"
#include "clang.h"

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

wasmMemory*
wasiMemory(
    void* instance
) {
    return clang_memory((clangInstance*)instance);
}

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

    {
        clangInstance instance;
        clangInstantiate(&instance, wasiResolveImport);
        clang_X5Fstart(&instance);
        clangFreeInstance(&instance);
    }

    return 0;
}
