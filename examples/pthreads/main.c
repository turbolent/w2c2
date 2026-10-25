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
    wasmModuleInstance* instance
) {
    return m8_pthreadsExport6_memory((m8_pthreadsInstance*)instance);
}

extern char** environ;

wasmMemory* mem = NULL;

void* resolveImport(
    WasmName moduleName,
    WasmName importName
) {
    if (moduleName.length == sizeof("env") - 1 && memcmp(moduleName.data, "env", moduleName.length) == 0
        && importName.length == sizeof("memory") - 1 && memcmp(importName.data, "memory", importName.length) == 0) {
        return mem;
    }
    return NULL;
}

int main(int argc, char** argv) {
    m8_pthreadsInstance instance;

    mem = WASM_MEMORY_ALLOCATE_SHARED(10, 20);

    m8_pthreadsInstantiate(&instance, resolveImport);

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }


    m8_pthreadsExport6_X5Fstart(&instance);

    m8_pthreadsFreeInstance(&instance);

    return 0;
}
