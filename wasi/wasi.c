#define _DEFAULT_SOURCE 1

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if HAS_UNISTD
#include <unistd.h>
#endif /* HAS_UNISTD */

#ifdef _MSC_VER
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#define INT64_C(val) val##i64
#endif /* _MSC_VER */

#ifdef _NEXT_SOURCE
typedef unsigned short mode_t;
typedef long ssize_t;

#define dirent direct
#endif /* _NEXT_SOURCE */

#include <time.h>
#if !HAS_TIMESPEC
#ifdef _NEXT_SOURCE
struct timespec {
    long ts_sec;
    long ts_nsec;
};
#else
struct timespec {
    long tv_sec;
    long tv_nsec;
};
#endif /* _NEXT_SOURCE */
#endif /* !HAS_TIMESPEC */

#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#if HAS_SYSTIME
#include <sys/time.h>
#endif /* HAS_SYSTIME */

#if HAS_SYSRESOURCE
#include <sys/resource.h>
#endif /* HAS_SYSRESOURCE */

#if HAS_SYSUIO
#include <sys/uio.h>
#endif /* HAS_SYSUIO */

#ifndef __MSL__
#include <sys/stat.h>
#endif

#define HAS_NONPOSIXPATH 0

#define PATH_SEPARATOR '/'
#define PATH_SEPARATOR_STRING "/"

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <direct.h>

#define mode_t unsigned short

#define S_IFMT  _S_IFMT
#define S_IFDIR _S_IFDIR
#define S_IFCHR _S_IFCHR
#define S_IFREG _S_IFREG

#define O_RDONLY _O_RDONLY
#define O_WRONLY _O_WRONLY
#define O_RDWR   _O_RDWR
#define O_APPEND _O_APPEND
#define O_CREAT  _O_CREAT
#define O_TRUNC  _O_TRUNC
#define O_EXCL   _O_EXCL

#define open    _open
#define read    _read
#define write   _write
#define close   _close
#define mkdir   _mkdir
#define rmdir   _rmdir
#define unlink  _unlink
#define stat    _stat
#define fstat   _fstat
#define lseek   _lseek
#define isatty  _isatty

/* TODO: could be redirected, use _fileno */
#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#undef HAS_NONPOSIXPATH
#define HAS_NONPOSIXPATH 1

#undef PATH_SEPARATOR
#define PATH_SEPARATOR '\\'
#undef PATH_SEPARATOR_STRING
#define PATH_SEPARATOR_STRING "\\"

#endif /* _WIN32 */

#ifdef __MSDOS__

#include <dos.h>
#include <ctype.h>

#undef HAS_NONPOSIXPATH
#define HAS_NONPOSIXPATH 1

#undef PATH_SEPARATOR
#define PATH_SEPARATOR '\\'
#undef PATH_SEPARATOR_STRING
#define PATH_SEPARATOR_STRING "\\"

#endif /* __MSDOS__ */

#ifdef __MSL__
#include <utime.h>

/* TODO: use fileno */
#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#endif /* __MSL__ */

#ifdef __NeXT__
/* Missing in unistd.h */
#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#endif

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

#ifdef macintosh
#include <Files.h>
#define __bool_true_false_are_defined
typedef char bool;

#undef HAS_NONPOSIXPATH
#define HAS_NONPOSIXPATH 1

#undef PATH_SEPARATOR
#define PATH_SEPARATOR ':'
#undef PATH_SEPARATOR_STRING
#define PATH_SEPARATOR_STRING ":"

#include "mac.h"
#endif

#if defined(__MACH__)
#include <mach/mach.h>
#endif /* __MACH__*/

#include "wasi.h"

#if !HAS_STRNDUP
char*
strndup(
    const char* s,
    size_t n
) {
    const char* p = memchr(s, 0, n);
    size_t l = p ? p-s : n;
    char* d = malloc(l + 1);
    if (!d) {
        return NULL;
    }
    memcpy(d, s, l);
    d[l] = '\0';
    return d;
}
#endif

#if !HAS_SYSUIO
struct iovec {
    void* iov_base;
    size_t iov_len;
};

ssize_t
readv(
    int fd,
    const struct iovec *iov,
    int iovcnt
) {
     int i = 0;
     ssize_t ret = 0;
     while (i < iovcnt) {
         ssize_t n = read(fd, iov[i].iov_base, iov[i].iov_len);
         if (n > 0) {
             ret += n;
         } else if (!n) {
             break;
         } else if (errno == EINTR) {
             continue;
         } else {
             if (ret == 0) {
                 ret = -1;
             }
             break;
         }
         i++;
     }
     return ret;
}

ssize_t
writev(
    int fd,
    const struct iovec *iov,
    int iovcnt
) {
    int i = 0;
    ssize_t ret = 0;
    while (i < iovcnt) {
        ssize_t n = 0;
#ifdef __MSL__
/*
 * For whatever reason, writing to SIOUX ends up overwriting
 * previous lines. Writing the individual characters however works
 */
        if (fd == STDOUT_FILENO || fd == STDERR_FILENO) {
            int j = 0;
            for (j = 0; j < iov[i].iov_len; j++) {
                putchar(((char*)iov[i].iov_base)[j]);
            }
            n = iov[i].iov_len;
        } else
#endif
        {
            n = write(fd, iov[i].iov_base, iov[i].iov_len);
        }
        if (n > 0) {
            ret += n;
        } else if (!n) {
            break;
        } else if (errno == EINTR) {
            continue;
        } else {
            if (ret == 0) {
                ret = -1;
            }
            break;
        }
        i++;
    }
    return ret;
}
#endif

#ifdef S_IFMT
#if !defined(S_ISBLK) && defined(S_IFBLK)
#define S_ISBLK(m)      (((m) & S_IFMT) == S_IFBLK)     /* block special */
#endif
#if !defined(S_ISCHR) && defined(S_IFCHR)
#define S_ISCHR(m)      (((m) & S_IFMT) == S_IFCHR)     /* char special */
#endif
#if !defined(S_ISDIR) && defined(S_IFDIR)
#define S_ISDIR(m)      (((m) & S_IFMT) == S_IFDIR)     /* directory */
#endif
#if !defined(S_ISREG) && defined(S_IFREG)
#define S_ISREG(m)      (((m) & S_IFMT) == S_IFREG)     /* regular file */
#endif
#if !defined(S_ISLNK) && defined(S_IFLNK)
#define S_ISLNK(m)      (((m) & S_IFMT) == S_IFLNK)     /* symbolic link */
#endif
#endif

void
wasiToNativePath(
    char *path
) {
#if HAS_NONPOSIXPATH
#if defined(macintosh)
    bool isAbsolute = path[0] == '/';
    posixToMacPath(path);
    /* Prefix with volume name */
    if (isAbsolute) {
        size_t pathLength = strlen(path);
        char *volumeName = NULL;
        size_t volumeNameLength = 0;

        Str255 pVolName;
        short vRefNum;
        long dirID;
        if (HGetVol(pVolName, &vRefNum, &dirID) == noErr) {
            /* Convert Pascal to C string */
            volumeNameLength = pVolName[0];
            pVolName[1 + volumeNameLength] = '\0';
            volumeName = (char*)(pVolName + 1);
        }

        memmove(path + volumeNameLength + 1, path, pathLength);
        strcpy(path, volumeName);
        path[volumeNameLength] = ':';
        pathLength += volumeNameLength + 1;
        path[pathLength] = '\0';
    }
#elif defined(__MSDOS__)
    bool isAbsolute = path[0] == '/';

    char *pos = path;
    while ((pos = strchr(pos, '/'))) {
        *pos = PATH_SEPARATOR;
    }

    /* Prefix with volume name */
    if (isAbsolute) {
        size_t pathLength = strlen(path);
        unsigned int drive;
        _dos_getdrive(&drive);

        memmove(path + 2, path, pathLength);
        path[0] = 'A' + drive - 1;
        path[1] = ':';
        pathLength += 2;
        path[pathLength] = '\0';
    }
#else
    char *pos = path;
    while ((pos = strchr(pos, '/'))) {
        *pos = PATH_SEPARATOR;
    }
#endif
#endif /* HAS_NONPOSIXPATH */
}

void
wasiFromNativePath(
    char *path
) {
#if HAS_NONPOSIXPATH
#if defined(macintosh)
    macToPosixPath(path);

    if (path[0] == '/') {
        /* Remove volume name */
        char* slashPos = strchr(path + 1, '/');
        if (slashPos) {
            size_t len = strlen(path) - (slashPos - path);
            memmove(path, slashPos, len);
            path[len] = '\0';
        }
    }
#elif defined(__MSDOS__)
    size_t pathLength = strlen(path);

    char *pos = path;
    while ((pos = strchr(pos, PATH_SEPARATOR))) {
        *pos = '/';
    }

    if (pathLength > 1 && isalpha(path[0]) && path[1] == ':') {
        /* Remove volume name */
        pathLength -= 2;
        memmove(path, path + 2, pathLength);
        path[pathLength] = '\0';
    }
#else
    char *pos = path;
    while ((pos = strchr(pos, PATH_SEPARATOR))) {
        *pos = '/';
    }
#endif
#endif /* HAS_NONPOSIXPATH */
}

