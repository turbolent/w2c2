import json
import glob
import re

import math
import struct
import subprocess
import sys
import textwrap
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
    return {'i32': 'U32', 'i64': 'U64', 'f32': 'F32', 'f64': 'F64', 'v128': 'V128'}[t]


def bits(value, width):
    if value in ('nan:canonical', 'nan:arithmetic'):
        return 0x7fc00000 if width == 32 else 0x7ff8000000000000
    return int(value) & ((1 << width) - 1)


def mask_for(value, width):
    if value == 'nan:canonical':
        return (1 << (width - 1)) - 1
    if value == 'nan:arithmetic':
        return 0x7fc00000 if width == 32 else 0x7ff8000000000000
    return (1 << width) - 1


def vector_bytes(value, mask=False):
    width = int(value['lane_type'][1:])
    convert = mask_for if mask else bits
    return b''.join(convert(v, width).to_bytes(width // 8, 'little') for v in value['value'])


def convert_value(value, t):
    if t in ('U32', 'U64'):
        return str(bits(value, int(t[1:]))) + ('u' if t == 'U32' else 'ull')
    if t in ('F32', 'F64'):
        width = int(t[1:])
        return 'f{0}_reinterpret_i{0}(0x{1:0{2}x}{3})'.format(
            width, bits(value, width), width // 4, 'u' if width == 32 else 'ull')
    raise ValueError('Unsupported scalar type: ' + t)


def argument(value):
    if value['type'] == 'v128':
        return 'w2c2_v128_const(' + ', '.join(str(b if b < 128 else b - 256) for b in vector_bytes(value)) + ')'
    return convert_value(value['value'], convert_type(value['type']))


def argument_description(value):
    # Preserve the text in existing architecture-specific expected output.
    if value['type'] in ('f32', 'f64'):
        width = int(value['type'][1:])
        number, = struct.unpack('<f' if width == 32 else '<d',
                                bits(value['value'], width).to_bytes(width // 8, 'little'))
        if math.isinf(number):
            return '-INFINITY' if number < 0 else 'INFINITY'
        if not math.isnan(number):
            return str(number)
    return argument(value)


def c_string(value):
    return '"' + ''.join(chr(b) if 32 <= b < 127 and b not in (34, 92)
                         else '\\{:03o}'.format(b) for b in value.encode('utf-8')) + '"'


def assertion(call, expected, description):
    if expected['type'] == 'v128':
        return ('    {\n        static const U8 expected[16] = {'
                + ', '.join(map(str, vector_bytes(expected))) + '};\n'
                + '        static const U8 masks[16] = {'
                + ', '.join(map(str, vector_bytes(expected, mask=True))) + '};\n'
                + '        assertEqualV128(' + call + ', expected, masks, ' + c_string(description) + ');\n    }\n')
    value_type = convert_type(expected['type'])
    value = expected['value']
    if value_type in ('F32', 'F64'):
        width = int(value_type[1:])
        value_type = 'U' + str(width)
        call = 'i{0}_reinterpret_f{0}({1})'.format(width, call)
        if value in ('nan:canonical', 'nan:arithmetic'):
            call = '({} & {})'.format(call, convert_value(str(mask_for(value, width)), value_type))
            value = str(bits(value, width))
    return '    assertEqual{}(\n        {},\n        {},\n        {}\n    );\n'.format(
        value_type, call, convert_value(value, value_type), c_string(description))


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


def generate_test_files(json_path, combined=False, output_dir=None):
    """Generate assertions using the shared test.h/main.c harness.

    The checked-in core fixtures retain their per-module layout and output. Combined output
    preserves script order and instance state for registrations and named actions.
    Both layouts use the same command and assertion generation.
    """
    json_path = Path(json_path)
    output_dir = Path(output_dir) if output_dir is not None else gen_dir
    commands = json.loads(json_path.read_text())['commands']
    tests = []
    named = {}
    current = None

    def new_test(name):
        test = {'path': output_dir / ('assert_' + name + '.c'),
                'modules': [], 'declarations': [], 'body': [], 'count': 0}
        tests.append(test)
        return test

    combined_test = new_test(json_path.stem) if combined else None
    for command in commands:
        kind = command['type']
        if kind == 'module':
            filename = command['filename']
            name = Path(filename).stem
            test = combined_test if combined else new_test(name)
            instance = 'instance_' + str(len(test['modules'])) if combined else 'instance'
            current = (name, instance, test)
            if 'name' in command:
                named[command['name']] = current
            test['modules'].append(filename)
            # Static storage preserves instance state across setjmp/longjmp.
            test['declarations'].append('    static {}Instance {};\n'.format(module_identifier(name), instance))
            test['body'].append('    {}Instantiate(&{}, resolveTestImports);\n'.format(module_identifier(name), instance))
            test['body'].append('    printStart({});\n'.format(c_string(filename)))
        elif kind == 'register':
            name, instance, test = named[command['name']] if 'name' in command else current
            for field in object_exports(json_path.parent / (name + '.wasm')):
                test['body'].append('    bindTestImport({}, {}, (void*){}(&{}));\n'.format(
                    c_string(command['as']), c_string(field), export_name(name, field), instance))
        elif kind in ('assert_return', 'assert_trap', 'action'):
            # Legacy per-module builds do not enable runtime bounds checks.
            # Whole-script runs enable them and exercise the trap assertions.
            if kind == 'assert_trap' and not combined:
                continue
            action = command.get('action')
            # Module-instantiation assertions are outside this harness.
            if action is None:
                continue
            selected = named[action['module']] if 'module' in action else current
            if selected is None:
                raise ValueError('Action before any module')
            name, instance, test = selected
            args = [argument(arg) for arg in action.get('args', [])]
            call = '{}({})'.format(export_name(name, action['field']), ', '.join(['&' + instance] + args))
            descriptions = args if combined else [argument_description(arg) for arg in action.get('args', [])]
            description = '{}({})'.format(action['field'], ', '.join(descriptions))
            if action['type'] == 'get':
                call = '*' + call
                description = 'get ' + action['field']
            elif action['type'] != 'invoke':
                raise ValueError('Unsupported action: ' + action['type'])
            if combined:
                description = 'WAST line {}: {}'.format(command.get('line', 0), description)
            if kind == 'assert_trap':
                test['body'].append('    assertTrap({}, {});\n'.format(call, c_string(description)))
            elif kind == 'assert_return' and command['expected']:
                expected = command['expected']
                if len(expected) == 1:
                    test['body'].append(assertion(call, expected[0], description))
                else:
                    codes = {'i32': 'i', 'i64': 'j', 'f32': 'f', 'f64': 'd', 'v128': 'v'}
                    result_type = 'w2c2_result_' + ''.join(codes[value['type']] for value in expected)
                    test['body'].append('    {{\n        struct {} result;\n        result = {};\n'.format(result_type, call))
                    for index, value in enumerate(expected):
                        field = assertion('result.v{}'.format(index), value,
                                          '{} result {}'.format(description, index))
                        test['body'].append(textwrap.indent(field, '    '))
                    test['body'].append('    }\n')
            else:
                test['body'].append('    (void)({});\n'.format(call))
                if combined or kind == 'action':
                    test['body'].append('    printOK({});\n'.format(c_string(description)))
            test['count'] += 1
        elif kind not in ('assert_invalid', 'assert_malformed', 'assert_unlinkable',
                          'assert_uninstantiable', 'assert_exhaustion'):
            raise ValueError('Unsupported command: ' + kind)

    for test in tests:
        includes = ''.join('#include "test_{}"\n'.format(Path(filename).with_suffix('.h').name)
                           for filename in test['modules'])
        cleanup = ''.join('    {}FreeInstance(&{});\n'.format(
            module_identifier(Path(filename).stem), 'instance_' + str(i) if combined else 'instance')
            for i, filename in reversed(list(enumerate(test['modules']))))
        source = ('#include "test.h"\n' + includes + '\nvoid test(void) {\n'
                  + ''.join(test['declarations']) + ''.join(test['body']) + cleanup + '}\n')
        with test['path'].open('w', newline='\n') as output:
            output.write(source)
    return tests


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
