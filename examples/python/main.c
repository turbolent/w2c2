#if defined(__MWERKS__) && defined(macintosh)
#include <MacMemory.h>
#include <Files.h>
#define __bool_true_false_are_defined
typedef char bool;
#endif

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#ifdef __MSL__
#include <SIOUX.h>
#include <console.h>
#endif

#include "../../w2c2/w2c2_base.h"
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

#if defined(__MSL__) && defined(macintosh)
char** environ = {NULL};
#else
extern char** environ;
#endif


/* Main */

int main(int argc, char* argv[]) {

#if defined(__MWERKS__) && defined(macintosh)
    MaxApplZone();
    MoreMasters();
    MoreMasters();

    argc = ccommand(&argv);
#endif

    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

#ifdef __MSL__
    SIOUXSetTitle("\pPython");
#endif

    {
        pythonInstance instance;
        pythonInstantiate(&instance, wasiResolveImport);
        python_X5Fstart(&instance);
        pythonFreeInstance(&instance);
    }

    return 0;
}