static
void
#if defined(__GNUC__) && GCC_VERSION >= 20905
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
#endif
#ifdef O_FSYNC
#define O_DSYNC O_FSYNC /* BSD */
#endif
#endif

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasiFileDescriptorsEnsureCapacity(
    WasiFileDescriptors* descriptors,
    size_t length
) {
    if (length > descriptors->capacity) {
        size_t newCapacity = length + (descriptors->capacity >> 1U);
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
W2C2_INLINE
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
    char* path,
    U32* wasiFD
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
    MUST (wasiFD < wasi.fds.length)
    *result = wasi.fds.fds[wasiFD];
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
    } else if (descriptor.fd >= 0) {
        MUST (close(descriptor.fd) == 0)
    }

    if (descriptor.path != NULL) {
        free(descriptor.path);
    }

    MUST (wasiFileDescriptorSet(wasiFD, -1))
    MUST (wasiDirectorySet(wasiFD, NULL))

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

    return true;
}

static
W2C2_INLINE
U16
wasiErrno(void) {
    switch (errno) {
    case EPERM:
        return WASI_ERRNO_PERM;
    case ENOENT:
        return WASI_ERRNO_NOENT;
    case ESRCH:
        return WASI_ERRNO_SRCH;
    case EINTR:
        return WASI_ERRNO_INTR;
    case EIO:
        return WASI_ERRNO_IO;
    case ENXIO:
        return WASI_ERRNO_NXIO;
    case E2BIG:
        return WASI_ERRNO_2_BIG;
    case ENOEXEC:
        return WASI_ERRNO_NOEXEC;
    case EBADF:
        return WASI_ERRNO_BADF;
    case ECHILD:
        return WASI_ERRNO_CHILD;
    case EAGAIN:
        return WASI_ERRNO_AGAIN;
    case ENOMEM:
        return WASI_ERRNO_NOMEM;
    case EACCES:
        return WASI_ERRNO_ACCES;
    case EFAULT:
        return WASI_ERRNO_FAULT;
    case EBUSY:
        return WASI_ERRNO_BUSY;
    case EEXIST:
        return WASI_ERRNO_EXIST;
    case EXDEV:
        return WASI_ERRNO_XDEV;
    case ENODEV:
        return WASI_ERRNO_NODEV;
    case ENOTDIR:
        return WASI_ERRNO_NOTDIR;
    case EISDIR:
        return WASI_ERRNO_ISDIR;
    case EINVAL:
        return WASI_ERRNO_INVAL;
    case ENFILE:
        return WASI_ERRNO_NFILE;
    case EMFILE:
        return WASI_ERRNO_MFILE;
    case ENOTTY:
        return WASI_ERRNO_NOTTY;
#ifdef ETXTBSY
    case ETXTBSY:
        return WASI_ERRNO_TXTBSY;
#endif
    case EFBIG:
        return WASI_ERRNO_FBIG;
    case ENOSPC:
        return WASI_ERRNO_NOSPC;
    case ESPIPE:
        return WASI_ERRNO_SPIPE;
    case EROFS:
        return WASI_ERRNO_ROFS;
    case EMLINK:
        return WASI_ERRNO_MLINK;
    case EPIPE:
        return WASI_ERRNO_PIPE;
    case EDOM:
        return WASI_ERRNO_DOM;
    case ERANGE:
        return WASI_ERRNO_RANGE;
#if defined(__MSL__) && defined(macintosh)
    case EMACOSERR:
        /* TODO: add support for more error codes */
        switch ( __MacOSErrNo) {
        case fnfErr:
            return WASI_ERRNO_NOENT;
        default:
            WASI_TRACE(("unknown Mac OS error: %d", __MacOSErrNo));
            return WASI_ERRNO_INVAL;
        }
#endif
    default:
        WASI_TRACE(("unknown errno: %d", errno));
        return WASI_ERRNO_INVAL;
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
    void* UNUSED(instance),
    U32 code
) {
    WASI_TRACE((
        "proc_exit("
        "code=%d"
        ")",
        code
   ));

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
    I64 total = 0;
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
           "resultPointer=0x%x"
           ")",
           wasiFD,
           ciovecsPointer,
           ciovecsCount,
           resultPointer
       ));
    }

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_write: bad FD"));
        return WASI_ERRNO_BADF;
    }

    if (descriptor.fd < 0) {
        /* TODO: WASI_ERRNO_ISDIR for directory / preopen */
        return WASI_ERRNO_BADF;
    }

    iovecs = malloc(ciovecsCount * sizeof(struct iovec));
    if (iovecs == NULL) {
        WASI_TRACE(("fd_write: no mem"));
        return WASI_ERRNO_NOMEM;
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
                    "fd_write: "
                    "length=%d, "
                    "bufferPointer=0x%x",
                    length,
                    bufferPointer
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
            return WASI_ERRNO_NOMEM;
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
                    "fd_write: "
                    "length=%d, "
                    "bufferPointer=0x%x",
                    length,
                    bufferPointer
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

    return WASI_ERRNO_SUCCESS;
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
    I64 total = 0;
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "fd_[p]read("
        "wasiFD=%d, "
        "iovecsPointer=0x%x, "
        "iovecsCount=%d, "
        "resultPointer=0x%x, "
        "offset=%lld"
        ")",
        wasiFD,
        iovecsPointer,
        iovecsCount,
        resultPointer,
        offset
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_[p]read: bad FD"));
        return WASI_ERRNO_BADF;
    }

    if (descriptor.fd < 0) {
        /* TODO: WASI_ERRNO_ISDIR for directory / preopen */
        return WASI_ERRNO_BADF;
    }

    iovecs = malloc(iovecsCount * sizeof(struct iovec));
    if (iovecs == NULL) {
        WASI_TRACE(("fd_[p]read: no mem"));
        return WASI_ERRNO_NOMEM;
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

    return WASI_ERRNO_SUCCESS;
}

ssize_t
readvWrapper(
    int fd,
    const struct iovec* iovecs,
    int count,
    off_t UNUSED(offset)
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
W2C2_INLINE
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
        "environ_sizes_get("
        "envcPointer=0x%x, "
        "envpBufSizePointer=0x%x"
        ")",
        envcPointer,
        envpBufSizePointer
    ));

    while (wasi.envp[envpIndex] != NULL) {
        envpBufSize += strlen(wasi.envp[envpIndex]) + 1;
        envpIndex++;
    }

    i32_store(memory, envcPointer, wasi.envc);
    i32_store(memory, envpBufSizePointer, envpBufSize);

    return WASI_ERRNO_SUCCESS;
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
        "environ_get("
        "envpPointer=0x%x, "
        "envpBufPointer=0x%x"
        ")",
        envpPointer,
        envpBufPointer
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

    return WASI_ERRNO_SUCCESS;
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
        "args_sizes_get("
        "argcPointer=0x%x, "
        "argvBufSizePointer=0x%x"
        ")",
        argcPointer,
        argvBufSizePointer
    ));

    for (; argvIndex < wasi.argc; argvIndex++) {
        argvBufSize += strlen(wasi.argv[argvIndex]) + 1;
    }

    i32_store(memory, argcPointer, wasi.argc);
    i32_store(memory, argvBufSizePointer, argvBufSize);

    return WASI_ERRNO_SUCCESS;
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
        "args_get("
        "argvPointer=0x%x, "
        "argvBufPointer=0x%x"
        ")",
        argvPointer,
        argvBufPointer
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

    return WASI_ERRNO_SUCCESS;
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
        return WASI_ERRNO_BADF;
    }

    /* TODO: support preopen (directory) */
    if (descriptor.fd < 0) {
        return WASI_ERRNO_BADF;
    }

    result = lseek(descriptor.fd, (off_t)offset, nativeWhence);
    if (result == (off_t)-1) {
        WASI_TRACE(("fd_seek: lseek failed: %s", strerror(errno)));
        return wasiErrno();
    }

    i64_store(memory, resultPointer, result);

    return WASI_ERRNO_SUCCESS;
}

