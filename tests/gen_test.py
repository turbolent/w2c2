import contextlib
import io
import json
import re
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import gen


class NaNTests(unittest.TestCase):
    def generate(self, value_type, expected, args=None):
        with tempfile.TemporaryDirectory() as directory:
            directory = Path(directory)
            source = directory / 'nan.json'
            source.write_text(json.dumps({'commands': [
                {'type': 'module', 'filename': 'nan.0.wasm'},
                {'type': 'assert_return',
                 'action': {'type': 'invoke', 'field': 'result', 'args': args or []},
                 'expected': [{'type': value_type, 'value': expected}]},
            ]}))
            with patch.object(gen, 'gen_dir', directory), contextlib.redirect_stdout(io.StringIO()):
                gen.generate_test_files(source)
            return (directory / 'assert_nan.0.c').read_text()

    def test_nan_argument_bits(self):
        for width, payloads in [
            (32, [0x7fc00000, 0x7fc01234, 0x7f800001]),
            (64, [0x7ff8000000000000, 0x7ff8000012345678, 0x7ff0000000800000, 0x7ff0000000000001]),
        ]:
            for bits in payloads:
                for sign in [0, 1 << (width - 1)]:
                    value = bits | sign
                    suffix = 'u' if width == 32 else 'ull'
                    expression = 'f{0}_reinterpret_i{0}(0x{1:0{2}x}{3})'.format(width, value, width // 4, suffix)
                    with self.subTest(width=width, bits=hex(value)):
                        self.assertEqual(gen.convert_value(str(value), 'F' + str(width)), expression)
                        output = self.generate('i32', '1', [{'type': 'f' + str(width), 'value': str(value)}])
                        self.assertIn('(&instance, ' + expression + ')', output)
                        self.assertEqual(output.count('assertEqualU32('), 1)

    def test_nan_result_masks(self):
        for width, canonical, infinity in [
            (32, 0x7fc00000, 0x7f800000),
            (64, 0x7ff8000000000000, 0x7ff0000000000000),
        ]:
            for pattern in ['canonical', 'arithmetic']:
                output = self.generate('f' + str(width), 'nan:' + pattern)
                match = re.search(r' & (\d+)u(?:ll)?\),\s*(\d+)u(?:ll)?,', output)
                self.assertIsNotNone(match)
                mask, expected = map(int, match.groups())
                for bits, accepted in [
                    (canonical, True),
                    (canonical | 1, pattern == 'arithmetic'),
                    (infinity | 1, False),
                    (infinity, False),
                    (infinity - 1, False),
                    (0, False),
                ]:
                    for sign in [0, 1 << (width - 1)]:
                        with self.subTest(width=width, pattern=pattern, bits=hex(bits | sign)):
                            self.assertEqual(((bits | sign) & mask) == expected, accepted)

    def test_exact_float_result_bits(self):
        for width, values in [
            (32, [0, 0x80000000, 1, 0xffc01234, 0x7f800001]),
            (64, [0, 0x8000000000000000, 1, 0xfff8000012345678, 0x7ff0000000000001]),
        ]:
            for bits in values:
                with self.subTest(width=width, bits=hex(bits)):
                    output = self.generate('f' + str(width), str(bits))
                    self.assertIn('assertEqualU{}('.format(width), output)
                    self.assertIn('i{0}_reinterpret_f{0}('.format(width), output)
                    self.assertIn('\n        {}{},'.format(bits, 'u' if width == 32 else 'ull'), output)
                    self.assertNotIn(' & ', output)


class GlobalTests(unittest.TestCase):
    def generate(self, commands):
        with tempfile.TemporaryDirectory() as directory:
            directory = Path(directory)
            source = directory / 'global.json'
            source.write_text(json.dumps({'commands': commands}))
            with patch.object(gen, 'gen_dir', directory), contextlib.redirect_stdout(io.StringIO()):
                gen.generate_test_files(source)
            return {p.name: p.read_text() for p in directory.glob('assert_*.c')}

    def test_get_all_scalar_types(self):
        for value_type, value, assertion in [
            ('i32', '4294967295', 'assertEqualU32'),
            ('i64', '18446744073709551615', 'assertEqualU64'),
            ('f32', '2147483648', 'assertEqualU32'),
            ('f64', '9223372036854775808', 'assertEqualU64'),
        ]:
            with self.subTest(value_type=value_type):
                files = self.generate([
                    {'type': 'module', 'filename': 'global.0.wasm'},
                    {'type': 'assert_return', 'action': {'type': 'get', 'field': 'value'},
                     'expected': [{'type': value_type, 'value': value}]},
                ])
                output = files['assert_global.0.c']
                self.assertIn(assertion + '(', output)
                self.assertIn('*' + gen.export_name('global.0', 'value') + '(&instance)', output)
                if value_type.startswith('f'):
                    width = value_type[1:]
                    self.assertIn('i' + width + '_reinterpret_f' + width + '(*', output)

    def test_named_get_does_not_change_current_module(self):
        files = self.generate([
            {'type': 'module', 'filename': 'global.0.wasm', 'name': '$First'},
            {'type': 'module', 'filename': 'global.1.wasm', 'name': '$Second'},
            {'type': 'assert_return', 'action': {'type': 'get', 'module': '$First', 'field': 'first'},
             'expected': [{'type': 'i32', 'value': '42'}]},
            {'type': 'assert_return', 'action': {'type': 'get', 'field': 'second'},
             'expected': [{'type': 'i32', 'value': '43'}]},
        ])
        self.assertIn(gen.export_name('global.0', 'first'), files['assert_global.0.c'])
        self.assertNotIn('get second', files['assert_global.0.c'])
        self.assertIn(gen.export_name('global.1', 'second'), files['assert_global.1.c'])
        self.assertNotIn('get first', files['assert_global.1.c'])

    def test_unknown_named_module_is_not_silently_ignored(self):
        with self.assertRaises(KeyError):
            self.generate([
                {'type': 'module', 'filename': 'global.0.wasm'},
                {'type': 'assert_return', 'action': {'type': 'get', 'module': '$Missing', 'field': 'value'},
                 'expected': [{'type': 'i32', 'value': '42'}]},
            ])


if __name__ == '__main__':
    unittest.main()
