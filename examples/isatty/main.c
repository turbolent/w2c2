#include <stdio.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "isatty.h"

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
    return isatty_memory((isattyInstance*)instance);
}

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    isattyInstance instance;
    isattyInstantiate(&instance, wasiResolveImport);

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    isatty_X5Fstart(&instance);
}