static
W2C2_INLINE
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
        "resultPointer=0x%x"
        ")",
        wasiFD,
        (off_t)offset,
        whence,
        resultPointer
    ));

    nativeWhence = convertPreview1Whence(whence);
    if (nativeWhence == -1) {
        WASI_TRACE(("fd_seek: invalid whence"));
        return WASI_ERRNO_INVAL;
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
W2C2_INLINE
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
        "resultPointer=0x%x"
        ")",
        wasiFD,
        (off_t)offset,
        whence,
        resultPointer
    ));

    nativeWhence = convertUnstableWhence(whence);
    if (nativeWhence == -1) {
        WASI_TRACE(("fd_seek: invalid whence"));
        return WASI_ERRNO_INVAL;
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
        "fd_tell("
        "wasiFD=%d, "
        "resultPointer=0x%x"
        ")",
        wasiFD,
        resultPointer
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
W2C2_INLINE
WasiFileType
wasiFileTypeFromMode(
    mode_t mode
) {
    if (S_ISCHR(mode)) {
        return WASI_FILE_TYPE_CHARACTER_DEVICE;
    }
    if (S_ISDIR(mode)) {
        return WASI_FILE_TYPE_DIRECTORY;
    }
    if (S_ISREG(mode)) {
        return WASI_FILE_TYPE_REGULAR_FILE;
    }
#ifdef S_ISLNK
    if (S_ISLNK(mode)) {
        return WASI_FILE_TYPE_SYMBOLIC_LINK;
    }
#endif /* S_ISLNK */
#ifdef S_ISBLK
    if (S_ISBLK(mode)) {
        return WASI_FILE_TYPE_BLOCK_DEVICE;
    }
#endif /* S_ISBLK */

    return WASI_FILE_TYPE_UNKNOWN;
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
    size_t adjustedNameLength = 0;
    /* NOTE: use target types, e.g. U8 for file type, instead of internal types */
    U8 fileType = WASI_FILE_TYPE_UNKNOWN;
    U32 bufferUsed = 0;
    U64 next = 0;
    U64 inode = 0;

    WASI_TRACE((
        "fd_readdir("
        "wasiDirFD=%d, "
        "bufferPointer=0x%x, "
        "bufferLength=%d, "
        "cookie=%lld, "
        "bufferUsedPointer=0x%x"
        ")",
        wasiDirFD,
        bufferPointer,
        bufferLength,
        cookie,
        bufferUsedPointer
    ));

    if (!wasiFileDescriptorGet(wasiDirFD, &descriptor)) {
        WASI_TRACE(("fd_readdir: bad FD"));
        return WASI_ERRNO_BADF;
    }

    if (descriptor.dir == NULL) {
        char nativePath[PATH_MAX];
        strcpy(nativePath, descriptor.path);
#if HAS_NONPOSIXPATH
        wasiToNativePath(nativePath);
#endif

        if (cookie != WASI_DIRCOOKIE_START) {
            WASI_TRACE(("fd_readdir: invalid cookie at start of readdir: %llu", cookie));
            return WASI_ERRNO_BADF;
        }

        WASI_TRACE((
            "fd_readdir: "
            "opendir(%s)",
            nativePath
        ));

        descriptor.dir = opendir(nativePath);

        if (descriptor.dir == NULL) {
            WASI_TRACE(("fd_readdir: opendir failed: %s", strerror(errno)));
            return wasiErrno();
        }

        if (!wasiDirectorySet(wasiDirFD, descriptor.dir)) {
            WASI_TRACE(("fd_readdir: setting DIR failed"));
            return WASI_ERRNO_BADF;
        }
    }

#if !defined(_WIN32) && !defined(macintosh)
    if (cookie != WASI_DIRCOOKIE_START) {
        seekdir(descriptor.dir, (long)cookie);
    }
#endif

    i32_store(
        memory,
        bufferUsedPointer,
        bufferUsed
    );

    while (bufferUsed < bufferLength) {
        long tell = 0;
        ssize_t bufferRemaining = bufferLength - bufferUsed;
        U32 resultPointer = bufferPointer + bufferUsed;

        WASI_TRACE(("fd_readdir: bufferRemaining=%ld", bufferRemaining));

        errno = 0;
        entry = readdir(descriptor.dir);
        if (entry == NULL) {
            if (errno != 0) {
                WASI_TRACE(("fd_readdir: readdir failed: %s", strerror(errno)));
                return wasiErrno();
            }

            break;
        }

#if !defined(_WIN32) && !defined(macintosh)
        tell = telldir(descriptor.dir);
        if (tell < 0) {
            WASI_TRACE(("fd_readdir: telldir failed: %s", strerror(errno)));
            return wasiErrno();
        }
#endif

        next = (U64)tell;
#if (defined(__MWERKS__) && defined(macintosh)) || defined(__MSDOS__)
        inode = 0;
#else
        inode = entry->d_ino;
#endif
        name = entry->d_name;
        nameLength = strlen(name);

        /*
         * Some operating systems don't support d_type.  Linux, Mac and some BSDs do.
         * When available, some file systems always supply an unknown type regardless.
         * Fallback is supplied by lstat in either case.
         */

#if defined(DTTOIF)
        fileType = wasiFileTypeFromMode(DTTOIF(entry->d_type));
#else
        fileType = WASI_FILE_TYPE_UNKNOWN;
#endif

#if HAS_LSTAT
        if (fileType == WASI_FILE_TYPE_UNKNOWN) {
            struct stat entryStat;

            char nativePath[PATH_MAX];
            strcpy(nativePath, descriptor.path);
#if HAS_NONPOSIXPATH
            wasiToNativePath(nativePath);
#endif
            strcat(nativePath, PATH_SEPARATOR_STRING);
            strcat(nativePath, name);

            WASI_TRACE((
                "fd_readdir: "
                "lstat(%s)",
                nativePath
            ));

            if (lstat(nativePath, &entryStat)) {
                WASI_TRACE(("fd_readdir: lstat failed: %s", strerror(errno)));
                return wasiErrno();
            }

            fileType = wasiFileTypeFromMode(entryStat.st_mode);
        }
#endif

        WASI_TRACE((
            "fd_readdir: "
            "name=%s, "
            "fileType=%d, "
            "inode=%llu",
            name,
            fileType,
            inode
        ));

        /* Only write entry if it fits */
        if (bufferRemaining < WASI_DIRENT_SIZE) {
            WASI_TRACE(("fd_readdir: exhausted buffer"));

            /*
             * If there are more entries to be written, but they don't fit,
             * then set the result value, buffer used, to the length of the buffer,
             * which indicates that there are more entries available
             */
            bufferUsed = bufferLength;
            break;
        }

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
        memset(
            memory->data + resultPointer,
            0,
            WASI_DIRENT_SIZE
        );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
        memset(
            memory->data + memory->size - resultPointer - WASI_DIRENT_SIZE,
            0,
            WASI_DIRENT_SIZE
        );
#endif

        i64_store(memory, resultPointer, next);
        i64_store(memory, resultPointer + 8, inode);
        i32_store(memory, resultPointer + 16, nameLength);
        i32_store8(memory, resultPointer + 20, fileType);

        bufferUsed += WASI_DIRENT_SIZE;
        bufferRemaining = bufferLength - bufferUsed;

        resultPointer = bufferPointer + bufferUsed;

        /* Write as much of the name as fits */
        adjustedNameLength =
            nameLength > bufferRemaining
            ? bufferRemaining
            : nameLength;

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
        memcpy(
            memory->data + resultPointer,
            name,
            adjustedNameLength
        );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
        {
            U8* base = memory->data + memory->size - 1 - resultPointer;

            U32 i = 0;
            for (; i < adjustedNameLength; i++) {
                base[-i] = name[i];
            }
        }
#endif
        bufferUsed += adjustedNameLength;
    }

    i32_store(
        memory,
        bufferUsedPointer,
        bufferUsed
    );

    return WASI_ERRNO_SUCCESS;
}

U32
wasiFDClose(
    void* UNUSED(instance),
    U32 wasiFD
) {
    WASI_TRACE((
        "fd_close("
        "wasiFD=%d"
        ")",
        wasiFD
    ));

    if (!wasiFileDescriptorClose(wasiFD)) {
        WASI_TRACE(("fd_close: bad FD"));
        return WASI_ERRNO_BADF;
    }
    return WASI_ERRNO_SUCCESS;
}

#ifndef NSEC_PER_SEC
#define NSEC_PER_SEC 1000000000LL
#endif
#ifndef NSEC_PER_USEC
#define NSEC_PER_USEC 1000LL
#endif

static
W2C2_INLINE
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
W2C2_INLINE
I64
convertTimeval(
    struct timeval t
) {
    return t.tv_sec * NSEC_PER_SEC
           + t.tv_usec * NSEC_PER_USEC;
}

static
W2C2_INLINE
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
    U64 UNUSED(precision),
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    I64 result = 0;

    WASI_TRACE((
        "clock_time_get("
        "clockID=%d, "
        "precision=%lld, "
        "resultPointer=0x%x"
        ")",
        clockID,
        precision,
        resultPointer
    ));

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0) && !defined(WASI_FALLBACK_TIMERS_ENABLED)

    {
        struct timespec timespec;
        clockid_t nativeClockID;

        switch (clockID) {
            case WASI_CLOCK_REALTIME: {
                nativeClockID = CLOCK_REALTIME;
                break;
            }
#ifdef _POSIX_MONOTONIC_CLOCK
            case WASI_CLOCK_MONOTONIC: {
                nativeClockID = CLOCK_MONOTONIC;
                break;
            }
#endif
#ifdef _POSIX_CPUTIME
            case WASI_CLOCK_PROCESS_CPUTIME_ID: {
                nativeClockID = CLOCK_PROCESS_CPUTIME_ID;
                break;
            }
#endif
#ifdef _POSIX_THREAD_CPUTIME
            case WASI_CLOCK_THREAD_CPUTIME_ID: {
                nativeClockID = CLOCK_THREAD_CPUTIME_ID;
                break;
            }
#endif
            default: {
                WASI_TRACE(("clock_time_get: invalid clock ID"));
                return WASI_ERRNO_INVAL;
            }
        }

        if (clock_gettime(nativeClockID, &timespec) != 0) {
            WASI_TRACE(("clock_time_get: clock_gettime failed: %s", strerror(errno)));
            return wasiErrno();
        }

        WASI_TRACE((
            "clock_time_get: "
            "clock_gettime: %d %d",
            timespec.tv_sec,
            timespec.tv_nsec
        ));

        result = convertTimespec(timespec);
    }
