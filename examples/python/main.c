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

#define PYTHONHOME_VAR "PYTHONHOME="

bool
hasPrefix(
    const char* string,
    const char* prefix
) {
    char cs, cp;

    while ((cp = *prefix++)) {
        cs = *string++;
        if (cp != cs) {
            return false;
        }
        if (!cs) {
            break;
        }
    }
    return true;
}

/* Main */

int main(int argc, char* argv[]) {
    char cwd[PATH_MAX];
    char** newEnviron = NULL;
    char* pythonHomeVar = NULL;

#if defined(__MWERKS__) && defined(macintosh)
    MaxApplZone();
    MoreMasters();
    MoreMasters();

    argc = ccommand(&argv);
#endif

    /*
     * Ensure the PYTHONHOME environment variable is set.
     * Default to the current working directory.
     */
    {
        bool hasPythonHome = false;
        char** e = environ;
        int count = 0;
        for (; *e != NULL; e++) {
            count++;
            if (hasPrefix(*e, PYTHONHOME_VAR)) {
                hasPythonHome = true;
            }
        }

        if (!hasPythonHome) {
            if (getcwd(cwd, PATH_MAX) == NULL) {
                fprintf(stderr, "failed to get current working directory: %s\n", strerror(errno));
                return 1;
            }
            wasiFromNativePath(cwd);

            fprintf(stderr, "(Automatically setting PYTHONHOME to %s)\n", cwd);

            // 2: new entry + NULL
            newEnviron = calloc(sizeof(char*) * (count + 2), 1);
            memcpy(newEnviron, environ, count * sizeof(char*));

            pythonHomeVar = calloc(sizeof(char) * (strlen(PYTHONHOME_VAR) + strlen(cwd) + 1), 1);
            strcat(pythonHomeVar, PYTHONHOME_VAR);
            strcat(pythonHomeVar, cwd);

            newEnviron[count] = pythonHomeVar;

            environ = newEnviron;
        }
    }

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

    if (newEnviron) {
        free(newEnviron);
    }
    if (pythonHomeVar) {
        free(pythonHomeVar);
    }

    return 0;
}
