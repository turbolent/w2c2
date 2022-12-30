#include <stdio.h>
#include "../../w2c2_base.h"
#include "../../wasi/wasi.h"
#include "swiftwasi.h"

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
    return swiftwasi_memory((swiftwasiInstance*)instance);
}

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/tmp", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

    {
        swiftwasiInstance instance;
        swiftwasiInstantiate(&instance, wasiResolveImport);
        swiftwasi_X5Fstart(&instance);
        swiftwasiFreeInstance(&instance);
    }

    return 0;
}
