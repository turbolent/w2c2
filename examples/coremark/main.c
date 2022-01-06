#include <stdio.h>
#include "../../w2c2_base.h"
#include "../../wasi/wasi.h"

extern void (*e_X5Fstart)();

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

extern void init();

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    /* Initialize module */
    init();

    (*e_X5Fstart)();
}
