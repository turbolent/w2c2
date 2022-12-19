#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "w2c2_base.h"
#include "../../wasi/wasi.h"
#include "ls.h"

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
    return ls_memory((lsInstance*)instance);
}

extern char** environ;


int main(int argc, char** argv) {
    lsInstance instance;
    lsInstantiate(&instance, wasiResolveImport);

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
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

    ls_X5Fstart(&instance);

    lsFreeInstance(&instance);

    return 0;
}
