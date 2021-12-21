#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "../w2c2_base.h"

#define WASI_ESUCCESS 0

extern wasmMemory (*e_memory);

static const int fds[] = {STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO};

WASM_IMPORT(void, wasiX5FsnapshotX5Fpreview1_procX5Fexit, (U32 code), {
    exit(code);
})

WASM_IMPORT(U32, wasiX5FsnapshotX5Fpreview1_fdX5Fwrite, (U32 fd, U32 iovs, U32 iovsLen, U32 nwritten), {
    U32 total = 0;
    U32 i = 0;
    for (; i < iovsLen; i++) {
        U32 ptr = i32_load(e_memory, iovs + i * 8);
        U32 len = i32_load(e_memory, iovs + i * 8 + 4);
        ssize_t result = write(fds[fd], e_memory->data + ptr, len);
        if (result < 0) {
            return -1;
        }
        if (result != len) {
            return -1;
        }
        total += len;
    }

    i32_store(e_memory, nwritten, total);

    return WASI_ESUCCESS;
})

WASM_IMPORT(U32, wasiX5FsnapshotX5Fpreview1_environX5FsizesX5Fget, (U32 pcount, U32 pbuf_size), {
    // TODO:
    i32_store(e_memory, pcount, 0);
    i32_store(e_memory, pbuf_size, 0);
    return WASI_ESUCCESS;
})

WASM_IMPORT(U32, wasiX5FsnapshotX5Fpreview1_environX5Fget, (U32 __environ, U32 environ_buf), {
    // TODO:
    return WASI_ESUCCESS;
})

WASM_IMPORT(U32, wasiX5FsnapshotX5Fpreview1_argsX5FsizesX5Fget, (U32 pcount, U32 pbuf_size), {
    // TODO:
    i32_store(e_memory, pcount, 0);
    i32_store(e_memory, pbuf_size, 0);
    return WASI_ESUCCESS;
})

WASM_IMPORT(U32, wasiX5FsnapshotX5Fpreview1_argsX5Fget, (U32 __args, U32 args_buf), {
    return WASI_ESUCCESS;
})

static
__inline__
int convertWhence(
    U32 whence
) {
    switch (whence) {
        case 0:
            return SEEK_SET;
        case 1:
            return SEEK_CUR;
        case 2:
            return SEEK_END;
        default:
            return -1;
    }
}

WASM_IMPORT(U32, wasiX5FsnapshotX5Fpreview1_fdX5Fseek, (U32 fd, U64 offset, U32 whence, U32 newOffset), {
    int nativeWhence = convertWhence(whence);
    if (nativeWhence == -1) {
        return -1;
    }
    off_t off = lseek(fd, offset, nativeWhence);
    if (off == (off_t)-1) {
        return -1;
    }
    i32_store(e_memory, newOffset, off);
    return WASI_ESUCCESS;
})

WASM_IMPORT(U32, wasiX5FsnapshotX5Fpreview1_fdX5Fclose, (U32 fd), {
    return close(fd);
})

WASM_IMPORT(U32, wasiX5FsnapshotX5Fpreview1_clockX5FtimeX5Fget, (U32 clockID, U64 maxLag, U32 out), {
    const double NSEC_PER_SEC = 1000.0 * 1000.0 * 1000.0;
    i64_store(e_memory, out, (U64)(clock() / (CLOCKS_PER_SEC / NSEC_PER_SEC)));
    return WASI_ESUCCESS;
})

WASM_IMPORT(U32, wasiX5FsnapshotX5Fpreview1_fdX5FfdstatX5Fget, (U32 fd, U32 out), {
    // TODO:
    memset(e_memory->data + out, 0, 24);
    return WASI_ESUCCESS;
})
