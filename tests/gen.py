import json
import glob
import math
import struct
import subprocess
import sys
from pathlib import Path


def export_name(name):
    escape_char = 'X'
    res = "e_"
    for c in name:
        if c.isalnum() and c != escape_char:
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


test_preamble = """
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"

void test() {
"""

def generate_test_files(json_path):

    test_file = None

    def create_test_file(filename):
        nonlocal test_file
        test_path = Path(filename)
        test_path = test_path.with_name('assert_' + test_path.name).with_suffix('.c')
        print("    " + str(test_path))
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

        for command in info['commands']:
            t = command['type']
            action = command.get('action')
            if t == "module":
                close_test_file()
                filename = command['filename']
                create_test_file(filename)
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

                argument_list = ', '.join(args)

                call = "(*{})({})".format(export_name(action['field']), argument_list)

                description = "{}({})".format(action['field'], argument_list)

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
    for wast_path in paths:
        print(wast_path)
            
        # Convert WAST to JSON and WASM files, if needed
        json_path = Path(wast_path).with_suffix('.json')
        if not json_path.exists():
            subprocess.check_call(['wast2json', wast_path])

        generate_test_files(json_path)


if __name__ == "__main__":
    if len(sys.argv) > 1:
        paths = sys.argv[1:]
    else:
        paths = glob.glob('*.wast')
    gen(paths)
