# Clang

`clang.wasm` is Clang built as a WebAssembly WASI binary.

## Build

```sh
make -j 12
```

## Usage

```sh
echo 'int printf(const char *, ...); int main(){ printf("hello world"); }' | \
  ./clang -cc1 -triple wasm32-unknown-wasi -isysroot $PWD/sys -internal-isystem $PWD/sys/include -emit-obj -o /tmp/hello.o -
```
