#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <errno.h>
#include <string.h>
#include "wasi.h"

#define WASI_UNSTABLE_IMPORT(returnType, name, parameters, body) \
  WASM_IMPORT(returnType, wasiX5FsnapshotX5Funstable_##name, parameters, body)

#define WASI_PREVIEW1_IMPORT(returnType, name, parameters, body) \
  WASM_IMPORT(returnType, wasiX5FsnapshotX5Fpreview1_##name, parameters, body)

#define WASI_IMPORT(returnType, name, parameters, body) \
  WASI_UNSTABLE_IMPORT(returnType, name, parameters, body) \
  WASI_PREVIEW1_IMPORT(returnType, name, parameters, body)

extern wasmMemory (*e_memory);

static WASI wasi;

static
__inline__
bool
WARN_UNUSED_RESULT
wasiFileDescriptorsEnsureCapacity(
    WasiFileDescriptors* descriptors,
    size_t length
) {
    if (length > descriptors->capacity) {
        size_t newCapacity = length + (descriptors->capacity >> 1u);
        void* newFileDescriptors = NULL;
        if (descriptors->fds == NULL) {
            newFileDescriptors = calloc(newCapacity * sizeof(int), 1);
        } else {
            newFileDescriptors = realloc(descriptors->fds, newCapacity * sizeof(int));
        }
        if (newFileDescriptors == NULL) {
            return false;
        }

        descriptors->fds = (int*) newFileDescriptors;
        descriptors->capacity = newCapacity;
    }
    return true;
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasiFileDescriptorsAdd(
    WasiFileDescriptors* descriptors,
    int fd
) {
    descriptors->length++;
    MUST (wasiFileDescriptorsEnsureCapacity(descriptors, descriptors->length))
    descriptors->fds[descriptors->length - 1] = fd;
    return true;
}

bool
WARN_UNUSED_RESULT
wasiAddFD(
    int nativeFD,
    U32* wasiFD
) {
    MUST (wasiFileDescriptorsAdd(&wasi.fds, nativeFD))
    if (wasiFD != NULL) {
        *wasiFD = wasi.fds.length - 1;
    }
    return true;
}

bool
WARN_UNUSED_RESULT
wasiSetFD(
    U32 wasiFD,
    int nativeFD
) {
    MUST (wasiFD < wasi.fds.length)
    wasi.fds.fds[wasiFD] = nativeFD;
    return true;
}

bool
WARN_UNUSED_RESULT
wasiGetFD(
    U32 wasiFD,
    int* nativeFD
) {
    int result = 0;
    MUST (wasiFD < wasi.fds.length)
    result = wasi.fds.fds[wasiFD];
    MUST (result >= 0)
    *nativeFD = result;
    return true;
}

bool
WARN_UNUSED_RESULT
wasiCloseFD(
    U32 wasiFD
) {
    int nativeFD;
    MUST (wasiGetFD(wasiFD, &nativeFD))
    MUST (close(nativeFD) == 0)
    wasi.fds.fds[wasiFD] = -1;
    return true;
}


static
__inline__
bool
WARN_UNUSED_RESULT
wasiPreopensEnsureCapacity(
    WasiPreopens* preopens,
    size_t length
) {
    if (length > preopens->capacity) {
        size_t newCapacity = length + (preopens->capacity >> 1u);
        void* newPreopens = NULL;
        if (preopens->preopens == NULL) {
            newPreopens = calloc(newCapacity * sizeof(WasiPreopen), 1);
        } else {
            newPreopens = realloc(preopens->preopens, newCapacity * sizeof(WasiPreopen));
        }
        if (newPreopens == NULL) {
            return false;
        }

        preopens->preopens = (WasiPreopen*) newPreopens;
        preopens->capacity = newCapacity;
    }
    return true;
}

static
__inline__
bool
WARN_UNUSED_RESULT
wasiPreopensAdd(
    WasiPreopens* preopens,
    WasiPreopen preopen
) {
    preopens->length++;
    MUST (wasiPreopensEnsureCapacity(preopens, preopens->length))
    preopens->preopens[preopens->length - 1] = preopen;
    return true;
}

bool
WARN_UNUSED_RESULT
wasiAddPreopen(
    WasiPreopen preopen
) {
    return wasiPreopensAdd(&wasi.preopens, preopen);
}

bool
WARN_UNUSED_RESULT
wasiGetPreopen(
    U32 wasiFD,
    WasiPreopen* preopen
) {
    WasiPreopen result;
    MUST (wasiFD < wasi.preopens.length)
    result = wasi.preopens.preopens[wasiFD];
    MUST (result.path != NULL && result.fd >= 0)
    *preopen = result;
    return true;
}

bool
WARN_UNUSED_RESULT
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

    MUST (wasiAddFD(STDIN_FILENO, NULL))
    MUST (wasiAddFD(STDOUT_FILENO, NULL))
    MUST (wasiAddFD(STDERR_FILENO, NULL))

    {
        short preopenIndex = 0;
        for (; preopenIndex < 3; preopenIndex++)  {
            WasiPreopen emptyPreopen = {NULL, -1};
            MUST (wasiAddPreopen(emptyPreopen))
        }
    }

    return true;
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

WASI_IMPORT(U32, fdX5Fwrite, (U32 wasiFD, U32 ciovecsPointer, U32 ciovecsCount, U32 resultPointer), {
    /* TODO: big-endian support */

    int nativeFD;
    if (!wasiGetFD(wasiFD, &nativeFD)) {
        return wasiErrnoBadf;
    }

    struct iovec* iovecs = malloc(ciovecsCount * sizeof(struct iovec));
    if (iovecs == NULL) {
        return wasiErrnoNomem;
    }

    /* Convert WASI ciovecs to native iovecs */
    {
        U32 ciovecIndex = 0;
        for (; ciovecIndex < ciovecsCount; ciovecIndex++) {
            U64 ciovecPointer = ciovecsPointer + ciovecIndex * ciovecSize;
            U32 bufferPointer = i32_load(e_memory, ciovecPointer);
            U32 length = i32_load(e_memory, ciovecPointer + 4);

            iovecs[ciovecIndex].iov_base = e_memory->data + bufferPointer;
            iovecs[ciovecIndex].iov_len = length;
        }
    }

    /* Perform the writes */
    ssize_t total = writev(nativeFD, iovecs, ciovecsCount);
    if (total < 0) {
        free(iovecs);
        return wasiErrno();
    }

    /* Store the amount of written bytes at the result pointer */
    i32_store(e_memory, resultPointer, total);

    free(iovecs);

    return wasiErrnoSuccess;
})

static const size_t iovecSize = 8;

static
__inline__
U32
wasiFdRead(
    ssize_t readFunc(int, const struct iovec*, int, off_t),
    U32 wasiFD,
    U32 iovecsPointer,
    U32 iovecsCount,
    U32 resultPointer,
    off_t offset
) {
    /* TODO: big-endian support */

    int nativeFD;
    if (!wasiGetFD(wasiFD, &nativeFD)) {
        return wasiErrnoBadf;
    }

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
    ssize_t total = readFunc(nativeFD, iovecs, iovecsCount, offset);
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

WASI_IMPORT(U32, fdX5Fread, (U32 wasiFD, U32 iovecsPointer, U32 iovecsCount, U32 resultPointer), {
    /* NOTE: offset -1 is ignored by readvWrapper */
    return wasiFdRead(readvWrapper, wasiFD, iovecsPointer, iovecsCount, resultPointer, -1);
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

WASI_IMPORT(U32, fdX5Fpread, (U32 wasiFD, U32 iovecsPointer, U32 iovecsCount, U32 offset, U32 resultPointer), {
    return wasiFdRead(preadvFallback, wasiFD, iovecsPointer, iovecsCount, resultPointer, offset);
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

WASI_PREVIEW1_IMPORT(U32, fdX5Fseek, (U32 wasiFD, U64 offset, U32 whence, U32 resultPointer), {
    int nativeFD;
    if (!wasiGetFD(wasiFD, &nativeFD)) {
        return wasiErrnoBadf;
    }

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

    off_t off = lseek(nativeFD, offset, nativeWhence);
    if (off == (off_t)-1) {
        return -1;
    }

    i32_store(e_memory, resultPointer, off);

    return wasiErrnoSuccess;
})

WASI_UNSTABLE_IMPORT(U32, fdX5Fseek, (U32 wasiFD, U64 offset, U32 whence, U32 resultPointer), {

    int nativeFD;
    if (!wasiGetFD(wasiFD, &nativeFD)) {
        return wasiErrnoBadf;
    }

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

    off_t off = lseek(nativeFD, offset, nativeWhence);
    if (off == (off_t)-1) {
        return -1;
    }

    i32_store(e_memory, resultPointer, off);

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, fdX5Fclose, (U32 wasiFD), {
    if (!wasiCloseFD(wasiFD)) {
        return wasiErrnoBadf;
    }
    return wasiErrnoSuccess;
})

static
__inline__
U64
convertTimespec(
    struct timespec t
) {
    return t.tv_sec * 1000000000 + t.tv_nsec;
}

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
        convertTimespec(timespec)
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

WASI_IMPORT(U32, fdX5FfdstatX5Fget, (U32 wasiFD, U32 resultPointer), {
    U8 filetype = wasiFiletypeUnknown;
    U16 flags = 0;

    int nativeFD;
    if (!wasiGetFD(wasiFD, &nativeFD)) {
        return wasiErrnoBadf;
    }

    /* Get filetype */
    struct stat stat;
    if (fstat(nativeFD, &stat) != 0) {
        return wasiErrno();
    }
    filetype = wasiFiletypeFromMode(stat.st_mode);

    /* Get flags */
    int fl = fcntl(nativeFD, F_GETFL);
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
    memset(e_memory->data + resultPointer, 0, 24);
    i32_store8(e_memory, resultPointer, filetype);
    i32_store16(e_memory, resultPointer + 2, flags);
    i64_store(e_memory, resultPointer + 8, /* TODO: rights. all for now */ (U64)-1);
    i64_store(e_memory, resultPointer + 16, /* TODO: inherited rights. all for now */ (U64)-1);

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, fdX5FprestatX5Fget, (U32 wasiFD, U32 prestatPointer), {
    WasiPreopen preopen;
    if (!wasiGetPreopen(wasiFD, &preopen)) {
        return wasiErrnoBadf;
    }

    {
        U32 length = strlen(preopen.path) + 1;
        i32_store(e_memory, prestatPointer, wasiPreopentypeDirectory);
        i32_store(e_memory, prestatPointer + 4, length);
    }

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, fdX5FprestatX5FdirX5Fname, (U32 wasiFD, U32 pathPointer, U32 pathLength), {
    /* TODO: big-endian support */

    WasiPreopen preopen;
    if (!wasiGetPreopen(wasiFD, &preopen)) {
        return wasiErrnoBadf;
    }

    {
        size_t length = strlen(preopen.path) + 1;
        memcpy(
            e_memory->data + pathPointer,
            preopen.path,
            length < pathLength ? length : pathLength
        );
    }

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, pathX5Fopen, (
    U32 wasiDirFD,
    U32 dirFlags,
    U32 pathPointer,
    U32 pathLength,
    U32 oflags,
    U64 fsRightsBase,
    U64 fsRightsInheriting,
    U32 fdFlags,
    U32 fdPointer
), {
    /* TODO: big-endian support */

    char* path = NULL;
    int flags = 0;
    static const int mode = 0644;

    WasiPreopen preopen;
    if (!wasiGetPreopen(wasiDirFD, &preopen)) {
        return wasiErrnoBadf;
    }

    path = malloc(pathLength + 1);
    memcpy(path, e_memory->data + pathPointer, pathLength);
    path[pathLength] = '\0';

    /* Convert WASI oflags to native flags */
    if (oflags & wasiOflagsCreat) {
        flags |= O_CREAT;
    }
    if (oflags & wasiOflagsDirectory) {
        flags |= O_DIRECTORY;
    }
    if (oflags & wasiOflagsExcl) {
        flags |= O_EXCL;
    }
    if (oflags & wasiOflagsTrunc) {
        flags |= O_TRUNC;
    }

    /* Convert WASI fdFlags to native flags */
    if (fdFlags & wasiFdflagsAppend) {
        flags |= O_APPEND;
    }
    if (fdFlags & wasiFdflagsDsync) {
        flags |= O_DSYNC;
    }
    if (fdFlags & wasiFdflagsNonblock) {
        flags |= O_NONBLOCK;
    }
    if (fdFlags & wasiFdflagsSync) {
        flags |= O_SYNC;
    }
    /* wasiFdflagsRsync is ignored, as O_RSYNC is often not implemented */

    /* Convert WASI fsRightsBase to native flags */
    if ((fsRightsBase & wasiRightsFdRead)
        && (fsRightsBase & wasiRightsFdWrite))
    {
        flags |= O_RDWR;
    } else if ((fsRightsBase & wasiRightsFdWrite)) {
        flags |= O_WRONLY;
    } else if ((fsRightsBase & wasiRightsFdRead)) {
        flags |= O_RDONLY;
    }

    /* Open the file */
    int nativeFD = openat(preopen.fd, path, flags, mode);
    if (nativeFD < 0) {
        free(path);
        return wasiErrno();
    }

    {
        /* Register the WASI file descriptor */
        U32 wasiFD;
        if (!wasiAddFD(nativeFD, &wasiFD)) {
            free(path);
            return wasiErrnoBadf;
        }

        /* Store the file descriptor at the result pointer */
        i32_store(e_memory, fdPointer, wasiFD);
    }

    free(path);

    return wasiErrnoSuccess;
})

static
__inline__
void
getStatTimes(
    struct stat* stat,
    struct timespec* access,
    struct timespec* modification,
    struct timespec* creation
) {
#if defined(__APPLE__)
    access->tv_sec = stat->st_atimespec.tv_sec;
    access->tv_nsec = stat->st_atimespec.tv_nsec;
    modification->tv_sec = stat->st_mtimespec.tv_sec;
    modification->tv_nsec = stat->st_mtimespec.tv_nsec;
    creation->tv_sec = stat->st_ctimespec.tv_sec;
    creation->tv_nsec = stat->st_ctimespec.tv_nsec;
#elif defined(__ANDROID__)
    access->tv_sec = stat->st_atime;
    access->tv_nsec = stat->st_atimensec;
    modification->tv_sec = stat->st_mtime;
    modification->tv_nsec = stat->st_mtimensec;
    creation->tv_sec = stat->st_ctime;
    creation->tv_nsec = stat->st_ctimensec;
#elif !defined(_AIX) &&         \
    !defined(__MVS__) && (      \
    defined(__DragonFly__)   || \
    defined(__FreeBSD__)     || \
    defined(__OpenBSD__)     || \
    defined(__NetBSD__)      || \
    defined(_GNU_SOURCE)     || \
    defined(_BSD_SOURCE)     || \
    defined(_SVID_SOURCE)    || \
    defined(_XOPEN_SOURCE)   || \
    defined(_DEFAULT_SOURCE))
    access->tv_sec = stat->st_atim.tv_sec;
    access->tv_nsec = stat->st_atim.tv_nsec;
    modification->tv_sec = stat->st_mtim.tv_sec;
    modification->tv_nsec = stat->st_mtim.tv_nsec;
    creation->tv_sec = stat->st_ctim.tv_sec;
    creation->tv_nsec = stat->st_ctim.tv_nsec;
#else
    access->tv_sec = stat->st_atime;
    access->tv_nsec = 0;
    modification->tv_sec = stat->st_mtime;
    modification->tv_nsec = 0;
    creation->tv_sec = stat->st_ctime;
    creation->tv_nsec = 0;
#endif
}

void DumpHex(const void* data, size_t size) {
    char ascii[17];
    size_t i, j;
    ascii[16] = '\0';
    for (i = 0; i < size; ++i) {
        printf("%02X ", ((unsigned char*)data)[i]);
        if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
            ascii[i % 16] = ((unsigned char*)data)[i];
        } else {
            ascii[i % 16] = '.';
        }
        if ((i+1) % 8 == 0 || i+1 == size) {
            printf(" ");
            if ((i+1) % 16 == 0) {
                printf("|  %s \n", ascii);
            } else if (i+1 == size) {
                ascii[(i+1) % 16] = '\0';
                if ((i+1) % 16 <= 8) {
                    printf(" ");
                }
                for (j = (i+1) % 16; j < 16; ++j) {
                    printf("   ");
                }
                printf("|  %s \n", ascii);
            }
        }
    }
}

static
__inline__
void
storePreview1Filestat(
    U32 statPointer,
    struct stat* stat
) {
    struct timespec access;
    struct timespec modification;
    struct timespec creation;

    getStatTimes(stat, &access, &modification, &creation);

    memset(e_memory->data + statPointer, 0, 64);
    i64_store(e_memory, statPointer,  stat->st_dev);
    i64_store(e_memory, statPointer + 8,  stat->st_ino);
    i32_store8(e_memory, statPointer + 16, wasiFiletypeFromMode(stat->st_mode));
    i64_store(e_memory, statPointer + 24, stat->st_nlink);
    i64_store(e_memory, statPointer + 32, stat->st_size);
    i64_store(e_memory, statPointer + 40, convertTimespec(access));
    i64_store(e_memory, statPointer + 48, convertTimespec(modification));
    i64_store(e_memory, statPointer + 56, convertTimespec(creation));
}

WASI_PREVIEW1_IMPORT(U32, fdX5FfilestatX5Fget, (U32 wasiFD, U32 statPointer), {
    struct stat stat;

    int nativeFD;
    if (!wasiGetFD(wasiFD, &nativeFD)) {
        return wasiErrnoBadf;
    }

    if (fstat(nativeFD, &stat) != 0) {
        return wasiErrno();
    }

    storePreview1Filestat(statPointer, &stat);

    return wasiErrnoSuccess;
})

static
__inline__
void
storeUnstableFilestat(
    U32 statPointer,
    struct stat* stat
) {
    struct timespec access;
    struct timespec modification;
    struct timespec creation;

    getStatTimes(stat, &access, &modification, &creation);

    memset(e_memory->data + statPointer, 0, 56);
    i64_store(e_memory, statPointer,  stat->st_dev);
    i64_store(e_memory, statPointer + 8,  stat->st_ino);
    i32_store8(e_memory, statPointer + 16, wasiFiletypeFromMode(stat->st_mode));
    i32_store(e_memory, statPointer + 20, stat->st_nlink);
    i64_store(e_memory, statPointer + 24, stat->st_size);
    i64_store(e_memory, statPointer + 32, convertTimespec(access));
    i64_store(e_memory, statPointer + 40, convertTimespec(modification));
    i64_store(e_memory, statPointer + 48, convertTimespec(creation));
}

WASI_UNSTABLE_IMPORT(U32, fdX5FfilestatX5Fget, (U32 wasiFD, U32 statPointer), {
    struct stat stat;

    int nativeFD;
    if (!wasiGetFD(wasiFD, &nativeFD)) {
        return wasiErrnoBadf;
    }

    if (fstat(nativeFD, &stat) != 0) {
        return wasiErrno();
    }

    storeUnstableFilestat(statPointer, &stat);

    return wasiErrnoSuccess;
})

WASI_PREVIEW1_IMPORT(U32, pathX5FfilestatX5Fget, (
    U32 fd,
    U32 lookupFlags,
    U32 pathPointer,
    U32 pathLength,
    U32 statPointer
), {
    /* TODO: big-endian support */

    char* path = NULL;
    int flags = 0;
    struct stat st;
    int res = 0;

    WasiPreopen preopen;
    if (!wasiGetPreopen(fd, &preopen)) {
        return wasiErrnoBadf;
    }

    path = malloc(pathLength + 1);
    memcpy(path, e_memory->data + pathPointer, pathLength);
    path[pathLength] = '\0';

    /* TODO: resolve path */

    if (flags & wasiLookupFlagSymlinkFollow) {
        res = stat(path, &st);
    } else {
        res = lstat(path, &st);
    }
    if (res != 0) {
        return wasiErrno();
    }

    storePreview1Filestat(statPointer, &st);

    return wasiErrnoSuccess;
})

WASI_UNSTABLE_IMPORT(U32, pathX5FfilestatX5Fget, (
    U32 fd,
    U32 lookupFlags,
    U32 pathPointer,
    U32 pathLength,
    U32 statPointer
), {
    /* TODO: big-endian support */

    char* path = NULL;
    int flags = 0;

    WasiPreopen preopen;
    if (!wasiGetPreopen(fd, &preopen)) {
        return wasiErrnoBadf;
    }

    path = malloc(pathLength + 1);
    memcpy(path, e_memory->data + pathPointer, pathLength);
    path[pathLength] = '\0';

    /* TODO: resolve path, use flags */

    struct stat st;
    if (stat(path, &st) != 0) {
        return wasiErrno();
    }

    storeUnstableFilestat(statPointer, &st);

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, pathX5Frename, (
    U32 oldDirFD,
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 newDirFD,
    U32 newPathPointer,
    U32 newPathLength
), {
    /* TODO: big-endian support */

    char* oldPath = NULL;
    char* newPath = NULL;

    WasiPreopen oldPreopen;
    if (!wasiGetPreopen(oldDirFD, &oldPreopen)) {
        return wasiErrnoBadf;
    }

    WasiPreopen newPreopen;
    if (!wasiGetPreopen(newDirFD, &newPreopen)) {
        return wasiErrnoBadf;
    }

    oldPath = malloc(oldPathLength + 1);
    memcpy(oldPath, e_memory->data + oldPathPointer, oldPathLength);
    oldPath[oldPathLength] = '\0';

    newPath = malloc(newPathLength + 1);
    memcpy(newPath, e_memory->data + newPathPointer, newPathLength);
    newPath[newPathLength] = '\0';

    if (renameat(oldPreopen.fd, oldPath, newPreopen.fd, newPath) != 0) {
        return wasiErrno();
    }

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, pathX5FunlinkX5Ffile, (U32 dirFD, U32 pathPointer, U32 pathLength), {
    /* TODO: big-endian support */

    char* path = NULL;

    WasiPreopen preopen;
    if (!wasiGetPreopen(dirFD, &preopen)) {
        return wasiErrnoBadf;
    }

    path = malloc(pathLength + 1);
    memcpy(path, e_memory->data + pathPointer, pathLength);
    path[pathLength] = '\0';

    if (unlinkat(preopen.fd, path, 0) != 0) {
        return wasiErrno();
    }

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, pathX5FremoveX5Fdirectory, (U32 dirFD, U32 pathPointer, U32 pathLength), {
    /* TODO: big-endian support */

    char* path = NULL;

    WasiPreopen preopen;
    if (!wasiGetPreopen(dirFD, &preopen)) {
        return wasiErrnoBadf;
    }

    path = malloc(pathLength + 1);
    memcpy(path, e_memory->data + pathPointer, pathLength);
    path[pathLength] = '\0';

    if (unlinkat(preopen.fd, path, AT_REMOVEDIR) != 0) {
        return wasiErrno();
    }

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, pathX5FcreateX5Fdirectory, (U32 dirFD, U32 pathPointer, U32 pathLength), {
    /* TODO: big-endian support */

    char* path = NULL;
    static const mode_t mode = 0755;

    WasiPreopen preopen;
    if (!wasiGetPreopen(dirFD, &preopen)) {
        return wasiErrnoBadf;
    }

    path = malloc(pathLength + 1);
    memcpy(path, e_memory->data + pathPointer, pathLength);
    path[pathLength] = '\0';

    if (mkdirat(preopen.fd, path, mode) != 0) {
        return wasiErrno();
    }

    return wasiErrnoSuccess;
})


WASI_IMPORT(U32, pathX5Fsymlink, (
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 dirFD,
    U32 newPathPointer,
    U32 newPathLength
), {
    /* TODO: big-endian support */

    char* oldPath = NULL;
    char* newPath = NULL;

    WasiPreopen preopen;
    if (!wasiGetPreopen(dirFD, &preopen)) {
        return wasiErrnoBadf;
    }

    oldPath = malloc(oldPathLength + 1);
    memcpy(oldPath, e_memory->data + oldPathPointer, oldPathLength);
    oldPath[oldPathLength] = '\0';

    newPath = malloc(newPathLength + 1);
    memcpy(newPath, e_memory->data + newPathPointer, newPathLength);
    newPath[newPathLength] = '\0';

    if (symlinkat(oldPath, preopen.fd, newPath) != 0) {
        return wasiErrno();
    }

    return wasiErrnoSuccess;
})

WASI_IMPORT(U32, pathX5Freadlink, (
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength,
    U32 bufferPointer,
    U32 bufferLength,
    U32 lengthPointer
), {
    /* TODO: big-endian support */

    char* path = NULL;
    char* buffer = NULL;
    int length = 0;

    WasiPreopen preopen;
    if (!wasiGetPreopen(dirFD, &preopen)) {
        return wasiErrnoBadf;
    }

    path = malloc(pathLength + 1);
    memcpy(path, e_memory->data + pathPointer, pathLength);
    path[pathLength] = '\0';

    buffer = (char*)e_memory->data + bufferPointer;
    length = readlinkat(preopen.fd, path, buffer, bufferLength);
    if (length < 0) {
        return wasiErrno();
    }

    i32_store(e_memory, lengthPointer, length);

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
