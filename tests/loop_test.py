"""Verify optimized C++ preserves terminating and nonterminating Wasm loops."""
import os
from pathlib import Path
import queue
import shlex
import subprocess
import tempfile
import threading
import unittest


ROOT = Path(__file__).resolve().parents[1]
W2C2 = Path(os.environ.get('W2C2', ROOT / 'w2c2/w2c2')).resolve()

DRIVER = '''#include <stdio.h>
#include "loops.h"

void trap(Trap reason) {
    fprintf(stderr, "unexpected trap: %s\\n", trapDescription(reason));
    abort();
}

int main(int argc, char** argv) {
    m5_loopsInstance instance;
    U32 index;
    U32 result;
    if (argc != 2) return 2;
    m5_loopsInstantiate(&instance, NULL);
    if (strcmp(argv[1], "finite") == 0) {
        if (m5_loopsExport11_conditional(&instance, 1) != 42) return 1;
        if (m5_loopsExport6_caller(&instance, 1) != 43) return 1;
        for (index = 0; index < 1024; index++) i32_store(instance.m0, index * 4, index);
        if (m5_loopsExport3_sum(&instance) != 523776) return 1;
        m5_loopsFreeInstance(&instance);
        return 0;
    }
    puts("ready");
    fflush(stdout);
    if (strcmp(argv[1], "spin") == 0) {
        result = m5_loopsExport4_spin(&instance);
    } else if (strcmp(argv[1], "conditional") == 0) {
        result = m5_loopsExport11_conditional(&instance, 0);
    } else if (strcmp(argv[1], "caller") == 0) {
        result = m5_loopsExport6_caller(&instance, 0);
    } else {
        return 2;
    }
    fprintf(stderr, "nonterminating call returned %u\\n", result);
    return 1;
}
'''


class LoopTests(unittest.TestCase):
    def assert_nonterminating(self, binary, function):
        with subprocess.Popen([str(binary), function], stdout=subprocess.PIPE,
                              stderr=subprocess.STDOUT, text=True) as process:
            ready = queue.Queue()
            reader = threading.Thread(target=lambda: ready.put(process.stdout.readline()), daemon=True)
            reader.start()
            try:
                # Start the observation interval after startup and instantiation,
                # so a slow process launch cannot masquerade as an infinite loop.
                try:
                    self.assertEqual(ready.get(timeout=10), 'ready\n')
                except queue.Empty:
                    self.fail('executable did not reach the loop')
                try:
                    process.wait(timeout=0.25)
                except subprocess.TimeoutExpired:
                    pass
                else:
                    self.fail(f'{function} exited with {process.returncode}: {process.stdout.read()}')
            finally:
                if process.poll() is None:
                    process.kill()
                process.wait(timeout=5)
                reader.join(timeout=5)

    def test_optimized_loop_semantics(self):
        with tempfile.TemporaryDirectory(prefix='w2c2-loops-') as directory:
            directory = Path(directory)
            wasm = directory / 'loops.wasm'
            generated = directory / 'loops.c'
            driver = directory / 'main.c'
            driver.write_text(DRIVER)
            commands = [
                ['wat2wasm', str(ROOT / 'tests/loop_test.wat'), '-o', str(wasm)],
                [str(W2C2), str(wasm), str(generated)],
            ]
            for command in commands:
                result = subprocess.run(command, capture_output=True, text=True)
                self.assertEqual(result.returncode, 0, result.stderr)
            compiler = shlex.split(os.environ.get('CXX', 'c++'))
            flags = shlex.split(os.environ.get('CXXFLAGS', ''))
            for opt_in in (False, True):
                with self.subTest(opt_in=opt_in):
                    binary = directory / ('loops.exe' if os.name == 'nt' else 'loops')
                    command = compiler + flags + ['-x', 'c++', '-std=c++11', '-O3', '-Werror',
                                                   '-I' + str(ROOT / 'w2c2')]
                    if opt_in:
                        command += ['-fno-finite-loops', '-DW2C2_LOOP_START=']
                    command += [str(driver), str(generated), '-o', str(binary)]
                    result = subprocess.run(command, capture_output=True, text=True)
                    self.assertEqual(result.returncode, 0, result.stderr)
                    result = subprocess.run([str(binary), 'finite'], capture_output=True,
                                            text=True, timeout=10)
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    for function in ('spin', 'conditional', 'caller'):
                        with self.subTest(function=function):
                            self.assert_nonterminating(binary, function)


if __name__ == '__main__':
    unittest.main()
