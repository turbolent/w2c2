# w2c2

Translates WebAssembly modules to C.
Inspired by [wabt's wasm2c](https://github.com/WebAssembly/wabt/tree/main/wasm2c).

## Features

- Implements the WebAssembly Core Specification 1.0
- Passes 99.9% of the WebAssembly core semantics test suite
- Written in C89 and generates C89
- Support for older operating systems and architectures
- Support for big-endian systems
- Streaming compilation, low memory usage
- Parallel compilation into multiple files
- WASI implementation which is able to run `clang.wasm`

## Performance

- Coremark 1.0: ~7% slower than native

## Usage

Compile `module.wasm` to `module.c`:

```sh
make release
./w2c2 -o module.c module.wasm
```

### Parallel Compilation

Compile `module.wasm` using 12 concurrent jobs into multiple files with 100 functions each:

```sh
./w2c2 -o module_directory -j 12 -f 100 module.wasm
```

## Examples

Coremark:

```sh
cd examples/coremark
./coremark
```

## Testing

Requires Python 3 and wabt (for wast2json).

```sh
cd tests
make gen
make run-tests
```

## WASI Status

- [x] args_get
- [x] args_sizes_get
- [ ] clock_res_get
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
- [ ] fd_readdir
- [ ] fd_renumber
- [x] fd_seek
- [ ] fd_sync
- [ ] fd_tell
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
- [ ] proc_raise
- [x] random_get
- [ ] sched_yield
- [ ] sock_recv
- [ ] sock_send
- [ ] sock_shutdown
