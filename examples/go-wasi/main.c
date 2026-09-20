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
    return m6_gowasiExport6_memory((m6_gowasiInstance*)instance);
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
        m6_gowasiInstance instance;
        m6_gowasiInstantiate(&instance, NULL);
        m6_gowasiExport6_X5Fstart(&instance);
        m6_gowasiFreeInstance(&instance);
    }

    return 0;
}
