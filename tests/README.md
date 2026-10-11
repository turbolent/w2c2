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

### Fixed-width SIMD

Build w2c2 first, then run the local regressions (requires WABT for integration):

```sh
make -C ../w2c2
make simd-test
make simd-benchmark
```

`simd_test.py` constructs binaries directly and compiles all 236 instruction
mappings, including constant lane immediates, with C89 and conversion warnings
as errors. It also checks malformed instructions in reachable and unreachable
code and translates into multiple C files with two worker threads.
`simd/integration.wast` exercises vector locals, signatures, globals, imports,
calls, indirect calls, and control flow.

To run the official specification execution assertions, obtain
[WebAssembly/spec](https://github.com/WebAssembly/spec) and pass its SIMD WASTs:

```sh
# From this directory; SPEC points to a WebAssembly/spec checkout.
python3 simd.py --exclude simd_memory-multi.wast "$SPEC"/test/core/simd/simd_*.wast
python3 simd.py --exclude simd_memory-multi.wast --portable --cc gcc \
  --cflags='-O1 -DSIMDE_NO_VECTOR -fsanitize=undefined,float-cast-overflow -fno-sanitize-recover=all' \
  "$SPEC"/test/core/simd/simd_*.wast
```

Exclude `simd_memory-multi.wast`: it tests the separate multi-memory proposal,
which w2c2 does not implement. The runner counts execution assertions, checks
vector results lane by lane as bits (including NaN masks), and checks traps with
runtime checks enabled. Validation assertions are left to Wasm validators.
Registered global and memory imports are supported; registered function imports need a C
host binding, as with other w2c2 modules.

Verified against spec commit `7e9fb78c63d65018cc111422f657947b3df80d7b`:
24,335 official execution assertions across 58 files, including linking module
instantiation. Tests use isolated temporary directories and leave no generated
artifacts in the worktree. Compiler flags can be selected with `--cc` and
`--cflags`; the benchmark compiles its native and translated kernels separately
with identical flags to prevent hoisting the native call out of the timing loop.
