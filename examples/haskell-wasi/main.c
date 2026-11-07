#include <stdio.h>
#include <stdlib.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "haskellwasi.h"

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
    return m11_haskellwasiExport6_memory((m11_haskellwasiInstance*)instance);
}

extern char** environ;

int main(int argc, char* argv[]) {
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    {
        m11_haskellwasiInstance instance;
        m11_haskellwasiInstantiate(&instance, NULL);
        m11_haskellwasiExport6_X5Fstart(&instance);
        m11_haskellwasiFreeInstance(&instance);
    }

    return 0;
}
