#include <stdio.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "coremark.h"
#include <unistd.h>

#ifdef __MSL__
#include <SIOUX.h>
#endif

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
    return coremark_memory((coremarkInstance*)instance);
}

#if defined(__MWERKS__) && defined(macintosh)
char** environ = NULL;
#else
extern char** environ;
#endif

/* Main */

int main(int argc, char* argv[]) {

    coremarkInstance instance;
    coremarkInstantiate(&instance, wasiResolveImport);

#ifdef __MSL__
    SIOUXSetTitle("\pCoreMark");
#endif

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    coremark_X5Fstart(&instance);
}
