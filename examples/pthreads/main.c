#include <stdlib.h>
#include <stdio.h>

#include "w2c2_base.h"
#include "../../wasi/wasi.h"
#include "pthreads.h"

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
    return pthreads_memory((pthreadsInstance*)instance);
}

extern char** environ;

wasmMemory* mem = NULL;

void* resolveImport(const char* moduleName, const char* importName) {
    if (strcmp(moduleName, "env") == 0 && strcmp(importName, "memory") == 0) {
        return mem;
    }
    return NULL;
}

int main(int argc, char** argv) {
    pthreadsInstance instance;

    mem = WASM_MEMORY_ALLOCATE_SHARED(10, 20);

    pthreadsInstantiate(&instance, resolveImport);

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }


    pthreads__start(&instance);

    pthreadsFreeInstance(&instance);

    return 0;
}
