#include <stdio.h>
#include "../../w2c2_base.h"

extern void (*e_X5Fstart)();

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

extern void init();

/* Main */

int main() {
    /* Initialize module */
    init();

    (*e_X5Fstart)();
}
