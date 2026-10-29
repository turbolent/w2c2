import argparse
import concurrent.futures
import difflib
import os
from pathlib import Path
import shlex
import subprocess
import tempfile
import sys

import gen

ROOT = Path(__file__).resolve().parents[1]


def simde_cflags():
    header = os.environ.get('SIMDE_HEADER')
    if not header:
        return []
    header = Path(header).resolve()
    return ['-I' + header.parent.as_posix(), '-DW2C2_SIMDE_HEADER=<' + header.name + '>']


def run_wast(path, args):
    with tempfile.TemporaryDirectory(prefix='w2c2-wast-') as directory:
        directory = Path(directory)
        manifest = directory / 'suite.json'
        subprocess.run(['wast2json', '--enable-threads', path.as_posix(), '-o', manifest.as_posix()],
                       check=True, capture_output=True)
        test, = gen.generate_test_files(manifest, combined=True, output_dir=directory)
        modules = []
        uses_simd = False
        for filename in test['modules']:
            source = directory / ('test_' + Path(filename).with_suffix('.c').name)
            subprocess.run([str(args.w2c2), '-m', (directory / filename).as_posix(), source.as_posix()],
                           check=True, capture_output=True)
            modules.append(source)
            uses_simd |= any('#include "w2c2_simd.h"' in p.read_text()
                             for p in (source, source.with_suffix('.h')))
        command = shlex.split(args.cc) + (['-std=c99'] if uses_simd else []) + [
            '-DW2C2_RUNTIME_CHECKS=1',
            '-I' + (ROOT / 'w2c2').as_posix(), '-I' + (ROOT / 'tests').as_posix()]
        if uses_simd:
            command += simde_cflags()
        flags = shlex.split(args.cflags)
        binary = directory / ('run.exe' if os.name == 'nt' else 'run')
        harness_object = directory / 'harness.o'
        # Keep large assertion functions cheap to compile. Translated modules
        # and the shared harness retain the requested optimization flags.
        subprocess.run(command + flags + ['-O1', '-c', test['path'].as_posix(), '-o', harness_object.as_posix()],
                       check=True, capture_output=True)
        libraries = [] if os.name == 'nt' else ['-lm']
        subprocess.run(command + flags + [harness_object.as_posix(), (ROOT / 'tests/main.c').as_posix()]
                       + [p.as_posix() for p in modules] + libraries
                       + shlex.split(getattr(args, 'ldflags', '')) + ['-o', binary.as_posix()],
                       check=True, capture_output=True)
        execute = shlex.split(getattr(args, 'execute', None) or '') + [str(binary)]
        result = subprocess.run(execute, check=True, capture_output=True)
        if b'FAIL: ' in result.stderr:
            failures = b'\n'.join(line for line in result.stderr.splitlines() if line.startswith(b'FAIL: '))
            raise subprocess.CalledProcessError(1, execute, output=result.stdout, stderr=failures)
        return test['count']


def run_binary(args):
    command = []

    if args.execute:
        command.extend(shlex.split(args.execute))
    command.append(os.path.abspath(args.tests[0]))

    output = subprocess.run(command, check=True, stderr=subprocess.PIPE).stderr.decode('utf-8').strip()

    print(output)

    if args.arch:
        path = args.tests[0] + '.' + args.arch + '.out'
        if os.path.isfile(path):
            expected = ''
            with open(path, 'r') as f:
                expected = f.read()
            diff = list(difflib.unified_diff(
                expected.splitlines(keepends=True),
                output.splitlines(keepends=True),
                fromfile='expected',
                tofile='actual'
            ))
            if diff:
                print()
                sys.stdout.writelines(diff)
                exit(1)
            return

    if 'FAIL: ' in output:
        exit(1)


def main():
    parser = argparse.ArgumentParser(description='Run compiled tests or generate, compile, and run WAST scripts.')
    parser.add_argument('tests', nargs='+')
    parser.add_argument('-a', '--arch')
    parser.add_argument('-e', '--execute')
    parser.add_argument('--w2c2', type=Path, default=ROOT / 'w2c2/w2c2')
    parser.add_argument('--cc', default=os.environ.get('CC', 'cc'))
    parser.add_argument('--cflags', default=os.environ.get('CFLAGS', '-O2'))
    parser.add_argument('--ldflags', default=os.environ.get('LDFLAGS', ''))
    parser.add_argument('-j', '--jobs', type=int, default=4)
    args = parser.parse_args()
    if not all(Path(path).suffix == '.wast' for path in args.tests):
        if len(args.tests) != 1:
            parser.error('Pass one compiled test or a list of WAST files')
        run_binary(args)
        return
    count = 0
    failed = 0
    paths = list(dict.fromkeys(Path(path).resolve() for path in args.tests))
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as executor:
        pending = {executor.submit(run_wast, path, args): path for path in paths}
        for future in concurrent.futures.as_completed(pending):
            path = pending[future]
            try:
                assertions = future.result()
                count += assertions
                print('{}: {} assertions passed'.format(path.name, assertions), flush=True)
            except Exception as error:
                failed += 1
                print('{}: FAILED: {}'.format(path.name, error), flush=True)
                if isinstance(error, subprocess.CalledProcessError) and error.stderr:
                    print(error.stderr.decode(errors='replace'), flush=True)
    print('{} assertions passed. {} files failed.'.format(count, failed))
    raise SystemExit(bool(failed))


if __name__ == '__main__':
    main()