#elif _WIN32
/*
 * Taken from mingw-w64's winpthreads library,
 * which has no copyright assigned and is placed in the Public Domain.
 */

#define POW10_7 10000000
#define POW10_9 1000000000

/* Number of 100ns-seconds between the beginning of the Windows epoch
 * (Jan. 1, 1601) and the Unix epoch (Jan. 1, 1970)
 */
#define DELTA_EPOCH_IN_100NS    INT64_C(116444736000000000)

    {
        struct timespec tp;
        U64 t;
        LARGE_INTEGER pf, pc;
        union {
            U64 u64;
            FILETIME ft;
        }  ct, et, kt, ut;

        switch (clockID) {
            case WASI_CLOCK_REALTIME: {
                GetSystemTimeAsFileTime(&ct.ft);
                t = ct.u64 - DELTA_EPOCH_IN_100NS;
                tp.tv_sec = t / POW10_7;
                tp.tv_nsec = ((int) (t % POW10_7)) * 100;

                result = convertTimespec(tp);
                break;
            }
            case WASI_CLOCK_MONOTONIC: {
                if (QueryPerformanceFrequency(&pf) == 0) {
                    return WASI_ERRNO_INVAL;
                }

                if (QueryPerformanceCounter(&pc) == 0) {
                    return WASI_ERRNO_INVAL;
                }

                tp.tv_sec = pc.QuadPart / pf.QuadPart;
                tp.tv_nsec = (int) (((pc.QuadPart % pf.QuadPart) * POW10_9 + (pf.QuadPart >> 1)) / pf.QuadPart);
                if (tp.tv_nsec >= POW10_9) {
                    tp.tv_sec++;
                    tp.tv_nsec -= POW10_9;
                }

                result = convertTimespec(tp);
                break;
            }
            case WASI_CLOCK_PROCESS_CPUTIME_ID: {
                if (GetProcessTimes(GetCurrentProcess(), &ct.ft, &et.ft, &kt.ft, &ut.ft) == 0) {
                    return WASI_ERRNO_INVAL;
                }
                t = kt.u64 + ut.u64;
                tp.tv_sec = t / POW10_7;
                tp.tv_nsec = ((int) (t % POW10_7)) * 100;

                result = convertTimespec(tp);
                break;
            }
            case WASI_CLOCK_THREAD_CPUTIME_ID: {
                if(GetThreadTimes(GetCurrentThread(), &ct.ft, &et.ft, &kt.ft, &ut.ft) == 0) {
                    return WASI_ERRNO_INVAL;
                }
                t = kt.u64 + ut.u64;
                tp.tv_sec = t / POW10_7;
                tp.tv_nsec = ((int) (t % POW10_7)) * 100;

                result = convertTimespec(tp);
                break;
            }
            default: {
                WASI_TRACE(("clock_time_get: invalid clock ID"));
                return WASI_ERRNO_INVAL;
            }
        }
    }
#else
    switch (clockID) {
#if HAS_SYSTIME
        case WASI_CLOCK_REALTIME: {
            struct timeval tv;
            if (gettimeofday(&tv, NULL) != 0) {
                WASI_TRACE(("clock_time_get: gettimeofday failed: %s", strerror(errno)));
                return wasiErrno();
            }
            result = convertTimeval(tv);
            break;
        }
#endif /* HAS_SYSTIME */
#if defined(__MWERKS__) && defined(macintosh)
#include <DateTimeUtils.h>
        case WASI_CLOCK_REALTIME: {
            static unsigned long savedTicks = 0, savedSecs = 0;

            struct timeval tv;
            unsigned long secs;
            unsigned long ticks;
            GetDateTime(&secs);
            ticks = TickCount();

            if (!savedSecs) {
                savedTicks = ticks;
                savedSecs = secs;
            } else {
                unsigned long elapsedTicks = ticks - savedTicks;
                unsigned long elapsedSecs = secs - savedSecs;
                unsigned long expectedTicks = elapsedSecs * 60 + elapsedSecs * 3 / 20;

                if (expectedTicks > elapsedTicks)
                    savedTicks = ticks;
                else
                    savedTicks += expectedTicks;
                savedSecs = secs;
            }

            {
                const int epochDifferenceInYears = 1970 - 1904;
                const int epochDifferenceInDays =
                    365 * epochDifferenceInYears
                    + (epochDifferenceInYears + 3)/ 4;  /* round up for leap years */

                tv.tv_sec = secs - 86400 * epochDifferenceInDays;
                tv.tv_usec = (ticks - savedTicks) * 20000000 / 2003;

                result = convertTimeval(tv);
            }
            break;
        }
#endif
#if defined(__MACH__) && defined(CLOCK_NULL)
#include <mach/mach_time.h>
        case WASI_CLOCK_MONOTONIC: {
            static mach_timebase_info_data_t timebase = {0, 0};

            if (!timebase.denom && mach_timebase_info(&timebase) != KERN_SUCCESS) {
                WASI_TRACE(("clock_time_get: mach_timebase_info failed"));
                return WASI_ERRNO_INVAL;
            }

            result = mach_absolute_time() * timebase.numer / timebase.denom;
            break;
        }
#endif /* defined(__MACH__) && defined(CLOCK_NULL) */
        case WASI_CLOCK_PROCESS_CPUTIME_ID: {
#if HAS_SYSRESOURCE
            struct rusage ru;
            int ret = 0;

            WASI_TRACE(("clock_time_get: getrusage(RUSAGE_SELF)"));

            ret = getrusage(RUSAGE_SELF, &ru);
            if (ret != 0) {
                WASI_TRACE(("clock_time_get: getrusage failed: %s", strerror(errno)));
                return wasiErrno();
            }
            addTimevals(&ru.ru_utime, &ru.ru_stime, &ru.ru_utime);
            result = convertTimeval(ru.ru_utime);
#else
#include <time.h>
            result = (clock() / CLOCKS_PER_SEC) * 1e9;
#endif /* HAS_SYSRESOURCE */
            break;
        }
        default: {
            WASI_TRACE(("clock_time_get: invalid clock ID"));
            return WASI_ERRNO_INVAL;
        }
    }
#endif

    WASI_TRACE((
        "clock_time_get: "
        "result=%lld",
        result
   ));

    i64_store(
        memory,
        resultPointer,
        result
    );

    return WASI_ERRNO_SUCCESS;
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
        "clock_res_get("
        "clockID=%d, "
        "resultPointer=0x%x"
        ")",
        clockID,
        resultPointer
    ));

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0) && !defined(WASI_FALLBACK_TIMERS_ENABLED)

    {
        struct timespec timespec;
        clockid_t nativeClockID;


        switch (clockID) {
            case WASI_CLOCK_REALTIME: {
                nativeClockID = CLOCK_REALTIME;
                break;
            }
#ifdef _POSIX_MONOTONIC_CLOCK
            case WASI_CLOCK_MONOTONIC: {
                nativeClockID = CLOCK_MONOTONIC;
                break;
            }
#endif
#ifdef _POSIX_CPUTIME
            case WASI_CLOCK_PROCESS_CPUTIME_ID: {
                nativeClockID = CLOCK_PROCESS_CPUTIME_ID;
                break;
            }
#endif
#ifdef _POSIX_THREAD_CPUTIME
            case WASI_CLOCK_THREAD_CPUTIME_ID: {
                nativeClockID = CLOCK_THREAD_CPUTIME_ID;
                break;
            }
#endif
            default: {
                WASI_TRACE(("clock_res_get: invalid clock ID"));
                return WASI_ERRNO_INVAL;
            }
        }

        if (clock_getres(nativeClockID, &timespec) != 0) {
            WASI_TRACE(("clock_res_get: clock_gettime failed: %s", strerror(errno)));
            return wasiErrno();
        }

        WASI_TRACE((
            "clock_res_get: "
            "clock_getres: %d %d",
            timespec.tv_sec,
            timespec.tv_nsec
        ));

        result = convertTimespec(timespec);
    }
#else
    switch (clockID) {
        case WASI_CLOCK_REALTIME: {
            result = 1000000;
            break;
        }
        case WASI_CLOCK_MONOTONIC:
        case WASI_CLOCK_PROCESS_CPUTIME_ID:
        case WASI_CLOCK_THREAD_CPUTIME_ID: {
            result = 1000;
            break;
        }
        default: {
            WASI_TRACE(("clock_res_get: invalid clock ID"));
            return WASI_ERRNO_INVAL;
        }
    }
#endif

    WASI_TRACE((
        "clock_res_get: "
        "result=%lld",
        result
   ));

    i64_store(
        memory,
        resultPointer,
        result
    );

    return WASI_ERRNO_SUCCESS;
}

#define WASI_FDSTAT_SIZE 24

