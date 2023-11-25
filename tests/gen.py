import json
import glob
import re
from os.path import splitext

import math
import struct
import subprocess
import sys
from pathlib import Path


gen_dir = Path('gen')


def compare_versions(a, b):
    for [a, b] in zip(*[[int(s) for s in v.split('.')] for v in [a, b]]):
        if a < b:
            return -1
        elif a > b:
            return 1
    return 0


def export_name(name):
    escape_char = 'X'
    res = ""
    for i, c in enumerate(name):
        if c == '_':
            if i > 0 and name[i-1] == '_':
                res += "__"
            else:
                res += c
        elif c != escape_char and c.isalnum():
            res += c
        else:
            res += escape_char + "{:02X}".format(ord(c))
    return res


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
        value = struct.unpack('f', struct.pack('I', int(value)))[0]
        if value == math.inf:
            return 'INFINITY'
        elif value == -math.inf:
            return '-INFINITY'
        else:
            return str(value)
    elif t == 'F64':
        value = struct.unpack('d', struct.pack('Q', int(value)))[0]
        if value == math.inf:
            return 'INFINITY'
        elif value == -math.inf:
            return '-INFINITY'
        else:
            return str(value)
    raise Exception("unsupported type {}".format(t))


invalid_char_regex = re.compile('[^a-zA-Z0-9]')

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
""".format(header=header, module_name=module_name)
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
                module_name = invalid_char_regex.sub('', splitext(filename)[0])
                close_test_file()
                create_test_file(filename, module_name)
                test_file.write("    printStart(\"{}\");\n".format(filename))

            elif action is not None and action['type'] == 'invoke':
                if not test_file:
                    continue

                # TODO:
                if 'nan' in (arg['value'] for arg in action['args']):
                    continue

                args = [
                    convert_value(arg['value'], convert_type(arg['type']))
                    for arg in action['args']
                ]

                # TODO:
                if 'nan' in args:
                    continue

                field = action['field']

                call = "{}_{}({})".format(
                    module_name,
                    export_name(field),
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
                    # TODO:
                    if expected_value.startswith('nan'):
                        continue

                    expected_value = convert_value(expected_value, expected_type)

                    # TODO:
                    if expected_value == 'nan':
                        continue

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

    memory_files = {'memory_copy.wast', 'memory_fill.wast', 'bulk.wast'}

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
