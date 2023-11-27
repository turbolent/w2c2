#include <stdio.h>
#include <stdlib.h>

#include "w2c2_base.h"
#include "../../wasi/wasi.h"
#include "threads.h"

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
    return threads_memory((threadsInstance*)instance);
}

extern char** environ;

int main(int argc, char** argv) {
    threadsInstance instance;
    threadsInstantiate(&instance, NULL);

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

    threads__start(&instance);

    threadsFreeInstance(&instance);

    return 0;
}
