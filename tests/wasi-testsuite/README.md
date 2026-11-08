# WASI P1 testsuite

Run the official [WebAssembly/wasi-testsuite](https://github.com/WebAssembly/wasi-testsuite)
against w2c2 and its WASI implementation.
CI pins the precompiled suite to
[`9d84631e427729802085c3d172d0a63cd360a1fa`](https://github.com/WebAssembly/wasi-testsuite/tree/9d84631e427729802085c3d172d0a63cd360a1fa).
It contains 72 P1 tests: 14 C, 46 Rust, and 12 AssemblyScript tests.

The driver translates and compiles each module before invoking the upstream runner.
The runner checks the original fixtures, output, and exit status.
No tests are skipped or marked as expected failures.
On Windows, the adapter sets the upstream `NO_RENAME_DIR_TO_EMPTY_DIR` option,
which checks that replacing an empty directory fails.

The launcher passes each test's arguments and environment to WASI,
and exposes its fixture directory as the guest preopen `/`.
Host environment variables are not inherited by the guest.
Runtime memory checks are enabled.

## Run locally

Python 3.12 or later, CMake, Git, and a native C compiler are required.
The precompiled modules do not require a WASI SDK, Rust, or AssemblyScript installation.
Run these commands from the repository root:

```sh
git clone --branch prod/testsuite-base https://github.com/WebAssembly/wasi-testsuite build/wasi-testsuite-upstream
git -C build/wasi-testsuite-upstream checkout 9d84631e427729802085c3d172d0a63cd360a1fa
python -m venv build/wasi-testsuite-venv
```

Activate the environment with `source build/wasi-testsuite-venv/bin/activate` on Unix,
or `build/wasi-testsuite-venv/Scripts/Activate.ps1` in PowerShell.
Then build and run:

```sh
python -m pip install -r build/wasi-testsuite-upstream/test-runner/requirements.txt
cmake -S w2c2 -B build/wasi-testsuite-translator -DCMAKE_BUILD_TYPE=Debug
cmake --build build/wasi-testsuite-translator --config Debug --parallel 4
python tests/wasi-testsuite/run.py --suite build/wasi-testsuite-upstream --w2c2 build/wasi-testsuite-translator/w2c2
```

With Visual Studio, use `build/wasi-testsuite-translator/Debug/w2c2.exe` for `--w2c2`.
Windows must permit symbolic link creation,
through Developer Mode or the process's privileges.

Use `--build` to choose an output directory,
`--config Release` to test optimized code,
and `--jobs` to set build concurrency.
Translations are reused when the module and translator are unchanged.

Results are written to `build/wasi-testsuite/results.json` by default.
Each generated module has a `translate.log` in `build/wasi-testsuite/generated/`.
The command exits unsuccessfully if translation, compilation, or any test fails.

[CI](../../.github/workflows/tests.yml) runs the suite on native Linux, macOS, and Windows hosts,
and uploads the results and translation logs.
