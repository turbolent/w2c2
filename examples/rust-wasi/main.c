#include <stdio.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "rustwasi.h"

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
    return rustwasi_memory((rustwasiInstance*)instance);
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
        rustwasiInstance instance;
        rustwasiInstantiate(&instance, wasiResolveImport);
        rustwasi_X5Fstart(&instance);
        rustwasiFreeInstance(&instance);
    }

    return 0;
}
