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
    wasmModuleInstance* instance
) {
    return m6_isattyExport6_memory((m6_isattyInstance*)instance);
}

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    m6_isattyInstance instance;
    m6_isattyInstantiate(&instance, NULL);

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    m6_isattyExport6_X5Fstart(&instance);
}
