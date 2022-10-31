#include <stdio.h>
#include "../../w2c2_base.h"
#include "../../wasi/wasi.h"
#include "coremark.h"

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
    return coremark_memory((coremarkInstance*)instance);
}

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    coremarkInstance instance;
    coremarkInstantiate(&instance, wasiResolveImport);

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    coremark_X5Fstart(&instance);
}
