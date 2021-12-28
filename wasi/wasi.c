#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include "wasi.h"
#include "../w2c2_base.h"

#define WASI_UNSTABLE_IMPORT(returnType, name, parameters, body) \
  WASM_IMPORT(returnType, wasiX5FsnapshotX5Funstable_##name, parameters, body)

#define WASI_PREVIEW1_IMPORT(returnType, name, parameters, body) \
  WASM_IMPORT(returnType, wasiX5FsnapshotX5Fpreview1_##name, parameters, body)

#define WASI_IMPORT(returnType, name, parameters, body) \
  WASI_UNSTABLE_IMPORT(returnType, name, parameters, body) \
  WASI_PREVIEW1_IMPORT(returnType, name, parameters, body)

extern wasmMemory (*e_memory);

static WASI wasi;

void
wasiInit(
    int argc,
    char* argv[],
    char** envp
) {
    int envc = 0;
    while (envp[envc] != NULL) {
        envc++;
    }

    wasi.envc = envc;
    wasi.envp = envp;
    wasi.argc = argc;
    wasi.argv = argv;
}

static
__inline__
U16
wasiErrno() {
    switch (errno) {
    case EPERM:
        return wasiErrnoPerm;
    case ENOENT:
        return wasiErrnoNoent;
    case ESRCH:
        return wasiErrnoSrch;
    case EINTR:
        return wasiErrnoIntr;
    case EIO:
        return wasiErrnoIo;
    case ENXIO:
        return wasiErrnoNxio;
    case E2BIG:
        return wasiErrno2big;
    case ENOEXEC:
        return wasiErrnoNoexec;
    case EBADF:
        return wasiErrnoBadf;
    case ECHILD:
        return wasiErrnoChild;
    case EAGAIN:
        return wasiErrnoAgain;
    case ENOMEM:
        return wasiErrnoNomem;
    case EACCES:
        return wasiErrnoAcces;
    case EFAULT:
        return wasiErrnoFault;
    case EBUSY:
        return wasiErrnoBusy;
    case EEXIST:
        return wasiErrnoExist;
    case EXDEV:
        return wasiErrnoXdev;
    case ENODEV:
        return wasiErrnoNodev;
    case ENOTDIR:
        return wasiErrnoNotdir;
    case EISDIR:
        return wasiErrnoIsdir;
    case EINVAL:
        return wasiErrnoInval;
    case ENFILE:
        return wasiErrnoNfile;
    case EMFILE:
        return wasiErrnoMfile;
    case ENOTTY:
        return wasiErrnoNotty;
    case ETXTBSY:
        return wasiErrnoTxtbsy;
    case EFBIG:
        return wasiErrnoFbig;
    case ENOSPC:
        return wasiErrnoNospc;
    case ESPIPE:
        return wasiErrnoSpipe;
    case EROFS:
        return wasiErrnoRofs;
    case EMLINK:
        return wasiErrnoMlink;
    case EPIPE:
        return wasiErrnoPipe;
    case EDOM:
        return wasiErrnoDom;
    case ERANGE:
        return wasiErrnoRange;
    default:
        return wasiErrnoInval;
    }
}

WASI_IMPORT(void, procX5Fexit, (U32 code), {
    exit(code);
})


static const size_t ciovecSize = 8;

WASI_IMPORT(U32, fdX5Fwrite, (U32 fd, U32 ciovsPointer, U32 ciovsCount, U32 resultPointer), {
    U32 total = 0;
    U32 ciovIndex = 0;
    for (; ciovIndex < ciovsCount; ciovIndex++) {
        U64 ciovPointer = ciovsPointer + ciovIndex * ciovecSize;
        U32 bufferPointer = i32_load(e_memory, ciovPointer);
        U32 length = i32_load(e_memory, ciovPointer + 4);
        /* TODO: big-endian support */
        ssize_t result = write(fd, e_memory->data + bufferPointer, length);
        if (result < 0) {
            return -1;
        }
        if (result != length) {
            return -1;

static const size_t iovecSize = 8;

static
__inline__
U32
wasiFdRead(
    ssize_t readFunc(int, const struct iovec*, int, off_t),
    U32 fd,
    U32 iovecsPointer,
    U32 iovecsCount,
    U32 resultPointer,
    off_t offset
) {
    /* TODO: big-endian support */

    struct iovec* iovecs = malloc(iovecsCount * sizeof(struct iovec));
    if (iovecs == NULL) {
        return wasiErrnoNomem;
    }

    /* Convert WASI iovecs to native iovecs */
    {
        U32 iovecIndex = 0;
        for (; iovecIndex < iovecsCount; iovecIndex++) {
            U64 iovecPointer = iovecsPointer + iovecIndex * iovecSize;
            U32 bufferPointer = i32_load(e_memory, iovecPointer);
            U32 length = i32_load(e_memory, iovecPointer + 4);

            iovecs[iovecIndex].iov_base = e_memory->data + bufferPointer;
            iovecs[iovecIndex].iov_len = length;
        }
    }

    /* Perform the reads */
    ssize_t total = readFunc(fd, iovecs, iovecsCount, offset);
    if (total < 0) {
        free(iovecs);
        return wasiErrno();
    }

    /* Store the amount of read bytes at the result pointer */
    i32_store(e_memory, resultPointer, total);

    free(iovecs);

    return wasiErrnoSuccess;
}
ssize_t
readvWrapper(
    int fd,
    const struct iovec* iovecs,
    int count,
    off_t offset
) {
    return readv(fd, iovecs, count);
}

WASI_IMPORT(U32, fdX5Fread, (U32 fd, U32 iovecsPointer, U32 iovecsCount, U32 resultPointer), {
    /* NOTE: offset -1 is ignored by readvWrapper */
    return wasiFdRead(readvWrapper, fd, iovecsPointer, iovecsCount, resultPointer, -1);
})

static
__inline__
ssize_t
wrapPositional(
    ssize_t f(int, const struct iovec*, int),
    int fd,
    const struct iovec* iovecs,
    int count,
    off_t offset
) {
    off_t origLoc = lseek(fd, 0, SEEK_CUR);
    if (origLoc == (off_t)-1) {
        return -1;
    }
    if (lseek(fd, offset, SEEK_SET) == (off_t)-1) {
        return -1;
    }

    ssize_t res = f(fd, iovecs, count);

    int currentErrno = errno;
    if (lseek(fd, origLoc, SEEK_SET) == (off_t)-1) {
        if (res == -1) {
            errno = currentErrno;
        }
        return -1;
    }
    errno = currentErrno;

    return res;
}

ssize_t
preadvFallback(
    int fd,
    const struct iovec* iovecs,
    int count,
    off_t offset
) {
    return wrapPositional(readv, fd, iovecs, count, offset);
}

WASI_IMPORT(U32, fdX5Fpread, (U32 fd, U32 iovecsPointer, U32 iovecsCount, U32 offset, U32 resultPointer), {
    return wasiFdRead(preadvFallback, fd, iovecsPointer, iovecsCount, resultPointer, offset);
})

WASI_IMPORT(U32, environX5FsizesX5Fget, (U32 envcPointer, U32 envpBufSizePointer), {
    int envpIndex = 0;
    size_t envpBufSize = 0;
    while (wasi.envp[envpIndex] != NULL) {
        envpBufSize += strlen(wasi.envp[envpIndex]) + 1;
        envpIndex++;
    }

    i32_store(e_memory, envcPointer, wasi.envc);
    i32_store(e_memory, envpBufSizePointer, envpBufSize);
    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, environX5Fget, (U32 envpPointer, U32 envpBufPointer), {
    /* TODO: big-endian support */
    U32 index = 0;
    for (; wasi.envp[index] != NULL; index++) {
        char* env = wasi.envp[index];
        size_t length = strlen(env) + 1;
        memcpy(
            e_memory->data + envpBufPointer,
            env,
            length
        );
        i32_store(
            e_memory,
            envpPointer + index * sizeof(U32),
            envpBufPointer
        );
        envpBufPointer += length;
    }
    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, argsX5FsizesX5Fget, (U32 argcPointer, U32 argvBufSizePointer), {
    size_t argvBufSize = 0;

    U32 argvIndex = 0;
    for (; argvIndex < wasi.argc; argvIndex++) {
        argvBufSize += strlen(wasi.argv[argvIndex]) + 1;
    }

    i32_store(e_memory, argcPointer, wasi.argc);
    i32_store(e_memory, argvBufSizePointer, argvBufSize);

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, argsX5Fget, (U32 argvPointer, U32 argvBufPointer), {
    /* TODO: big-endian support */
    U32 index = 0;
    for (; index < wasi.argc; index++) {
        char* arg = wasi.argv[index];
        size_t length = strlen(arg) + 1;
        memcpy(
            e_memory->data + argvBufPointer,
            arg,
            length
        );
        i32_store(
            e_memory,
            argvPointer + index * sizeof(U32),
            argvBufPointer
        );
        argvBufPointer += length;
    }
    return wasiErrnoSuccess;
})

WASI_PREVIEW1_IMPORT(U32, fdX5Fseek, (U32 fd, U64 offset, U32 whence, U32 resultPointer), {
    int nativeWhence = 0;
    /* Oder changed from unstable to preview1: https://github.com/WebAssembly/WASI/pull/106 */
    switch (whence) {
        case 0: {
            nativeWhence = SEEK_SET;
            break;
        }
        case 1: {
            nativeWhence = SEEK_CUR;
            break;
        }
        case 2: {
            nativeWhence = SEEK_END;
            break;
        }
        default:
            return -1;
    }
    off_t off = lseek(fd, offset, nativeWhence);
    if (off == (off_t)-1) {
        return -1;
    }
    i32_store(e_memory, resultPointer, off);
    return wasiErrnoSuccess;
})

WASI_UNSTABLE_IMPORT(U32, fdX5Fseek, (U32 fd, U64 offset, U32 whence, U32 resultPointer), {
    int nativeWhence = 0;
    /* Oder changed from unstable to preview1: https://github.com/WebAssembly/WASI/pull/106 */
    switch (whence) {
        case 0: {
            nativeWhence = SEEK_CUR;
            break;
        }
        case 1: {
            nativeWhence = SEEK_END;
            break;
        }
        case 2: {
            nativeWhence = SEEK_SET;
            break;
        }
        default:
            return -1;
    }
    off_t off = lseek(fd, offset, nativeWhence);
    if (off == (off_t)-1) {
        return -1;
    }
    i32_store(e_memory, resultPointer, off);
    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, fdX5Fclose, (U32 fd), {
    return close(fd);
})

WASI_IMPORT(U32, clockX5FtimeX5Fget, (U32 clockID, U64 precision, U32 resultPointer), {
    struct timespec timespec;

    clockid_t nativeClockID;
    switch (clockID) {
        case wasiClockRealtime: {
            nativeClockID = CLOCK_REALTIME;
            break;
        }
        case wasiClockMonotonic: {
            nativeClockID = CLOCK_MONOTONIC;
            break;
        }
        default:
            return wasiErrnoInval;
    }

    if (clock_gettime(nativeClockID, &timespec) != 0) {
        return wasiErrno();
    }

    i64_store(
        e_memory,
        resultPointer,
        timespec.tv_sec * 1000000000 + timespec.tv_nsec
    );

    return wasiErrnoSuccess;
})

static
__inline__
WasiFiletype
wasiFiletypeFromMode(
    mode_t mode
) {
  switch (mode & S_IFMT) {
      case S_IFBLK:
          return wasiFiletypeBlockDevice;
      case S_IFCHR:
          return wasiFiletypeCharacterDevice;
      case S_IFDIR:
          return wasiFiletypeDirectory;
      case S_IFREG:
          return wasiFiletypeRegularFile;
      case S_IFLNK:
          return wasiFiletypeSymbolicLink;
      default:
          return wasiFiletypeUnknown;
  }
}

WASI_IMPORT(U32, fdX5FfdstatX5Fget, (U32 fd, U32 resultPointer), {
    U8 filetype = wasiFiletypeUnknown;
    U16 flags = 0;

    /* Get filetype */
    struct stat stat;
    if (fstat(fd, &stat) != 0) {
        return wasiErrno();
    }
    filetype = wasiFiletypeFromMode(stat.st_mode);

    /* Get flags */
    int fl = fcntl(fd, F_GETFL);
    if (fl < 0) {
        return wasiErrno();
    }

    if (fl & O_APPEND) {
        flags |= wasiFdflagsAppend;
    }
    if (fl & O_DSYNC) {
        flags |= wasiFdflagsDsync;
    }
    if (fl & O_NONBLOCK) {
        flags |= wasiFdflagsNonblock;
    }
    if (fl & O_SYNC) {
        flags |= wasiFdflagsRsync | wasiFdflagsSync;
    }

    /* Store result */
    i32_store8(e_memory, resultPointer, filetype);
    i32_store16(e_memory, resultPointer + 2, flags);
    i64_store(e_memory, resultPointer + 8, /* TODO: rights. all for now */ (U64)-1);
    i64_store(e_memory, resultPointer + 16, /* TODO: inherited rights. all for now */ (U64)-1);

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, randomX5Fget, (U32 bufferPointer, U32 bufferLength), {
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0) {
        return wasiErrno();
    }
    read(fd, e_memory->data + bufferPointer, bufferLength);
    close(fd);

    return wasiErrnoSuccess;
})
