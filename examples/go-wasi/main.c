#include <stdio.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "gowasi.h"

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
    return gowasi_memory((gowasiInstance*)instance);
}

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {

    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    {
        gowasiInstance instance;
        gowasiInstantiate(&instance, NULL);
        gowasi__start(&instance);
        gowasiFreeInstance(&instance);
    }

    return 0;
}
