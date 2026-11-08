import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys


HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
LANGUAGES = ("c", "rust", "assemblyscript")


def cmake_path(path):
    value = path.as_posix().replace('"', '\\"').replace("$", "\\$")
    return '"' + value.replace(";", "\\;") + '"'


def write_if_changed(path, text):
    if not path.is_file() or path.read_text() != text:
        path.write_text(text)


def main():
    parser = argparse.ArgumentParser(
        description="Run the official WASI P1 tests with w2c2"
    )
    parser.add_argument("--suite", required=True, type=Path)
    parser.add_argument("--w2c2", required=True, type=Path)
    parser.add_argument("--build", type=Path, default=ROOT / "build/wasi-testsuite")
    parser.add_argument("--config", default="Debug", choices=("Debug", "Release"))
    parser.add_argument("--jobs", type=int, default=4)
    options = parser.parse_args()
    suite = options.suite.resolve()
    build = options.build.resolve()
    translator = options.w2c2.resolve()
    if options.jobs < 1:
        parser.error("--jobs must be positive")
    if not translator.is_file():
        parser.error(f"missing w2c2 executable: {translator}")
    suites = [
        suite / "tests" / language / "testsuite/wasm32-wasip1"
        for language in LANGUAGES
    ]
    for directory in suites:
        if not (directory / "manifest.json").is_file() or not any(directory.glob("*.wasm")):
            parser.error(f"missing precompiled suite: {directory}")
    cases = [
        (language, path)
        for language, directory in zip(LANGUAGES, suites)
        for path in sorted(directory.glob("*.wasm"))
    ]
    build.mkdir(parents=True, exist_ok=True)
    translator_hash = hashlib.sha256(translator.read_bytes()).hexdigest()

    def translate(case):
        language, path = case
        name = language + "-" + path.stem
        directory = build / "generated" / name
        directory.mkdir(parents=True, exist_ok=True)
        fingerprint = translator_hash + hashlib.sha256(path.read_bytes()).hexdigest()
        stamp = directory / "translation.sha256"
        if (stamp.is_file() and stamp.read_text() == fingerprint
                and (directory / "module.c").is_file()
                and (directory / "module.h").is_file()):
            return name, path, directory
        module = directory / "module.wasm"
        shutil.copyfile(path, module)
        with (directory / "translate.log").open("w") as log:
            result = subprocess.run(
                [str(translator), str(module), str(directory / "module.c")],
                stdout=log, stderr=subprocess.STDOUT,
            )
        if result.returncode:
            raise RuntimeError(
                f"translation failed: {path}; see {directory / 'translate.log'}"
            )
        stamp.write_text(fingerprint)
        return name, path, directory

    with ThreadPoolExecutor(max_workers=options.jobs) as executor:
        translated = list(executor.map(translate, cases))
    cmake = []
    for name, path, directory in translated:
        cmake += [
            f"add_executable({name}",
            f"  {cmake_path(HERE / 'main.c')}",
            f"  {cmake_path(directory / 'module.c')})",
            f"target_include_directories({name} PRIVATE",
            f"  {cmake_path(directory)}",
            f"  {cmake_path(ROOT / 'w2c2')}",
            f"  {cmake_path(ROOT / 'wasi')})",
            f"target_link_libraries({name} PRIVATE w2c2wasi)",
            "if(NOT WIN32)",
            f"  target_link_libraries({name} PRIVATE m)",
            "endif()",
            f"set_target_properties({name} PROPERTIES",
            f"  RUNTIME_OUTPUT_DIRECTORY {cmake_path(build / 'bin')})",
        ]
    write_if_changed(build / "cases.cmake", "\n".join(cmake) + "\n")
    subprocess.run([
        "cmake", "-S", str(HERE), "-B", str(build),
        f"-DCMAKE_BUILD_TYPE={options.config}",
    ], check=True)
    subprocess.run([
        "cmake", "--build", str(build), "--config", options.config,
        "--parallel", str(options.jobs),
    ], check=True)
    executables = {}
    for name, path, directory in translated:
        filename = name + (".exe" if os.name == "nt" else "")
        candidates = [build / "bin" / options.config / filename, build / "bin" / filename]
        executables[str(path)] = str(next(p for p in candidates if p.is_file()))
    version = subprocess.check_output([
        "git", "-C", str(ROOT), "describe", "--always", "--dirty",
    ], text=True).strip()
    manifest = build / "executables.json"
    manifest.write_text(json.dumps({
        "version": version, "executables": executables,
    }, indent=2) + "\n")
    environment = dict(os.environ, W2C2_WASI_TEST_MANIFEST=str(manifest))
    command = [
        sys.executable, str(suite / "test-runner/wasi_test_runner.py"),
        "--runtime-adapter", str(HERE / "adapter.py"),
        "--json-output-location", str(build / "results.json"),
        "--disable-colors", "--test-suite",
    ] + [str(path) for path in suites]
    return subprocess.call(command, env=environment)


if __name__ == "__main__":
    sys.exit(main())
