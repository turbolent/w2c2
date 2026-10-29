"""SIMD decoder, generated-code, and malformed-immediate regression tests."""
import os
from pathlib import Path
import shlex
import subprocess
import tempfile
import unittest
from types import SimpleNamespace
from unittest.mock import patch

import gen
from run import run_wast, simde_cflags

ROOT = Path(__file__).resolve().parents[1]
W2C2 = Path(os.environ.get('W2C2', ROOT / 'w2c2/w2c2')).resolve()
SIMD_CFLAGS = shlex.split(os.environ.get('SIMD_CFLAGS', '-O2 -Werror=conversion -Werror=float-conversion'))
TYPES = {'I32': 0x7f, 'I64': 0x7e, 'F32': 0x7d, 'F64': 0x7c, 'V128': 0x7b}


def leb(value):
    result = bytearray()
    while value >= 128:
        result.append((value & 127) | 128)
        value >>= 7
    result.append(value)
    return bytes(result)


def section(kind, data):
    return bytes([kind]) + leb(len(data)) + data


def module(functions, memory=True):
    types = leb(len(functions))
    bodies = leb(len(functions))
    for params, result, code in functions:
        types += b'\x60' + leb(len(params)) + bytes(params)
        types += b'\x00' if result is None else b'\x01' + bytes([result])
        body = b'\x00' + code + b'\x0b'
        bodies += leb(len(body)) + body
    return (b'\x00asm\x01\x00\x00\x00' + section(1, types)
            + section(3, leb(len(functions)) + b''.join(leb(i) for i in range(len(functions))))
            + (section(5, b'\x01\x00\x01') if memory else b'') + section(10, bodies))


