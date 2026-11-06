# WebAssembly specification tests

Tests from [WebAssembly/testsuite](https://github.com/WebAssembly/testsuite),
licensed under Apache-2.0.

Build w2c2 first, then run these commands from this directory.
Python 3 and a C compiler are required.

```sh
make run-tests
```

Scalar tests enable runtime checks and verify trap reasons.
Validation assertions, module-instantiation traps, and stack exhaustion are skipped.
Running scalar tests does not require WABT.

For optimized runs with Clang:

```sh
CC=clang CFLAGS=-ffp-model=strict make -B run-tests OPT=-O2
CC=clang CFLAGS=-ffp-model=strict make -B run-tests OPT=-O3
```

Use `-B` when changing compiler flags.
Other compiler configurations are in the [CI workflow](../.github/workflows/tests.yml).

To cross-compile and run with QEMU:

```sh
ARCH=ppc EXECUTE=qemu-ppc-static CC=powerpc-linux-gnu-gcc CFLAGS=-static make run-tests
```

## SIMD

SIMD tests also require WABT's `wast2json`, a C99 compiler, and [SIMDe](https://github.com/simd-everywhere/simde).
CI uses SIMDe revision `65c15e6b545361f6dd89b1e3bcc76273e1344653`.

```sh
export SIMDE_HEADER=/path/to/simde/simde/wasm/simd128.h
make simd-test
```

Use `make simd-spec-test` to run only the WAST execution tests.
To exercise the portable backends:

```sh
make simd-spec-test SIMD_CFLAGS="-O2 -DSIMDE_NO_NATIVE"
make simd-spec-test SIMD_CFLAGS="-O2 -DSIMDE_NO_NATIVE -DSIMDE_NO_VECTOR"
```

The suite covers fixed-width SIMD.
Relaxed SIMD and `simd_memory-multi.wast` are excluded.

## Updating tests

After editing scalar WAST files, regenerate the fixtures with Python 3 and WABT 1.0.42:

```sh
make gen
```

Keep imported SIMD files unchanged.
Name local SIMD regressions `simd_*.wast` so the test target includes them.
Run the scalar and SIMD suites after updates.

Upstream revisions:

- Table/reference/import/linking, extended-const, and SIMD imports: [44f1503](https://github.com/WebAssembly/testsuite/tree/44f1503f98409fa3737437bf9449a37a5def4210).
- Additional invocation-trap cases: [6390867](https://github.com/WebAssembly/testsuite/tree/63908677d00585fdab4c4eccbf01f781d3a454d5).
