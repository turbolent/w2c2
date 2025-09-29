# Clang

`llvm.wasm` is LLVM/Clang built as a WebAssembly WASI binary,
from https://github.com/YoWASP/clang/commit/3aa8abe1f0146bb9c0fe9191bd72d0fab06e4eb0,
which is a project by https://github.com/whitequark.

It was optimized with Binaryen:

```sh
$ wasm-opt --enable-bulk-memory --enable-nontrapping-float-to-int -O4 -o llvm.opt.wasm llvm.wasm
```

## Build

```sh
make -j12
```

## Usage

```sh
$ echo 'int printf(const char *, ...); int main(){ printf("Hello, world!"); }' > hello.c
$ ./sys/bin/clang -o `pwd`/hello.wasm `pwd`/hello.c
$ wasmtime ./hello.wasm
Hello, world!
```
