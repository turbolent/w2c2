"""SIMD decoder, generated-code, and malformed-immediate regression tests."""
import os
from pathlib import Path
import shlex
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
W2C2 = Path(os.environ.get('W2C2', ROOT / 'w2c2/w2c2')).resolve()
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
        result = subprocess.run([str(W2C2), *flags, str(source), str(output)], capture_output=True)
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
                '-std=c89', '-O2', '-Werror=conversion', '-I' + str(ROOT / 'w2c2'),
                '-c', str(source), '-o', str(source.with_suffix('.o'))], capture_output=True)
            self.assertEqual(result.returncode, 0, result.stderr.decode())
        self.assertTrue(output.exists())

    def test_vector_headers_support_cpp(self):
        output = self.translate(module([([TYPES['V128']], TYPES['V128'], b'\x20\x00')]))
        result = subprocess.run(shlex.split(os.environ.get('CXX', 'c++')) + [
            '-x', 'c++', '-std=c++11', '-Werror=conversion', '-I' + str(ROOT / 'w2c2'),
            '-c', str(output), '-o', str(output.with_suffix('.o'))], capture_output=True)
        self.assertEqual(result.returncode, 0, result.stderr.decode())

    def test_scalar_immediates_do_not_include_simd(self):
        output = self.translate(module([([], TYPES['I32'], b'\x41\xfd\x01')], memory=False))
        self.assertNotIn('simd', output.read_text().lower())
        self.assertNotIn('simd', output.with_suffix('.h').read_text().lower())

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

    def test_invalid_global_export_is_rejected(self):
        self.translate(b'\x00asm\x01\x00\x00\x00' + section(7, b'\x01\x01g\x03\x00'), succeeds=False)

    def test_memory_is_required_even_when_unreachable(self):
        self.translate(module([([], None, b'\x00\xfd\x00\x00\x00')], memory=False), succeeds=False)


if __name__ == '__main__':
    unittest.main()
