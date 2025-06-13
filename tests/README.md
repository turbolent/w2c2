# WebAssembly specification test suite

Taken from https://github.com/WebAssembly/spec/tree/wg-1.0/test/core

Licensed under the Apache License 2.0

```sh
make run-tests
```

To run for a different architecture, cross-compile and use e.g. qemu to run the binary:

```sh
ARCH=ppc EXECUTE=qemu-ppc-static CC=powerpc-linux-gnu-gcc make run-tests CFLAGS="-static -I../w2c2"
```

### Development

When updating the test cases, re-run `make gen`, which requires Python 3 and wabt.
