#include "../../w2c2_base.h"
#include "../../wasi/wasi.h"

extern void (*e_X5Fstart)();

void
trap(
    Trap trap
) {}

extern void init();

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    /* Initialize WASI */
    wasiInit(argc, argv, environ);

    /* Initialize module */
    init();

    (*e_X5Fstart)();
}