U32
wasiFdFdstatGet(
    void* instance,
    U32 wasiFD,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    WasiFileType fileType = WASI_FILE_TYPE_UNKNOWN;
    U16 wasiFlags = 0;
    struct stat st;
    int nativeFlags = 0;
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    WasiRights baseRights = 0;
    WasiRights inheritingRights = 0;

    WASI_TRACE((
        "fd_fdstat_get("
        "wasiFD=%d, "
        "resultPointer=0x%x"
        ")",
        wasiFD,
        resultPointer
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_fdstat_get: bad FD"));
        return WASI_ERRNO_BADF;
    }

    /* Get fileType */
    if (descriptor.fd >= 0) {
        if (fstat(descriptor.fd, &st) != 0) {
            WASI_TRACE(("fd_fdstat_get: fstat failed: %s", strerror(errno)));
            return wasiErrno();
        }
    } else {
        char nativePath[PATH_MAX];
        strcpy(nativePath, descriptor.path);
#if HAS_NONPOSIXPATH
        wasiToNativePath(nativePath);
#endif
        WASI_TRACE((
            "fd_fdstat_get: "
            "stat(%s)",
            nativePath
        ));

        if (stat(nativePath, &st) != 0) {
            WASI_TRACE(("fd_fdstat_get: stat failed: %s", strerror(errno)));
            return wasiErrno();
        }
    }

    fileType = wasiFileTypeFromMode(st.st_mode);

    switch (fileType) {
        case WASI_FILE_TYPE_CHARACTER_DEVICE: {
            if (descriptor.fd >= 0 && isatty(descriptor.fd)) {
                baseRights = WASI_RIGHTS_TTY_BASE;
                inheritingRights = WASI_RIGHTS_TTY_INHERITING;
            } else {
                baseRights = WASI_RIGHTS_ALL;
                inheritingRights = WASI_RIGHTS_ALL;
            }
            break;
        }
        case WASI_FILE_TYPE_DIRECTORY: {
            baseRights = WASI_RIGHTS_DIRECTORY_BASE;
            inheritingRights = WASI_RIGHTS_DIRECTORY_INHERITING;
            break;
        }
        case WASI_FILE_TYPE_REGULAR_FILE: {
            baseRights = WASI_RIGHTS_REGULAR_FILE_BASE;
            inheritingRights = WASI_RIGHTS_REGULAR_FILE_INHERITING;
            break;
        }
        default: {
            baseRights = WASI_RIGHTS_ALL;
            inheritingRights = WASI_RIGHTS_ALL;
            break;
        }
    }

    if (descriptor.fd >= 0) {
#if HAS_FCNTL
        /* Get flags */
        nativeFlags = fcntl(descriptor.fd, F_GETFL);
        if (nativeFlags < 0) {
            WASI_TRACE(("fd_fdstat_get: fcntl failed: %s", strerror(errno)));
            return wasiErrno();
        }

        if (nativeFlags & O_APPEND) {
            wasiFlags |= WASI_FDFLAGS_APPEND;
        }
#ifdef O_DSYNC
        if (nativeFlags & O_DSYNC) {
            wasiFlags |= WASI_FDFLAGS_DSYNC;
        }
#endif
#ifdef O_NONBLOCK
        if (nativeFlags & O_NONBLOCK) {
            wasiFlags |= WASI_FDFLAGS_NONBLOCK;
        }
#endif
#ifdef O_SYNC
        if (nativeFlags & O_SYNC) {
            wasiFlags |= WASI_FDFLAGS_RSYNC | WASI_FDFLAGS_SYNC;
        }
#endif /* O_SYNC */
#endif /* HAS_FCNTL */
    }

    /* Store result */
#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    memset(
        memory->data + resultPointer,
        0,
        WASI_FDSTAT_SIZE
    );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    memset(
        memory->data + memory->size - resultPointer - WASI_FDSTAT_SIZE,
        0,
        WASI_FDSTAT_SIZE
    );
#endif

    WASI_TRACE((
        "fd_fdstat_get: "
        "fileType=%u, "
        "wasiFlags=%u, "
        "baseRights=%llu, "
        "inheritingRights=%llu",
        fileType,
        wasiFlags,
        baseRights,
        inheritingRights
    ));

    i32_store8(memory, resultPointer, fileType);
    i32_store16(memory, resultPointer + 2, wasiFlags);
    i64_store(memory, resultPointer + 8, baseRights);
    i64_store(memory, resultPointer + 16, inheritingRights);

    return WASI_ERRNO_SUCCESS;
}

U32
wasiFDPrestatGet(
    void* instance,
    U32 wasiFD,
    U32 prestatPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    WasiFileDescriptor fileDescriptor = emptyWasiFileDescriptor;
    U32 length = 0;
    char* path = NULL;

    WASI_TRACE((
        "fd_prestat_get("
        "wasiFD=%d, "
        "prestatPointer=0x%x"
        ")",
        wasiFD,
        prestatPointer
    ));

    if (!wasiFileDescriptorGet(wasiFD, &fileDescriptor)) {
        WASI_TRACE(("fd_prestat_get: bad FD"));
        return WASI_ERRNO_BADF;
    }

    path = fileDescriptor.path;

    if (path == NULL) {
        WASI_TRACE(("fd_prestat_get: bad FD"));
        return WASI_ERRNO_BADF;
    }

    length = strlen(path) + 1;
    i32_store(memory, prestatPointer, WASI_PREOPEN_TYPE_DIRECTORY);
    i32_store(memory, prestatPointer + 4, length);

    return WASI_ERRNO_SUCCESS;
}

U32
wasiFdPrestatDirName(
    void* instance,
    U32 wasiFD,
    U32 pathPointer,
    U32 pathLength
) {
    wasmMemory* memory = wasiMemory(instance);

    WasiFileDescriptor fileDescriptor = emptyWasiFileDescriptor;
    size_t length = 0;
    char* path = NULL;

    WASI_TRACE((
        "fd_prestat_dir_name("
        "wasiFD=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d"
        ")",
        wasiFD,
        pathPointer,
        pathLength
    ));

    if (!wasiFileDescriptorGet(wasiFD, &fileDescriptor)) {
        WASI_TRACE(("fd_prestat_dir_name: bad FD"));
        return WASI_ERRNO_BADF;
    }

    path = fileDescriptor.path;

    if (path == NULL) {
        WASI_TRACE(("fd_prestat_dir_name: bad FD"));
        return WASI_ERRNO_BADF;
    }

    length = strlen(path) + 1;
    if (length >= pathLength) {
        length = pathLength;
    }

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    memcpy(
        memory->data + pathPointer,
        path,
        length
    );
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    {
        U8* base = memory->data + memory->size - 1 - pathPointer;

        U32 i = 0;
        for (; i < length; i++) {
            base[-i] = path[i];
        }
    }
#endif

    return WASI_ERRNO_SUCCESS;
}

static
W2C2_INLINE
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
    U32 UNUSED(dirFlags),
    U32 pathPointer,
    U32 pathLength,
    U32 oflags,
    U64 fsRightsBase,
    U64 UNUSED(fsRightsInheriting),
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
    char nativeResolvedPath[PATH_MAX];
    int nativeFlags = 0;
    static const int mode = 0644;
    int nativeFD = -1;
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;
    U32 wasiFD = 0;
    char* preopenPath = NULL;
    bool success = false;

    bool isRead = fsRightsBase & (WASI_RIGHTS_FD_READ
                                  | WASI_RIGHTS_FD_READDIR);
    bool isWrite = fsRightsBase & (WASI_RIGHTS_FD_DATASYNC
                                   | WASI_RIGHTS_FD_WRITE
                                   | WASI_RIGHTS_FD_ALLOCATE
                                   | WASI_RIGHTS_FD_FILESTAT_SET_SIZE);

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
        "fdPointer=0x%x"
        ")",
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

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_open: bad path"));
        return WASI_ERRNO_INVAL;
    }
