#!/usr/bin/env python3

import os
import sys
import shlex
import subprocess


ROOT_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LAUNCHER = [
    f"{ROOT_DIR}/bin/llvm"
]
DIR_ARGS = [
    "--sysroot", f"{ROOT_DIR}",
    "-resource-dir", f"{ROOT_DIR}",
]


def run_llvm_tool(args):
    arg0, *args = args
    return subprocess.call([*LAUNCHER, os.path.basename(arg0), *args])


def run_clang_driver(args):
    arg0, *args = args
    if "-###" in args:
        return run_llvm_tool([arg0, *DIR_ARGS, *args])
    output = subprocess.run(
        [*LAUNCHER, os.path.basename(arg0), "-###", *DIR_ARGS, *args],
        check=True,
        stderr=subprocess.PIPE,
        text=True,
    ).stderr
    for line in output.splitlines():
        print(line, file=sys.stderr)
        if line.startswith(" \""):
            command = shlex.split(line)
            if command[0] == "": # clang would normally run this (usually cc1/cc1as) in-process
                del command[0]
            exit_code = run_llvm_tool(command)
            if exit_code != 0:
                return exit_code

RUNNERS = {
    "addr2line":    run_llvm_tool,
    "size":         run_llvm_tool,
    "objdump":      run_llvm_tool,
    "objcopy":      run_llvm_tool,
    "strip":        run_llvm_tool,
    "c++filt":      run_llvm_tool,
    "ar":           run_llvm_tool,
    "ranlib":       run_llvm_tool,
    "wasm-ld":      run_llvm_tool,
    "clang":        run_clang_driver,
    "clang++":      run_clang_driver,
}


if __name__ == "__main__":
    if os.getenv("__DRIVERDRIVER_LIST") == "1":
        print(" ".join(runner for runner in RUNNERS if runner))
    else:
        sys.exit(RUNNERS[os.path.basename(sys.argv[0])](sys.argv))
