# w2c2

Translates WebAssembly modules to C.
Inspired by [wabt's wasm2c](https://github.com/WebAssembly/wabt/tree/main/wasm2c).

Working towards [WebAssembly as the Elusive Universal Binary](https://kripken.github.io/talks/2020/universal.html#/):

```
                                          ↗ different
  source code     →  WebAssembly  →  C89  → OSes,
(C++, Rust, ...)                          ↘ CPUs
```


## Features

- Implements the WebAssembly Core Specification 1.0, as well as
  - [Bulk memory operations](https://github.com/WebAssembly/bulk-memory-operations/blob/master/proposals/bulk-memory-operations/Overview.md)
  - [Sign-extension operators](https://github.com/WebAssembly/sign-extension-ops/blob/master/proposals/sign-extension-ops/Overview.md)
- Passes 99.9% of the WebAssembly core semantics test suite
- Written in C89 and generates C89
- Support for older operating systems and architectures
  (e.g. Mac OS X on PowerPC, Mac OS 9, Haiku, Rhapsody, OPENSTEP, Windows XP, etc.)
- Support for big-endian systems (e.g. PowerPC)
- Streaming/single-pass compilation, low memory usage
- Separate compilation into multiple files
- Parallel compilation
- Support for multiple modules and instances
- WASI implementation which is able to run clang and Python

## Performance

- Coremark 1.0: ~7% slower than native

## Compilation

If your system is supported by at least CMake 2.8.12, prefer using CMake to detect features.
On systems without CMake you can also use Make.

### w2c2

```sh
cd w2c2
cmake -B build
cmake --build build
```

### wasi

```sh
cd wasi
cmake -B build
cmake --build build
```

## Usage

For example, to compile `module.wasm` to `module.c` (and `module.h`):

```sh
./w2c2 module.wasm module.c
```

### Separate Compilation

w2c2 is able to compile a module into separate C files.
This is recommended when compiling large modules and on hosts with limited resources.

For example, to compile `module.wasm` (and `module.h`), into multiple files with 100 functions each:

```sh
./w2c2 -f 100 module.wasm module.c
```

### Parallel Compilation

When w2c2 was built with threading support, it is able to compile a module in parallel.
By default, w2c2 spawns as many worker threads as CPU cores are available.

To manually specify the number of worker threads, pass the number using the `-t` flag.

For example, to compile using 2 threads:

```sh
./w2c2 -t 2 module.wasm module.c
```

## Examples

Coremark:

```sh
cd examples/coremark
make
./coremark
```

## Testing

Requires Python 3 and [wabt](https://github.com/WebAssembly/wabt) (for `wast2json`).

```sh
cd tests
make gen
make run-tests
```

## WASI Status

- [x] args_get
- [x] args_sizes_get
- [x] clock_res_get
- [x] clock_time_get
- [x] environ_get
- [x] environ_sizes_get
- [ ] fd_advise
- [ ] fd_allocate
- [x] fd_close
- [ ] fd_datasync
- [x] fd_fdstat_get
- [ ] fd_fdstat_set_flags
- [ ] fd_fdstat_set_rights
- [x] fd_filestat_get
- [ ] fd_filestat_set_size
- [ ] fd_filestat_set_times
- [x] fd_pread
- [x] fd_prestat_get
- [x] fd_prestat_dir_name
- [ ] fd_pwrite
- [x] fd_read
- [x] fd_readdir
- [ ] fd_renumber
- [x] fd_seek
- [ ] fd_sync
- [x] fd_tell
- [x] fd_write
- [x] path_create_directory
- [x] path_filestat_get
- [ ] path_filestat_set_times
- [ ] path_link
- [x] path_open
- [x] path_readlink
- [x] path_remove_directory
- [x] path_rename
- [x] path_symlink
- [x] path_unlink_file
- [ ] poll_oneoff
- [x] proc_exit
- [x] random_get
- [ ] sched_yield
- [ ] sock_recv
- [ ] sock_send
- [ ] sock_shutdown

## Development

To build a debug release, pass `BUILD=debug` to `make`.

To enable sanitizers, list them in the `SANITIZERS` variable passed to `make`, e.g. `make BUILD=debug SANITIZERS="base clang address thread"`.
- `base` enables the [Undefined Behavior Sanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
- `clang` enables Clang-specific sanitizers
- `thread` enables the [Thread Sanitizer](https://clang.llvm.org/docs/ThreadSanitizer.html)
- `address` enables the [Address Sanitizer](https://clang.llvm.org/docs/AddressSanitizer.html)
