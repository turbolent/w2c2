#include <stdio.h>
#include <stdlib.h>

#include "w2c2_base.h"
#include "fac.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        return 1;
    }

    U64 n = atoi(argv[1]);

    facInstance instance;
    facInstantiate(&instance, NULL);

    U64 result = fac_fac(&instance, n);

    printf("fac(%llu) -> %llu\n", n, result);

    facFreeInstance(&instance);

    return 0;
}
