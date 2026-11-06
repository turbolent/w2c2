import os
from pathlib import Path
import shlex
import subprocess
import sys
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[1]


class TrapHarnessTests(unittest.TestCase):
    def test_missing_and_wrong_traps_fail_the_runner(self):
        with tempfile.TemporaryDirectory(prefix='w2c2-trap-harness-') as directory:
            directory = Path(directory)
            source = directory / 'harness.c'
            source.write_text('''#include "test.h"
static U32 evaluations;
void test(void) {
    assertTrap((++evaluations, trap(trapMemoryOutOfBounds)),
        trapMemoryOutOfBounds, "correct trap");
    assertTrap(++evaluations, trapMemoryOutOfBounds, "missing trap");
    assertTrap((++evaluations, trap(trapUnreachable)),
        trapMemoryOutOfBounds, "wrong trap");
    assertEqualU32(evaluations, 3, "evaluated once");
    assertTrap(trap(trapDivByZero), trapDivByZero, "recovered after failure");
}
''')
            binary = directory / ('harness.exe' if os.name == 'nt' else 'harness')
            command = shlex.split(os.environ.get('CC', 'cc'))
            command += shlex.split(os.environ.get('CFLAGS', '-O2'))
            command += ['-DW2C2_RUNTIME_CHECKS=1', '-I' + str(ROOT / 'w2c2'),
                        '-I' + str(ROOT / 'tests'), str(source), str(ROOT / 'tests/main.c')]
            command += shlex.split(os.environ.get('LDFLAGS', ''))
            command += ['-o', str(binary)]
            subprocess.run(command, check=True, capture_output=True)
            command = [sys.executable, str(ROOT / 'tests/run.py')]
            if os.environ.get('EXECUTE'):
                command += ['--execute', os.environ['EXECUTE']]
            result = subprocess.run(command + [str(binary)], capture_output=True, text=True)
            self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
            self.assertIn('OK: correct trap', result.stdout)
            self.assertIn('FAIL: missing trap', result.stdout)
            self.assertIn('FAIL: wrong trap: expected trap out of bounds memory access, got unreachable',
                          result.stdout)
            self.assertIn('OK: evaluated once', result.stdout)
            self.assertIn('OK: recovered after failure', result.stdout)
            self.assertEqual(result.stdout.count('FAIL: '), 2)


if __name__ == '__main__':
    unittest.main()
