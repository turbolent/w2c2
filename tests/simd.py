#!/usr/bin/env python3
"""Compile and run SIMD WAST assertions through w2c2.

Requires WABT's wast2json and a C compiler. Pass the official spec's
 test/core/simd/*.wast paths. --portable disables SIMDe native backends.
Only execution assertions are counted; validation assertions belong to a
Wasm validator, which w2c2 is not. Each test runs in an isolated directory.
"""
import argparse
import concurrent.futures
import json
import os
from pathlib import Path
import shlex
import subprocess
import tempfile

from gen import export_name, module_identifier

ROOT = Path(__file__).resolve().parents[1]


def bits(value, width):
    if value == 'nan:canonical' or value == 'nan:arithmetic':
        return 0x7fc00000 if width == 32 else 0x7ff8000000000000
    return int(value) & ((1 << width) - 1)


def vector_bytes(value):
    width = int(value['lane_type'][1:])
    return b''.join(bits(v, width).to_bytes(width // 8, 'little') for v in value['value'])


def argument(value):
    t = value['type']
    if t == 'v128':
        data = vector_bytes(value)
        return 'w2c2_v128_const(' + ','.join(str(b if b < 128 else b - 256) for b in data) + ')'
    width = int(t[1:])
    literal = '0x{:x}{}'.format(bits(value['value'], width), 'U' if width == 32 else 'ULL')
    return literal if t[0] == 'i' else 'f{0}_reinterpret_i{0}({1})'.format(width, literal)


def mask_for(value, width):
    if value == 'nan:canonical':
        return (1 << (width - 1)) - 1
    if value == 'nan:arithmetic':
        return 0x7fc00000 if width == 32 else 0x7ff8000000000000
    return (1 << width) - 1


def assertion(call, expected, line):
    t = expected['type']
    if t == 'v128':
        width = int(expected['lane_type'][1:])
        masks = b''.join(mask_for(v, width).to_bytes(width // 8, 'little') for v in expected['value'])
        data = vector_bytes(expected)
        checks = ''.join('CHECK((actual[{0}] & {1}) == {2}, {3});\n'.format(i, mask, byte, line)
                         for i, (byte, mask) in enumerate(zip(data, masks)))
        return '{ U8 actual[16]; wasmMemory memory; memory.data=actual; memory.size=16; w2c2_v128_store(&memory,0,' + call + ');\n' + checks + '}\n'
    width = int(t[1:])
    if t[0] == 'f':
        call = 'i{0}_reinterpret_f{0}({1})'.format(width, call)
    mask = mask_for(expected['value'], width)
    suffix = 'U' if width == 32 else 'ULL'
    return 'CHECK((({}) & 0x{:x}{}) == 0x{:x}{}, {});\n'.format(
        call, mask, suffix, bits(expected['value'], width), suffix, line)


PREAMBLE = r'''
#include <stdio.h>
#include <setjmp.h>
#include "w2c2_simd.h"
static jmp_buf trap_target;
static int trap_expected;
struct ImportBinding { const char* module; const char* name; void* value; };
static struct ImportBinding globals[256];
static size_t global_count;
static void bind_import(const char* module, const char* name, void* value) {
    globals[global_count].module=module;
    globals[global_count].name=name;
    globals[global_count++].value=value;
}
void trap(Trap reason) {
    if (!trap_expected) { fprintf(stderr,"Unexpected trap %d\n",(int)reason); exit(1); }
    longjmp(trap_target,1);
}
#define CHECK(condition,line) do { if (!(condition)) { fprintf(stderr,"Assertion failed at WAST line %d\n",line); exit(1); } } while (0)
static void* resolve(WasmName module,WasmName name) {
    size_t index;
    for (index=0;index<global_count;index++) {
        if (strlen(globals[index].module)==module.length && memcmp(globals[index].module,module.data,module.length)==0
            && strlen(globals[index].name)==name.length && memcmp(globals[index].name,name.data,name.length)==0) return globals[index].value;
    }
    fprintf(stderr,"Unresolved import\n"); exit(1); return NULL;
}
'''


def object_exports(path):
    data = path.read_bytes()
    offset = 8

    def integer():
        nonlocal offset
        result = 0
        shift = 0
        while True:
            byte = data[offset]
            offset += 1
            result |= (byte & 127) << shift
            if not byte & 128:
                return result
            shift += 7

    while offset < len(data):
        section = data[offset]
        offset += 1
        length = integer()
        end = offset + length
        if section == 7:
            exports = []
            for _ in range(integer()):
                length = integer()
                name = data[offset:offset + length].decode('utf-8')
                offset += length
                kind = data[offset]
                offset += 1
                integer()
                if kind in (2, 3):
                    exports.append(name)
            return exports
        offset = end
    return []


def run(path, args):
    with tempfile.TemporaryDirectory(prefix='w2c2-simd-') as directory:
        directory = Path(directory)
        manifest = directory / 'suite.json'
        subprocess.run(['wast2json', str(path), '-o', str(manifest)], check=True, capture_output=True)
        commands = json.loads(manifest.read_text())['commands']
        modules = []
        body = []
        current = None
        named = {}
        count = 0
        for command in commands:
            kind = command['type']
            if kind == 'module':
                name = Path(command['filename']).stem
                ident = module_identifier(name)
                out = directory / (name + '.c')
                subprocess.run([str(args.w2c2), '-m', str(directory / command['filename']), str(out)],
                               check=True, capture_output=True)
                modules.append(out)
                current = name
                if 'name' in command:
                    named[command['name']] = name
                body.append('{}Instance instance_{};\n{}Instantiate(&instance_{},resolve);\n'.format(ident, len(modules), ident, len(modules)))
            elif kind == 'register':
                name = named.get(command.get('name'), current)
                module_index = next(i + 1 for i, m in enumerate(modules) if m.stem == name)
                for field in object_exports(directory / (name + '.wasm')):
                    body.append('bind_import({},{},(void*){}(&instance_{}));\n'.format(
                        json.dumps(command['as']), json.dumps(field), export_name(name, field), module_index))
            elif kind in ('assert_return', 'assert_trap', 'action'):
                action = command['action']
                name = named.get(action.get('module'), current)
                module_index = next(i + 1 for i, m in enumerate(modules) if m.stem == name)
                instance = '&instance_' + str(module_index)
                if action['type'] == 'invoke':
                    call = '{}({})'.format(export_name(name, action['field']), ','.join([instance] + [argument(a) for a in action['args']]))
                elif action['type'] == 'get':
                    call = '*{}({})'.format(export_name(name, action['field']), instance)
                else:
                    raise ValueError('Unsupported action: ' + action['type'])
                line = command['line']
                if kind == 'assert_trap':
                    body.append('trap_expected=1; if (setjmp(trap_target)==0) { (void)(' + call + '); CHECK(0,' + str(line) + '); } trap_expected=0;\n')
                elif kind == 'assert_return' and command['expected']:
                    if len(command['expected']) != 1:
                        raise ValueError('Multiple results are outside w2c2 support')
                    body.append(assertion(call, command['expected'][0], line))
                else:
                    body.append('(void)(' + call + ');\n')
                count += 1
        for i, module in reversed(list(enumerate(modules, 1))):
            body.append('{}FreeInstance(&instance_{});\n'.format(module_identifier(module.stem), i))
        harness = directory / 'harness.c'
        includes = ''.join('#include "{}"\n'.format(m.with_suffix('.h').name) for m in modules)
        harness.write_text(PREAMBLE + includes + 'int main(void) {\n' + ''.join(body) + 'return 0; }\n')
        binary = directory / 'run'
        flags = shlex.split(args.cflags)
        if args.portable:
            flags += ['-DSIMDE_NO_NATIVE']
        command = shlex.split(args.cc) + ['-std=c89', '-DW2C2_RUNTIME_CHECKS=1', '-I' + str(ROOT / 'w2c2')]
        subprocess.run(command + flags + [str(harness)] + [str(m) for m in modules] + ['-lm', '-o', str(binary)], check=True, capture_output=True)
        subprocess.run([str(binary)], check=True, capture_output=True)
        return count


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('paths', type=Path, nargs='+')
    parser.add_argument('--exclude', action='append', default=[], help='Exclude a WAST basename')
    parser.add_argument('--w2c2', type=Path, default=ROOT / 'w2c2/w2c2')
    parser.add_argument('--cc', default=os.environ.get('CC', 'cc'))
    parser.add_argument('--cflags', default='-O2')
    parser.add_argument('--portable', action='store_true')
    parser.add_argument('-j', '--jobs', type=int, default=4)
    args = parser.parse_args()
    args.paths = [path for path in args.paths if path.name not in args.exclude]
    count = 0
    failed = 0
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as executor:
        pending = {executor.submit(run, path.resolve(), args): path for path in args.paths}
        for future in concurrent.futures.as_completed(pending):
            path = pending[future]
            try:
                n = future.result()
                count += n
                print('{}: {} assertions passed'.format(path.name, n), flush=True)
            except Exception as error:
                failed += 1
                print('{}: FAILED: {}'.format(path.name, error), flush=True)
                if isinstance(error, subprocess.CalledProcessError):
                    print(error.stderr.decode(errors='replace'), flush=True)
    print('{} assertions passed; {} files failed'.format(count, failed))
    raise SystemExit(bool(failed))


if __name__ == '__main__':
    main()
