#define _DEFAULT_SOURCE 1

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "wasi.h"

#if NEED_STRNDUP
char *strndup(const char *s, size_t n) {
    const char *p = memchr(s, 0, n);
    size_t l = p ? p-s : n;
    char *d = malloc(l + 1);
    if (!d) {
        return NULL;
    }
    memcpy(d, s, l);
    d[l] = '\0';
    return d;
}
#endif

static
void
#ifdef __GNUC__
__attribute__ ((format(printf, 1, 2)))
#endif
tracePrintf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "### WASI: ");
    vfprintf(stderr, fmt, args);
    fputc('\n', stderr);
    va_end(args);
}

#if WASI_TRACE_ENABLED
#define WASI_TRACE(args) (tracePrintf args)
#else
#define WASI_TRACE(args)
#endif

extern wasmMemory* wasiMemory(void* instance);

static WASI wasi;

#ifndef O_DSYNC
#ifdef O_SYNC
#define O_DSYNC O_SYNC /* POSIX */
#else
#define O_DSYNC O_FSYNC /* BSD */
#endif
#endif

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
            newFileDescriptors = calloc(newCapacity * sizeof(WasiFileDescriptor), 1);
        } else {
            newFileDescriptors = realloc(descriptors->fds, newCapacity * sizeof(WasiFileDescriptor));
        }
        if (newFileDescriptors == NULL) {
            return false;
        }

        descriptors->fds = (WasiFileDescriptor*) newFileDescriptors;
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
    int fd,
    char* path
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    descriptor.fd = fd;
    if (path != NULL) {
        size_t length = strlen(path);
        MUST (length > 0 && length < PATH_MAX)
        path = strndup(path, length);
        MUST (path != NULL)
    }
    descriptor.path = path;
    descriptors->length++;
    if (!wasiFileDescriptorsEnsureCapacity(descriptors, descriptors->length)) {
        free(path);
        return false;
    }
    descriptors->fds[descriptors->length - 1] = descriptor;
    return true;
}

bool
WARN_UNUSED_RESULT
wasiFileDescriptorAdd(
    int nativeFD,
    U32* wasiFD,
    char* path
) {
    MUST (wasiFileDescriptorsAdd(&wasi.fds, nativeFD, path))
    if (wasiFD != NULL) {
        *wasiFD = wasi.fds.length - 1;
    }
    return true;
}

bool
WARN_UNUSED_RESULT
wasiFileDescriptorSet(
    U32 wasiFD,
    int nativeFD
) {
    MUST (wasiFD < wasi.fds.length)
    wasi.fds.fds[wasiFD].fd = nativeFD;
    return true;
}

bool
WARN_UNUSED_RESULT
wasiFileDescriptorGet(
    U32 wasiFD,
    WasiFileDescriptor* result
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    MUST (wasiFD < wasi.fds.length)
    descriptor = wasi.fds.fds[wasiFD];
    MUST (descriptor.fd >= 0)
    *result = descriptor;
    return true;
}

static
bool
WARN_UNUSED_RESULT
wasiDirectorySet(
    U32 wasiFD,
    DIR* nativeDir
) {
    MUST (wasiFD < wasi.fds.length)
    wasi.fds.fds[wasiFD].dir = nativeDir;
    return true;
}

bool
WARN_UNUSED_RESULT
wasiFileDescriptorClose(
    U32 wasiFD
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    MUST (wasiFileDescriptorGet(wasiFD, &descriptor))

    if (descriptor.dir != NULL) {
        MUST (closedir(descriptor.dir) == 0)
    } else {
        MUST (close(descriptor.fd) == 0)
    }

    if (descriptor.path != NULL) {
        free(descriptor.path);
    }

    MUST (wasiFileDescriptorSet(wasiFD, -1))
    MUST (wasiDirectorySet(wasiFD, NULL))

    wasi.fds.length -= 1;

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
    if (preopen.path != NULL) {
        size_t length = strlen(preopen.path);
        MUST (length > 0 && length < PATH_MAX)
        preopen.path = strndup(preopen.path, length);
        MUST (preopen.path != NULL)
    }

    preopens->length++;
    MUST (wasiPreopensEnsureCapacity(preopens, preopens->length))
    preopens->preopens[preopens->length - 1] = preopen;
    return true;
}

bool
WARN_UNUSED_RESULT
wasiPreopenAdd(
    WasiPreopen preopen,
    U32* wasiFD
) {
    MUST (wasiPreopensAdd(&wasi.preopens, preopen))
    if (preopen.fd < 0) {
        return true;
    }
    return wasiFileDescriptorAdd(preopen.fd, wasiFD, preopen.path);
}

