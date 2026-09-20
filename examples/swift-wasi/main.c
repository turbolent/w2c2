#include <stdio.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "swiftwasi.h"

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
    return m10_swiftX2DwasiExport6_memory((m10_swiftX2DwasiInstance*)instance);
}

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/tmp", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

    {
        m10_swiftX2DwasiInstance instance;
        m10_swiftX2DwasiInstantiate(&instance, NULL);
        m10_swiftX2DwasiExport6_X5Fstart(&instance);
        m10_swiftX2DwasiFreeInstance(&instance);
    }

    return 0;
}
