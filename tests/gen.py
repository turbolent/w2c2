import json
import glob
import re

import math
import struct
import subprocess
import sys
from pathlib import Path


gen_dir = Path('gen')


def compare_versions(a, b):
    versions = [
        [int(s) for s in re.match(r'\d+(?:\.\d+)*', v).group(0).split('.')]
        for v in [a, b]
    ]
    for [a, b] in zip(*versions):
        if a < b:
            return -1
        elif a > b:
            return 1
    return 0


def name_component(name):
    data = name.encode('utf-8')
    escaped = ''.join(
        chr(c) if (ord('a') <= c <= ord('z')
                   or (ord('A') <= c <= ord('Z') and c != ord('X'))
                   or ord('0') <= c <= ord('9')) else 'X{:02X}'.format(c)
        for c in data
    )
    return '{}_{}'.format(len(data), escaped)


def module_identifier(name):
    return 'm' + name_component(name)


def export_name(module, name):
    return module_identifier(module) + 'Export' + name_component(name)


def convert_type(t):
    if t == "i32":
        return "U32"
    elif t == "i64":
        return "U64"
    elif t == "f32":
        return "F32"
    elif t == "f64":
        return "F64"
    raise Exception("unsupported type {}".format(t))


def convert_value(value, t):
    if t == "U32":
        return value + "u"
    elif t == "U64":
        return value + "ull"
    elif t == 'F32':
        bits = int(value)
        value = struct.unpack('f', struct.pack('I', bits))[0]
        if math.isnan(value):
            return 'f32_reinterpret_i32(0x{:08x}u)'.format(bits)
        if value == math.inf:
            return 'INFINITY'
        elif value == -math.inf:
            return '-INFINITY'
        else:
            return str(value)
    elif t == 'F64':
        bits = int(value)
        value = struct.unpack('d', struct.pack('Q', bits))[0]
        if math.isnan(value):
            return 'f64_reinterpret_i64(0x{:016x}ull)'.format(bits)
        if value == math.inf:
            return 'INFINITY'
        elif value == -math.inf:
            return '-INFINITY'
        else:
            return str(value)
    raise Exception("unsupported type {}".format(t))


def generate_test_files(json_path):

    test_file = None

    def create_test_file(filename, module_name):
        nonlocal test_file

        test_path = gen_dir / filename
        test_path = test_path.with_name('assert_' + test_path.name).with_suffix('.c')
        print("    " + str(test_path))

        header = Path(filename)
        header = header.with_name('test_' + header.name).with_suffix('.h')

        test_preamble = """
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "{header}"

void test() {{
    {module_name}Instance instance;
    {module_name}Instantiate(&instance, resolveTestImports);
""".format(header=header, module_name=module_identifier(module_name))
        test_file = open(test_path, 'w')
        test_file.write(test_preamble)

    def close_test_file():
        nonlocal test_file
        if not test_file:
            return
        test_file.write('}\n')
        test_file.flush()
        test_file.close()
        test_file = None

    with open(json_path, 'r') as f:
        info = json.load(f)

        module_name = ""

        for command in info['commands']:
            t = command['type']
            action = command.get('action')
            if t == "module":
                filename = command['filename']
                module_name = Path(filename).stem
                close_test_file()
                create_test_file(filename, module_name)
                test_file.write("    printStart(\"{}\");\n".format(filename))

            elif action is not None and action['type'] == 'invoke':
                if not test_file:
                    continue

                args = [
                    convert_value(arg['value'], convert_type(arg['type']))
                    for arg in action['args']
                ]

                field = action['field']

                call = "{}({})".format(
                    export_name(module_name, field),
                    ', '.join(['&instance', *args])
                )

                description = "{}({})".format(field, ', '.join(args))

                if t == 'assert_return':

                    expected = command['expected']

                    if len(expected) == 0:
                        test_file.write("    {};\n".format(call))
                        continue

                    # TODO: add support for multiple result values
                    if len(expected) > 1:
                        continue

                    expected_type = convert_type(expected[0]['type'])
                    expected_value = expected[0]['value']

                    # Compare exact results as bits;
                    # NaN patterns ignore only the bits left unspecified by the assertion.
                    if expected_type in ('F32', 'F64'):
                        width = int(expected_type[1:])
                        expected_type = 'U' + str(width)
                        call = 'i{0}_reinterpret_f{0}({1})'.format(width, call)
                        if expected_value in ('nan:canonical', 'nan:arithmetic'):
                            # Canonical NaNs allow either sign;
                            # arithmetic NaNs also allow arbitrary lower payload bits.
                            canonical = 0x7fc00000 if width == 32 else 0x7ff8000000000000
                            mask = (1 << (width - 1)) - 1 if expected_value == 'nan:canonical' else canonical
                            call = '({} & {})'.format(call, convert_value(str(mask), expected_type))
                            expected_value = str(canonical)

                    expected_value = convert_value(expected_value, expected_type)

                    test_file.write("    assertEqual{}(\n".format(expected_type))
                    test_file.write("        {},\n".format(call))
                    test_file.write("        {},\n".format(expected_value))
                    test_file.write("        \"{}\"\n".format(description))
                    test_file.write("    );\n")

                elif t == 'action':
                    test_file.write("    {};\n".format(call))
                    test_file.write("    printOK(\"{}\");\n".format(description))

        close_test_file()


def gen(paths):
    wast2json_version = subprocess.check_output(['wast2json', '--version']).decode('utf-8').strip()
    has_new_wabt = compare_versions(wast2json_version, "1.0.25") > 0

    memory_files = {
        'memory_copy.wast',
        'memory_fill.wast',
        'memory_init.wast',
        'bulk.wast',
        'binary-leb128.wast'
    }

    for wast_path in paths:
        print(wast_path)

        wast2json_opts = ['--enable-threads']

        if has_new_wabt:
            if wast_path not in memory_files:
                wast2json_opts.append('--disable-bulk-memory')
        else:
            if wast_path in memory_files:
                wast2json_opts.append('--enable-bulk-memory')

        # Convert WAST to JSON and WASM files, if needed
        json_path = gen_dir / Path(wast_path).with_suffix('.json').name
        wast2json_opts.extend(['-o', str(json_path)])

        subprocess.check_call(['wast2json', *wast2json_opts, wast_path])

        generate_test_files(json_path)


if __name__ == "__main__":
    if len(sys.argv) > 1:
        paths = sys.argv[1:]
    else:
        paths = glob.glob('*.wast')
    gen(paths)