bool
WARN_UNUSED_RESULT
wasiPreopenGet(
    U32 wasiFD,
    WasiPreopen* preopen
) {
    WasiPreopen result = wasiEmptyPreopen;
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

    MUST (wasiFileDescriptorAdd(STDIN_FILENO, NULL, NULL))
    MUST (wasiFileDescriptorAdd(STDOUT_FILENO, NULL, NULL))
    MUST (wasiFileDescriptorAdd(STDERR_FILENO, NULL, NULL))

    {
        short preopenIndex = 0;
        for (; preopenIndex < 3; preopenIndex++)  {
            WasiPreopen emptyPreopen = wasiEmptyPreopen;
            MUST (wasiPreopenAdd(emptyPreopen, NULL))
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

bool
resolvePath(
    char* directory,
    char* path,
    U32 pathLength,
    char result[PATH_MAX]
) {
    MUST (pathLength > 0)

    if (path[0] == '/') {
        /* If the path is absolute, return it as-is */
        MUST (pathLength < PATH_MAX)
        memcpy(result, path, pathLength);
        result[pathLength] = '\0';
    } else {
        /* If the path is relative, concatenate the directory and the path */
        size_t totalLength = strlen(directory);
        MUST (totalLength + pathLength + 1 < PATH_MAX)
        memcpy(result, directory, totalLength);

        if (directory[totalLength - 1] != '/') {
            result[totalLength++] = '/';
        }

        memcpy(result + totalLength, path, pathLength);
        totalLength += pathLength;

        result[totalLength] = '\0';
    }

    return true;
}

void
wasiProcExit(
    void* instance,
    U32 code
) {
    WASI_TRACE(("proc_exit(code=%d)", code));

    exit(code);
}

static const size_t ciovecSize = 8;

U32
wasiFDWrite(
    void* instance,
    U32 wasiFD,
    U32 ciovecsPointer,
    U32 ciovecsCount,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    struct iovec* iovecs = NULL;
    ssize_t total = 0;
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
#if WASM_ENDIAN == WASM_BIG_ENDIAN
    U8* temporaryBuffer = NULL;
#endif

    if (wasiFD > 2) {
        WASI_TRACE((
           "fd_write("
           "wasiFD=%d, "
           "ciovecsPointer=0x%x, "
           "ciovecsCount=%d, "
           "resultPointer=0x%x)",
           wasiFD, ciovecsPointer, ciovecsCount, resultPointer
       ));
    }

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_write: bad FD"));
        return wasiErrnoBadf;
    }

    iovecs = malloc(ciovecsCount * sizeof(struct iovec));
    if (iovecs == NULL) {
        WASI_TRACE(("fd_write: no mem"));
        return wasiErrnoNomem;
    }

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    /* Convert WASI ciovecs to native iovecs */
    {
        U32 ciovecIndex = 0;
        for (; ciovecIndex < ciovecsCount; ciovecIndex++) {
            U64 ciovecPointer = ciovecsPointer + ciovecIndex * ciovecSize;
            U32 bufferPointer = i32_load(memory, ciovecPointer);
            U32 length = i32_load(memory, ciovecPointer + 4);

            if (wasiFD > 2) {
                WASI_TRACE((
                    "fd_write: length=%d, bufferPointer=0x%x",
                    length, bufferPointer
                ));
            }

            iovecs[ciovecIndex].iov_base = memory->data + bufferPointer;
            iovecs[ciovecIndex].iov_len = length;
        }
    }
#elif WASM_ENDIAN == WASM_BIG_ENDIAN

    /* Convert WASI ciovecs to native iovecs */
    {
        U8* memoryStart = memory->data + memory->size - 1;

        U32 totalLength = 0;
        U32 ciovecIndex = 0;
        for (; ciovecIndex < ciovecsCount; ciovecIndex++) {
            U64 ciovecPointer = ciovecsPointer + ciovecIndex * ciovecSize;
            U32 length = i32_load(memory, ciovecPointer + 4);
            iovecs[ciovecIndex].iov_len = length;
            totalLength += length;
        }

        temporaryBuffer = malloc(totalLength);
        if (temporaryBuffer == NULL) {
            return wasiErrnoNomem;
        }

        totalLength = 0;
        ciovecIndex = 0;
        for (; ciovecIndex < ciovecsCount; ciovecIndex++) {
            U64 ciovecPointer = ciovecsPointer + ciovecIndex * ciovecSize;
            U32 bufferPointer = i32_load(memory, ciovecPointer);
            U32 length = iovecs[ciovecIndex].iov_len;
            U8* bufferStart = memoryStart - bufferPointer;
            U32 i = 0;
            for (; i < length; i++) {
                temporaryBuffer[totalLength + i] = bufferStart[-i];
            }

            iovecs[ciovecIndex].iov_base = temporaryBuffer + totalLength;

            totalLength += length;
            if (wasiFD > 2) {
                WASI_TRACE((
                    "fd_write: length=%d, bufferPointer=0x%x",
                    length, bufferPointer
                ));
            }
        }
    }
#endif

    /* Perform the writes */
    total = writev(descriptor.fd, iovecs, ciovecsCount);

    free(iovecs);

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    free(temporaryBuffer);
#endif

    if (total < 0) {
        WASI_TRACE(("fd_write: writev failed: %s", strerror(errno)));
        return wasiErrno();
    }

    /* Store the amount of written bytes at the result pointer */
    i32_store(memory, resultPointer, total);

    return wasiErrnoSuccess;
}

static const size_t iovecSize = 8;

static
U32
fdReadImpl(
    wasmMemory* memory,
    ssize_t readFunc(int, const struct iovec*, int, off_t),
    U32 wasiFD,
    U32 iovecsPointer,
    U32 iovecsCount,
    U32 resultPointer,
    off_t offset
) {
    struct iovec* iovecs = NULL;
    ssize_t total = 0;
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "fd_[p]read("
        "wasiFD=%d, "
        "iovecsPointer=0x%x, "
        "iovecsCount=%d, "
        "resultPointer=0x%x, "
        "offset=%lld)",
        wasiFD,
        iovecsPointer,
        iovecsCount,
        resultPointer,
        offset
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_[p]read: bad FD"));
        return wasiErrnoBadf;
    }

    iovecs = malloc(iovecsCount * sizeof(struct iovec));
    if (iovecs == NULL) {
        WASI_TRACE(("fd_[p]read: no mem"));
        return wasiErrnoNomem;
    }

    /* Convert WASI iovecs to native iovecs */
    {
#if WASM_ENDIAN == WASM_BIG_ENDIAN
        U8* memoryStart = memory->data + memory->size;
#endif
        U32 iovecIndex = 0;
        for (; iovecIndex < iovecsCount; iovecIndex++) {
            U64 iovecPointer = iovecsPointer + iovecIndex * iovecSize;
            U32 bufferPointer = i32_load(memory, iovecPointer);
            U32 length = i32_load(memory, iovecPointer + 4);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
            iovecs[iovecIndex].iov_base = memory->data + bufferPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
            iovecs[iovecIndex].iov_base = memoryStart - bufferPointer - length;
#endif
            iovecs[iovecIndex].iov_len = length;
        }
    }

    /* Perform the reads */
    total = readFunc(descriptor.fd, iovecs, (int)iovecsCount, offset);

    if (total < 0) {
        free(iovecs);

        WASI_TRACE(("fd_[p]read: read failed: %s", strerror(errno)));
        return wasiErrno();
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    {
        U32 iovecIndex = 0;
        for (; iovecIndex < iovecsCount; iovecIndex++) {
            U8* base = iovecs[iovecIndex].iov_base;
            U32 length = iovecs[iovecIndex].iov_len;
            int i = 0;
            for (; i < length / 2; i++) {
                U8 value = base[i];
                base[i] = base[length - i - 1];
                base[length - i - 1] = value;
            }
        }
    }
#endif

    free(iovecs);

    /* Store the amount of read bytes at the result pointer */
    i32_store(memory, resultPointer, total);

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

U32
wasiFDRead(
    void* instance,
    U32 wasiFD,
    U32 iovecsPointer,
    U32 iovecsCount,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);
    /* NOTE: offset -1 is ignored by readvWrapper */
    const int offset = -1;
    return fdReadImpl(
        memory,
        readvWrapper,
        wasiFD,
        iovecsPointer,
        iovecsCount,
        resultPointer,
        offset
    );
}

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
    ssize_t res = 0;
    int currentErrno = 0;

    off_t origLoc = lseek(fd, 0, SEEK_CUR);
    if (origLoc == (off_t)-1) {
        return -1;
    }
    if (lseek(fd, offset, SEEK_SET) == (off_t)-1) {
        return -1;
    }

    res = f(fd, iovecs, count);

    currentErrno = errno;
    if (lseek(fd, origLoc, SEEK_SET) == (off_t)-1) {
        if (res == -1) {
            errno = currentErrno;
        }
        return -1;
    }
    errno = currentErrno;

    return res;
}

static
ssize_t
preadvFallback(
    int fd,
    const struct iovec* iovecs,
    int count,
    off_t offset
) {
    return wrapPositional(readv, fd, iovecs, count, offset);
}

U32
wasiFDPread(
    void* instance,
    U32 wasiFD,
    U32 iovecsPointer,
    U32 iovecsCount,
    U32 offset,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);
    return fdReadImpl(
        memory,
        preadvFallback,
        wasiFD,
        iovecsPointer,
        iovecsCount,
        resultPointer,
        offset
    );
}

U32
wasiEnvironSizesGet(
    void* instance,
    U32 envcPointer,
    U32 envpBufSizePointer
) {
    wasmMemory* memory = wasiMemory(instance);

    int envpIndex = 0;
    size_t envpBufSize = 0;

    WASI_TRACE((
        "environ_sizes_get(envcPointer=0x%x, envpBufSizePointer=0x%x)",
        envcPointer, envpBufSizePointer
    ));

    while (wasi.envp[envpIndex] != NULL) {
        envpBufSize += strlen(wasi.envp[envpIndex]) + 1;
        envpIndex++;
    }

    i32_store(memory, envcPointer, wasi.envc);
    i32_store(memory, envpBufSizePointer, envpBufSize);

    return wasiErrnoSuccess;
}

U32
wasiEnvironGet(
    void* instance,
    U32 envpPointer,
    U32 envpBufPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    U32 index = 0;
#if WASM_ENDIAN == WASM_BIG_ENDIAN
    U8* memoryStart = memory->data + memory->size - 1;
#endif

    WASI_TRACE((
        "environ_get(envpPointer=0x%x, envpBufPointer=0x%x)",
        envpPointer, envpBufPointer
    ));

    for (; wasi.envp[index] != NULL; index++) {
        char* env = wasi.envp[index];
        size_t length = strlen(env) + 1;
#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
        memcpy(
            memory->data + envpBufPointer,
            env,
            length
        );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
        U32 i = 0;
        for (; i < length; i++) {
           memoryStart[-envpBufPointer-i] = env[i];
        }
#endif
        i32_store(
            memory,
            envpPointer + index * sizeof(U32),
            envpBufPointer
        );
        envpBufPointer += length;
    }

    return wasiErrnoSuccess;
}

U32
wasiArgsSizesGet(
    void* instance,
    U32 argcPointer,
    U32 argvBufSizePointer
) {
    wasmMemory* memory = wasiMemory(instance);

    size_t argvBufSize = 0;
    U32 argvIndex = 0;

    WASI_TRACE((
        "args_sizes_get(argcPointer=0x%x, argvBufSizePointer=0x%x)",
        argcPointer, argvBufSizePointer
    ));

    for (; argvIndex < wasi.argc; argvIndex++) {
        argvBufSize += strlen(wasi.argv[argvIndex]) + 1;
    }

    i32_store(memory, argcPointer, wasi.argc);
    i32_store(memory, argvBufSizePointer, argvBufSize);

    return wasiErrnoSuccess;
}

U32
wasiArgsGet(
    void* instance,
    U32 argvPointer,
    U32 argvBufPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    U32 index = 0;
#if WASM_ENDIAN == WASM_BIG_ENDIAN
    U8* memoryStart = memory->data + memory->size - 1;
#endif

    WASI_TRACE((
        "args_get(argvPointer=0x%x, argvBufPointer=0x%x)",
        argvPointer, argvBufPointer
    ));

    for (; index < wasi.argc; index++) {
        char* arg = wasi.argv[index];
        size_t length = strlen(arg) + 1;
#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
        memcpy(
            memory->data + argvBufPointer,
            arg,
            length
        );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
        U32 i = 0;
        for (; i < length; i++) {
            memoryStart[-argvBufPointer-i] = arg[i];
        }
#endif
        i32_store(
            memory,
            argvPointer + index * sizeof(U32),
            argvBufPointer
        );
        argvBufPointer += length;
    }

    return wasiErrnoSuccess;
}

