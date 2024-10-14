#!/bin/bash -ex

WASI_SDK=/opt/wasi-sdk
CC=${WASI_SDK}/bin/clang

cat >w2c2_main.c <<END
#include <stdio.h>
#include "w2c2_base.h"
#include "wasi.h"
#include "w2c2.h"

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
    return w2c2_memory((w2c2Instance*)instance);
}

extern char** environ;

/* Main */

int main(int argc, char* argv[]) {
    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

    {
        w2c2Instance instance;
        w2c2Instantiate(&instance, NULL);
        w2c2__start(&instance);
        w2c2FreeInstance(&instance);
    }

    return 0;
}
END

if ! [ -d build ]; then
    mkdir build
    cd build
    mkdir w2c2
    cd w2c2
    cmake ../../../w2c2 -DCMAKE_TOOLCHAIN_FILE=${WASI_SDK}/share/cmake/wasi-sdk.cmake -DCMAKE_BUILD_TYPE=Debug
    make
    cd ..
    mkdir wasi
    cd wasi
    cmake ../../../wasi -DCMAKE_TOOLCHAIN_FILE=${WASI_SDK}/share/cmake/wasi-sdk.cmake -DCMAKE_BUILD_TYPE=Debug
    make
    cd ../..
fi

rm -rf silly
mkdir -p silly/gen1
cp build/w2c2/w2c2 silly/gen1/w2c2.wasm

function breed() {
    genX=gen$1
    genY=gen$(($1 + 1))
    echo "=======> breeding ${genX} into ${genY}" >&2

    mkdir -p silly/${genY}
    wasmtime run --dir . "silly/${genX}/w2c2.wasm" "silly/${genX}/w2c2.wasm" "silly/${genY}/w2c2.c"
    ${CC} -Iw2c2 -Iwasi -Isilly/${genY} build/wasi/libw2c2wasi.a silly/${genY}/w2c2.c w2c2_main.c -o silly/${genY}/w2c2.wasm
}

for gen in $(seq 1 10); do
    breed "$gen"
done