#endif

    WASI_TRACE((
        "path_open: "
        "path=%.*s",
        pathLength,
        path
    ));


    if (!wasiFileDescriptorGet(wasiDirFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_open: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    preopenPath = preopenFileDescriptor.path;

    if (preopenPath == NULL) {
        WASI_TRACE(("path_open: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (!resolvePath(preopenPath, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_open: path resolution failed"));
        return WASI_ERRNO_INVAL;
    }

    WASI_TRACE((
        "path_open: "
        "resolvedPath=%s",
        resolvedPath
    ));

    /* Convert WASI fsRightsBase to native flags */
    nativeFlags = isWrite ? isRead ? O_RDWR : O_WRONLY : O_RDONLY;

    /* Convert WASI oflags to native flags */
    if (oflags & WASI_OFLAGS_CREAT) {
        nativeFlags |= O_CREAT;
    }
#if defined(O_DIRECTORY) || (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200809L))
    if (oflags & WASI_OFLAGS_DIRECTORY) {
        nativeFlags |= O_DIRECTORY;
    }
#endif
    if (oflags & WASI_OFLAGS_EXCL) {
        nativeFlags |= O_EXCL;
    }
    if (oflags & WASI_OFLAGS_TRUNC) {
        nativeFlags |= O_TRUNC;
    }

    /* Convert WASI fdFlags to native flags */
    if (fdFlags & WASI_FDFLAGS_APPEND) {
        nativeFlags |= O_APPEND;
    }

#ifdef O_DSYNC
    if (fdFlags & WASI_FDFLAGS_DSYNC) {
        nativeFlags |= O_DSYNC;
    }
#endif
#ifdef O_NONBLOCK
    if (fdFlags & WASI_FDFLAGS_NONBLOCK) {
        nativeFlags |= O_NONBLOCK;
    }
#endif
#ifdef O_SYNC
    if (fdFlags & WASI_FDFLAGS_SYNC) {
        nativeFlags |= O_SYNC;
    }
#endif
    /* wasiFdflagsRsync is ignored, as O_RSYNC is often not implemented */

    strcpy(nativeResolvedPath, resolvedPath);
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativeResolvedPath);
#endif

    WASI_TRACE((
        "path_open: "
        "open(%s)",
        nativeResolvedPath
    ));

    /* Open the file */
    nativeFD = open(nativeResolvedPath, nativeFlags, mode);

    WASI_TRACE((
        "path_open: "
        "nativeFD=%d, "
        "errno=%d",
        nativeFD,
        errno
    ));

    success = nativeFD >= 0;

#ifdef _WIN32
    /*
     * Windows does not support opening directories.
     * Check if the opened path is an existing directory.
     */
    if (!success && errno == EACCES) {
        struct stat st;
        if (stat(nativeResolvedPath, &st) == 0) {
            success = S_ISDIR(st.st_mode);
        }
    }
#endif
#if defined(__MSL__) && defined(macintosh)
    /*
     * Macintosh does not support opening directories.
     * Check if the opened path is an existing directory.
     */
    if (!success && errno == EMACOSERR && __MacOSErrNo == errFSForkNotFound) {
        struct stat st;
        if (stat(nativeResolvedPath, &st) == 0) {
            success = S_ISDIR(st.st_mode);
        }
    }
#endif

    if (!success) {
        WASI_TRACE(("path_open: open failed: %s", strerror(errno)));
        return wasiErrno();
    }

    /* Not all platforms support O_DIRECTORY, so emulate it */
    if (nativeFD >= 0 && oflags & WASI_OFLAGS_DIRECTORY) {
        struct stat st;

        if (fstat(nativeFD, &st) < 0) {
            WASI_TRACE(("path_open: fstat failed: %s", strerror(errno)));
            return wasiErrno();
        }

        if (wasiFileTypeFromMode(st.st_mode) != WASI_FILE_TYPE_DIRECTORY) {
            return WASI_ERRNO_NOTDIR;
        }
    }

    /* Register the WASI file descriptor */
    if (!wasiFileDescriptorAdd(nativeFD, resolvedPath, &wasiFD)) {
        WASI_TRACE(("path_open: adding FD failed"));
        return WASI_ERRNO_BADF;
    }

    WASI_TRACE((
        "path_open: "
        "wasiFD=%d",
        wasiFD
    ));

    /* Store the file descriptor at the result pointer */
    i32_store(memory, fdPointer, wasiFD);

    return WASI_ERRNO_SUCCESS;
}

static
W2C2_INLINE
void
getStatTimes(
    struct stat* st,
    struct timespec* access,
    struct timespec* modification,
    struct timespec* creation
) {
#if (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200809L)) || \
    (defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE >= 700))

    access->tv_sec = st->st_atim.tv_sec;
    access->tv_nsec = st->st_atim.tv_nsec;
    modification->tv_sec = st->st_mtim.tv_sec;
    modification->tv_nsec = st->st_mtim.tv_nsec;
    creation->tv_sec = st->st_ctim.tv_sec;
    creation->tv_nsec = st->st_ctim.tv_nsec;
#elif defined(_NEXT_SOURCE)
    access->ts_sec = st->st_atime;
    access->ts_nsec = 0;
    modification->ts_sec = st->st_mtime;
    modification->ts_nsec = 0;
    creation->ts_sec = st->st_ctime;
    creation->ts_nsec = 0;
#else
    access->tv_sec = st->st_atime;
    access->tv_nsec = 0;
    modification->tv_sec = st->st_mtime;
    modification->tv_nsec = 0;
    creation->tv_sec = st->st_ctime;
    creation->tv_nsec = 0;
#endif
}

static const size_t wasiPreview1FilestatSize = 64;

