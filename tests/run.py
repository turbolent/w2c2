import argparse
import subprocess
import os
import difflib
import sys
import shlex

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('test')
    parser.add_argument('-a', '--arch')
    parser.add_argument('-e', '--execute')
    args = parser.parse_args()

    command = []

    if args.execute:
        command.extend(shlex.split(args.execute))
    command.append(os.path.abspath(args.test))

    output = subprocess.run(command, check=True, stderr=subprocess.PIPE).stderr.decode('utf-8').strip()

    print(output)

    if args.arch:
        path = args.test + '.' + args.arch + '.out'
        if os.path.isfile(path):
            expected = ''
            with open(path, 'r') as f:
                expected = f.read()
            diff = list(difflib.unified_diff(
                expected.splitlines(keepends=True),
                output.splitlines(keepends=True),
                fromfile='expected',
                tofile='actual'
            ))
            if diff:
                print()
                sys.stdout.writelines(diff)
                exit(1)
            return

    if 'FAIL: ' in output:
        exit(1)

if __name__ == "__main__":
    main()