class SIMDTests(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory(prefix='w2c2-simd-unit-')
        self.addCleanup(self.directory.cleanup)
        self.path = Path(self.directory.name)

    def translate(self, data, succeeds=True, flags=()):
        source = self.path / 'module.wasm'
        output = self.path / 'module.c'
        source.write_bytes(data)
        result = subprocess.run([str(W2C2), *flags, source.as_posix(), output.as_posix()], capture_output=True)
        self.assertEqual(result.returncode == 0, succeeds, result.stderr.decode())
        return output

    def test_every_fixed_width_opcode_compiles(self):
        functions = []
        opcodes = []
        for row in (ROOT / 'w2c2/simd_opcodes.def').read_text().splitlines():
            if not row.startswith('SIMD('):
                continue
            fields = row[5:-1].split(', ')
            opcode = int(fields[0], 16)
            opcodes.append(opcode)
            result = fields[2].removeprefix('wasmValueType')
            count = int(fields[3])
            params = [TYPES[t.removeprefix('wasmValueType')] for t in fields[4:4 + count]]
            width, immediate, lanes = map(int, fields[7:10])
            code = b''.join(b'\x20' + leb(i) for i in range(count)) + b'\xfd' + leb(opcode)
            if width:
                code += b'\x00\x00'
            if opcode == 12:
                code += bytes(range(0x80, 0x90))
            elif opcode == 13:
                code += bytes(range(16, 32))
            elif immediate:
                code += bytes([lanes - 1])
            functions.append((params, None if result == '_count' else TYPES[result], code))
        self.assertEqual(len(functions), 236)
        self.assertEqual(opcodes, sorted(set(opcodes)))
        output = self.translate(module(functions), flags=('-f', '17', '-t', '2'))
        for source in self.path.glob('*.c'):
            result = subprocess.run(shlex.split(os.environ.get('CC', 'cc')) + [
                '-std=c99', *SIMD_CFLAGS, *simde_cflags(), '-I' + (ROOT / 'w2c2').as_posix(),
                '-c', source.as_posix(), '-o', source.with_suffix('.o').as_posix()], capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr.decode())
        self.assertTrue(output.exists())

    def test_vector_headers_support_cpp(self):
        output = self.translate(module([([TYPES['V128']], TYPES['V128'], b'\x20\x00')]))
        self.assertIn('w2c2_simd.h', output.with_suffix('.h').read_text())
        result = subprocess.run(shlex.split(os.environ.get('CXX', 'c++')) + [
            '-x', 'c++', '-std=c++11', *SIMD_CFLAGS, *simde_cflags(), '-I' + (ROOT / 'w2c2').as_posix(),
            '-c', output.as_posix(), '-o', output.with_suffix('.o').as_posix()], capture_output=True)
        self.assertEqual(result.returncode, 0, result.stderr.decode())

    def test_simd_requires_header_configuration(self):
        output = self.translate(module([([], TYPES['V128'], b'\xfd\x0c' + bytes(16))]))
        result = subprocess.run(shlex.split(os.environ.get('CC', 'cc')) + [
            '-std=c99', *SIMD_CFLAGS, '-UW2C2_SIMDE_HEADER', '-I' + (ROOT / 'w2c2').as_posix(),
            '-c', output.as_posix(), '-o', output.with_suffix('.o').as_posix()], capture_output=True)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn(b'SIMD output requires SIMDe. Define W2C2_SIMDE_HEADER', result.stderr)

    def test_scalar_immediates_do_not_include_simd(self):
        output = self.translate(module([([], TYPES['I32'], b'\x41\xfd\x01')], memory=False))
        self.assertNotIn('simd', output.read_text().lower())
        self.assertNotIn('simd', output.with_suffix('.h').read_text().lower())
        (self.path / 'w2c2_base.h').write_bytes((ROOT / 'w2c2/w2c2_base.h').read_bytes())
        result = subprocess.run(shlex.split(os.environ.get('CC', 'cc')) + [
            '-std=c89', *SIMD_CFLAGS, '-I' + self.path.as_posix(),
            '-c', output.as_posix(), '-o', output.with_suffix('.o').as_posix()], capture_output=True)
        self.assertEqual(result.returncode, 0, result.stderr.decode())

    def test_invalid_immediates_are_rejected(self):
        cases = {
            'unknown': b'\xfd' + leb(0xfff),
            'relaxed': b'\xfd' + leb(0x100),
            'truncated opcode': b'\xfd\x80',
            'truncated const': b'\xfd\x0c' + bytes(14),
            'truncated shuffle': b'\xfd\x0d' + bytes(14),
            'shuffle lane': b'\xfd\x0d' + bytes([32]) + bytes(15),
            'extract lane': b'\xfd\x15\x10',
            'load lane': b'\xfd\x54\x00\x00\x10',
            'over-aligned load': b'\xfd\x00\x05\x00',
            'over-aligned lane': b'\xfd\x55\x02\x00\x00',
        }
        for name, code in cases.items():
            for unreachable in (False, True):
                with self.subTest(case=name, unreachable=unreachable):
                    self.translate(module([([], None, (b'\x00' if unreachable else b'') + code)]), succeeds=False)

    def test_shared_scalar_harness_without_simde(self):
        script = '''
(module $owner
  (global (export "value") (mut i32) (i32.const 7)))
(module (func (export "unused")))
(register "state" $owner)
(module
  (import "state" "value" (global $value (mut i32)))
  (func (export "set") (global.set $value (i32.const 42)))
  (func (export "trap") unreachable))
(assert_return (invoke "set"))
(assert_return (get $owner "value") (i32.const 42))
(assert_trap (invoke "trap") "unreachable")
'''
        source = self.path / 'shared.wast'
        args = SimpleNamespace(w2c2=W2C2, cc=os.environ.get('CC', 'cc'),
                               cflags=os.environ.get('SIMD_CFLAGS', '-O2') + ' -std=c89')
        for contents, succeeds in [(script, True),
                                   (script.replace('(i32.const 42))\n(assert_trap', '(i32.const 99))\n(assert_trap'), False),
                                   (script.replace('(export "trap") unreachable', '(export "trap") nop'), False)]:
            with self.subTest(succeeds=succeeds), patch.dict(os.environ, {'SIMDE_HEADER': ''}):
                source.write_text(contents)
                if succeeds:
                    self.assertEqual(run_wast(source, args), 3)
                else:
                    with self.assertRaises(subprocess.CalledProcessError) as error:
                        run_wast(source, args)
                    self.assertIn(b'FAIL: WAST line', error.exception.stderr)

    def test_invalid_global_export_is_rejected(self):
        self.translate(b'\x00asm\x01\x00\x00\x00' + section(7, b'\x01\x01g\x03\x00'), succeeds=False)

    def test_memory_is_required_even_when_unreachable(self):
        self.translate(module([([], None, b'\x00\xfd\x00\x00\x00')], memory=False), succeeds=False)

    def test_vector_assertions_check_bits_and_nan_classes(self):
        def vector(lanes, lane_type='f32'):
            return {'type': 'v128', 'lane_type': lane_type, 'value': lanes}

        cases = [
            (vector(list(range(16)), 'i8'), vector(list(range(16)), 'i8'), True),
            (vector(list(range(15)) + [99], 'i8'), vector(list(range(16)), 'i8'), False),
            (vector([0xffc00000] * 4), vector(['nan:canonical'] * 4), True),
            (vector([0x7fc00001] * 4), vector(['nan:canonical'] * 4), False),
            (vector([0xffc00001] * 4), vector(['nan:arithmetic'] * 4), True),
            (vector([0x7f800001] * 4), vector(['nan:arithmetic'] * 4), False),
            (vector([0x80000000] * 4), vector([0] * 4), False),
        ]
        source = self.path / 'assertion.c'
        binary = self.path / ('assertion.exe' if os.name == 'nt' else 'assertion')
        for actual, expected, succeeds in cases:
            with self.subTest(actual=actual, expected=expected):
                source.write_text('#include \"test.h\"\nvoid test(void) {\n'
                                  + gen.assertion(gen.argument(actual), expected, 'WAST line 123')
                                  + '}\n')
                command = shlex.split(os.environ.get('CC', 'cc')) + [
                    '-std=c99', *SIMD_CFLAGS, *simde_cflags(), '-I' + (ROOT / 'w2c2').as_posix(),
                    '-I' + (ROOT / 'tests').as_posix(),
                    source.as_posix(), (ROOT / 'tests/main.c').as_posix(), '-o', binary.as_posix()]
                if os.name != 'nt':
                    command.append('-lm')
                subprocess.run(command, check=True, capture_output=True)
                result = subprocess.run([str(binary)], capture_output=True)
                self.assertEqual(result.returncode, 0, result.stderr.decode())
                self.assertEqual(b'FAIL: ' not in result.stderr, succeeds, result.stderr.decode())
                if not succeeds:
                    self.assertIn(b'WAST line 123', result.stderr)


if __name__ == '__main__':
    unittest.main()
