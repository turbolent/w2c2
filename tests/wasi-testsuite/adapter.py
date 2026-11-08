import json
import os
from pathlib import Path


def configuration():
    return json.loads(Path(os.environ["W2C2_WASI_TEST_MANIFEST"]).read_text())


def get_name():
    return "w2c2"


def get_version():
    return configuration()["version"]


def get_wasi_versions():
    return ["wasm32-wasip1"]


def get_wasi_worlds():
    return ["wasi:cli/command"]


def compute_argv(test_path, args_env_root, proposals, wasi_world, wasi_version):
    args, environment, root = args_env_root
    executable = configuration()["executables"][str(Path(test_path).resolve())]
    command = [executable]
    if root is not None:
        command += ["--root", str(Path(root).resolve())]
    if os.name == "nt":
        command += ["--env", "NO_RENAME_DIR_TO_EMPTY_DIR=1"]
    for key, value in environment.items():
        command += ["--env", f"{key}={value}"]
    return command + ["--", str(test_path)] + args
