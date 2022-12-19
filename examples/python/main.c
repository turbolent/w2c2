#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../w2c2_base.h"
#include "../../wasi/wasi.h"
#include "python.h"

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
    return python_memory((pythonInstance*)instance);
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
        static char* rootPath = "/";
        int rootFD = open(rootPath, O_RDONLY);
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

    {
        pythonInstance instance;
        pythonInstantiate(&instance, wasiResolveImport);
        python_X5Fstart(&instance);
        pythonFreeInstance(&instance);
    }

    return 0;
}
