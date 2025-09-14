# Clang

`llvm.wasm` is LLVM/Clang built as a WebAssembly WASI binary,
from https://github.com/YoWASP/clang/commit/3aa8abe1f0146bb9c0fe9191bd72d0fab06e4eb0,
which is a project by https://github.com/whitequark

## Build

```sh
make -j12
```

## Usage

```sh
echo 'int printf(const char *, ...); int main(){ printf("hello world"); }' > hello.c
./sys/bin/clang -o `pwd`/hello.o `pwd`/hello.c
```
