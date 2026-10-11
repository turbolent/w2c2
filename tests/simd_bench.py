#!/usr/bin/env python3
"""Build and run the matching native/translated SIMD dot-product benchmark."""
import argparse
import os
from pathlib import Path
import shlex
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cc', default=os.environ.get('CC', 'cc'))
    parser.add_argument('--cflags', default='-O3')
    parser.add_argument('--w2c2', type=Path, default=ROOT / 'w2c2/w2c2')
    args = parser.parse_args()
    with tempfile.TemporaryDirectory(prefix='w2c2-simd-bench-') as directory:
        directory = Path(directory)
        wasm = directory / 'simd_bench.wasm'
        generated = directory / 'simd_bench.c'
        executable = directory / 'benchmark'
        subprocess.run(['wat2wasm', str(ROOT / 'tests/simd_bench.wat'), '-o', str(wasm)], check=True)
        subprocess.run([str(args.w2c2), str(wasm), str(generated)], check=True)
        command = shlex.split(args.cc) + ['-std=c89'] + shlex.split(args.cflags)
        command += ['-I' + str(ROOT / 'w2c2'), '-I' + str(directory),
                    str(ROOT / 'tests/simd_bench.c'), str(ROOT / 'tests/simd_bench_native.c'),
                    str(generated), '-lm', '-o', str(executable)]
        subprocess.run(command, check=True)
        subprocess.run([str(executable)], check=True)


if __name__ == '__main__':
    main()
