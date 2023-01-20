#if defined(__MWERKS__) && defined(macintosh)
#include <MacMemory.h>
#define __bool_true_false_are_defined
typedef char bool;
#endif

#include <stdio.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "rustwasi.h"

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
    return rustwasi_memory((rustwasiInstance*)instance);
}

#if defined(__MSL__) && defined(macintosh)
char** environ = NULL;
#else
extern char** environ;
#endif

/* Main */

int main(int argc, char* argv[]) {
#if defined(__MWERKS__) && defined(macintosh)
    MaxApplZone();
    MoreMasters();
    MoreMasters();
#endif

    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/tmp", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

#ifdef __MSL__
    SIOUXSetTitle("\pRust");
#endif

    {
        rustwasiInstance instance;
        rustwasiInstantiate(&instance, wasiResolveImport);
        rustwasi_X5Fstart(&instance);
        rustwasiFreeInstance(&instance);
    }

    return 0;
}
