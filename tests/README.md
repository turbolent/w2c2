# WebAssembly specification test suite

Taken from https://github.com/WebAssembly/testsuite

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
Running the checked-in scalar fixtures does not require wabt.
Scripts with registered modules generate a combined driver and Make dependencies.
The normal `run-tests` target discovers these drivers and runs them
with runtime checks enabled and disabled.

The `table*.wast`, `ref.wast`, `ref_*.wast`, `imports.wast`, and `linking.wast`
specification tests were imported from
[WebAssembly/testsuite](https://github.com/WebAssembly/testsuite/tree/44f1503f98409fa3737437bf9449a37a5def4210),
commit `44f1503f98409fa3737437bf9449a37a5def4210`.
Later-proposal cases, including typed references and GC, are commented out.
The reference-type cases in the older general fixtures are checked against this revision.
The `extern.wast` conversion tests require GC;
the numbered import/linking variants require multiple memories.
Function-reference variants supplement the upstream external-reference cases.
`table_operations.wast` covers control flow, ownership, and bulk operations.
`table_instances_test.c` tests host functions, borrowed host objects,
and segment state across instances.
The shared harness maps each `ref.extern` ID to a stable host object;
ID zero is non-null.
It releases these objects after freeing the generated instances.

### SIMD

The 59 imported `simd_*.wast` files in this directory are unmodified copies from [WebAssembly/testsuite](https://github.com/WebAssembly/testsuite/tree/44f1503f98409fa3737437bf9449a37a5def4210), commit `44f1503f98409fa3737437bf9449a37a5def4210`.
They are licensed under Apache-2.0.
Local regressions are in `simd_integration.wast`, `simd_conversions_regression.wast`,
`simd_multivalue.wast`, and `simd_table.wast`.

Set `SIMDE_HEADER` to the full path of `simde/wasm/simd128.h` in an external [SIMDe](https://github.com/simd-everywhere/simde) checkout:

```sh
export SIMDE_HEADER=/path/to/simde/simde/wasm/simd128.h
make simd-test
```

`make simd-test` runs the local regressions and the imported upstream execution tests.
Use `make simd-spec-test` for the WAST execution tests alone:

```sh
make simd-spec-test
make simd-spec-test SIMD_CFLAGS="-O2 -DSIMDE_NO_NATIVE"
make simd-spec-test SIMD_CFLAGS="-O2 -DSIMDE_NO_NATIVE -DSIMDE_NO_VECTOR"
```

The SIMD CI matrix runs the suite with GCC and Clang across SSE2, AVX2, portable vector, and scalar configurations.
Running requires Python 3, WABT's `wast2json`, a built w2c2, a C99 compiler, and an external SIMDe checkout.
CI uses SIMDe commit `65c15e6b545361f6dd89b1e3bcc76273e1344653`, which includes the WebAssembly conversion fixes from upstream PRs 1460 and 1461.
Once these dependencies are available, no network access is needed.

`simd_memory-multi.wast` is retained for provenance but excluded from the default target because it requires the separate multi-memory extension.
The remaining 58 imported files cover fixed-width SIMD.
Relaxed SIMD files are outside this import.

`gen.py` generates both scalar and SIMD assertions using the shared `test.h` and `main.c` harness.
`run.py` can run an existing test binary or generate, compile, and run a WAST script.
Whole-script runs preserve module order and registered function, table, memory, and global imports.
Registered function wrappers call the exporting instance.
Scripts without registrations use a per-module layout
and architecture-specific expected output.
Only generated code that uses SIMD enables C99 and the external SIMDe headers.
The runner translates valid modules and executes their actions, return assertions, and trap assertions.
It skips validation assertions (`assert_invalid`, `assert_malformed`, and `assert_unlinkable`) because w2c2 is not a Wasm validator.
Module-instantiation traps and stack-exhaustion assertions are outside this harness.
The malformed-immediate regression tests run separately.
A passing execution run does not establish validator conformance or verify the specific trap reason.

To update the import, copy the root `simd_*.wast` files from a new testsuite revision, update the pinned commit above, and run the complete matrix.
Keep upstream files unchanged.
Name local regression files `simd_*.wast` so the normal test target includes them.
