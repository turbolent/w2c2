#include "../w2c2_base.h"
#include "wasi.h"

wasmMemory *e_memory;

extern char** environ;

int
main(int argc, char* argv[]) {
    wasmAllocateMemory(e_memory, 2, 65535);
    wasiInit(argc, argv, environ);
}
