#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
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
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    {
        static char* rootPath = "/";
        int rootFD = open(rootPath, O_DIRECTORY);
        if (rootFD < 0) {
            fprintf(stderr, "failed to open root path\n");
            return 1;
        }
        {
            WasiPreopen preopen = {rootPath, rootFD};
            if (!wasiPreopenAdd(preopen, NULL)) {
                fprintf(stderr, "failed to add preopen\n");
                close(rootFD);
                return 1;
            }
        }
    }

    /* Initialize module */
    init();

    (*e_X5Fstart)();

    return 0;
}