static
U32
fdSeekImpl(
    wasmMemory* memory,
    U32 wasiFD,
    U64 offset,
    int nativeWhence,
    U32 resultPointer
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    off_t result = 0;

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_seek: bad FD"));
        return wasiErrnoBadf;
    }

    result = lseek(descriptor.fd, (off_t)offset, nativeWhence);
    if (result == (off_t)-1) {
        WASI_TRACE(("fd_seek: lseek failed: %s", strerror(errno)));
        return wasiErrno();
    }

    i64_store(memory, resultPointer, result);

    return wasiErrnoSuccess;
}

static
__inline__
int
convertPreview1Whence(
    U32 wasiWhence
) {
    /* Oder changed from unstable to preview1: https://github.com/WebAssembly/WASI/pull/106 */
    switch (wasiWhence) {
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

U32
wasiPreview1FDSeek(
    void* instance,
    U32 wasiFD,
    U64 offset,
    U32 whence,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    int nativeWhence = 0;

    WASI_TRACE((
        "fd_seek("
        "wasiFD=%d, "
        "offset=%lld, "
        "whence=%d, "
        "resultPointer=0x%x)",
        wasiFD,
        (off_t)offset,
        whence,
        resultPointer
    ));

    nativeWhence = convertPreview1Whence(whence);
    if (nativeWhence == -1) {
        WASI_TRACE(("fd_seek: invalid whence"));
        return wasiErrnoInval;
    }

    return fdSeekImpl(
        memory,
        wasiFD,
        offset,
        nativeWhence,
        resultPointer
    );
}

static
__inline__
int
convertUnstableWhence(
    U32 wasiWhence
) {
    /* Oder changed from unstable to preview1: https://github.com/WebAssembly/WASI/pull/106 */
    switch (wasiWhence) {
        case 0:
            return SEEK_CUR;
        case 1:
            return SEEK_END;
        case 2:
            return SEEK_SET;
        default:
            return -1;
    }
}

U32
wasiUnstableFDSeek(
    void* instance,
    U32 wasiFD,
    U64 offset,
    U32 whence,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    int nativeWhence = 0;

    WASI_TRACE((
        "fd_seek("
        "wasiFD=%d, "
        "offset=%lld, "
        "whence=%d, "
        "resultPointer=0x%x)",
        wasiFD,
        (off_t)offset,
        whence,
        resultPointer
    ));

    nativeWhence = convertUnstableWhence(whence);
    if (nativeWhence == -1) {
        WASI_TRACE(("fd_seek: invalid whence"));
        return wasiErrnoInval;
    }

    return fdSeekImpl(
        memory,
        wasiFD,
        offset,
        nativeWhence,
        resultPointer
    );
}

U32
wasiFDTell(
    void* instance,
    U32 wasiFD,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    WASI_TRACE((
        "fd_tell(wasiFD=%d, resultPointer=0x%x)",
        wasiFD, resultPointer
    ));

    return fdSeekImpl(
        memory,
        wasiFD,
        0,
        SEEK_CUR,
        resultPointer
    );
}

static
__inline__
WasiFileType
wasiFileTypeFromMode(
    mode_t mode
) {
    switch (mode & S_IFMT) {
        case S_IFBLK:
            return wasiFileTypeBlockDevice;
        case S_IFCHR:
            return wasiFileTypeCharacterDevice;
        case S_IFDIR:
            return wasiFileTypeDirectory;
        case S_IFREG:
            return wasiFileTypeRegularFile;
        case S_IFLNK:
            return wasiFileTypeSymbolicLink;
        default:
            return wasiFileTypeUnknown;
    }
}


#define WASI_DIRENT_SIZE 24

U32
wasiFDReaddir(
    void* instance,
    U32 wasiDirFD,
    U32 bufferPointer,
    U32 bufferLength,
    U64 cookie,
    U32 bufferUsedPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    char* name = NULL;
    struct dirent* entry;
    size_t nameLength = 0;
    WasiFileType fileType = wasiFileTypeUnknown;
    U32 bufferUsed = 0;
    U64 next = 0;
    U64 inode = 0;
    U8 entryData[WASI_DIRENT_SIZE];

    WASI_TRACE((
        "fd_readdir("
        "wasiDirFD=%d, "
        "bufferPointer=0x%x, "
        "bufferLength=%d, "
        "cookie=%lld, "
        "bufferUsedPointer=0x%x)",
        wasiDirFD,
        bufferPointer,
        bufferLength,
        cookie,
        bufferUsedPointer
    ));

    if (!wasiFileDescriptorGet(wasiDirFD, &descriptor)) {
        WASI_TRACE(("fd_readdir: bad FD"));
        return wasiErrnoBadf;
    }

    if (descriptor.dir == NULL) {

        if (cookie != 0) {
            WASI_TRACE(("fd_readdir: invalid cookie at start of readdir: %llu", cookie));
            return wasiErrnoBadf;
        }

        descriptor.dir = opendir(descriptor.path);
        if (descriptor.dir == NULL) {
            WASI_TRACE(("fd_readdir: fdopendir failed: %s", strerror(errno)));
            return wasiErrno();
        }

        if (!wasiDirectorySet(wasiDirFD, descriptor.dir)) {
            WASI_TRACE(("fd_readdir: setting DIR failed"));
            return wasiErrnoBadf;
        }
    } else {
        long current = telldir(descriptor.dir);
        if (current < 0) {
            WASI_TRACE(("fd_readdir: telldir failed: %s", strerror(errno)));
            return wasiErrno();
        }

        if (current != cookie) {
            seekdir(descriptor.dir, (long)cookie);
        }
    }

    while (bufferUsed < bufferLength) {
        size_t bufferRemaining = bufferLength - bufferUsed;
        size_t nextSize = 0;

        WASI_TRACE(("fd_readdir: bufferRemaining=%lu", bufferRemaining));

        errno = 0;
        entry = readdir(descriptor.dir);
        if (entry == NULL) {
            if (errno != 0) {
                WASI_TRACE(("fd_readdir: readdir failed: %s", strerror(errno)));
                return wasiErrno();
            }

            break;
        }

        next = telldir(descriptor.dir);
        inode = entry->d_ino;
        name = entry->d_name;
        nameLength = strlen(name);

        /*
         * Some operating systems don't support d_type.  Linux, Mac and some BSDs do.
         * When available, some file systems always supply an unknown type regardless.
         * Fallback is supplied by lstat in either case.
         */

#if defined (DTTOIF)
        fileType = wasiFileTypeFromMode(DTTOIF(entry->d_type));
#else
        fileType = wasiFileTypeUnknown;
#endif

        if (fileType == wasiFileTypeUnknown) {
            struct stat entryStat;

            if (lstat(descriptor.path, &entryStat)) {
                WASI_TRACE(("fd_readdir: lstat failed: %s", strerror(errno)));
                return wasiErrno();
            }

            fileType = wasiFileTypeFromMode(entryStat.st_mode);
        }

        WASI_TRACE(("fd_readdir: name=%s, fileType=%d, inode=%llu", name, fileType, inode));

        memset(entryData, 0, WASI_DIRENT_SIZE);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
        memcpy(entryData, &next, sizeof(U64));
        memcpy(entryData + 8, &inode, sizeof(U64));
        memcpy(entryData + 16, &nameLength, sizeof(U32));
        memcpy(entryData + 20, &fileType, sizeof(U8));

        nextSize = WASI_DIRENT_SIZE;
        if (bufferRemaining < nextSize) {
            nextSize = bufferRemaining;
        }
        memcpy(
            memory->data + bufferPointer + bufferUsed,
            entryData,
            nextSize
        );
        bufferUsed += nextSize;

        bufferRemaining = bufferLength - bufferUsed;

        nextSize = nameLength;
        if (bufferRemaining < nextSize) {
            nextSize = bufferRemaining;
        }
        memcpy(
            memory->data + bufferPointer + bufferUsed,
            name,
            nextSize
        );
        bufferUsed += nextSize;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
        memcpy(entryData + WASI_DIRENT_SIZE - sizeof(U64), &next, sizeof(U64));
        memcpy(entryData + WASI_DIRENT_SIZE - 8 - sizeof(U64), &inode, sizeof(U64));
        memcpy(entryData + WASI_DIRENT_SIZE - 16 - sizeof(U32), &nameLength, sizeof(U32));
        memcpy(entryData + WASI_DIRENT_SIZE - 20 - sizeof(U8), &fileType, sizeof(U8));

        if (bufferRemaining < WASI_DIRENT_SIZE) {
            U32 index = 0;
            U8* base = memory->data + memory->size - bufferPointer - bufferUsed - 1;
            for (; index < bufferRemaining; index++) {
                base[-index] = entryData[-index];
            }
            bufferUsed += bufferRemaining;
        } else {
            memcpy(
                memory->data + memory->size - bufferPointer - bufferUsed - WASI_DIRENT_SIZE,
                entryData,
                WASI_DIRENT_SIZE
            );
            bufferUsed += WASI_DIRENT_SIZE;
        }

        bufferRemaining = bufferLength - bufferUsed;

        {
            U32 index = 0;
            U8* base = memory->data + memory->size - bufferPointer - bufferUsed - 1;

            nextSize = nameLength;
            if (bufferRemaining < nextSize) {
                nextSize = bufferRemaining;
            }

            for (; index < nextSize; index++) {
                base[-index] = name[index];
            }
            bufferUsed += nextSize;
        }
#endif
    }

    i64_store(
        memory,
        bufferUsedPointer,
        bufferUsed
    );

    return wasiErrnoSuccess;
}

U32
wasiFDClose(
    void* instance,
    U32 wasiFD
) {
    WASI_TRACE(("fd_close(wasiFD=%d)", wasiFD));

    if (!wasiFileDescriptorClose(wasiFD)) {
        WASI_TRACE(("fd_close: bad FD"));
        return wasiErrnoBadf;
    }
    return wasiErrnoSuccess;
}

#define NSEC_PER_SEC 1000000000LL
#define NSEC_PER_USEC 1000LL

static
__inline__
I64
convertTimespec(
    struct timespec t
) {
#ifdef _NEXT_SOURCE
    return t.ts_sec * NSEC_PER_SEC
           + t.ts_nsec;
#else
    return t.tv_sec * NSEC_PER_SEC
           + t.tv_nsec;
#endif
}

static
__inline__
I64
convertTimeval(
    struct timeval t
) {
    return t.tv_sec * NSEC_PER_SEC
           + t.tv_usec * NSEC_PER_USEC;
}

static
__inline__
void
addTimevals(
    struct timeval* tvp,
    struct timeval* uvp,
    struct timeval* vvp
) {
    (vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;
    (vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;
    if ((vvp)->tv_usec >= 1000000) {
        (vvp)->tv_sec++;
        (vvp)->tv_usec -= 1000000;
    }
}

U32
wasiClockTimeGet(
    void* instance,
    U32 clockID,
    U64 precision,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    I64 result = 0;

    WASI_TRACE((
        "clock_time_get(clockID=%d, precision=%lld, resultPointer=0x%x)",
        clockID, precision, resultPointer
    ));

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0) && !defined(WASI_FALLBACK_TIMERS_ENABLED)

    {
        struct timespec timespec;
        clockid_t nativeClockID;


        switch (clockID) {
            case wasiClockRealtime: {
                nativeClockID = CLOCK_REALTIME;
                break;
            }
#ifdef _POSIX_MONOTONIC_CLOCK
            case wasiClockMonotonic: {
                nativeClockID = CLOCK_MONOTONIC;
                break;
            }
#endif
#ifdef _POSIX_CPUTIME
            case wasiClockProcessCputimeId: {
                nativeClockID = CLOCK_PROCESS_CPUTIME_ID;
                break;
            }
#endif
#ifdef _POSIX_THREAD_CPUTIME
            case wasiClockThreadCputimeId: {
                nativeClockID = CLOCK_THREAD_CPUTIME_ID;
                break;
            }
#endif
            default: {
                WASI_TRACE(("clock_time_get: invalid clock ID"));
                return wasiErrnoInval;
            }
        }

        if (clock_gettime(nativeClockID, &timespec) != 0) {
            WASI_TRACE(("clock_time_get: clock_gettime failed: %s", strerror(errno)));
            return wasiErrno();
        }

        WASI_TRACE(("clock_time_get: clock_gettime: %d %d", timespec.tv_sec, timespec.tv_nsec));

        result = convertTimespec(timespec);
    }
#else
    switch (clockID) {
        case wasiClockRealtime: {
            struct timeval tv;
            if (gettimeofday(&tv, NULL) != 0) {
                WASI_TRACE(("clock_time_get: gettimeofday failed: %s", strerror(errno)));
                return wasiErrno();
            }
            result = convertTimeval(tv);
            break;
        }
#ifdef __MACH__
        case wasiClockMonotonic: {
#include <mach/mach_time.h>
            static mach_timebase_info_data_t timebase = {0, 0};

            if (!timebase.denom && mach_timebase_info(&timebase) != KERN_SUCCESS) {
                WASI_TRACE(("clock_time_get: mach_timebase_info failed"));
                return wasiErrnoInval;
            }

            result = mach_absolute_time() * timebase.numer / timebase.denom;
            break;
        }
#endif
        case wasiClockProcessCputimeId: {
            struct rusage ru;
            WASI_TRACE(("clock_time_get: getrusage(RUSAGE_SELF)"));
            int ret = getrusage(RUSAGE_SELF, &ru);
            if (ret != 0) {
                WASI_TRACE(("clock_time_get: getrusage failed: %s", strerror(errno)));
                return wasiErrno();
            }
            addTimevals(&ru.ru_utime, &ru.ru_stime, &ru.ru_utime);
            result = convertTimeval(ru.ru_utime);
            break;
        }
        default: {
            WASI_TRACE(("clock_time_get: invalid clock ID"));
            return wasiErrnoInval;
        }
    }
#endif

    WASI_TRACE(("clock_time_get: result=%lld", result));

    i64_store(
        memory,
        resultPointer,
        result
    );

    return wasiErrnoSuccess;
}

U32
wasiClockResGet(
    void* instance,
    U32 clockID,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    I64 result = 0;

    WASI_TRACE((
        "clock_res_get(clockID=%d, resultPointer=0x%x)",
        clockID, resultPointer
    ));

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0) && !defined(WASI_FALLBACK_TIMERS_ENABLED)

    {
        struct timespec timespec;
        clockid_t nativeClockID;


        switch (clockID) {
            case wasiClockRealtime: {
                nativeClockID = CLOCK_REALTIME;
                break;
            }
#ifdef _POSIX_MONOTONIC_CLOCK
            case wasiClockMonotonic: {
                nativeClockID = CLOCK_MONOTONIC;
                break;
            }
#endif
#ifdef _POSIX_CPUTIME
            case wasiClockProcessCputimeId: {
                nativeClockID = CLOCK_PROCESS_CPUTIME_ID;
                break;
            }
#endif
#ifdef _POSIX_THREAD_CPUTIME
            case wasiClockThreadCputimeId: {
                nativeClockID = CLOCK_THREAD_CPUTIME_ID;
                break;
            }
#endif
            default: {
                WASI_TRACE(("clock_res_get: invalid clock ID"));
                return wasiErrnoInval;
            }
        }

        if (clock_getres(nativeClockID, &timespec) != 0) {
            WASI_TRACE(("clock_res_get: clock_gettime failed: %s", strerror(errno)));
            return wasiErrno();
        }

        WASI_TRACE(("clock_res_get: clock_getres: %d %d", timespec.tv_sec, timespec.tv_nsec));

        result = convertTimespec(timespec);
    }
#else
    switch (clockID) {
        case wasiClockRealtime: {
            result = 1000000;
            break;
        }
        case wasiClockMonotonic:
        case wasiClockProcessCputimeId:
        case wasiClockThreadCputimeId: {
            result = 1000;
            break;
        }
        default: {
            WASI_TRACE(("clock_res_get: invalid clock ID"));
            return wasiErrnoInval;
        }
    }
#endif

    WASI_TRACE(("clock_res_get: result=%lld", result));

    i64_store(
        memory,
        resultPointer,
        result
    );

    return wasiErrnoSuccess;
}

static const size_t wasiFdstatSize = 24;

U32
wasiFdFdstatGet(
    void* instance,
    U32 wasiFD,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    WasiFileType fileType = wasiFileTypeUnknown;
    U16 wasiFlags = 0;
    struct stat stat;
    int nativeFlags = 0;
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    WasiRights baseRights = 0;
    WasiRights inheritingRights = 0;

    WASI_TRACE((
        "fd_fdstat_get(wasiFD=%d, resultPointer=0x%x)",
        wasiFD, resultPointer
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_fdstat_get: bad FD"));
        return wasiErrnoBadf;
    }

    /* Get fileType */
    if (fstat(descriptor.fd, &stat) != 0) {
        WASI_TRACE(("fd_fdstat_get: fstat failed: %s", strerror(errno)));
        return wasiErrno();
    }
    fileType = wasiFileTypeFromMode(stat.st_mode);

    switch (fileType) {
        case wasiFileTypeCharacterDevice: {
            if (isatty(descriptor.fd)) {
                baseRights = wasiRightsTTYBase;
                inheritingRights = wasiRightsTTYInheriting;
            } else {
                baseRights = wasiRightsAll;
                inheritingRights = wasiRightsAll;
            }
            break;
        }
        case wasiFileTypeDirectory: {
            baseRights = wasiRightsDirectoryBase;
            inheritingRights = wasiRightsDirectoryInheriting;
            break;
        }
        case wasiFileTypeRegularFile: {
            baseRights = wasiRightsRegularFileBase;
            inheritingRights = wasiRightsRegularFileInheriting;
            break;
        }
        default: {
            baseRights = wasiRightsAll;
            inheritingRights = wasiRightsAll;
            break;
        }
    }

    /* Get flags */
    nativeFlags = fcntl(descriptor.fd, F_GETFL);
    if (nativeFlags < 0) {
        WASI_TRACE(("fd_fdstat_get: fcntl failed: %s", strerror(errno)));
        return wasiErrno();
    }

    if (nativeFlags & O_APPEND) {
        wasiFlags |= wasiFdflagsAppend;
    }
    if (nativeFlags & O_DSYNC) {
        wasiFlags |= wasiFdflagsDsync;
    }
    if (nativeFlags & O_NONBLOCK) {
        wasiFlags |= wasiFdflagsNonblock;
    }
#ifdef O_SYNC
    if (nativeFlags & O_SYNC) {
        wasiFlags |= wasiFdflagsRsync | wasiFdflagsSync;
    }
#endif

    /* Store result */
#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    memset(
        memory->data + resultPointer,
        0,
        wasiFdstatSize
    );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    memset(
        memory->data + memory->size - resultPointer - wasiFdstatSize,
        0,
        wasiFdstatSize
    );
#endif

    i32_store8(memory, resultPointer, fileType);
    i32_store16(memory, resultPointer + 2, wasiFlags);
    i64_store(memory, resultPointer + 8, baseRights);
    i64_store(memory, resultPointer + 16, inheritingRights);

    return wasiErrnoSuccess;
}

U32
wasiFDPrestatGet(
    void* instance,
    U32 wasiFD,
    U32 prestatPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    WasiPreopen preopen = wasiEmptyPreopen;
    U32 length = 0;

    WASI_TRACE((
        "fd_prestat_get(wasiFD=%d, prestatPointer=0x%x)",
        wasiFD, prestatPointer
    ));

    if (!wasiPreopenGet(wasiFD, &preopen)) {
        WASI_TRACE(("fd_prestat_get: bad FD"));
        return wasiErrnoBadf;
    }

    length = strlen(preopen.path) + 1;
    i32_store(memory, prestatPointer, wasiPreopentypeDirectory);
    i32_store(memory, prestatPointer + 4, length);

    return wasiErrnoSuccess;
}

U32
wasiFdPrestatDirName(
    void* instance,
    U32 wasiFD,
    U32 pathPointer,
    U32 pathLength
) {
    wasmMemory* memory = wasiMemory(instance);

    WasiPreopen preopen = wasiEmptyPreopen;
    size_t length = 0;

    WASI_TRACE((
        "fd_prestat_dir_name(wasiFD=%d, pathPointer=0x%x, pathLength=%d)",
        wasiFD, pathPointer, pathLength
    ));

    if (!wasiPreopenGet(wasiFD, &preopen)) {
        WASI_TRACE(("fd_prestat_dir_name: bad FD"));
        return wasiErrnoBadf;
    }

    length = strlen(preopen.path) + 1;
    if (length >= pathLength) {
        length = pathLength;
    }

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    memcpy(
        memory->data + pathPointer,
        preopen.path,
        length
    );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    {
        U8* base = memory->data + memory->size - 1 - pathPointer;

        U32 i = 0;
        for (; i < length; i++) {
            base[-i] = preopen.path[i];
        }
    }
#endif

    return wasiErrnoSuccess;
}

static
__inline__
bool
getBigEndianPath(
    wasmMemory* memory,
    U32 pathPointer,
    U32 pathLength,
    char path[PATH_MAX]
) {
    char* base = (char*) memory->data + memory->size - 1 - pathPointer;
    U32 i = 0;

    MUST (pathLength <= PATH_MAX)

    for (; i < pathLength; i++) {
        path[i] = base[-i];
    }

    path[pathLength] = '\0';

    return true;
}

U32
wasiPathOpen(
    void* instance,
    U32 wasiDirFD,
    U32 dirFlags,
    U32 pathPointer,
    U32 pathLength,
    U32 oflags,
    U64 fsRightsBase,
    U64 fsRightsInheriting,
    U32 fdFlags,
    U32 fdPointer
) {
    wasmMemory* memory = wasiMemory(instance);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    char* path = (char*) memory->data + pathPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    char path[PATH_MAX];
#endif
    char resolvedPath[PATH_MAX];
    int nativeFlags = 0;
    static const int mode = 0644;
    int nativeFD = -1;
    WasiPreopen preopen = wasiEmptyPreopen;
    U32 wasiFD = 0;

    WASI_TRACE((
        "path_open("
        "wasiDirFD=%d, "
        "dirFlags=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d, "
        "oflags=%d, "
        "fsRightsBase=%llu, "
        "fsRightsInheriting=%llu, "
        "fdFlags=%d, "
        "fdPointer=0x%x)",
        wasiDirFD,
        dirFlags,
        pathPointer,
        pathLength,
        oflags,
        fsRightsBase,
        fsRightsInheriting,
        fdFlags,
        fdPointer
    ));

    if (!wasiPreopenGet(wasiDirFD, &preopen)) {
        WASI_TRACE(("path_open: bad FD"));
        return wasiErrnoBadf;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_open: bad path"));
        return wasiErrnoInval;
    }
#endif

    WASI_TRACE(("path_open: path=%.*s", pathLength, path));

    if (!resolvePath(preopen.path, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_open: path resolution failed"));
        return wasiErrnoInval;
    }

    WASI_TRACE(("path_open: resolvedPath=%s", resolvedPath));

    /* Convert WASI oflags to native flags */
    if (oflags & wasiOflagsCreat) {
        nativeFlags |= O_CREAT;
    }
#if defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200809L)
    if (oflags & wasiOflagsDirectory) {
        nativeFlags |= O_DIRECTORY;
    }
#endif
    if (oflags & wasiOflagsExcl) {
        nativeFlags |= O_EXCL;
    }
    if (oflags & wasiOflagsTrunc) {
        nativeFlags |= O_TRUNC;
    }

    /* Convert WASI fdFlags to native flags */
    if (fdFlags & wasiFdflagsAppend) {
        nativeFlags |= O_APPEND;
    }
    if (fdFlags & wasiFdflagsDsync) {
        nativeFlags |= O_DSYNC;
    }
    if (fdFlags & wasiFdflagsNonblock) {
        nativeFlags |= O_NONBLOCK;
    }
#ifdef O_SYNC
    if (fdFlags & wasiFdflagsSync) {
        nativeFlags |= O_SYNC;
    }
#endif
    /* wasiFdflagsRsync is ignored, as O_RSYNC is often not implemented */

    /* Convert WASI fsRightsBase to native flags */
    if ((fsRightsBase & wasiRightsFdRead)
        && (fsRightsBase & wasiRightsFdWrite))
    {
        nativeFlags |= O_RDWR;
    } else if (fsRightsBase & wasiRightsFdWrite) {
        nativeFlags |= O_WRONLY;
    } else if (fsRightsBase & wasiRightsFdRead) {
        nativeFlags |= O_RDONLY;
    }

    /* Open the file */
    nativeFD = open(resolvedPath, nativeFlags, mode);

    if (nativeFD < 0) {
        WASI_TRACE(("path_open: open failed: %s", strerror(errno)));
        return wasiErrno();
    }

    WASI_TRACE(("path_open: nativeFD=%d", nativeFD));

    /* Register the WASI file descriptor */
    if (!wasiFileDescriptorAdd(nativeFD, &wasiFD, resolvedPath)) {
        WASI_TRACE(("path_open: adding FD failed"));
        return wasiErrnoBadf;
    }

    WASI_TRACE(("path_open: wasiFD=%d", wasiFD));

    /* Store the file descriptor at the result pointer */
    i32_store(memory, fdPointer, wasiFD);

    return wasiErrnoSuccess;
}

static
__inline__
void
getStatTimes(
    struct stat* stat,
    struct timespec* access,
    struct timespec* modification,
    struct timespec* creation
) {
#if (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200809L)) || \
    (defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE >= 700))

    access->tv_sec = stat->st_atim.tv_sec;
    access->tv_nsec = stat->st_atim.tv_nsec;
    modification->tv_sec = stat->st_mtim.tv_sec;
    modification->tv_nsec = stat->st_mtim.tv_nsec;
    creation->tv_sec = stat->st_ctim.tv_sec;
    creation->tv_nsec = stat->st_ctim.tv_nsec;
#elif defined(_NEXT_SOURCE)
    access->ts_sec = stat->st_atime;
    access->ts_nsec = 0;
    modification->ts_sec = stat->st_mtime;
    modification->ts_nsec = 0;
    creation->ts_sec = stat->st_ctime;
    creation->ts_nsec = 0;
#else
    access->tv_sec = stat->st_atime;
    access->tv_nsec = 0;
    modification->tv_sec = stat->st_mtime;
    modification->tv_nsec = 0;
    creation->tv_sec = stat->st_ctime;
    creation->tv_nsec = 0;
#endif
}

static const size_t wasiPreview1FilestatSize = 64;

static
__inline__
void
storePreview1Filestat(
    wasmMemory* memory,
    U32 statPointer,
    struct stat* stat
) {
    struct timespec access;
    struct timespec modification;
    struct timespec creation;

    getStatTimes(stat, &access, &modification, &creation);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    memset(
        memory->data + statPointer,
        0,
        wasiPreview1FilestatSize
    );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    memset(
        memory->data + memory->size - statPointer - wasiPreview1FilestatSize,
        0,
        wasiPreview1FilestatSize
    );
#endif

    {
        dev_t dev = stat->st_dev;
        ino_t ino = stat->st_ino;
        WasiFileType wasiFileType = wasiFileTypeFromMode(stat->st_mode);
        nlink_t nlink = stat->st_nlink;
        off_t size = stat->st_size;
        I64 accessTime = convertTimespec(access);
        I64 modificationTime = convertTimespec(modification);
        I64 creationTime = convertTimespec(creation);

        WASI_TRACE((
            "storing preview1 filestat to 0x%x: "
            "dev=%d, "
            "ino=%llu, "
            "wasiFileType=%d, "
            "nlink=%d, "
            "size=%lld, "
            "accessTime=%lld, "
            "modificationTime=%lld, "
            "creationTime=%lld",
            statPointer,
            dev,
            ino,
            wasiFileType,
            nlink,
            size,
            accessTime,
            modificationTime,
            creationTime
        ));

        i64_store(memory, statPointer, dev);
        i64_store(memory, statPointer + 8, ino);
        i32_store8(memory, statPointer + 16, wasiFileType);
        i64_store(memory, statPointer + 24, nlink);
        i64_store(memory, statPointer + 32, size);
        i64_store(memory, statPointer + 40, accessTime);
        i64_store(memory, statPointer + 48, modificationTime);
        i64_store(memory, statPointer + 56, creationTime);
    }
}

static
U32
fdFilestatGetImpl(
    U32 wasiFD,
    struct stat* st
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_filestat_get: bad FD"));
        return wasiErrnoBadf;
    }

    if (fstat(descriptor.fd, st) != 0) {
        WASI_TRACE(("fd_filestat_get: fstat failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return wasiErrnoSuccess;
}

U32
wasiPreview1FDFilestatGet(
    void* instance,
    U32 wasiFD,
    U32 statPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    struct stat stat;
    U32 res = wasiErrnoInval;

    WASI_TRACE((
        "fd_filestat_get(wasiFD=%d, statPointer=0x%x)",
        wasiFD, statPointer
    ));

    res = fdFilestatGetImpl(wasiFD, &stat);
    if (res != wasiErrnoSuccess) {
        return res;
    }

    storePreview1Filestat(memory, statPointer, &stat);

    return wasiErrnoSuccess;
}

static const size_t wasiUnstableFilestatSize = 64;

static
__inline__
void
storeUnstableFilestat(
    wasmMemory* memory,
    U32 statPointer,
    struct stat* stat
) {
    struct timespec access;
    struct timespec modification;
    struct timespec creation;

    getStatTimes(stat, &access, &modification, &creation);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    memset(
        memory->data + statPointer,
        0,
        wasiUnstableFilestatSize
    );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    memset(
        memory->data + memory->size - statPointer - wasiUnstableFilestatSize,
        0,
        wasiUnstableFilestatSize
    );
#endif

    {
        dev_t dev = stat->st_dev;
        ino_t ino = stat->st_ino;
        WasiFileType wasiFileType = wasiFileTypeFromMode(stat->st_mode);
        nlink_t nlink = stat->st_nlink;
        off_t size = stat->st_size;
        I64 accessTime = convertTimespec(access);
        I64 modificationTime = convertTimespec(modification);
        I64 creationTime = convertTimespec(creation);

        WASI_TRACE((
           "storing unstable filestat to 0x%x: "
           "dev=%d, "
           "ino=%llu, "
           "wasiFileType=%d, "
           "nlink=%d, "
           "size=%lld, "
           "accessTime=%lld, "
           "modificationTime=%lld, "
           "creationTime=%lld",
           statPointer,
           dev,
           ino,
           wasiFileType,
           nlink,
           size,
           accessTime,
           modificationTime,
           creationTime
        ));

        i64_store(memory, statPointer, dev);
        i64_store(memory, statPointer + 8, ino);
        i32_store8(memory, statPointer + 16, wasiFileType);
        i32_store(memory, statPointer + 20, nlink);
        i64_store(memory, statPointer + 24, size);
        i64_store(memory, statPointer + 32, accessTime);
        i64_store(memory, statPointer + 40, modificationTime);
        i64_store(memory, statPointer + 48, creationTime);
    }
}

U32
wasiUnstableFDFilestatGet(
    void* instance,
    U32 wasiFD,
    U32 statPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    struct stat stat;
    U32 res = wasiErrnoInval;

    WASI_TRACE((
        "fd_filestat_get(wasiFD=%d, statPointer=0x%x)",
        wasiFD, statPointer
    ));

    res = fdFilestatGetImpl(wasiFD, &stat);

    if (res != wasiErrnoSuccess) {
        return res;
    }

    storeUnstableFilestat(memory, statPointer, &stat);

    return wasiErrnoSuccess;
}

static
U32
pathFilestatGetImpl(
    wasmMemory* memory,
    U32 wasiFD,
    U32 lookupFlags,
    U32 pathPointer,
    U32 pathLength,
    struct stat* st
) {
#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    char* path = (char*) memory->data + pathPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    char path[PATH_MAX];
#endif
    char resolvedPath[PATH_MAX];
    int res = 0;
    WasiPreopen preopen = wasiEmptyPreopen;

    if (!wasiPreopenGet(wasiFD, &preopen)) {
        WASI_TRACE(("path_filestat_get: bad FD"));
        return wasiErrnoBadf;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_filestat_get: bad path"));
        return wasiErrnoInval;
    }
#endif

    WASI_TRACE(("path_filestat_get: path=%.*s", pathLength, path));

    if (!resolvePath(preopen.path, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_filestat_get: path resolution failed"));
        return wasiErrnoInval;
    }

    WASI_TRACE(("path_filestat_get: resolvedPath=%s", resolvedPath));

    /* TODO: use lookupFlags & wasiLookupFlagSymlinkFollow */

    res = stat(resolvedPath, st);

    if (res != 0) {
        WASI_TRACE(("path_filestat_get: stat failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return wasiErrnoSuccess;
}

U32
wasiPreview1PathFilestatGet(
    void* instance,
    U32 dirFD,
    U32 lookupFlags,
    U32 pathPointer,
    U32 pathLength,
    U32 statPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    struct stat stat;
    U32 res = wasiErrnoInval;

    WASI_TRACE((
        "path_filestat_get("
        "dirFD=%d, "
        "lookupFlags=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d, "
        "statPointer=0x%x)",
        dirFD,
        lookupFlags,
        pathPointer,
        pathLength,
        statPointer
    ));

    res = pathFilestatGetImpl(memory, dirFD, lookupFlags, pathPointer, pathLength, &stat);
    if (res != wasiErrnoSuccess) {
        return res;
    }

    storePreview1Filestat(memory, statPointer, &stat);

    return wasiErrnoSuccess;
}

U32
wasiUnstablePathFilestatGet(
    void* instance,
    U32 dirFD,
    U32 lookupFlags,
    U32 pathPointer,
    U32 pathLength,
    U32 statPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    struct stat stat;
    U32 res = wasiErrnoInval;

    WASI_TRACE((
        "path_filestat_get("
        "dirFD=%d, "
        "lookupFlags=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d, "
        "statPointer=0x%x)",
        dirFD,
        lookupFlags,
        pathPointer,
        pathLength,
        statPointer
    ));

    res = pathFilestatGetImpl(memory, dirFD, lookupFlags, pathPointer, pathLength, &stat);
    if (res != wasiErrnoSuccess) {
        return res;
    }

    storeUnstableFilestat(memory, statPointer, &stat);

    return wasiErrnoSuccess;
}

U32
wasiPathRename(
    void* instance,
    U32 oldDirFD,
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 newDirFD,
    U32 newPathPointer,
    U32 newPathLength
) {
    wasmMemory* memory = wasiMemory(instance);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    char* oldPath = (char*) memory->data + oldPathPointer;
    char* newPath = (char*) memory->data + newPathPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    char oldPath[PATH_MAX];
    char newPath[PATH_MAX];
#endif
    char oldResolvedPath[PATH_MAX];
    char newResolvedPath[PATH_MAX];
    int res = -1;
    WasiPreopen oldPreopen = wasiEmptyPreopen;
    WasiPreopen newPreopen = wasiEmptyPreopen;

    WASI_TRACE((
        "path_rename("
        "oldDirFD=%d, "
        "oldPathPointer=0x%x, "
        "oldPathLength=%d, "
        "newDirFD=%d, "
        "newPathPointer=0x%x, "
        "newPathLength=%d)",
        oldDirFD,
        oldPathPointer,
        oldPathLength,
        newDirFD,
        newPathPointer,
        newPathLength
    ));

    if (!wasiPreopenGet(oldDirFD, &oldPreopen)) {
        WASI_TRACE(("path_rename: bad old fd"));
        return wasiErrnoBadf;
    }

    if (!wasiPreopenGet(newDirFD, &newPreopen)) {
        WASI_TRACE(("path_rename: bad new fd"));
        return wasiErrnoBadf;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, oldPathPointer, oldPathLength, oldPath)) {
        WASI_TRACE(("path_rename: bad old path"));
        return wasiErrnoInval;
    }

    if (!getBigEndianPath(memory, newPathPointer, newPathLength, newPath)) {
        WASI_TRACE(("path_rename: bad new path"));
        return wasiErrnoInval;
    }
#endif

    WASI_TRACE(("path_rename: oldPath=%.*s, newPath=%.*s", oldPathLength, oldPath, newPathLength, newPath));

    if (!resolvePath(oldPreopen.path, oldPath, oldPathLength, oldResolvedPath)) {
        WASI_TRACE(("path_rename: old path resolution failed"));
        return wasiErrnoInval;
    }

    if (!resolvePath(newPreopen.path, newPath, newPathLength, newResolvedPath)) {
        WASI_TRACE(("path_rename: new path resolution failed"));
        return wasiErrnoInval;
    }

    WASI_TRACE(("path_rename: oldResolvedPath=%s, newResolvedPath=%s", oldResolvedPath, newResolvedPath));

    res = rename(oldResolvedPath, newResolvedPath);

    if (res != 0) {
        WASI_TRACE(("path_rename: rename failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return wasiErrnoSuccess;
}

U32
wasiPathUnlinkFile(
    void* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength
) {
    wasmMemory* memory = wasiMemory(instance);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    char* path = (char*) memory->data + pathPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    char path[PATH_MAX];
#endif
    char resolvedPath[PATH_MAX];
    int res = -1;
    WasiPreopen preopen = wasiEmptyPreopen;

    WASI_TRACE((
        "path_unlink_file(dirFD=%d, pathPointer=0x%x, pathLength=%d)",
        dirFD, pathPointer, pathLength
    ));

    if (!wasiPreopenGet(dirFD, &preopen)) {
        WASI_TRACE(("path_unlink_file: bad FD"));
        return wasiErrnoBadf;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_unlink_file: bad path"));
        return wasiErrnoInval;
    }
#endif

    WASI_TRACE(("path_unlink_file: path=%.*s", pathLength, path));

    if (!resolvePath(preopen.path, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_unlink_file: path resolution failed"));
        return wasiErrnoInval;
    }

    WASI_TRACE(("path_unlink_file: resolvedPath=%s", resolvedPath));

    res = unlink(resolvedPath);

    if (res != 0) {
        WASI_TRACE(("path_unlink_file: unlink failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return wasiErrnoSuccess;
}

U32
wasiPathRemoveDirectory(
    void* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength
) {
    wasmMemory* memory = wasiMemory(instance);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    char* path = (char*) memory->data + pathPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    char path[PATH_MAX];
#endif
    char resolvedPath[PATH_MAX];
    int res = -1;
    WasiPreopen preopen = wasiEmptyPreopen;

    WASI_TRACE((
        "path_remove_directory(dirFD=%d, pathPointer=0x%x, pathLength=%d)",
        dirFD, pathPointer, pathLength
    ));

    if (!wasiPreopenGet(dirFD, &preopen)) {
        WASI_TRACE(("path_remove_directory: bad FD"));
        return wasiErrnoBadf;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_remove_directory: bad path"));
        return wasiErrnoInval;
    }
#endif

    WASI_TRACE(("path_remove_directory: path=%.*s", pathLength, path));

    if (!resolvePath(preopen.path, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_remove_directory: path resolution failed"));
        return wasiErrnoInval;
    }

    WASI_TRACE(("path_remove_directory: resolvedPath=%s", resolvedPath));

    res = rmdir(resolvedPath);

    if (res != 0) {
        WASI_TRACE(("path_remove_directory: rmdir failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return wasiErrnoSuccess;
}

U32
wasiPathCreateDirectory(
    void* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength
) {
    wasmMemory* memory = wasiMemory(instance);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    char* path = (char*) memory->data + pathPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    char path[PATH_MAX];
#endif
    char resolvedPath[PATH_MAX];
    static const mode_t mode = 0755;
    int res = -1;
    WasiPreopen preopen = wasiEmptyPreopen;

    WASI_TRACE((
        "path_create_directory(dirFD=%d, pathPointer=0x%x, pathLength=%d)",
        dirFD, pathPointer, pathLength
    ));

    if (!wasiPreopenGet(dirFD, &preopen)) {
        WASI_TRACE(("path_create_directory: bad FD"));
        return wasiErrnoBadf;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_create_directory: bad path"));
        return wasiErrnoInval;
    }
#endif

    WASI_TRACE(("path_create_directory: path=%.*s", pathLength, path));

    if (!resolvePath(preopen.path, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_create_directory: path resolution failed"));
        return wasiErrnoInval;
    }

    WASI_TRACE(("path_create_directory: resolvedPath=%s", resolvedPath));

    res = mkdir(resolvedPath, mode);

    if (res != 0) {
        WASI_TRACE(("path_create_directory: mkdir failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return wasiErrnoSuccess;
}

U32
wasiPathSymlink(
    void* instance,
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 dirFD,
    U32 newPathPointer,
    U32 newPathLength
) {
    wasmMemory* memory = wasiMemory(instance);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    char* newPath = (char*) memory->data + newPathPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    char newPath[PATH_MAX];
#endif
    char oldResolvedPath[PATH_MAX];
    char newResolvedPath[PATH_MAX];
    int res = -1;
    WasiPreopen preopen = wasiEmptyPreopen;

    WASI_TRACE((
        "path_symlink("
        "oldPathPointer=0x%x, "
        "oldPathLength=%d, "
        "dirFD=%d, "
        "newPathPointer=0x%x, "
        "newPathLength=%d)",
        oldPathPointer,
        oldPathLength,
        dirFD,
        newPathPointer,
        newPathLength
    ));

    if (!wasiPreopenGet(dirFD, &preopen)) {
        WASI_TRACE(("path_symlink: bad FD"));
        return wasiErrnoBadf;
    }

    if (oldPathLength >= PATH_MAX) {
        WASI_TRACE(("path_symlink: old path too long"));
        return wasiErrnoInval;
    }

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    memcpy(oldResolvedPath, memory->data + oldPathPointer, oldPathLength);
    oldResolvedPath[oldPathLength] = '\0';

#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, oldPathPointer, oldPathLength, oldResolvedPath)) {
        WASI_TRACE(("path_symlink: bad old path"));
        return wasiErrnoInval;
    }

    if (!getBigEndianPath(memory, newPathPointer, newPathLength, newPath)) {
        WASI_TRACE(("path_symlink: bad new path"));
        return wasiErrnoInval;
    }
#endif

    WASI_TRACE(("path_symlink: oldResolvedPath=%s, newPath=%.*s", oldResolvedPath, newPathLength, newPath));

    if (!resolvePath(preopen.path, newPath, newPathLength, newResolvedPath)) {
        WASI_TRACE(("path_symlink: new path resolution failed"));
        return wasiErrnoInval;
    }

    WASI_TRACE(("path_symlink: newResolvedPath=%s", newResolvedPath));

    res = symlink(oldResolvedPath, newResolvedPath);

    if (res != 0) {
        WASI_TRACE(("path_symlink: symlink failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return wasiErrnoSuccess;
}

U32
wasiPathReadlink(
    void* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength,
    U32 bufferPointer,
    U32 bufferLength,
    U32 lengthPointer
) {
    wasmMemory* memory = wasiMemory(instance);

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    char* path = (char*) memory->data + pathPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    char path[PATH_MAX];
#endif
    char resolvedPath[PATH_MAX];
    char* buffer = NULL;
    long length = 0;
    WasiPreopen preopen = wasiEmptyPreopen;

    WASI_TRACE((
        "path_readlink("
        "dirFD=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d, "
        "bufferPointer=0x%x, "
        "bufferLength=%d, "
        "lengthPointer=0x%x)",
        dirFD,
        pathPointer,
        pathLength,
        bufferPointer,
        bufferLength,
        lengthPointer
    ));

    if (!wasiPreopenGet(dirFD, &preopen)) {
        WASI_TRACE(("path_readlink: bad FD"));
        return wasiErrnoBadf;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_readlink: bad path"));
        return wasiErrnoInval;
    }
#endif

    WASI_TRACE(("path_readlink: path=%.*s", pathLength, path));

    if (!resolvePath(preopen.path, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_readlink: path resolution failed"));
        return wasiErrnoInval;
    }

    WASI_TRACE(("path_readlink: resolvedPath=%s", resolvedPath));

    /* TODO: big-endian support */
#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    buffer = (char*)memory->data + bufferPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    buffer = (char*)memory->data + memory->size - bufferPointer - bufferLength;
#endif

    length = readlink(resolvedPath, buffer, bufferLength);

    if (length < 0) {
        WASI_TRACE(("path_readlink: readlink failed: %s", strerror(errno)));
        return wasiErrno();
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    {
        U32 i = 0;
        for (; i < length / 2; i++) {
            U8 value = buffer[i];
            buffer[i] = buffer[length - i - 1];
            buffer[length - i - 1] = value;
        }
    }
#endif

    i32_store(memory, lengthPointer, length);

    return wasiErrnoSuccess;
}

U32
wasiFDFdstatSetFlags(
    void* instance,
    U32 fd,
    U32 flags
) {
    /* TODO: */
    WASI_TRACE(("fd_fdstat_set_flags: unimplemented function"));
    return wasiErrnoNosys;
}

U32
wasiPollOneoff(
    void* instance,
    U32 inPointer,
    U32 outPointer,
    U32 subscriptionCount,
    U32 eventCount
) {
    /* TODO: */
    WASI_TRACE(("poll_oneoff: unimplemented function"));
    return wasiErrnoNosys;
}

U32
wasiRandomGet(
    void* instance,
    U32 bufferPointer,
    U32 bufferLength
) {
    wasmMemory* memory = wasiMemory(instance);

    ssize_t result = 0;
    int fd = -1;

    WASI_TRACE((
        "random_get(bufferPointer=0x%x, bufferLength=%d)",
        bufferPointer, bufferLength
    ));

    fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0) {
        WASI_TRACE(("random_get: open failed: %s", strerror(errno)));
        return wasiErrno();
    }
    result = read(
        fd,
#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    memory->data + bufferPointer,
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
        memory->data + memory->size - bufferPointer - bufferLength,
#endif
        bufferLength
    );
    if (result < 0) {
        WASI_TRACE(("random_get: read failed: %s", strerror(errno)));
        return wasiErrno();
    }
    if (close(fd) != 0) {
        WASI_TRACE(("random_get: close failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return wasiErrnoSuccess;
}

void*
wasiResolveImport(
    const char* module,
    const char* name
) {
    bool isWASI = false;

    if (strcmp(module, "wasi_snapshot_preview1") == 0) {
        isWASI = true;

        if (strcmp(name, "fd_seek") == 0) {
            return (void*)wasiPreview1FDSeek;
        }

        if (strcmp(name, "fd_filestat_get") == 0) {
            return (void*)wasiPreview1FDFilestatGet;
        }

        if (strcmp(name, "path_filestat_get") == 0) {
            return (void*)wasiPreview1PathFilestatGet;
        }

    } else if (strcmp(module, "wasi_unstable") == 0) {
        isWASI = true;

        if (strcmp(name, "fd_seek") == 0) {
            return (void*)wasiUnstableFDSeek;
        }

        if (strcmp(name, "fd_filestat_get") == 0) {
            return (void*)wasiUnstableFDFilestatGet;
        }

        if (strcmp(name, "path_filestat_get") == 0) {
            return (void*)wasiUnstablePathFilestatGet;
        }

    }

    if (!isWASI) {
        return NULL;
    }

    if (strcmp(name, "proc_exit") == 0) {
        return (void*)wasiProcExit;
    }

    if (strcmp(name, "fd_write") == 0) {
        return (void*)wasiFDWrite;
    }

    if (strcmp(name, "fd_read") == 0) {
        return (void*)wasiFDRead;
    }

    if (strcmp(name, "fd_pread") == 0) {
        return (void*)wasiFDPread;
    }

    if (strcmp(name, "environ_sizes_get") == 0) {
        return (void*)wasiEnvironSizesGet;
    }

    if (strcmp(name, "environ_get") == 0) {
        return (void*)wasiEnvironGet;
    }

    if (strcmp(name, "args_sizes_get") == 0) {
        return (void*)wasiArgsSizesGet;
    }

    if (strcmp(name, "args_get") == 0) {
        return (void*)wasiArgsGet;
    }

    if (strcmp(name, "fd_tell") == 0) {
        return (void*)wasiFDTell;
    }

    if (strcmp(name, "fd_readdir") == 0) {
        return (void*)wasiFDReaddir;
    }

    if (strcmp(name, "fd_close") == 0) {
        return (void*)wasiFDClose;
    }

    if (strcmp(name, "clock_time_get") == 0) {
        return (void*)wasiClockTimeGet;
    }

    if (strcmp(name, "clock_res_get") == 0) {
        return (void*)wasiClockResGet;
    }

    if (strcmp(name, "fd_fdstat_get") == 0) {
        return (void*)wasiFdFdstatGet;
    }

    if (strcmp(name, "fd_prestat_get") == 0) {
        return (void*)wasiFDPrestatGet;
    }

    if (strcmp(name, "fd_prestat_dir_name") == 0) {
        return (void*)wasiFdPrestatDirName;
    }

    if (strcmp(name, "path_open") == 0) {
        return (void*)wasiPathOpen;
    }

    if (strcmp(name, "path_rename") == 0) {
        return (void*)wasiPathRename;
    }

    if (strcmp(name, "path_unlink_file") == 0) {
        return (void*)wasiPathUnlinkFile;
    }

    if (strcmp(name, "path_create_directory") == 0) {
        return (void*)wasiPathCreateDirectory;
    }

    if (strcmp(name, "path_remove_directory") == 0) {
        return (void*)wasiPathRemoveDirectory;
    }

    if (strcmp(name, "path_symlink") == 0) {
        return (void*)wasiPathSymlink;
    }

    if (strcmp(name, "path_readlink") == 0) {
        return (void*)wasiPathReadlink;
    }

    if (strcmp(name, "fd_fdstat_set_flags") == 0) {
        return (void*)wasiFDFdstatSetFlags;
    }

    if (strcmp(name, "poll_oneoff") == 0) {
        return (void*)wasiPollOneoff;
    }

    if (strcmp(name, "random_get") == 0) {
        return (void*)wasiRandomGet;
    }

    return NULL;
}
