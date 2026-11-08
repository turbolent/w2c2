#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif
#include "wasi.h"
#include "module.h"

void trap(Trap reason) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(reason));
    exit(125);
}

wasmMemory* wasiMemory(wasmModuleInstance* instance) {
    return m6_moduleExport6_memory((m6_moduleInstance*)instance);
}

int main(int argc, char** argv) {
    m6_moduleInstance instance;
    char** environment = calloc((size_t)argc, sizeof(char*));
    const char* root = NULL;
    int environmentCount = 0;
    int index = 1;
    if (environment == NULL) {
        return 2;
    }
    while (index < argc && strcmp(argv[index], "--") != 0) {
        const char* option = argv[index++];
        if (index >= argc) {
            free(environment);
            return 2;
        }
        if (strcmp(option, "--root") == 0) {
            root = argv[index++];
        } else if (strcmp(option, "--env") == 0) {
            environment[environmentCount++] = argv[index++];
        } else {
            free(environment);
            return 2;
        }
    }
    index++;
    if (index >= argc) {
        free(environment);
        return 2;
    }
#ifdef _WIN32
    if (_setmode(_fileno(stdin), _O_BINARY) == -1
        || _setmode(_fileno(stdout), _O_BINARY) == -1
        || _setmode(_fileno(stderr), _O_BINARY) == -1) {
        free(environment);
        return 2;
    }
#endif
    if (!wasiInit(argc - index, argv + index, environment)
        || (root != NULL && !wasiPreopenDirectory(root, "/", NULL))) {
        fprintf(stderr, "failed to initialize WASI\n");
        free(environment);
        return 2;
    }
    m6_moduleInstantiate(&instance, NULL);
    m6_moduleExport6_X5Fstart(&instance);
    m6_moduleFreeInstance(&instance);
    free(environment);
    return 0;
}