static
W2C2_INLINE
void
storePreview1Filestat(
    wasmMemory* memory,
    U32 statPointer,
    struct stat* st
) {
    struct timespec access;
    struct timespec modification;
    struct timespec creation;

    getStatTimes(st, &access, &modification, &creation);

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
        I64 dev = st->st_dev;
        U64 ino = st->st_ino;
        U8 wasiFileType = wasiFileTypeFromMode(st->st_mode);
        U64 nlink = st->st_nlink;
        U64 size = st->st_size;
        I64 accessTime = convertTimespec(access);
        I64 modificationTime = convertTimespec(modification);
        I64 creationTime = convertTimespec(creation);

        WASI_TRACE((
            "storing preview1 filestat to 0x%x: "
            "dev=%lld, "
            "ino=%llu, "
            "wasiFileType=%d, "
            "nlink=%lld, "
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
        return WASI_ERRNO_BADF;
    }

    if (descriptor.fd >= 0) {
        if (fstat(descriptor.fd, st) != 0) {
            WASI_TRACE(("fd_filestat_get: fstat failed: %s", strerror(errno)));
            return wasiErrno();
        }
    } else {
        char nativePath[PATH_MAX];
        strcpy(nativePath, descriptor.path);
#if HAS_NONPOSIXPATH
        wasiToNativePath(nativePath);
#endif
        WASI_TRACE((
            "fd_filestat_get: "
            "stat(%s)",
            nativePath
        ));

        if (stat(nativePath, st) != 0) {
            WASI_TRACE(("fd_filestat_get: stat failed: %s", strerror(errno)));
            return wasiErrno();
        }
    }

    WASI_TRACE((
        "fd_filestat_get: "
        "st_mode=%u = %u",
        st->st_mode,
        wasiFileTypeFromMode(st->st_mode)
    ));

    return WASI_ERRNO_SUCCESS;
}

U32
wasiPreview1FDFilestatGet(
    void* instance,
    U32 wasiFD,
    U32 statPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    struct stat st;
    U32 res = WASI_ERRNO_INVAL;

    WASI_TRACE((
        "fd_filestat_get("
        "wasiFD=%d, "
        "statPointer=0x%x"
        ")",
        wasiFD,
        statPointer
    ));

    res = fdFilestatGetImpl(wasiFD, &st);
    if (res != WASI_ERRNO_SUCCESS) {
        return res;
    }

    storePreview1Filestat(memory, statPointer, &st);

    return WASI_ERRNO_SUCCESS;
}

static const size_t wasiUnstableFilestatSize = 64;

static
W2C2_INLINE
void
storeUnstableFilestat(
    wasmMemory* memory,
    U32 statPointer,
    struct stat* st
) {
    struct timespec access;
    struct timespec modification;
    struct timespec creation;

    getStatTimes(st, &access, &modification, &creation);

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
        I64 dev = st->st_dev;
        U64 ino = st->st_ino;
        U8 wasiFileType = wasiFileTypeFromMode(st->st_mode);
        U32 nlink = st->st_nlink;
        U64 size = st->st_size;
        I64 accessTime = convertTimespec(access);
        I64 modificationTime = convertTimespec(modification);
        I64 creationTime = convertTimespec(creation);

        WASI_TRACE((
           "storing unstable filestat to 0x%x: "
           "dev=%lld, "
           "ino=%llu, "
           "wasiFileType=%d, "
           "nlink=%u, "
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

    struct stat st;
    U32 res = WASI_ERRNO_INVAL;

    WASI_TRACE((
        "fd_filestat_get("
        "wasiFD=%d, "
        "statPointer=0x%x"
        ")",
        wasiFD,
        statPointer
    ));

    res = fdFilestatGetImpl(wasiFD, &st);

    if (res != WASI_ERRNO_SUCCESS) {
        return res;
    }

    storeUnstableFilestat(memory, statPointer, &st);

    return WASI_ERRNO_SUCCESS;
}

static
U32
pathFilestatGetImpl(
    wasmMemory* memory,
    U32 wasiFD,
    U32 UNUSED(lookupFlags),
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
    char nativeResolvedPath[PATH_MAX];
    int res = 0;
    char* preopenPath = NULL;
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;

    if (!wasiFileDescriptorGet(wasiFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_filestat_get: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_filestat_get: bad path"));
        return WASI_ERRNO_INVAL;
    }
#endif

    WASI_TRACE((
        "path_filestat_get: "
        "path=%.*s",
        pathLength,
        path
    ));

    preopenPath = preopenFileDescriptor.path;
    if (preopenPath == NULL) {
        WASI_TRACE(("path_filestat_get: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (!resolvePath(preopenPath, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_filestat_get: path resolution failed"));
        return WASI_ERRNO_INVAL;
    }

    WASI_TRACE(("path_filestat_get: resolvedPath=%s", resolvedPath));

    strcpy(nativeResolvedPath, resolvedPath);
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativeResolvedPath);
#endif

    WASI_TRACE((
        "path_filestat_get: "
        "stat(%s)",
        nativeResolvedPath
    ));

    /* TODO: use lookupFlags & wasiLookupFlagSymlinkFollow */
    res = stat(nativeResolvedPath, st);

    if (res != 0) {
        WASI_TRACE(("path_filestat_get: stat failed: %s", strerror(errno)));
        return wasiErrno();
    }

    WASI_TRACE((
        "path_filestat_get: "
        "st_mode=%u = %u",
        st->st_mode,
        wasiFileTypeFromMode(st->st_mode)
    ));

    return WASI_ERRNO_SUCCESS;
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

    struct stat st;
    U32 res = WASI_ERRNO_INVAL;

    WASI_TRACE((
        "path_filestat_get("
        "dirFD=%d, "
        "lookupFlags=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d, "
        "statPointer=0x%x"
        ")",
        dirFD,
        lookupFlags,
        pathPointer,
        pathLength,
        statPointer
    ));

    res = pathFilestatGetImpl(memory, dirFD, lookupFlags, pathPointer, pathLength, &st);
    if (res != WASI_ERRNO_SUCCESS) {
        return res;
    }

    storePreview1Filestat(memory, statPointer, &st);

    return WASI_ERRNO_SUCCESS;
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

    struct stat st;
    U32 res = WASI_ERRNO_INVAL;

    WASI_TRACE((
        "path_filestat_get("
        "dirFD=%d, "
        "lookupFlags=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d, "
        "statPointer=0x%x"
        ")",
        dirFD,
        lookupFlags,
        pathPointer,
        pathLength,
        statPointer
    ));

    res = pathFilestatGetImpl(memory, dirFD, lookupFlags, pathPointer, pathLength, &st);
    if (res != WASI_ERRNO_SUCCESS) {
        return res;
    }

    storeUnstableFilestat(memory, statPointer, &st);

    return WASI_ERRNO_SUCCESS;
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
    char nativeOldResolvedPath[PATH_MAX];
    char nativeNewResolvedPath[PATH_MAX];
    int res = -1;
    char* oldPreopenPath = NULL;
    char* newPreopenPath = NULL;
    WasiFileDescriptor oldPreopenFileDescriptor = emptyWasiFileDescriptor;
    WasiFileDescriptor newPreopenFileDescriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "path_rename("
        "oldDirFD=%d, "
        "oldPathPointer=0x%x, "
        "oldPathLength=%d, "
        "newDirFD=%d, "
        "newPathPointer=0x%x, "
        "newPathLength=%d"
        ")",
        oldDirFD,
        oldPathPointer,
        oldPathLength,
        newDirFD,
        newPathPointer,
        newPathLength
    ));

    if (!wasiFileDescriptorGet(oldDirFD, &oldPreopenFileDescriptor)) {
        WASI_TRACE(("path_rename: bad old preopen fd"));
        return WASI_ERRNO_BADF;
    }

    if (!wasiFileDescriptorGet(newDirFD, &newPreopenFileDescriptor)) {
        WASI_TRACE(("path_rename: bad new preopen fd"));
        return WASI_ERRNO_BADF;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, oldPathPointer, oldPathLength, oldPath)) {
        WASI_TRACE(("path_rename: bad old path"));
        return WASI_ERRNO_INVAL;
    }

    if (!getBigEndianPath(memory, newPathPointer, newPathLength, newPath)) {
        WASI_TRACE(("path_rename: bad new path"));
        return WASI_ERRNO_INVAL;
    }
#endif

    WASI_TRACE((
        "path_rename: "
        "oldPath=%.*s, "
        "newPath=%.*s",
        oldPathLength,
        oldPath,
        newPathLength,
        newPath
    ));

    oldPreopenPath = oldPreopenFileDescriptor.path;
    if (oldPreopenPath == NULL) {
        WASI_TRACE(("path_rename: bad old preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (!resolvePath(oldPreopenPath, oldPath, oldPathLength, oldResolvedPath)) {
        WASI_TRACE(("path_rename: old path resolution failed"));
        return WASI_ERRNO_INVAL;
    }

    newPreopenPath = newPreopenFileDescriptor.path;
    if (newPreopenPath == NULL) {
        WASI_TRACE(("path_rename: bad new preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (!resolvePath(newPreopenPath, newPath, newPathLength, newResolvedPath)) {
        WASI_TRACE(("path_rename: new path resolution failed"));
        return WASI_ERRNO_INVAL;
    }

    WASI_TRACE((
        "path_rename: "
        "oldResolvedPath=%s, "
        "newResolvedPath=%s",
        oldResolvedPath,
        newResolvedPath
    ));

    strcpy(nativeOldResolvedPath, oldResolvedPath);
    strcpy(nativeNewResolvedPath, newResolvedPath);
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativeOldResolvedPath);
    wasiToNativePath(nativeNewResolvedPath);
#endif

    WASI_TRACE((
        "path_rename: "
        "rename(%s, %s)",
        nativeOldResolvedPath,
        nativeNewResolvedPath
    ));

    res = rename(
        nativeOldResolvedPath,
        nativeNewResolvedPath
    );

    if (res != 0) {
        WASI_TRACE(("path_rename: rename failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return WASI_ERRNO_SUCCESS;
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
    char nativeResolvedPath[PATH_MAX];
    int res = -1;
    char *preopenPath = NULL;
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "path_unlink_file("
        "dirFD=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d"
        ")",
        dirFD,
        pathPointer,
        pathLength
    ));

    if (!wasiFileDescriptorGet(dirFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_unlink_file: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_unlink_file: bad path"));
        return WASI_ERRNO_INVAL;
    }
#endif

    WASI_TRACE((
        "path_unlink_file: "
        "path=%.*s",
        pathLength,
        path
    ));

    preopenPath = preopenFileDescriptor.path;
    if (preopenPath == NULL) {
        WASI_TRACE(("path_rename: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (!resolvePath(preopenPath, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_unlink_file: path resolution failed"));
        return WASI_ERRNO_INVAL;
    }

    WASI_TRACE((
        "path_unlink_file: "
        "resolvedPath=%s",
        resolvedPath
    ));

    strcpy(nativeResolvedPath, resolvedPath);
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativeResolvedPath);
#endif

    WASI_TRACE((
        "path_unlink_file: "
        "unlink(%s)",
        nativeResolvedPath
    ));

    res = unlink(nativeResolvedPath);

    if (res != 0) {
        WASI_TRACE(("path_unlink_file: unlink failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return WASI_ERRNO_SUCCESS;
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
    char nativeResolvedPath[PATH_MAX];
    int res = -1;
    char* preopenPath = NULL;
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "path_remove_directory("
        "dirFD=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d"
        ")",
        dirFD,
        pathPointer,
        pathLength
    ));

    if (!wasiFileDescriptorGet(dirFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_remove_directory: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_remove_directory: bad path"));
        return WASI_ERRNO_INVAL;
    }
#endif

    WASI_TRACE((
        "path_remove_directory: "
        "path=%.*s",
        pathLength,
        path
    ));

    preopenPath = preopenFileDescriptor.path;
    if (preopenPath == NULL) {
        WASI_TRACE(("path_remove_directory: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (!resolvePath(preopenPath, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_remove_directory: path resolution failed"));
        return WASI_ERRNO_INVAL;
    }

    WASI_TRACE((
        "path_remove_directory: "
        "resolvedPath=%s",
        resolvedPath
    ));

    strcpy(nativeResolvedPath, resolvedPath);
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativeResolvedPath);
#endif

    WASI_TRACE((
        "path_remove_directory: "
        "rmdir(%s)",
        nativeResolvedPath
    ));

    res = rmdir(nativeResolvedPath);

    if (res != 0) {
        WASI_TRACE(("path_remove_directory: rmdir failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return WASI_ERRNO_SUCCESS;
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
    char nativeResolvedPath[PATH_MAX];
    int res = -1;
    char* preopenPath = NULL;
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "path_create_directory("
        "dirFD=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d"
        ")",
        dirFD,
        pathPointer,
        pathLength
    ));

    if (!wasiFileDescriptorGet(dirFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_create_directory: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_create_directory: bad path"));
        return WASI_ERRNO_INVAL;
    }
#endif

    WASI_TRACE((
        "path_create_directory: "
        "path=%.*s",
        pathLength,
        path
    ));

    preopenPath = preopenFileDescriptor.path;
    if (preopenPath == NULL) {
        WASI_TRACE(("path_create_directory: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (!resolvePath(preopenPath, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_create_directory: path resolution failed"));
        return WASI_ERRNO_INVAL;
    }

    WASI_TRACE(("path_create_directory: resolvedPath=%s", resolvedPath));

    strcpy(nativeResolvedPath, resolvedPath);
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativeResolvedPath);
#endif

    WASI_TRACE((
        "path_create_directory: "
        "mkdir(%s)",
        nativeResolvedPath
    ));

#ifdef _WIN32
    res = _mkdir(nativeResolvedPath);
#else
    res = mkdir(nativeResolvedPath, 0755);
#endif /* _WIN32 */
    if (res != 0) {
        WASI_TRACE(("path_create_directory: mkdir failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return WASI_ERRNO_SUCCESS;
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
    char nativeOldResolvedPath[PATH_MAX];
    char nativeNewResolvedPath[PATH_MAX];
    int res = -1;
    char* preopenPath = NULL;
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "path_symlink("
        "oldPathPointer=0x%x, "
        "oldPathLength=%d, "
        "dirFD=%d, "
        "newPathPointer=0x%x, "
        "newPathLength=%d"
        ")",
        oldPathPointer,
        oldPathLength,
        dirFD,
        newPathPointer,
        newPathLength
    ));

#ifdef _WIN32
    /* TODO: */
    WASI_TRACE(("path_symlink: not supported on Win32"));
    return WASI_ERRNO_NOSYS;
#elif defined(__MWERKS__) && defined(macintosh)
    /* TODO: */
    WASI_TRACE(("path_symlink: not supported on Macintosh"));
    return WASI_ERRNO_NOSYS;
#else

    if (!wasiFileDescriptorGet(dirFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_symlink: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (oldPathLength >= PATH_MAX) {
        WASI_TRACE(("path_symlink: old path too long"));
        return WASI_ERRNO_INVAL;
    }

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    memcpy(oldResolvedPath, memory->data + oldPathPointer, oldPathLength);
    oldResolvedPath[oldPathLength] = '\0';

#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, oldPathPointer, oldPathLength, oldResolvedPath)) {
        WASI_TRACE(("path_symlink: bad old path"));
        return WASI_ERRNO_INVAL;
    }

    if (!getBigEndianPath(memory, newPathPointer, newPathLength, newPath)) {
        WASI_TRACE(("path_symlink: bad new path"));
        return WASI_ERRNO_INVAL;
    }
#endif

    WASI_TRACE((
        "path_symlink: "
        "oldResolvedPath=%s, "
        "newPath=%.*s",
        oldResolvedPath,
        newPathLength,
        newPath
    ));

    preopenPath = preopenFileDescriptor.path;
    if (preopenPath == NULL) {
        WASI_TRACE(("path_symlink: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (!resolvePath(preopenPath, newPath, newPathLength, newResolvedPath)) {
        WASI_TRACE(("path_symlink: new path resolution failed"));
        return WASI_ERRNO_INVAL;
    }

    WASI_TRACE((
        "path_symlink: "
        "newResolvedPath=%s",
        newResolvedPath
    ));

    strcpy(nativeOldResolvedPath, oldResolvedPath);
    strcpy(nativeNewResolvedPath, newResolvedPath);
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativeOldResolvedPath);
    wasiToNativePath(nativeNewResolvedPath);
#endif

    WASI_TRACE((
        "path_symlink: "
        "symlink(%s, %s)",
        nativeOldResolvedPath,
        nativeNewResolvedPath
    ));

    res = symlink(
        nativeOldResolvedPath,
        nativeNewResolvedPath
    );

    if (res != 0) {
        WASI_TRACE(("path_symlink: symlink failed: %s", strerror(errno)));
        return wasiErrno();
    }

    return WASI_ERRNO_SUCCESS;
#endif /* _WIN32 */
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
    char nativeResolvedPath[PATH_MAX];
    char* buffer = NULL;
    long length = 0;
    char* preopenPath = NULL;
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "path_readlink("
        "dirFD=%d, "
        "pathPointer=0x%x, "
        "pathLength=%d, "
        "bufferPointer=0x%x, "
        "bufferLength=%d, "
        "lengthPointer=0x%x"
        ")",
        dirFD,
        pathPointer,
        pathLength,
        bufferPointer,
        bufferLength,
        lengthPointer
    ));

#ifdef _WIN32
    /* TODO: */
    WASI_TRACE(("path_readlink: not supported on Win32"));
    return WASI_ERRNO_NOSYS;
#elif defined(__MWERKS__) && defined(macintosh)
    /* TODO: */
    WASI_TRACE(("path_readlink: not supported on Macintosh"));
    return WASI_ERRNO_NOSYS;
#else
    if (!wasiFileDescriptorGet(dirFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_readlink: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    if (!getBigEndianPath(memory, pathPointer, pathLength, path)) {
        WASI_TRACE(("path_readlink: bad path"));
        return WASI_ERRNO_INVAL;
    }
#endif

    WASI_TRACE((
        "path_readlink: "
        "path=%.*s",
        pathLength,
        path
    ));

    preopenPath = preopenFileDescriptor.path;
    if (preopenPath == NULL) {
        WASI_TRACE(("path_readlink: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (!resolvePath(preopenPath, path, pathLength, resolvedPath)) {
        WASI_TRACE(("path_readlink: path resolution failed"));
        return WASI_ERRNO_INVAL;
    }

    WASI_TRACE((
        "path_readlink: "
        "resolvedPath=%s",
        resolvedPath
    ));

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    buffer = (char*)memory->data + bufferPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    buffer = (char*)memory->data + memory->size - bufferPointer - bufferLength;
#endif

    strcpy(nativeResolvedPath, resolvedPath);
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativeResolvedPath);
#endif

    WASI_TRACE((
        "path_readlink: "
        "readlink(%s)",
        nativeResolvedPath
    ));

    length = readlink(
        nativeResolvedPath,
        buffer,
        bufferLength
    );

    if (length < 0) {
        WASI_TRACE(("path_readlink: readlink failed: %s", strerror(errno)));
        return wasiErrno();
    }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
    {
        U32 i = 0;
        for (; i < length / 2; i++) {
            char value = buffer[i];
            buffer[i] = buffer[length - i - 1];
            buffer[length - i - 1] = value;
        }
    }
#endif

    i32_store(memory, lengthPointer, length);

    return WASI_ERRNO_SUCCESS;
#endif /* _WIN32 */
}

U32
wasiFDFdstatSetFlags(
    void* UNUSED(instance),
    U32 UNUSED(fd),
    U32 UNUSED(flags)
) {
    /* TODO: */
    WASI_TRACE(("fd_fdstat_set_flags: unimplemented function"));
    return WASI_ERRNO_NOSYS;
}

U32
wasiPollOneoff(
    void* UNUSED(instance),
    U32 UNUSED(inPointer),
    U32 UNUSED(outPointer),
    U32 UNUSED(subscriptionCount),
    U32 UNUSED(eventCount)
) {
    /* TODO: */
    WASI_TRACE(("poll_oneoff: unimplemented function"));
    return WASI_ERRNO_NOSYS;
}

U32
wasiRandomGet(
    void* instance,
    U32 bufferPointer,
    U32 bufferLength
) {
    wasmMemory* memory = wasiMemory(instance);
    U8* bufferStart = NULL;
    ssize_t result = 0;

    WASI_TRACE((
        "random_get("
        "bufferPointer=0x%x, "
        "bufferLength=%d"
        ")",
        bufferPointer,
        bufferLength
    ));

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    bufferStart = memory->data + bufferPointer;
#elif WASM_ENDIAN == WASM_BIG_ENDIAN
    bufferStart = memory->data + memory->size - bufferPointer - bufferLength;
#endif

#ifdef _WIN32
#include <wincrypt.h>
    {
        HCRYPTPROV provider;
        bool success;

        if (bufferLength > 256) {
            return WASI_ERRNO_IO;
        }

        if (!CryptAcquireContext(
            &provider,
            NULL,
            NULL,
            PROV_RSA_FULL,
            CRYPT_VERIFYCONTEXT|CRYPT_SILENT
        )) {
            WASI_TRACE(("random_get: CryptAcquireContext failed"));
            return WASI_ERRNO_IO;
        }

        success = CryptGenRandom(
            provider,
            bufferLength,
            bufferStart
        );

        CryptReleaseContext(provider, 0);

        if (!success) {
            WASI_TRACE(("random_get: CryptGenRandom failed"));
            return WASI_ERRNO_IO;
        }
    }
#else
#if HAS_GETENTROPY
    result = getentropy(
        bufferStart,
        bufferLength
    );
    if (result != 0 && result != ENOSYS) {
        WASI_TRACE(("random_get: getentropy failed: %s", strerror(errno)));
        return wasiErrno();
    }
    if (result == ENOSYS)
#endif
    /* Try /dev/random. Might not be available */
    {
        int fd = -1;

        fd = open("/dev/random", O_RDONLY);
        if (fd >= 0) {
            result = read(
                fd,
                bufferStart,
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

            return WASI_ERRNO_SUCCESS;
        }
    }
#if defined(__MWERKS__) && defined(macintosh)
    /* Fall back to rand */
    {
        U32 i = 0;
        srand(time(NULL));

        for (; i < bufferLength; i++) {
            bufferStart[i] = rand();
        }
    }
#else
    /* Fall back to random */
    {
        U32 i = 0;
        srandom(time(NULL));

        for (; i < bufferLength; i++) {
            bufferStart[i] = random();
        }
    }
#endif
#endif
    return WASI_ERRNO_SUCCESS;
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
