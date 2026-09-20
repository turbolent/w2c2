#include <stdio.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "llvm.h"

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
    return m4_llvmExport6_memory((m4_llvmInstance*)instance);
}

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

    {
        m4_llvmInstance instance;
        m4_llvmInstantiate(&instance, NULL);
        m4_llvmExport6_X5Fstart(&instance);
        m4_llvmFreeInstance(&instance);
    }

    return 0;
}
