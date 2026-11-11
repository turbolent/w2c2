#define _DEFAULT_SOURCE 1

#ifdef _WIN32
#include <winsock2.h>
#elif HAS_SOCKETS
#include <sys/socket.h>
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#if HAS_UNISTD
#include <unistd.h>
#endif /* HAS_UNISTD */

#ifdef _MSC_VER
#if _MSC_VER <= 1000
typedef signed int ssize_t; /* assuming target machine is ILP32 ! */
#else
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif
#endif /* _MSC_VER */

#ifdef _NEXT_SOURCE
typedef unsigned short mode_t;
typedef long ssize_t;

#define dirent direct
#endif /* _NEXT_SOURCE */

#include <time.h>
#if HAS_UTIME
#include <utime.h>
#endif
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

#if HAS_SYSTIME || HAS_FUTIMES || HAS_UTIMES || HAS_LUTIMES
#include <sys/time.h>
#endif /* HAS_SYSTIME */

#if HAS_SYSRESOURCE
#include <sys/resource.h>
#endif /* HAS_SYSRESOURCE */

#if HAS_SYSUIO
#include <sys/uio.h>
#endif /* HAS_SYSUIO */

#if HAS_POLL
#include <poll.h>
#endif /* HAS_POLL */

#if HAS_SCHED_YIELD
#include <sched.h>
#endif /* HAS_SCHED_YIELD */

#if HAS_GETENTROPY && defined(__APPLE__)
#include <AvailabilityMacros.h>
#ifndef MAC_OS_X_VERSION_10_12
#define MAC_OS_X_VERSION_10_12 101200
#endif
#if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12
#include <sys/random.h>
#endif
#endif

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
#define S_IFLNK WASI_WINDOWS_S_IFLNK
#define S_IFIFO _S_IFIFO

#define O_RDONLY _O_RDONLY
#define O_WRONLY _O_WRONLY
#define O_RDWR   _O_RDWR
#define O_APPEND _O_APPEND
#define O_CREAT  _O_CREAT
#define O_TRUNC  _O_TRUNC
#define O_EXCL   _O_EXCL

#define open      wasiWindowsOpen
#define read      _read
#define write     wasiWindowsWrite
#define close     _close
#define mkdir     _mkdir
#define rmdir     wasiWindowsRmdir
#define unlink    wasiWindowsUnlink
#define rename    wasiWindowsRename
#define stat      wasiWindowsStat
#define lstat     wasiWindowsLstat
#define fstat     wasiWindowsFstat
#define symlink   wasiWindowsSymlink
#define readlink  wasiWindowsReadlink
#define lseek     _lseek
#define isatty    _isatty
#define ftruncate _chsize

/* TODO: could be redirected, use _fileno */
#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#undef HAS_NONPOSIXPATH
#define HAS_NONPOSIXPATH 1

#undef HAS_LSTAT
#define HAS_LSTAT 1

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
         ssize_t n = read(fd, iov[i].iov_base, (unsigned int)iov[i].iov_len);
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
            n = write(fd, iov[i].iov_base, (unsigned int)iov[i].iov_len);
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
#else
    UNUSED_PARAMETER(path);
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
#else
    UNUSED_PARAMETER(path);
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

static WASI wasi;

static U32 wasiSocketError(void);
static int wasiSocketClose(WasiNativeSocket nativeSocket);

#ifdef WASM_MUTEX_TYPE
static WASM_MUTEX_TYPE wasiFileDescriptorsMutex;
static bool wasiFileDescriptorsMutexInitialized;
#endif

static
W2C2_INLINE
void
wasiFileDescriptorsLock(void) {
#ifdef WASM_MUTEX_TYPE
    if (wasiFileDescriptorsMutexInitialized) {
        WASM_MUTEX_LOCK(&wasiFileDescriptorsMutex);
    }
#endif
}

static
W2C2_INLINE
void
wasiFileDescriptorsUnlock(void) {
#ifdef WASM_MUTEX_TYPE
    if (wasiFileDescriptorsMutexInitialized) {
        WASM_MUTEX_UNLOCK(&wasiFileDescriptorsMutex);
    }
#endif
}

#ifndef O_DSYNC
#ifdef O_SYNC
#define O_DSYNC O_SYNC /* POSIX */
#endif
#ifdef O_FSYNC
#define O_DSYNC O_FSYNC /* BSD */
#endif
#endif

/* name is the length-prefixed, escaped import-name component. */
#define WASI_UNSTABLE_IMPORT(returnType, name, parameters, body) \
  returnType i13_wasiX5Funstable ## name parameters body

#define WASI_PREVIEW1_IMPORT(returnType, name, parameters, body) \
  returnType i22_wasiX5FsnapshotX5Fpreview1 ## name parameters body

#define WASI_IMPORT(returnType, name, parameters, body) \
  WASI_UNSTABLE_IMPORT(returnType, name, parameters, body) \
  WASI_PREVIEW1_IMPORT(returnType, name, parameters, body)

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
        size_t maximum = (size_t)-1 / sizeof(WasiFileDescriptor);
        if (length > maximum) {
            return false;
        }
        if (newCapacity < length || newCapacity > maximum) {
            newCapacity = length;
        }
        if (descriptors->fds == NULL) {
            newFileDescriptors = calloc(newCapacity, sizeof(WasiFileDescriptor));
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
void
wasiFileDescriptorDefaultRights(
    WasiFileDescriptor* descriptor
) {
    struct stat st;

    descriptor->rightsBase = WASI_RIGHTS_ALL;
    descriptor->rightsInheriting = WASI_RIGHTS_ALL;

    /* Registration also accepts paths and native descriptors
     * that are not yet usable. */
    if (descriptor->fd >= 0) {
        if (fstat(descriptor->fd, &st) != 0) {
            return;
        }
    } else if (descriptor->path != NULL) {
        char nativePath[PATH_MAX];
        strcpy(nativePath, descriptor->path);
#if HAS_NONPOSIXPATH
        wasiToNativePath(nativePath);
#endif
        if (stat(nativePath, &st) != 0) {
            return;
        }
    } else {
        return;
    }

    if (S_ISCHR(st.st_mode) && descriptor->fd >= 0 && isatty(descriptor->fd)) {
        descriptor->rightsBase = WASI_RIGHTS_TTY_BASE;
        descriptor->rightsInheriting = WASI_RIGHTS_TTY_INHERITING;
    } else if (S_ISDIR(st.st_mode)) {
        descriptor->rightsBase = WASI_RIGHTS_DIRECTORY_BASE;
        descriptor->rightsInheriting = WASI_RIGHTS_DIRECTORY_INHERITING;
    } else if (S_ISREG(st.st_mode)) {
        descriptor->rightsBase = WASI_RIGHTS_REGULAR_FILE_BASE;
        descriptor->rightsInheriting = WASI_RIGHTS_REGULAR_FILE_INHERITING;
    }
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasiFileDescriptorsAdd(
    WasiFileDescriptors* descriptors,
    int fd,
    const char* path,
    const char* preopenName,
    WasiRights rightsBase,
    WasiRights rightsInheriting,
    U16 fileFlags
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    descriptor.fd = fd;
    descriptor.fileFlags = fileFlags;
    if (path != NULL) {
        size_t length = strlen(path);
        MUST (length > 0 && length < PATH_MAX)
        descriptor.path = strndup(path, length);
        MUST (descriptor.path != NULL)
    }
    if (preopenName != NULL) {
        size_t length = strlen(preopenName);
        if (length == 0 || length >= PATH_MAX) {
            free(descriptor.path);
            return false;
        }
        descriptor.preopenName = strndup(preopenName, length);
        if (descriptor.preopenName == NULL) {
            free(descriptor.path);
            return false;
        }
    }
    wasiFileDescriptorDefaultRights(&descriptor);
    descriptor.rightsBase &= rightsBase;
    descriptor.rightsInheriting &= rightsInheriting;
    if (descriptors->length == (size_t)-1
        || !wasiFileDescriptorsEnsureCapacity(descriptors, descriptors->length + 1)) {
        free(descriptor.preopenName);
        free(descriptor.path);
        return false;
    }
    descriptors->fds[descriptors->length++] = descriptor;
    return true;
}

static
bool
WARN_UNUSED_RESULT
wasiFileDescriptorAddWithRights(
    int nativeFD,
    const char* path,
    const char* preopenName,
    WasiRights rightsBase,
    WasiRights rightsInheriting,
    U16 fileFlags,
    U32* wasiFD
) {
    bool added;
    wasiFileDescriptorsLock();
    added = (U64)wasi.fds.length <= (U64)UINT32_MAX
            && wasiFileDescriptorsAdd(
                &wasi.fds,
                nativeFD,
                path,
                preopenName,
                rightsBase,
                rightsInheriting,
                fileFlags
            );
    if (added && wasiFD != NULL) {
        *wasiFD = (U32)(wasi.fds.length - 1);
    }
    wasiFileDescriptorsUnlock();
    return added;
}

bool
WARN_UNUSED_RESULT
wasiFileDescriptorAdd(
    int nativeFD,
    char* path,
    U32* wasiFD
) {
    return wasiFileDescriptorAddWithRights(
        nativeFD,
        path,
        path,
        WASI_RIGHTS_ALL,
        WASI_RIGHTS_ALL,
        0,
        wasiFD
    );
}

bool
WARN_UNUSED_RESULT
wasiPreopenDirectory(
    const char* path,
    const char* name,
    U32* wasiFD
) {
    MUST (path != NULL && name != NULL)
    return wasiFileDescriptorAddWithRights(
        -1,
        path,
        name,
        WASI_RIGHTS_DIRECTORY_BASE,
        WASI_RIGHTS_DIRECTORY_INHERITING,
        0,
        wasiFD
    );
}

bool
WARN_UNUSED_RESULT
wasiFileDescriptorSet(
    U32 wasiFD,
    int nativeFD
) {
    bool valid;
    wasiFileDescriptorsLock();
    valid = wasiFD < wasi.fds.length
            && wasi.fds.fds[wasiFD].socket == WASI_INVALID_SOCKET;
    if (valid) {
        wasi.fds.fds[wasiFD].fd = nativeFD;
    }
    wasiFileDescriptorsUnlock();
    return valid;
}

static
bool
WARN_UNUSED_RESULT
wasiFileDescriptorGetLocked(
    U32 wasiFD,
    WasiFileDescriptor* result
) {
    MUST (wasiFD < wasi.fds.length)
    *result = wasi.fds.fds[wasiFD];
    return result->fd >= 0 || result->path != NULL
           || result->socket != WASI_INVALID_SOCKET;
}

bool
WARN_UNUSED_RESULT
wasiFileDescriptorGet(
    U32 wasiFD,
    WasiFileDescriptor* result
) {
    bool valid;
    wasiFileDescriptorsLock();
    valid = wasiFileDescriptorGetLocked(wasiFD, result);
    wasiFileDescriptorsUnlock();
    return valid;
}

static
W2C2_INLINE
bool
wasiFileDescriptorHasRights(
    const WasiFileDescriptor* descriptor,
    WasiRights required
) {
    WasiRights rights = descriptor->rightsBase;
    /* Seeking also permits querying the current offset. */
    if (rights & WASI_RIGHTS_FD_SEEK) {
        rights |= WASI_RIGHTS_FD_TELL;
    }
    return (rights & required) == required;
}

static
bool
WARN_UNUSED_RESULT
wasiDirectorySet(
    U32 wasiFD,
    DIR* nativeDir
) {
    bool valid;
    wasiFileDescriptorsLock();
    valid = wasiFD < wasi.fds.length;
    if (valid) {
        wasi.fds.fds[wasiFD].dir = nativeDir;
    }
    wasiFileDescriptorsUnlock();
    return valid;
}

static
bool
WARN_UNUSED_RESULT
wasiFileDescriptorRelease(
    WasiFileDescriptor* descriptor
) {
    if (descriptor->socket != WASI_INVALID_SOCKET) {
        MUST (wasiSocketClose(descriptor->socket) == 0)
        descriptor->socket = WASI_INVALID_SOCKET;
    }
    if (descriptor->dir != NULL) {
        int error = closedir(descriptor->dir);
        descriptor->dir = NULL;
        MUST (error == 0)
    }
    /* Directory streams are opened separately from the native descriptor. */
    if (descriptor->fd >= 0) {
        MUST (close(descriptor->fd) == 0)
        descriptor->fd = -1;
    }

    if (descriptor->path != NULL) {
        free(descriptor->path);
        descriptor->path = NULL;
    }
    free(descriptor->preopenName);
    descriptor->preopenName = NULL;

    return true;
}

bool
WARN_UNUSED_RESULT
wasiFileDescriptorClose(
    U32 wasiFD
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    bool closed;
    wasiFileDescriptorsLock();
    closed = wasiFileDescriptorGetLocked(wasiFD, &descriptor)
             && wasiFileDescriptorRelease(&wasi.fds.fds[wasiFD]);
    if (closed) {
        wasi.fds.fds[wasiFD] = emptyWasiFileDescriptor;
    }
    wasiFileDescriptorsUnlock();
    return closed;
}

bool
WARN_UNUSED_RESULT
wasiInit(
    int argc,
    char* argv[],
    char** envp
) {
    int envc = 0;
#ifdef WASM_MUTEX_TYPE
    if (!wasiFileDescriptorsMutexInitialized) {
        MUST (WASM_MUTEX_INIT(&wasiFileDescriptorsMutex))
        wasiFileDescriptorsMutexInitialized = true;
    }
#endif
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
#ifdef ELOOP
    case ELOOP:
        return WASI_ERRNO_LOOP;
#endif
#ifdef ENAMETOOLONG
    case ENAMETOOLONG:
        return WASI_ERRNO_NAMETOOLONG;
#endif
#ifdef ENOTEMPTY
    case ENOTEMPTY:
        return WASI_ERRNO_NOTEMPTY;
#endif
#ifdef EOVERFLOW
    case EOVERFLOW:
        return WASI_ERRNO_OVERFLOW;
#endif
#ifdef ENOSYS
    case ENOSYS:
        return WASI_ERRNO_NOSYS;
#endif
#ifdef ENOTSUP
    case ENOTSUP:
        return WASI_ERRNO_NOTSUP;
#endif
#if defined(EOPNOTSUPP) && (!defined(ENOTSUP) || EOPNOTSUPP != ENOTSUP)
    case EOPNOTSUPP:
        return WASI_ERRNO_NOTSUP;
#endif
#if defined(EWOULDBLOCK) && EWOULDBLOCK != EAGAIN
    case EWOULDBLOCK:
        return WASI_ERRNO_AGAIN;
#endif
#if defined(EINPROGRESS)
    case EINPROGRESS:
        return WASI_ERRNO_INPROGRESS;
#endif
#if defined(EALREADY)
    case EALREADY:
        return WASI_ERRNO_ALREADY;
#endif
#if defined(ENOTSOCK)
    case ENOTSOCK:
        return WASI_ERRNO_NOTSOCK;
#endif
#if defined(EDESTADDRREQ)
    case EDESTADDRREQ:
        return WASI_ERRNO_DESTADDRREQ;
#endif
#if defined(EMSGSIZE)
    case EMSGSIZE:
        return WASI_ERRNO_MSGSIZE;
#endif
#if defined(EPROTOTYPE)
    case EPROTOTYPE:
        return WASI_ERRNO_PROTOTYPE;
#endif
#if defined(ENOPROTOOPT)
    case ENOPROTOOPT:
        return WASI_ERRNO_NOPROTOOPT;
#endif
#if defined(EPROTONOSUPPORT)
    case EPROTONOSUPPORT:
        return WASI_ERRNO_PROTONOSUPPORT;
#endif
#if defined(EAFNOSUPPORT)
    case EAFNOSUPPORT:
        return WASI_ERRNO_AFNOSUPPORT;
#endif
#if defined(EADDRINUSE)
    case EADDRINUSE:
        return WASI_ERRNO_ADDRINUSE;
#endif
#if defined(EADDRNOTAVAIL)
    case EADDRNOTAVAIL:
        return WASI_ERRNO_ADDRNOTAVAIL;
#endif
#if defined(ENETDOWN)
    case ENETDOWN:
        return WASI_ERRNO_NETDOWN;
#endif
#if defined(ENETUNREACH)
    case ENETUNREACH:
        return WASI_ERRNO_NETUNREACH;
#endif
#if defined(ENETRESET)
    case ENETRESET:
        return WASI_ERRNO_NETRESET;
#endif
#if defined(ECONNABORTED)
    case ECONNABORTED:
        return WASI_ERRNO_CONNABORTED;
#endif
#if defined(ECONNRESET)
    case ECONNRESET:
        return WASI_ERRNO_CONNRESET;
#endif
#if defined(ENOBUFS)
    case ENOBUFS:
        return WASI_ERRNO_NOBUFS;
#endif
#if defined(EISCONN)
    case EISCONN:
        return WASI_ERRNO_ISCONN;
#endif
#if defined(ENOTCONN)
    case ENOTCONN:
        return WASI_ERRNO_NOTCONN;
#endif
#if defined(ETIMEDOUT)
    case ETIMEDOUT:
        return WASI_ERRNO_TIMEDOUT;
#endif
#if defined(ECONNREFUSED)
    case ECONNREFUSED:
        return WASI_ERRNO_CONNREFUSED;
#endif
#if defined(EHOSTUNREACH)
    case EHOSTUNREACH:
        return WASI_ERRNO_HOSTUNREACH;
#endif
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

WASI_IMPORT(void, 9_procX5Fexit, (
    wasmModuleInstance* instance,
    U32 code
), {
    UNUSED_PARAMETER(instance);

    WASI_TRACE((
        "proc_exit("
        "code=%d"
        ")",
        code
    ));

    exit(code);
})

static
int
wasiSignalToNative(U32 signal) {
    switch (signal) {
        case WASI_SIGNAL_INT: return SIGINT;
        case WASI_SIGNAL_ILL: return SIGILL;
        case WASI_SIGNAL_ABRT: return SIGABRT;
        case WASI_SIGNAL_FPE: return SIGFPE;
        case WASI_SIGNAL_SEGV: return SIGSEGV;
        case WASI_SIGNAL_TERM: return SIGTERM;
        /* The Windows CRT only accepts the six standard C signals. */
#ifndef _WIN32
#ifdef SIGHUP
        case WASI_SIGNAL_HUP: return SIGHUP;
#endif
#ifdef SIGQUIT
        case WASI_SIGNAL_QUIT: return SIGQUIT;
#endif
#ifdef SIGTRAP
        case WASI_SIGNAL_TRAP: return SIGTRAP;
#endif
#ifdef SIGBUS
        case WASI_SIGNAL_BUS: return SIGBUS;
#endif
#ifdef SIGKILL
        case WASI_SIGNAL_KILL: return SIGKILL;
#endif
#ifdef SIGUSR1
        case WASI_SIGNAL_USR1: return SIGUSR1;
#endif
#ifdef SIGUSR2
        case WASI_SIGNAL_USR2: return SIGUSR2;
#endif
#ifdef SIGPIPE
        case WASI_SIGNAL_PIPE: return SIGPIPE;
#endif
#ifdef SIGALRM
        case WASI_SIGNAL_ALRM: return SIGALRM;
#endif
#ifdef SIGCHLD
        case WASI_SIGNAL_CHLD: return SIGCHLD;
#endif
#ifdef SIGCONT
        case WASI_SIGNAL_CONT: return SIGCONT;
#endif
#ifdef SIGSTOP
        case WASI_SIGNAL_STOP: return SIGSTOP;
#endif
#ifdef SIGTSTP
        case WASI_SIGNAL_TSTP: return SIGTSTP;
#endif
#ifdef SIGTTIN
        case WASI_SIGNAL_TTIN: return SIGTTIN;
#endif
#ifdef SIGTTOU
        case WASI_SIGNAL_TTOU: return SIGTTOU;
#endif
#ifdef SIGURG
        case WASI_SIGNAL_URG: return SIGURG;
#endif
#ifdef SIGXCPU
        case WASI_SIGNAL_XCPU: return SIGXCPU;
#endif
#ifdef SIGXFSZ
        case WASI_SIGNAL_XFSZ: return SIGXFSZ;
#endif
#ifdef SIGVTALRM
        case WASI_SIGNAL_VTALRM: return SIGVTALRM;
#endif
#ifdef SIGPROF
        case WASI_SIGNAL_PROF: return SIGPROF;
#endif
#ifdef SIGWINCH
        case WASI_SIGNAL_WINCH: return SIGWINCH;
#endif
#if defined(SIGPOLL)
        case WASI_SIGNAL_POLL: return SIGPOLL;
#elif defined(SIGIO)
        case WASI_SIGNAL_POLL: return SIGIO;
#endif
#ifdef SIGPWR
        case WASI_SIGNAL_PWR: return SIGPWR;
#endif
#ifdef SIGSYS
        case WASI_SIGNAL_SYS: return SIGSYS;
#endif
#endif /* !_WIN32 */
        default: return 0;
    }
}

static
U32
wasiProcRaise(U32 signal) {
    int nativeSignal;

    WASI_TRACE(("proc_raise(signal=%u)", signal));

    if (signal == WASI_SIGNAL_NONE || signal > WASI_SIGNAL_SYS) {
        return WASI_ERRNO_INVAL;
    }
    nativeSignal = wasiSignalToNative(signal);
    if (nativeSignal == 0) {
        return WASI_ERRNO_NOTSUP;
    }

    /* C does not require raise to set errno on failure. */
    errno = 0;
    if (raise(nativeSignal) != 0) {
        return errno == 0 ? WASI_ERRNO_IO : wasiErrno();
    }
    return WASI_ERRNO_SUCCESS;
}

WASI_IMPORT(U32, 10_procX5Fraise, (
    wasmModuleInstance* instance,
    U32 signal
), {
    UNUSED_PARAMETER(instance);
    return wasiProcRaise(signal);
})

static
W2C2_INLINE
bool
wasiMemoryRangeIsValid(
    wasmMemory* memory,
    U32 pointer,
    U32 count,
    U32 size
) {
    U64 length = (U64)count * size;
    U64 end = (U64)pointer + length;

    return memory != NULL
           && length <= UINT32_MAX
           && end <= (U64)wasmMemorySize(memory) * WASM_PAGE_SIZE;
}

static
U32
wasiSocketError(void) {
#ifdef _WIN32
    switch (WSAGetLastError()) {
        case WSAEWOULDBLOCK: return WASI_ERRNO_AGAIN;
        case WSAEINTR: return WASI_ERRNO_INTR;
        case WSAEBADF: return WASI_ERRNO_BADF;
        case WSAEACCES: return WASI_ERRNO_ACCES;
        case WSAEFAULT: return WASI_ERRNO_FAULT;
        case WSAEINVAL: return WASI_ERRNO_INVAL;
        case WSAEMFILE: return WASI_ERRNO_MFILE;
        case WSAEINPROGRESS: return WASI_ERRNO_INPROGRESS;
        case WSAEALREADY: return WASI_ERRNO_ALREADY;
        case WSAENOTSOCK: return WASI_ERRNO_NOTSOCK;
        case WSAEDESTADDRREQ: return WASI_ERRNO_DESTADDRREQ;
        case WSAEMSGSIZE: return WASI_ERRNO_MSGSIZE;
        case WSAEPROTOTYPE: return WASI_ERRNO_PROTOTYPE;
        case WSAENOPROTOOPT: return WASI_ERRNO_NOPROTOOPT;
        case WSAEPROTONOSUPPORT: return WASI_ERRNO_PROTONOSUPPORT;
        case WSAEOPNOTSUPP: return WASI_ERRNO_NOTSUP;
        case WSAEAFNOSUPPORT: return WASI_ERRNO_AFNOSUPPORT;
        case WSAEADDRINUSE: return WASI_ERRNO_ADDRINUSE;
        case WSAEADDRNOTAVAIL: return WASI_ERRNO_ADDRNOTAVAIL;
        case WSAENETDOWN: return WASI_ERRNO_NETDOWN;
        case WSAENETUNREACH: return WASI_ERRNO_NETUNREACH;
        case WSAENETRESET: return WASI_ERRNO_NETRESET;
        case WSAECONNABORTED: return WASI_ERRNO_CONNABORTED;
        case WSAECONNRESET: return WASI_ERRNO_CONNRESET;
        case WSAENOBUFS: return WASI_ERRNO_NOBUFS;
        case WSAEISCONN: return WASI_ERRNO_ISCONN;
        case WSAENOTCONN: return WASI_ERRNO_NOTCONN;
        case WSAESHUTDOWN: return WASI_ERRNO_PIPE;
        case WSAETIMEDOUT: return WASI_ERRNO_TIMEDOUT;
        case WSAECONNREFUSED: return WASI_ERRNO_CONNREFUSED;
        case WSAEHOSTUNREACH: return WASI_ERRNO_HOSTUNREACH;
        case WSANOTINITIALISED: return WASI_ERRNO_NOSYS;
        default: return WASI_ERRNO_IO;
    }
#else
    return wasiErrno();
#endif
}

static
int
wasiSocketClose(WasiNativeSocket nativeSocket) {
#ifdef _WIN32
    return closesocket(nativeSocket);
#elif HAS_SOCKETS
    return close(nativeSocket);
#else
    UNUSED_PARAMETER(nativeSocket);
    return -1;
#endif
}

static
U32
wasiSocketSetFlags(WasiNativeSocket nativeSocket, U32 flags) {
    if (flags & ~(U32)(WASI_FDFLAGS_APPEND | WASI_FDFLAGS_DSYNC |
                      WASI_FDFLAGS_NONBLOCK | WASI_FDFLAGS_RSYNC |
                      WASI_FDFLAGS_SYNC)) {
        return WASI_ERRNO_INVAL;
    }
    if (flags & ~(U32)WASI_FDFLAGS_NONBLOCK) {
        return WASI_ERRNO_NOTSUP;
    }
#ifdef _WIN32
    {
        u_long nonblocking = (flags & WASI_FDFLAGS_NONBLOCK) != 0;
        if (ioctlsocket(nativeSocket, FIONBIO, &nonblocking) != 0) {
            return wasiSocketError();
        }
    }
#elif HAS_SOCKETS && HAS_FCNTL
    {
        int nativeFlags = fcntl(nativeSocket, F_GETFL);
        if (nativeFlags < 0) {
            return wasiErrno();
        }
        nativeFlags &= ~O_NONBLOCK;
        if (flags & WASI_FDFLAGS_NONBLOCK) {
            nativeFlags |= O_NONBLOCK;
        }
        if (fcntl(nativeSocket, F_SETFL, nativeFlags) != 0) {
            return wasiErrno();
        }
    }
#else
    UNUSED_PARAMETER(nativeSocket);
    return WASI_ERRNO_NOSYS;
#endif
    return WASI_ERRNO_SUCCESS;
}

#if HAS_SOCKETS || defined(_WIN32)
static
U32
wasiSocketConfigure(
    WasiNativeSocket nativeSocket,
    U32 flags,
    WasiFileDescriptor* descriptor
) {
    int type = 0;
#ifdef _WIN32
    int length = sizeof(type);
#else
    socklen_t length = sizeof(type);
#endif
    U32 error;
    if (getsockopt(
        nativeSocket, SOL_SOCKET, SO_TYPE, (char*)&type, &length
    ) != 0) {
        return wasiSocketError();
    }
    if (type != SOCK_STREAM && type != SOCK_DGRAM) {
        return WASI_ERRNO_NOTSUP;
    }
    error = wasiSocketSetFlags(nativeSocket, flags);
    if (error != WASI_ERRNO_SUCCESS) {
        return error;
    }
#ifdef SO_NOSIGPIPE
    {
        int enabled = 1;
        if (setsockopt(
            nativeSocket, SOL_SOCKET, SO_NOSIGPIPE,
            (const char*)&enabled, sizeof(enabled)
        ) != 0) {
            return wasiSocketError();
        }
    }
#endif
    descriptor->socket = nativeSocket;
    descriptor->socketType = type == SOCK_STREAM
        ? WASI_FILE_TYPE_SOCKET_STREAM : WASI_FILE_TYPE_SOCKET_DGRAM;
    descriptor->socketFlags = (U16)flags;
    return WASI_ERRNO_SUCCESS;
}
#endif

static
U32
wasiSocketAddWithRights(
    WasiNativeSocket nativeSocket,
    U32 flags,
    WasiRights base,
    WasiRights inheriting,
    U32* wasiFD
) {
#if HAS_SOCKETS || defined(_WIN32)
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    U32 error = wasiSocketConfigure(nativeSocket, flags, &descriptor);
    if (error != WASI_ERRNO_SUCCESS) {
        return error;
    }
    descriptor.rightsBase = base & WASI_RIGHTS_SOCKET_BASE;
    descriptor.rightsInheriting = inheriting & WASI_RIGHTS_SOCKET_BASE;

    wasiFileDescriptorsLock();
    if ((U64)wasi.fds.length > (U64)UINT32_MAX
        || wasi.fds.length == (size_t)-1
        || !wasiFileDescriptorsEnsureCapacity(&wasi.fds, wasi.fds.length + 1)) {
        error = WASI_ERRNO_NOMEM;
    } else {
        if (wasiFD != NULL) {
            *wasiFD = (U32)wasi.fds.length;
        }
        wasi.fds.fds[wasi.fds.length++] = descriptor;
    }
    wasiFileDescriptorsUnlock();
    return error;
#else
    UNUSED_PARAMETER(nativeSocket);
    UNUSED_PARAMETER(flags);
    UNUSED_PARAMETER(base);
    UNUSED_PARAMETER(inheriting);
    UNUSED_PARAMETER(wasiFD);
    return WASI_ERRNO_NOSYS;
#endif
}

bool
WARN_UNUSED_RESULT
wasiSocketAdd(
    WasiNativeSocket nativeSocket,
    U32 flags,
    U32* wasiFD
) {
    return wasiSocketAddWithRights(
        nativeSocket,
        flags,
        WASI_RIGHTS_SOCKET_BASE,
        WASI_RIGHTS_SOCKET_BASE,
        wasiFD
    ) == WASI_ERRNO_SUCCESS;
}

static
U32
wasiSocketGet(
    U32 wasiFD,
    WasiRights rights,
    WasiFileDescriptor* descriptor
) {
    if (!wasiFileDescriptorGet(wasiFD, descriptor)) {
        return WASI_ERRNO_BADF;
    }
    if (descriptor->socket == WASI_INVALID_SOCKET) {
        return WASI_ERRNO_NOTSOCK;
    }
    if (!wasiFileDescriptorHasRights(descriptor, rights)) {
        return WASI_ERRNO_NOTCAPABLE;
    }
    return WASI_ERRNO_SUCCESS;
}

static
U32
wasiSocketTransfer(
    wasmMemory* memory,
    const WasiFileDescriptor* descriptor,
    U32 vectorsPointer,
    U32 vectorsCount,
    U32 flags,
    U32 sizePointer,
    U16* flagsResult,
    bool receive
) {
#if HAS_SOCKETS || defined(_WIN32)
#ifdef _WIN32
    WSABUF* vectors;
    DWORD transferred = 0;
    DWORD nativeFlags = 0;
    int result;
#else
    struct iovec* vectors;
    struct msghdr message;
    int nativeFlags = 0;
    ssize_t transferred;
#endif
    U32 i, count = vectorsCount == 0 ? 1 : vectorsCount;
    U64 capacity = 0;
    U16 resultFlags = 0;
    U32 error = WASI_ERRNO_SUCCESS;

    if (receive) {
        if (flags & ~(U32)(WASI_RIFLAGS_RECV_PEEK | WASI_RIFLAGS_RECV_WAITALL)) {
            return WASI_ERRNO_INVAL;
        }
        if (flags & WASI_RIFLAGS_RECV_PEEK) {
            nativeFlags |= MSG_PEEK;
        }
        if (flags & WASI_RIFLAGS_RECV_WAITALL) {
#ifdef MSG_WAITALL
            nativeFlags |= MSG_WAITALL;
#else
            return WASI_ERRNO_NOTSUP;
#endif
        }
    } else if (flags != 0) {
        return WASI_ERRNO_INVAL;
    }
    if (!wasiMemoryRangeIsValid(memory, vectorsPointer, vectorsCount, 8)
        || !wasiMemoryRangeIsValid(memory, sizePointer, 1, 4)) {
        return WASI_ERRNO_FAULT;
    }
    if (count > INT_MAX || (U64)count * sizeof(*vectors) > (size_t)-1) {
        return WASI_ERRNO_INVAL;
    }
    vectors = calloc(count, sizeof(*vectors));
    if (vectors == NULL) {
        return WASI_ERRNO_NOMEM;
    }
    for (i = 0; i < vectorsCount; i++) {
        U32 pointer = i32_load(memory, vectorsPointer + i * 8);
        U32 length = i32_load(memory, vectorsPointer + i * 8 + 4);
        if (!wasiMemoryRangeIsValid(memory, pointer, length, 1)) {
            error = WASI_ERRNO_FAULT;
            goto done;
        }
        capacity += length;
        if (capacity > INT_MAX) {
            error = WASI_ERRNO_INVAL;
            goto done;
        }
#ifdef _WIN32
        vectors[i].buf = (char*)memory->data + pointer;
        vectors[i].len = length;
#else
        vectors[i].iov_base = memory->data + pointer;
        vectors[i].iov_len = length;
#endif
    }
    if (capacity == 0 && descriptor->socketType == WASI_FILE_TYPE_SOCKET_STREAM) {
        i32_store(memory, sizePointer, 0);
        if (flagsResult != NULL) {
            *flagsResult = 0;
        }
        goto done;
    }

#ifdef _WIN32
    if (receive) {
        result = WSARecv(
            descriptor->socket, vectors, count, &transferred,
            &nativeFlags, NULL, NULL
        );
    } else {
        result = WSASend(
            descriptor->socket, vectors, count, &transferred,
            0, NULL, NULL
        );
    }
    if (result != 0) {
        if (receive && descriptor->socketType == WASI_FILE_TYPE_SOCKET_DGRAM
            && WSAGetLastError() == WSAEMSGSIZE) {
            transferred = (DWORD)capacity;
            resultFlags = WASI_ROFLAGS_RECV_DATA_TRUNCATED;
        } else {
            error = wasiSocketError();
            goto done;
        }
    }
    if (receive && (nativeFlags & MSG_PARTIAL)) {
        resultFlags = WASI_ROFLAGS_RECV_DATA_TRUNCATED;
    }
#else
    memset(&message, 0, sizeof(message));
    message.msg_iov = vectors;
    message.msg_iovlen = count;
    if (receive) {
        transferred = recvmsg(descriptor->socket, &message, nativeFlags);
    } else {
#ifdef MSG_NOSIGNAL
        nativeFlags |= MSG_NOSIGNAL;
#endif
        transferred = sendmsg(descriptor->socket, &message, nativeFlags);
    }
    if (transferred < 0) {
        error = wasiSocketError();
        goto done;
    }
    if (receive && (message.msg_flags & MSG_TRUNC)) {
        resultFlags = WASI_ROFLAGS_RECV_DATA_TRUNCATED;
    }
#endif
    i32_store(memory, sizePointer, (U32)transferred);
    if (flagsResult != NULL) {
        *flagsResult = resultFlags;
    }
done:
    free(vectors);
    return error;
#else
    UNUSED_PARAMETER(memory);
    UNUSED_PARAMETER(descriptor);
    UNUSED_PARAMETER(vectorsPointer);
    UNUSED_PARAMETER(vectorsCount);
    UNUSED_PARAMETER(flags);
    UNUSED_PARAMETER(sizePointer);
    UNUSED_PARAMETER(flagsResult);
    UNUSED_PARAMETER(receive);
    return WASI_ERRNO_NOSYS;
#endif
}

static const U32 ciovecSize = 8;

static
W2C2_INLINE
U32
wasiFDWrite(
    wasmMemory* memory,
    ssize_t writeFunc(int, const struct iovec*, int, off_t),
    U32 wasiFD,
    U32 ciovecsPointer,
    U32 ciovecsCount,
    U32 resultPointer,
    off_t offset,
    WasiRights requiredRights
) {
    struct iovec* iovecs = NULL;
    I64 total = 0;
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;

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
    if (!wasiFileDescriptorHasRights(&descriptor, requiredRights)) {
        return WASI_ERRNO_NOTCAPABLE;
    }

    if (descriptor.socket != WASI_INVALID_SOCKET) {
        return wasiSocketTransfer(
            memory, &descriptor, ciovecsPointer, ciovecsCount,
            0, resultPointer, NULL, false
        );
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

    /* Convert WASI ciovecs to native iovecs */
    {
        U32 ciovecIndex = 0;
        for (; ciovecIndex < ciovecsCount; ciovecIndex++) {
            WasmPtr ciovecPointer =
                ciovecsPointer + ciovecIndex * ciovecSize;
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

            iovecs[ciovecIndex].iov_base = (void*)(memory->data + bufferPointer);
            iovecs[ciovecIndex].iov_len = length;
        }
    }

    /* Perform the writes */
#ifdef _WIN32
    if ((descriptor.fileFlags & WASI_FDFLAGS_APPEND) != 0
        && requiredRights == WASI_RIGHTS_FD_WRITE
        && lseek(descriptor.fd, 0, SEEK_END) == (off_t)-1) {
        free(iovecs);
        return wasiErrno();
    }
#endif
    total = writeFunc(descriptor.fd, iovecs, ciovecsCount, offset);

    free(iovecs);

    if (total < 0) {
        WASI_TRACE(("fd_write: writev failed: %s", strerror(errno)));
        return wasiErrno();
    }
    if ((U64)total > (U64)UINT32_MAX) {
        return WASI_ERRNO_OVERFLOW;
    }

    /* Store the amount of written bytes at the result pointer */
    i32_store(memory, resultPointer, (U32)total);

    return WASI_ERRNO_SUCCESS;
}

ssize_t
writevWrapper(
    int fd,
    const struct iovec* iovecs,
    int count,
    off_t offset
) {
    UNUSED_PARAMETER(offset);
    return writev(fd, iovecs, count);
}

WASI_IMPORT(U32, 8_fdX5Fwrite, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 ciovecsPointer,
    U32 ciovecsCount,
    U32 resultPointer
), {
    wasmMemory* memory = wasiMemory(instance);
    /* NOTE: offset -1 is ignored by writevWrapper */
    const int offset = -1;
    return wasiFDWrite(
        memory,
        writevWrapper,
        wasiFD,
        ciovecsPointer,
        ciovecsCount,
        resultPointer,
        offset,
        WASI_RIGHTS_FD_WRITE
    );
})

static
W2C2_INLINE
ssize_t
wrapPositional(
    ssize_t f(int, const struct iovec*, int, off_t),
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

    res = f(fd, iovecs, count, 0);

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
pwritevFallback(
    int fd,
    const struct iovec* iovecs,
    int count,
    off_t offset
) {
    return wrapPositional(writevWrapper, fd, iovecs, count, offset);
}

WASI_IMPORT(U32, 9_fdX5Fpwrite, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 iovecsPointer,
    U32 iovecsCount,
    U64 offset,
    U32 resultPointer
), {
    wasmMemory* memory = wasiMemory(instance);
    if ((off_t)offset < 0 || (U64)(off_t)offset != offset) {
        return WASI_ERRNO_OVERFLOW;
    }
    return wasiFDWrite(
        memory,
        pwritevFallback,
        wasiFD,
        iovecsPointer,
        iovecsCount,
        resultPointer,
        (off_t)offset,
        WASI_RIGHTS_FD_WRITE | WASI_RIGHTS_FD_SEEK
    );
})

static const U32 iovecSize = 8;

static
U32
wasiFDRead(
    wasmMemory* memory,
    ssize_t readFunc(int, const struct iovec*, int, off_t),
    U32 wasiFD,
    U32 iovecsPointer,
    U32 iovecsCount,
    U32 resultPointer,
    off_t offset,
    WasiRights requiredRights
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
    if (!wasiFileDescriptorHasRights(&descriptor, requiredRights)) {
        return WASI_ERRNO_NOTCAPABLE;
    }

    if (descriptor.socket != WASI_INVALID_SOCKET) {
        return wasiSocketTransfer(
            memory, &descriptor, iovecsPointer, iovecsCount,
            0, resultPointer, NULL, true
        );
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
        U32 iovecIndex = 0;
        for (; iovecIndex < iovecsCount; iovecIndex++) {
            WasmPtr iovecPointer =
                iovecsPointer + iovecIndex * iovecSize;
            U32 bufferPointer = i32_load(memory, iovecPointer);
            U32 length = i32_load(memory, iovecPointer + 4);
            iovecs[iovecIndex].iov_base = (void*)(memory->data + bufferPointer);
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

    free(iovecs);

    if ((U64)total > (U64)UINT32_MAX) {
        return WASI_ERRNO_OVERFLOW;
    }

    /* Store the amount of read bytes at the result pointer */
    i32_store(memory, resultPointer, (U32)total);

    return WASI_ERRNO_SUCCESS;
}

ssize_t
readvWrapper(
    int fd,
    const struct iovec* iovecs,
    int count,
    off_t offset
) {
    UNUSED_PARAMETER(offset);
    return readv(fd, iovecs, count);
}

WASI_IMPORT(U32, 7_fdX5Fread, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 iovecsPointer,
    U32 iovecsCount,
    U32 resultPointer
), {
    wasmMemory* memory = wasiMemory(instance);
    /* NOTE: offset -1 is ignored by readvWrapper */
    const int offset = -1;
    return wasiFDRead(
        memory,
        readvWrapper,
        wasiFD,
        iovecsPointer,
        iovecsCount,
        resultPointer,
        offset,
        WASI_RIGHTS_FD_READ
    );
})

static
ssize_t
preadvFallback(
    int fd,
    const struct iovec* iovecs,
    int count,
    off_t offset
) {
    return wrapPositional(readvWrapper, fd, iovecs, count, offset);
}

WASI_IMPORT(U32, 8_fdX5Fpread, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 iovecsPointer,
    U32 iovecsCount,
    U64 offset,
    U32 resultPointer
), {
    wasmMemory* memory = wasiMemory(instance);
    if ((off_t)offset < 0 || (U64)(off_t)offset != offset) {
        return WASI_ERRNO_OVERFLOW;
    }
    return wasiFDRead(
        memory,
        preadvFallback,
        wasiFD,
        iovecsPointer,
        iovecsCount,
        resultPointer,
        (off_t)offset,
        WASI_RIGHTS_FD_READ | WASI_RIGHTS_FD_SEEK
    );
})

WASI_IMPORT(U32, 17_environX5FsizesX5Fget, (
    wasmModuleInstance* instance,
    U32 envcPointer,
    U32 envpBufSizePointer
), {
    wasmMemory* memory = wasiMemory(instance);

    int envpIndex = 0;
    U32 envpBufSize = 0;

    WASI_TRACE((
        "environ_sizes_get("
        "envcPointer=0x%x, "
        "envpBufSizePointer=0x%x"
        ")",
        envcPointer,
        envpBufSizePointer
    ));

    while (wasi.envp[envpIndex] != NULL) {
        const size_t length = strlen(wasi.envp[envpIndex]) + 1;
        if ((U64)length > (U64)UINT32_MAX - envpBufSize) {
            return WASI_ERRNO_OVERFLOW;
        }
        envpBufSize += (U32)length;
        envpIndex++;
    }

    i32_store(memory, envcPointer, wasi.envc);
    i32_store(memory, envpBufSizePointer, envpBufSize);

    return WASI_ERRNO_SUCCESS;
})

static
W2C2_INLINE
U32
wasiEnvironGet(
    wasmModuleInstance* instance,
    U32 envpPointer,
    U32 envpBufPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    U32 index = 0;

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
        if ((U64)length > (U64)UINT32_MAX) {
            return WASI_ERRNO_OVERFLOW;
        }
        memcpy(
            memory->data + envpBufPointer,
            env,
            length
        );
        i32_store(
            memory,
            envpPointer + index * (U32)sizeof(U32),
            envpBufPointer
        );
        envpBufPointer += (U32)length;
    }

    return WASI_ERRNO_SUCCESS;
}

WASI_IMPORT(U32, 11_environX5Fget, (
    wasmModuleInstance* instance,
    U32 envpPointer,
    U32 envpBufPointer
), {
    return wasiEnvironGet(
        instance,
        envpPointer,
        envpBufPointer
    );
})

WASI_IMPORT(U32, 14_argsX5FsizesX5Fget, (
    wasmModuleInstance* instance,
    U32 argcPointer,
    U32 argvBufSizePointer
), {
    wasmMemory* memory = wasiMemory(instance);

    U32 argvBufSize = 0;
    int argvIndex = 0;

    WASI_TRACE((
        "args_sizes_get("
        "argcPointer=0x%x, "
        "argvBufSizePointer=0x%x"
        ")",
        argcPointer,
        argvBufSizePointer
    ));

    for (; argvIndex < wasi.argc; argvIndex++) {
        const size_t length = strlen(wasi.argv[argvIndex]) + 1;
        if ((U64)length > (U64)UINT32_MAX - argvBufSize) {
            return WASI_ERRNO_OVERFLOW;
        }
        argvBufSize += (U32)length;
    }

    i32_store(memory, argcPointer, wasi.argc);
    i32_store(memory, argvBufSizePointer, argvBufSize);

    return WASI_ERRNO_SUCCESS;
})

static
W2C2_INLINE
U32
wasiArgsGet(
    wasmModuleInstance* instance,
    U32 argvPointer,
    U32 argvBufPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    int index = 0;

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
        if ((U64)length > (U64)UINT32_MAX) {
            return WASI_ERRNO_OVERFLOW;
        }
        memcpy(
            memory->data + argvBufPointer,
            arg,
            length
        );
        i32_store(
            memory,
            argvPointer + (U32)index * (U32)sizeof(U32),
            argvBufPointer
        );
        argvBufPointer += (U32)length;
    }

    return WASI_ERRNO_SUCCESS;
}

WASI_IMPORT(U32, 8_argsX5Fget, (
    wasmModuleInstance* instance,
    U32 argvPointer,
    U32 argvBufPointer
), {
    return wasiArgsGet(
        instance,
        argvPointer,
        argvBufPointer
    );
})

static
U32
wasiFDSeek(
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
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        offset == 0 && nativeWhence == SEEK_CUR
            ? WASI_RIGHTS_FD_TELL : WASI_RIGHTS_FD_SEEK
    )) {
        return WASI_ERRNO_NOTCAPABLE;
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

WASI_PREVIEW1_IMPORT(U32, 7_fdX5Fseek, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U64 offset,
    U32 whence,
    U32 resultPointer
), {
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

    return wasiFDSeek(
        memory,
        wasiFD,
        offset,
        nativeWhence,
        resultPointer
    );
})

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

WASI_UNSTABLE_IMPORT(U32, 7_fdX5Fseek, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U64 offset,
    U32 whence,
    U32 resultPointer
), {
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

    return wasiFDSeek(
        memory,
        wasiFD,
        offset,
        nativeWhence,
        resultPointer
    );
})

WASI_IMPORT(U32, 7_fdX5Ftell, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 resultPointer
), {
    wasmMemory* memory = wasiMemory(instance);

    WASI_TRACE((
        "fd_tell("
        "wasiFD=%d, "
        "resultPointer=0x%x"
        ")",
        wasiFD,
        resultPointer
    ));

    return wasiFDSeek(
        memory,
        wasiFD,
        0,
        SEEK_CUR,
        resultPointer
    );
})

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

static
W2C2_INLINE
U32
wasiFDReaddir(
    wasmModuleInstance* instance,
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
    U32 adjustedNameLength = 0;
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
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_FD_READDIR
    )) {
        return WASI_ERRNO_NOTCAPABLE;
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

#if defined(PLAN9) || defined(_WIN32)
    /* APE has no seekdir or telldir;
     * use entry counts as cookies and replay the directory. */
    rewinddir(descriptor.dir);
    while (next < cookie) {
        errno = 0;
        if (readdir(descriptor.dir) == NULL) {
            if (errno != 0) {
                return wasiErrno();
            }
            break;
        }
        next++;
    }
#elif !defined(_WIN32) && !defined(macintosh)
    if (cookie == WASI_DIRCOOKIE_START) {
        rewinddir(descriptor.dir);
    } else {
        seekdir(descriptor.dir, (long)cookie);
    }
#endif

    i32_store(
        memory,
        bufferUsedPointer,
        bufferUsed
    );

    while (bufferUsed < bufferLength) {
#if !defined(PLAN9) && !defined(_WIN32)
        long tell = 0;
#endif
        U32 bufferRemaining = bufferLength - bufferUsed;
        U32 resultPointer = bufferPointer + bufferUsed;

        WASI_TRACE(("fd_readdir: bufferRemaining=%u", bufferRemaining));

        errno = 0;
        entry = readdir(descriptor.dir);
        if (entry == NULL) {
            if (errno != 0) {
                WASI_TRACE(("fd_readdir: readdir failed: %s", strerror(errno)));
                return wasiErrno();
            }

            break;
        }

#if defined(PLAN9) || defined(_WIN32)
        next++;
#else
#if !defined(_WIN32) && !defined(macintosh)
        tell = telldir(descriptor.dir);
        if (tell < 0) {
            WASI_TRACE(("fd_readdir: telldir failed: %s", strerror(errno)));
            return wasiErrno();
        }
#endif

        next = (U64)tell;
#endif
#if defined(PLAN9) || (defined(__MWERKS__) && defined(macintosh)) || defined(__MSDOS__)
        inode = 0;
#else
        inode = entry->d_ino;
#endif
        name = entry->d_name;
        nameLength = strlen(name);
        if ((U64)nameLength > (U64)UINT32_MAX) {
            return WASI_ERRNO_OVERFLOW;
        }

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

        memset(
            memory->data + resultPointer,
            0,
            WASI_DIRENT_SIZE
        );

        i64_store(memory, resultPointer, next);
        i64_store(memory, resultPointer + 8, inode);
        i32_store(memory, resultPointer + 16, (U32)nameLength);
        i32_store8(memory, resultPointer + 20, fileType);

        bufferUsed += WASI_DIRENT_SIZE;
        bufferRemaining = bufferLength - bufferUsed;

        resultPointer = bufferPointer + bufferUsed;

        /* Write as much of the name as fits */
        adjustedNameLength =
            nameLength > bufferRemaining
            ? bufferRemaining
            : (U32)nameLength;

        memcpy(
            memory->data + resultPointer,
            name,
            adjustedNameLength
        );

        bufferUsed += adjustedNameLength;
    }

    i32_store(
        memory,
        bufferUsedPointer,
        bufferUsed
    );

    return WASI_ERRNO_SUCCESS;
}

WASI_IMPORT(U32, 10_fdX5Freaddir, (
    wasmModuleInstance* instance,
    U32 wasiDirFD,
    U32 bufferPointer,
    U32 bufferLength,
    U64 cookie,
    U32 bufferUsedPointer
), {
    return wasiFDReaddir(
        instance,
        wasiDirFD,
        bufferPointer,
        bufferLength,
        cookie,
        bufferUsedPointer
    );
})

WASI_IMPORT(U32, 8_fdX5Fclose, (
    wasmModuleInstance* instance,
    U32 wasiFD
), {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    UNUSED_PARAMETER(instance);

    WASI_TRACE((
        "fd_close("
        "wasiFD=%d"
        ")",
        wasiFD
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_close: bad FD"));
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorClose(wasiFD)) {
        return descriptor.socket != WASI_INVALID_SOCKET
            ? wasiSocketError() : wasiErrno();
    }
    return WASI_ERRNO_SUCCESS;
})

static
U32
wasiFdRenumber(U32 from, U32 to) {
    WasiFileDescriptor source = emptyWasiFileDescriptor;
    WasiFileDescriptor target = emptyWasiFileDescriptor;
    U32 result = WASI_ERRNO_SUCCESS;
    WASI_TRACE(("fd_renumber(from=%u, to=%u)", from, to));

    wasiFileDescriptorsLock();
    if (!wasiFileDescriptorGetLocked(from, &source)
        || !wasiFileDescriptorGetLocked(to, &target)) {
        result = WASI_ERRNO_BADF;
    } else if (from != to) {
        if (!wasiFileDescriptorRelease(&wasi.fds.fds[to])) {
            result = target.socket != WASI_INVALID_SOCKET
                ? wasiSocketError() : wasiErrno();
        } else {
            /* Move the complete descriptor,
             * including its path and directory stream.
             */
            wasi.fds.fds[to] = source;
            wasi.fds.fds[from] = emptyWasiFileDescriptor;
        }
    }
    wasiFileDescriptorsUnlock();
    return result;
}

WASI_IMPORT(U32, 11_fdX5Frenumber, (
    wasmModuleInstance* instance,
    U32 from,
    U32 to
), {
    UNUSED_PARAMETER(instance);
    return wasiFdRenumber(from, to);
})

#ifndef NSEC_PER_SEC
#define NSEC_PER_SEC W2C2_LL(1000000000)
#endif
#ifndef NSEC_PER_USEC
#define NSEC_PER_USEC W2C2_LL(1000)
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

static
W2C2_INLINE
U32
wasiClockTime(
    U32 clockID,
    I64* timestamp
) {
    I64 result = 0;

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0) && !WASI_FALLBACK_TIMERS_ENABLED && !defined(__wii__)

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
/* Don't check for _POSIX_CPUTIME, because e.g. WASI libc defines it,
 * but it does not have CLOCK_PROCESS_CPUTIME_ID.
 * See https://github.com/WebAssembly/wasi-libc/issues/513
 */
#ifdef CLOCK_PROCESS_CPUTIME_ID
            case WASI_CLOCK_PROCESS_CPUTIME_ID: {
                nativeClockID = CLOCK_PROCESS_CPUTIME_ID;
                break;
            }
#endif
/* Don't check for _POSIX_THREAD_CPUTIME, because e.g. WASI libc defines it,
 * but it does not have CLOCK_THREAD_CPUTIME_ID.
 * See https://github.com/WebAssembly/wasi-libc/issues/513
 */
#ifdef CLOCK_THREAD_CPUTIME_ID
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
#define DELTA_EPOCH_IN_100NS W2C2_LL(116444736000000000)

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
#if HAS_SYSRESOURCE && !defined(__wii__)
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

    *timestamp = result;

    return WASI_ERRNO_SUCCESS;
}

static
W2C2_INLINE
U32
wasiClockTimeGet(
    wasmModuleInstance* instance,
    U32 clockID,
    U64 precision,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);
    I64 result = 0;
    U32 error = WASI_ERRNO_SUCCESS;
    UNUSED_PARAMETER(precision);

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

    error = wasiClockTime(clockID, &result);
    if (error != WASI_ERRNO_SUCCESS) {
        return error;
    }

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

WASI_IMPORT(U32, 14_clockX5FtimeX5Fget, (
    wasmModuleInstance* instance,
    U32 clockID,
    U64 precision,
    U32 resultPointer
), {
    return wasiClockTimeGet(
        instance,
        clockID,
        precision,
        resultPointer
    );
})

static
W2C2_INLINE
U32
wasiClockResGet(
    wasmModuleInstance* instance,
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

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0) && !WASI_FALLBACK_TIMERS_ENABLED && !defined(__wii__)

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
/* Don't check for _POSIX_CPUTIME, because e.g. WASI libc defines it,
 * but it does not have CLOCK_PROCESS_CPUTIME_ID.
 * See https://github.com/WebAssembly/wasi-libc/issues/513
 */
#ifdef CLOCK_PROCESS_CPUTIME_ID
            case WASI_CLOCK_PROCESS_CPUTIME_ID: {
                nativeClockID = CLOCK_PROCESS_CPUTIME_ID;
                break;
            }
#endif
/* Don't check for _POSIX_THREAD_CPUTIME, because e.g. WASI libc defines it,
 * but it does not have CLOCK_THREAD_CPUTIME_ID.
 * See https://github.com/WebAssembly/wasi-libc/issues/513
 */
#ifdef CLOCK_THREAD_CPUTIME_ID
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

WASI_IMPORT(U32, 13_clockX5FresX5Fget, (
    wasmModuleInstance* instance,
    U32 clockID,
    U32 resultPointer
), {
    return wasiClockResGet(
        instance,
        clockID,
        resultPointer
    );
})

#define WASI_FDSTAT_SIZE 24

#if HAS_FCNTL

static
W2C2_INLINE
U16
wasiFdFlagsFromNative(int nativeFlags) {
    U16 wasiFlags = 0;

    if (nativeFlags & O_APPEND) {
        wasiFlags |= WASI_FDFLAGS_APPEND;
    }
#ifdef O_DSYNC
    if ((nativeFlags & O_DSYNC) == O_DSYNC) {
        wasiFlags |= WASI_FDFLAGS_DSYNC;
    }
#endif
#ifdef O_NONBLOCK
    if (nativeFlags & O_NONBLOCK) {
        wasiFlags |= WASI_FDFLAGS_NONBLOCK;
    }
#endif
#ifdef O_RSYNC
    if ((nativeFlags & O_RSYNC) == O_RSYNC) {
        wasiFlags |= WASI_FDFLAGS_RSYNC;
    }
#endif
#ifdef O_SYNC
    if ((nativeFlags & O_SYNC) == O_SYNC) {
        wasiFlags |= WASI_FDFLAGS_SYNC;
    }
#endif /* O_SYNC */

    return wasiFlags;
}

#endif /* HAS_FCNTL */

static
W2C2_INLINE
U32
wasiFdFdstatGet(
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 resultPointer
) {
    wasmMemory* memory = wasiMemory(instance);

    WasiFileType fileType = WASI_FILE_TYPE_UNKNOWN;
    U16 wasiFlags = 0;
    struct stat st;
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "fd_fdstat_get("
        "wasiFD=%d, "
        "resultPointer=0x%x"
        ")",
        wasiFD,
        resultPointer
    ));

    if (!wasiMemoryRangeIsValid(memory, resultPointer, 1, WASI_FDSTAT_SIZE)) {
        return WASI_ERRNO_FAULT;
    }

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_fdstat_get: bad FD"));
        return WASI_ERRNO_BADF;
    }

    if (descriptor.socket != WASI_INVALID_SOCKET) {
        fileType = descriptor.socketType;
#if HAS_SOCKETS && HAS_FCNTL && !defined(_WIN32)
        {
            int flags = fcntl(descriptor.socket, F_GETFL);
            if (flags < 0) {
                return wasiErrno();
            }
            wasiFlags = wasiFdFlagsFromNative(flags);
        }
#else
        wasiFlags = descriptor.socketFlags;
#endif
    } else {
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

        if (descriptor.fd >= 0) {
#if HAS_FCNTL
            int nativeFlags = 0;

            /* Get flags */
            nativeFlags = fcntl(descriptor.fd, F_GETFL);
            if (nativeFlags < 0) {
                WASI_TRACE(("fd_fdstat_get: fcntl failed: %s", strerror(errno)));
                return wasiErrno();
            }

            wasiFlags = wasiFdFlagsFromNative(nativeFlags);
#elif defined(_WIN32)
            wasiFlags = descriptor.fileFlags;
#endif /* HAS_FCNTL */
        }
    }

    /* Store result */
    memset(
        memory->data + resultPointer,
        0,
        WASI_FDSTAT_SIZE
    );

    WASI_TRACE((
        "fd_fdstat_get: "
        "fileType=%u, "
        "wasiFlags=%u, "
        "baseRights=%llu, "
        "inheritingRights=%llu",
        fileType,
        wasiFlags,
        descriptor.rightsBase,
        descriptor.rightsInheriting
    ));

    i32_store8(memory, resultPointer, fileType);
    i32_store16(memory, resultPointer + 2, wasiFlags);
    i64_store(memory, resultPointer + 8, descriptor.rightsBase);
    i64_store(memory, resultPointer + 16, descriptor.rightsInheriting);

    return WASI_ERRNO_SUCCESS;
}

WASI_IMPORT(U32, 13_fdX5FfdstatX5Fget, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 resultPointer
), {
    return wasiFdFdstatGet(
        instance,
        wasiFD,
        resultPointer
    );
})

static
W2C2_INLINE
U32
wasiFDDatasync(
    wasmModuleInstance* instance,
    U32 wasiFD
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    UNUSED_PARAMETER(instance);

    WASI_TRACE((
        "fd_datasync("
        "wasiFD=%d, "
        ")",
        wasiFD
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_datasync: bad FD"));
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_FD_DATASYNC
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

#if (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 199309L)) || \
    (defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE >= 500))
    if (descriptor.fd < 0) {
        return WASI_ERRNO_INVAL;
    }

    if (fdatasync(descriptor.fd) != 0) {
        return wasiErrno();
    }

    return WASI_ERRNO_SUCCESS;
#else
    return WASI_ERRNO_NOSYS;
#endif
}

WASI_IMPORT(U32, 11_fdX5Fdatasync, (
    wasmModuleInstance* instance,
    U32 wasiFD
), {
    return wasiFDDatasync(
        instance,
        wasiFD
    );
})

static
W2C2_INLINE
U32
wasiFDSync(
    wasmModuleInstance* instance,
    U32 wasiFD
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    UNUSED_PARAMETER(instance);

    WASI_TRACE((
       "fd_sync("
       "wasiFD=%d, "
       ")",
       wasiFD
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_sync: bad FD"));
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_FD_SYNC
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

#if (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)) || \
    defined(_XOPEN_SOURCE) || defined(_BSD_SOURCE)
    if (descriptor.fd < 0) {
        return WASI_ERRNO_INVAL;
    }

    if (fsync(descriptor.fd) != 0) {
        return wasiErrno();
    }

    return WASI_ERRNO_SUCCESS;
#else
    return WASI_ERRNO_NOSYS;
#endif
}

WASI_IMPORT(U32, 7_fdX5Fsync, (
    wasmModuleInstance* instance,
    U32 wasiFD
), {
    return wasiFDSync(
        instance,
        wasiFD
    );
})

WASI_IMPORT(U32, 14_fdX5FprestatX5Fget, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 prestatPointer
), {
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

    path = fileDescriptor.preopenName;

    if (path == NULL) {
        WASI_TRACE(("fd_prestat_get: bad FD"));
        return WASI_ERRNO_BADF;
    }

    length = (U32)strlen(path);
    i32_store(memory, prestatPointer, WASI_PREOPEN_TYPE_DIRECTORY);
    i32_store(memory, prestatPointer + 4, length);

    return WASI_ERRNO_SUCCESS;
})

static
W2C2_INLINE
U32
wasiFdPrestatDirName(
    wasmModuleInstance* instance,
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

    path = fileDescriptor.preopenName;

    if (path == NULL) {
        WASI_TRACE(("fd_prestat_dir_name: bad FD"));
        return WASI_ERRNO_BADF;
    }

    length = strlen(path);
    if (length > pathLength) {
        return WASI_ERRNO_NAMETOOLONG;
    }
    if (!wasiMemoryRangeIsValid(memory, pathPointer, (U32)length, 1)) {
        return WASI_ERRNO_FAULT;
    }

    memcpy(
        memory->data + pathPointer,
        path,
        length
    );

    return WASI_ERRNO_SUCCESS;
}

WASI_IMPORT(U32, 19_fdX5FprestatX5FdirX5Fname, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 pathPointer,
    U32 pathLength
), {
    return wasiFdPrestatDirName(
        instance,
        wasiFD,
        pathPointer,
        pathLength
    );
})

static
W2C2_INLINE
U32
wasiPathOpen(
    wasmModuleInstance* instance,
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

    char* path = (char*) memory->data + pathPointer;

    char resolvedPath[PATH_MAX];
    char nativeResolvedPath[PATH_MAX];
    int nativeFlags = 0;
    static const int mode = 0644;
    int nativeFD = -1;
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;
    U32 wasiFD = 0;
    char* preopenPath = NULL;
    bool success = false;
    WasiRights requiredBase = WASI_RIGHTS_PATH_OPEN;
    WasiRights requiredInheriting = fsRightsBase | fsRightsInheriting;

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

    if (oflags & WASI_OFLAGS_CREAT) {
        requiredBase |= WASI_RIGHTS_PATH_CREATE_FILE;
    }
    if (oflags & WASI_OFLAGS_TRUNC) {
        requiredBase |= WASI_RIGHTS_PATH_FILESTAT_SET_SIZE;
    }
    if (fdFlags & WASI_FDFLAGS_DSYNC) {
        requiredInheriting |= WASI_RIGHTS_FD_DATASYNC;
    }
    if (fdFlags & (WASI_FDFLAGS_RSYNC | WASI_FDFLAGS_SYNC)) {
        requiredInheriting |= WASI_RIGHTS_FD_SYNC;
    }
    if (!wasiFileDescriptorHasRights(&preopenFileDescriptor, requiredBase)
        || (requiredInheriting & ~preopenFileDescriptor.rightsInheriting) != 0) {
        return WASI_ERRNO_NOTCAPABLE;
    }

    preopenPath = preopenFileDescriptor.path;

    if (preopenPath == NULL) {
        WASI_TRACE(("path_open: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }

    if (dirFlags & ~(U32)WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW
        || oflags & ~(U32)(WASI_OFLAGS_CREAT | WASI_OFLAGS_DIRECTORY |
                          WASI_OFLAGS_EXCL | WASI_OFLAGS_TRUNC)
        || fdFlags & ~(U32)(WASI_FDFLAGS_APPEND | WASI_FDFLAGS_DSYNC |
                           WASI_FDFLAGS_NONBLOCK | WASI_FDFLAGS_RSYNC |
                           WASI_FDFLAGS_SYNC)) {
        return WASI_ERRNO_INVAL;
    }
#ifdef _WIN32
    if (fdFlags & (WASI_FDFLAGS_DSYNC | WASI_FDFLAGS_RSYNC | WASI_FDFLAGS_SYNC)) {
        return WASI_ERRNO_NOTSUP;
    }
#endif
    if (!wasiMemoryRangeIsValid(memory, pathPointer, pathLength, 1)) {
        return WASI_ERRNO_FAULT;
    }
    if (pathLength == 0) {
        return WASI_ERRNO_NOENT;
    }
    if (memchr(path, '\0', pathLength) != NULL) {
        return WASI_ERRNO_INVAL;
    }
    {
        U32 index = 0;
        U32 depth = 0;
        if (path[0] == '/') {
            return WASI_ERRNO_NOTCAPABLE;
        }
        while (index < pathLength) {
            U32 start = index;
            U32 length;
            while (index < pathLength && path[index] != '/') {
                index++;
            }
            length = index - start;
            if (length == 2 && path[start] == '.' && path[start + 1] == '.') {
                if (depth == 0) {
                    return WASI_ERRNO_NOTCAPABLE;
                }
                depth--;
            } else if (length != 0 && !(length == 1 && path[start] == '.')) {
                depth++;
            }
            if (index < pathLength) {
                index++;
            }
        }
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
#ifdef O_NOFOLLOW
    if (!(dirFlags & WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW)) {
        nativeFlags |= O_NOFOLLOW;
    }
#endif

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
#ifdef _WIN32
    if (!(dirFlags & WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW)) {
        DWORD attributes = GetFileAttributesA(nativeResolvedPath);
        if (attributes != INVALID_FILE_ATTRIBUTES
            && (attributes & FILE_ATTRIBUTE_REPARSE_POINT)) {
            return (oflags & (WASI_OFLAGS_CREAT | WASI_OFLAGS_EXCL))
                == (WASI_OFLAGS_CREAT | WASI_OFLAGS_EXCL)
                ? WASI_ERRNO_EXIST : WASI_ERRNO_LOOP;
        }
    }
#endif
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
            if (success && isWrite) {
                return WASI_ERRNO_ISDIR;
            }
            if (success && (oflags & WASI_OFLAGS_CREAT)) {
                return WASI_ERRNO_EXIST;
            }
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
            U32 error = wasiErrno();
            WASI_TRACE(("path_open: fstat failed: %s", strerror(errno)));
            close(nativeFD);
            return error;
        }

        if (wasiFileTypeFromMode(st.st_mode) != WASI_FILE_TYPE_DIRECTORY) {
            close(nativeFD);
            return WASI_ERRNO_NOTDIR;
        }
    }

    /* Register the WASI file descriptor */
    if (!wasiFileDescriptorAddWithRights(
        nativeFD,
        resolvedPath,
        NULL,
        fsRightsBase,
        fsRightsInheriting,
        (U16)fdFlags,
        &wasiFD
    )) {
        WASI_TRACE(("path_open: adding FD failed"));
        if (nativeFD >= 0) {
            close(nativeFD);
        }
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

WASI_IMPORT(U32, 9_pathX5Fopen, (
    wasmModuleInstance* instance,
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
    return wasiPathOpen(
        instance,
        wasiDirFD,
        dirFlags,
        pathPointer,
        pathLength,
        oflags,
        fsRightsBase,
        fsRightsInheriting,
        fdFlags,
        fdPointer
    );
})

static
W2C2_INLINE
void
getStatTimes(
    struct stat* st,
    struct timespec* access,
    struct timespec* modification,
    struct timespec* creation
) {
#if defined(_WIN32)
    access->tv_sec = st->st_atime;
    access->tv_nsec = st->accessNanoseconds;
    modification->tv_sec = st->st_mtime;
    modification->tv_nsec = st->modificationNanoseconds;
    creation->tv_sec = st->st_ctime;
    creation->tv_nsec = st->creationNanoseconds;
#elif defined(__APPLE__) && defined(__MACH__)
    *access = st->st_atimespec;
    *modification = st->st_mtimespec;
    *creation = st->st_ctimespec;
#elif (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200809L)) || \
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

    memset(
        memory->data + statPointer,
        0,
        wasiPreview1FilestatSize
    );

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
wasiFDFilestatGet(
    U32 wasiFD,
    struct stat* st,
    WasiFileType* socketType
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_filestat_get: bad FD"));
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_FD_FILESTAT_GET
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

    *socketType = descriptor.socketType;
    if (descriptor.socket != WASI_INVALID_SOCKET) {
#if HAS_SOCKETS && !defined(_WIN32)
        if (fstat(descriptor.socket, st) != 0) {
            return wasiErrno();
        }
#else
        memset(st, 0, sizeof(*st));
#endif
        return WASI_ERRNO_SUCCESS;
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

WASI_PREVIEW1_IMPORT(U32, 15_fdX5FfilestatX5Fget, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 statPointer
), {
    wasmMemory* memory = wasiMemory(instance);

    struct stat st;
    WasiFileType socketType;
    U32 res = WASI_ERRNO_INVAL;

    WASI_TRACE((
        "fd_filestat_get("
        "wasiFD=%d, "
        "statPointer=0x%x"
        ")",
        wasiFD,
        statPointer
    ));

    res = wasiFDFilestatGet(wasiFD, &st, &socketType);
    if (res != WASI_ERRNO_SUCCESS) {
        return res;
    }

    storePreview1Filestat(memory, statPointer, &st);
    if (socketType != WASI_FILE_TYPE_UNKNOWN) {
        i32_store8(memory, statPointer + 16, socketType);
    }

    return WASI_ERRNO_SUCCESS;
})

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

    memset(
        memory->data + statPointer,
        0,
        wasiUnstableFilestatSize
    );

    {
        I64 dev = st->st_dev;
        U64 ino = st->st_ino;
        U8 wasiFileType = wasiFileTypeFromMode(st->st_mode);
        U32 nlink = (U32)st->st_nlink;
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

WASI_UNSTABLE_IMPORT(U32, 15_fdX5FfilestatX5Fget, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U32 statPointer
), {
    wasmMemory* memory = wasiMemory(instance);

    struct stat st;
    WasiFileType socketType;
    U32 res = WASI_ERRNO_INVAL;

    WASI_TRACE((
        "fd_filestat_get("
        "wasiFD=%d, "
        "statPointer=0x%x"
        ")",
        wasiFD,
        statPointer
    ));

    res = wasiFDFilestatGet(wasiFD, &st, &socketType);

    if (res != WASI_ERRNO_SUCCESS) {
        return res;
    }

    storeUnstableFilestat(memory, statPointer, &st);
    if (socketType != WASI_FILE_TYPE_UNKNOWN) {
        i32_store8(memory, statPointer + 16, socketType);
    }

    return WASI_ERRNO_SUCCESS;
})

static
U32
wasiPathFilestatGet(
    wasmMemory* memory,
    U32 wasiFD,
    U32 lookupFlags,
    U32 pathPointer,
    U32 pathLength,
    struct stat* st
) {
    char* path = (char*) memory->data + pathPointer;
    char resolvedPath[PATH_MAX];
    char nativeResolvedPath[PATH_MAX];
    int res = 0;
    char* preopenPath = NULL;
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;

    if (!wasiFileDescriptorGet(wasiFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_filestat_get: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &preopenFileDescriptor,
        WASI_RIGHTS_PATH_FILESTAT_GET
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

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

    if (lookupFlags & ~(U32)WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW) {
        return WASI_ERRNO_INVAL;
    }
#if HAS_LSTAT
    res = lookupFlags & WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW
        ? stat(nativeResolvedPath, st) : lstat(nativeResolvedPath, st);
#else
    /* TODO: use lookupFlags & wasiLookupFlagSymlinkFollow */
    res = stat(nativeResolvedPath, st);
#endif

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

static
W2C2_INLINE
U32
wasiFdFilestatSetSize(
    U32 wasiFD,
    U64 size
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;

    WASI_TRACE((
        "fd_filestat_set_size("
        "wasiFD=%d, "
        "size=%llu"
        ")",
        wasiFD,
        size
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        WASI_TRACE(("fd_filestat_set_size: bad FD"));
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_FD_FILESTAT_SET_SIZE
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

#if (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200112L)) || \
    (defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE >= 500)) || \
    defined(_BSD_SOURCE) || defined(_WIN32)
    if (descriptor.fd < 0) {
        return WASI_ERRNO_INVAL;
    }

    if (ftruncate(descriptor.fd, (off_t)size) != 0) {
        return wasiErrno();
    }

    return WASI_ERRNO_SUCCESS;
#else
    return WASI_ERRNO_NOSYS;
#endif
}

WASI_IMPORT(U32, 20_fdX5FfilestatX5FsetX5Fsize, (
    wasmModuleInstance* instance,
    U32 wasiFD,
    U64 size
), {
    UNUSED_PARAMETER(instance);
    return wasiFdFilestatSetSize(wasiFD, size);
})

static
W2C2_INLINE
bool
wasiFstFlagsValid(U32 flags) {
    return !(flags & ~(U32)(WASI_FSTFLAGS_ATIM | WASI_FSTFLAGS_ATIM_NOW |
                           WASI_FSTFLAGS_MTIM | WASI_FSTFLAGS_MTIM_NOW)) &&
        (flags & (WASI_FSTFLAGS_ATIM | WASI_FSTFLAGS_ATIM_NOW)) !=
            (WASI_FSTFLAGS_ATIM | WASI_FSTFLAGS_ATIM_NOW) &&
        (flags & (WASI_FSTFLAGS_MTIM | WASI_FSTFLAGS_MTIM_NOW)) !=
            (WASI_FSTFLAGS_MTIM | WASI_FSTFLAGS_MTIM_NOW);
}

#ifndef _WIN32

static
W2C2_INLINE
bool
wasiTimestampSeconds(U64 timestamp, time_t* seconds) {
    U64 value = timestamp / NSEC_PER_SEC;
    *seconds = (time_t)value;
    return (U64)*seconds == value;
}

static
U32
wasiSetFileTimesLegacy(
    int fd,
    const char* path,
    bool follow,
    U64 atime,
    U64 mtime,
    U32 flags
) {
#if HAS_FUTIMES || HAS_UTIMES || HAS_LUTIMES || HAS_UTIME
    struct stat st;
    time_t seconds[2];
    long microseconds[2];
    struct timespec access, modification, creation;
    U64 timestamps[2];
    I64 now = 0;
    bool bothNow = flags == (WASI_FSTFLAGS_ATIM_NOW | WASI_FSTFLAGS_MTIM_NOW);
    U32 error;
    int i;

    if (fd >= 0) {
#if !HAS_FUTIMES
        return WASI_ERRNO_NOSYS;
#endif
        if (fstat(fd, &st) != 0) {
            return wasiErrno();
        }
    } else if (!follow) {
#if HAS_LUTIMES && HAS_LSTAT
        if (lstat(path, &st) != 0) {
            return wasiErrno();
        }
#else
        return WASI_ERRNO_NOTSUP;
#endif
    } else if (stat(path, &st) != 0) {
        return wasiErrno();
    }

    if (flags == 0) {
        return WASI_ERRNO_SUCCESS;
    }

    /* Older APIs require reading the timestamps that must remain unchanged.
     * Concurrent timestamp updates can race with this read-modify-write sequence.
     */
    getStatTimes(
        &st,
        &access,
        &modification,
        &creation
    );
#ifdef _NEXT_SOURCE
    seconds[0] = access.ts_sec;
    seconds[1] = modification.ts_sec;
    microseconds[0] = access.ts_nsec / 1000;
    microseconds[1] = modification.ts_nsec / 1000;
#else
    seconds[0] = access.tv_sec;
    seconds[1] = modification.tv_sec;
    microseconds[0] = access.tv_nsec / 1000;
    microseconds[1] = modification.tv_nsec / 1000;
#endif

    if (!bothNow && (flags & (WASI_FSTFLAGS_ATIM_NOW | WASI_FSTFLAGS_MTIM_NOW))) {
        error = wasiClockTime(WASI_CLOCK_REALTIME, &now);
        if (error != WASI_ERRNO_SUCCESS) {
            return error;
        }
    }
    timestamps[0] = atime;
    timestamps[1] = mtime;
    for (i = 0; i < 2; i++) {
        U32 mode = (flags >> (i * 2)) & 3;
        if (mode == 0 || bothNow) {
            continue;
        }
        if (mode == 2) {
            timestamps[i] = (U64)now;
        }
        if (!wasiTimestampSeconds(timestamps[i], &seconds[i])) {
            return WASI_ERRNO_OVERFLOW;
        }
        microseconds[i] = (long)((timestamps[i] % NSEC_PER_SEC) / 1000);
    }

#if HAS_FUTIMES || HAS_UTIMES || HAS_LUTIMES
    {
        struct timeval times[2];
        /* NULL lets the host apply its current-time permission rules. */
        const struct timeval* values = bothNow ? NULL : times;
        times[0].tv_sec = seconds[0];
        times[0].tv_usec = microseconds[0];
        times[1].tv_sec = seconds[1];
        times[1].tv_usec = microseconds[1];
#if HAS_FUTIMES
        if (fd >= 0) {
            return futimes(fd, values) == 0 ? WASI_ERRNO_SUCCESS : wasiErrno();
        }
#endif
#if HAS_LUTIMES
        if (!follow) {
            return lutimes(path, values) == 0 ? WASI_ERRNO_SUCCESS : wasiErrno();
        }
#endif
#if HAS_UTIMES
        return utimes(path, values) == 0 ? WASI_ERRNO_SUCCESS : wasiErrno();
#endif
    }
#else
    UNUSED_PARAMETER(microseconds);
#endif
#if HAS_UTIME
    {
        struct utimbuf times;
        times.actime = seconds[0];
        times.modtime = seconds[1];
        /* NULL lets the host apply its current-time permission rules. */
        return utime(path, bothNow ? NULL : &times) == 0 ? WASI_ERRNO_SUCCESS : wasiErrno();
    }
#endif
#else
    UNUSED_PARAMETER(fd);
    UNUSED_PARAMETER(path);
    UNUSED_PARAMETER(follow);
    UNUSED_PARAMETER(atime);
    UNUSED_PARAMETER(mtime);
    UNUSED_PARAMETER(flags);
#endif
    return WASI_ERRNO_NOSYS;
}

#endif /* !_WIN32 */

static
U32
wasiSetFileTimes(
    int fd,
    const char* path,
    bool follow,
    U64 atime,
    U64 mtime,
    U32 flags
) {
    if (!wasiFstFlagsValid(flags)) {
        return WASI_ERRNO_INVAL;
    }

#ifdef _WIN32
    {
        HANDLE handle;
        FILETIME times[2];
        FILETIME now;
        const FILETIME* pointers[2] = {NULL, NULL};
        U64 timestamps[2];
        U32 result = WASI_ERRNO_SUCCESS;
        int i;

        if (fd >= 0) {
            handle = (HANDLE)_get_osfhandle(fd);
            if (handle == INVALID_HANDLE_VALUE) {
                return WASI_ERRNO_BADF;
            }
        } else {
            DWORD attributes = FILE_FLAG_BACKUP_SEMANTICS;
            if (!follow) {
#ifdef FILE_FLAG_OPEN_REPARSE_POINT
                attributes |= FILE_FLAG_OPEN_REPARSE_POINT;
#else
                return WASI_ERRNO_NOTSUP;
#endif
            }
            handle = CreateFileA(
                path,
                FILE_WRITE_ATTRIBUTES,
                FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                NULL,
                OPEN_EXISTING,
                attributes,
                NULL
            );
            if (handle == INVALID_HANDLE_VALUE) {
                wasiSetErrno(GetLastError());
                return wasiErrno();
            }
        }

        GetSystemTimeAsFileTime(&now);
        timestamps[0] = atime;
        timestamps[1] = mtime;
        for (i = 0; i < 2; i++) {
            U32 mode = (flags >> (i * 2)) & 3;
            if (mode == 1) {
                /* FILETIME counts 100 ns intervals since January 1, 1601. */
                U64 ticks = timestamps[i] / 100 + W2C2_LL(116444736000000000);
                times[i].dwLowDateTime = (DWORD)ticks;
                times[i].dwHighDateTime = (DWORD)(ticks >> 32);
                pointers[i] = &times[i];
            } else if (mode == 2) {
                pointers[i] = &now;
            }
        }
        if (!SetFileTime(
            handle,
            NULL,
            pointers[0],
            pointers[1]
        )) {
            wasiSetErrno(GetLastError());
            result = wasiErrno();
        }
        if (fd < 0) {
            CloseHandle(handle);
        }
        return result;
    }
#else
#if HAS_FUTIMENS || HAS_UTIMENSAT
    {
        struct timespec times[2];
        U64 timestamps[2];
        int i;

        timestamps[0] = atime;
        timestamps[1] = mtime;
        for (i = 0; i < 2; i++) {
            U32 mode = (flags >> (i * 2)) & 3;
            times[i].tv_sec = 0;
            if (mode == 1) {
                if (!wasiTimestampSeconds(timestamps[i], &times[i].tv_sec)) {
                    return WASI_ERRNO_OVERFLOW;
                }
                times[i].tv_nsec = (long)(timestamps[i] % NSEC_PER_SEC);
            } else {
                times[i].tv_nsec = mode == 2 ? UTIME_NOW : UTIME_OMIT;
            }
        }
#if HAS_FUTIMENS
        if (fd >= 0) {
            return futimens(fd, times) == 0 ? WASI_ERRNO_SUCCESS : wasiErrno();
        }
#endif
#if HAS_UTIMENSAT
        if (fd < 0) {
            return utimensat(
                AT_FDCWD,
                path,
                times,
                follow ? 0 : AT_SYMLINK_NOFOLLOW
            ) == 0 ? WASI_ERRNO_SUCCESS : wasiErrno();
        }
#endif
    }
#endif
    return wasiSetFileTimesLegacy(
        fd,
        path,
        follow,
        atime,
        mtime,
        flags
    );
#endif
}

static
U32
wasiFdFilestatSetTimes(
    U32 wasiFD,
    U64 atime,
    U64 mtime,
    U32 flags
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    char nativePath[PATH_MAX];

    WASI_TRACE((
        "fd_filestat_set_times(wasiFD=%u, atime=%llu, mtime=%llu, flags=%u)",
        wasiFD,
        atime,
        mtime,
        flags
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_FD_FILESTAT_SET_TIMES
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }
    if (descriptor.fd >= 0) {
        return wasiSetFileTimes(
            descriptor.fd,
            NULL,
            true,
            atime,
            mtime,
            flags
        );
    }

    strcpy(nativePath, descriptor.path);
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativePath);
#endif
    return wasiSetFileTimes(
        -1,
        nativePath,
        true,
        atime,
        mtime,
        flags
    );
}

WASI_IMPORT(U32, 21_fdX5FfilestatX5FsetX5Ftimes, (
    wasmModuleInstance* instance,
    U32 fd,
    U64 atime,
    U64 mtime,
    U32 fstFlags
), {
    UNUSED_PARAMETER(instance);
    return wasiFdFilestatSetTimes(
        fd,
        atime,
        mtime,
        fstFlags
    );
})

WASI_PREVIEW1_IMPORT(U32, 17_pathX5FfilestatX5Fget, (
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 lookupFlags,
    U32 pathPointer,
    U32 pathLength,
    U32 statPointer
), {
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

    res = wasiPathFilestatGet(memory, dirFD, lookupFlags, pathPointer, pathLength, &st);
    if (res != WASI_ERRNO_SUCCESS) {
        return res;
    }

    storePreview1Filestat(memory, statPointer, &st);

    return WASI_ERRNO_SUCCESS;
})

WASI_UNSTABLE_IMPORT(U32, 17_pathX5FfilestatX5Fget, (
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 lookupFlags,
    U32 pathPointer,
    U32 pathLength,
    U32 statPointer
), {
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

    res = wasiPathFilestatGet(memory, dirFD, lookupFlags, pathPointer, pathLength, &st);
    if (res != WASI_ERRNO_SUCCESS) {
        return res;
    }

    storeUnstableFilestat(memory, statPointer, &st);

    return WASI_ERRNO_SUCCESS;
})

static
U32
wasiPathFilestatSetTimes(
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 lookupFlags,
    U32 pathPointer,
    U32 pathLength,
    U64 atime,
    U64 mtime,
    U32 fstFlags
) {
    wasmMemory* memory = wasiMemory(instance);
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    char nativePath[PATH_MAX];
    char* path;

    WASI_TRACE((
        "path_filestat_set_times(dirFD=%u, lookupFlags=%u, fstFlags=%u)",
        dirFD,
        lookupFlags,
        fstFlags
    ));

    if (!wasiFileDescriptorGet(dirFD, &descriptor) || descriptor.path == NULL) {
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_PATH_FILESTAT_SET_TIMES
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }
    if (lookupFlags & ~(U32)WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW ||
        !wasiFstFlagsValid(fstFlags)) {
        return WASI_ERRNO_INVAL;
    }
    if (pathPointer > memory->size || pathLength > memory->size - pathPointer) {
        return WASI_ERRNO_FAULT;
    }
    path = (char*)memory->data + pathPointer;
    if (memchr(path, '\0', pathLength) != NULL ||
        !resolvePath(
            descriptor.path,
            path,
            pathLength,
            nativePath
        )) {
        return WASI_ERRNO_INVAL;
    }
#if HAS_NONPOSIXPATH
    wasiToNativePath(nativePath);
#endif
    return wasiSetFileTimes(
        -1,
        nativePath,
        (lookupFlags & WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW) != 0,
        atime,
        mtime,
        fstFlags
    );
}

WASI_IMPORT(U32, 23_pathX5FfilestatX5FsetX5Ftimes, (
    wasmModuleInstance* instance,
    U32 fd,
    U32 flags,
    U32 path,
    U32 pathLen,
    U64 atime,
    U64 mtime,
    U32 fstFlags
), {
    return wasiPathFilestatSetTimes(
        instance,
        fd,
        flags,
        path,
        pathLen,
        atime,
        mtime,
        fstFlags
    );
})

static
W2C2_INLINE
U32
wasiPathRename(
    wasmModuleInstance* instance,
    U32 oldDirFD,
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 newDirFD,
    U32 newPathPointer,
    U32 newPathLength
) {
    wasmMemory* memory = wasiMemory(instance);

    char* oldPath = (char*) memory->data + oldPathPointer;
    char* newPath = (char*) memory->data + newPathPointer;
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
    if (!wasiFileDescriptorHasRights(
        &oldPreopenFileDescriptor,
        WASI_RIGHTS_PATH_RENAME_SOURCE
    ) || !wasiFileDescriptorHasRights(
        &newPreopenFileDescriptor,
        WASI_RIGHTS_PATH_RENAME_TARGET
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

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

WASI_IMPORT(U32, 11_pathX5Frename, (
    wasmModuleInstance* instance,
    U32 oldDirFD,
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 newDirFD,
    U32 newPathPointer,
    U32 newPathLength
), {
    return wasiPathRename(
        instance,
        oldDirFD,
        oldPathPointer,
        oldPathLength,
        newDirFD,
        newPathPointer,
        newPathLength
    );
})

static
W2C2_INLINE
U32
wasiPathUnlinkFile(
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength
) {
    wasmMemory* memory = wasiMemory(instance);

    char* path = (char*) memory->data + pathPointer;
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
    if (!wasiFileDescriptorHasRights(
        &preopenFileDescriptor,
        WASI_RIGHTS_PATH_UNLINK_FILE
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

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

WASI_IMPORT(U32, 16_pathX5FunlinkX5Ffile, (
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength
), {
    return wasiPathUnlinkFile(
        instance,
        dirFD,
        pathPointer,
        pathLength
    );
})

static
W2C2_INLINE
U32
wasiPathRemoveDirectory(
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength
) {
    wasmMemory* memory = wasiMemory(instance);

    char* path = (char*) memory->data + pathPointer;
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
    if (!wasiFileDescriptorHasRights(
        &preopenFileDescriptor,
        WASI_RIGHTS_PATH_REMOVE_DIRECTORY
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

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

WASI_IMPORT(U32, 21_pathX5FremoveX5Fdirectory, (
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength
), {
    return wasiPathRemoveDirectory(
        instance,
        dirFD,
        pathPointer,
        pathLength
    );
})

static
W2C2_INLINE
U32
wasiPathCreateDirectory(
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength
) {
    wasmMemory* memory = wasiMemory(instance);

    char* path = (char*) memory->data + pathPointer;
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
    if (!wasiFileDescriptorHasRights(
        &preopenFileDescriptor,
        WASI_RIGHTS_PATH_CREATE_DIRECTORY
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

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

WASI_IMPORT(U32, 21_pathX5FcreateX5Fdirectory, (
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength
), {
    return wasiPathCreateDirectory(
        instance,
        dirFD,
        pathPointer,
        pathLength
    );
})

static
W2C2_INLINE
U32
wasiPathSymlink(
    wasmModuleInstance* instance,
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 dirFD,
    U32 newPathPointer,
    U32 newPathLength
) {
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;
#if (defined(__MWERKS__) && defined(macintosh)) || \
    defined(__wii__)
    UNUSED_PARAMETER(instance);
    UNUSED_PARAMETER(oldPathPointer);
    UNUSED_PARAMETER(oldPathLength);
    UNUSED_PARAMETER(dirFD);
    UNUSED_PARAMETER(newPathPointer);
    UNUSED_PARAMETER(newPathLength);
#else
    wasmMemory* memory = wasiMemory(instance);

    char* newPath = (char*) memory->data + newPathPointer;
    char oldResolvedPath[PATH_MAX];
    char newResolvedPath[PATH_MAX];
    char nativeOldResolvedPath[PATH_MAX];
    char nativeNewResolvedPath[PATH_MAX];
    int res = -1;
    char* preopenPath = NULL;
#endif

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

    if (!wasiFileDescriptorGet(dirFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_symlink: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &preopenFileDescriptor,
        WASI_RIGHTS_PATH_SYMLINK
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

#if defined(__MWERKS__) && defined(macintosh)
    /* TODO: */
    WASI_TRACE(("path_symlink: not supported on Macintosh"));
    return WASI_ERRNO_NOSYS;
#elif defined(__wii__)
    /* TODO: */
    WASI_TRACE(("path_symlink: not supported on Wii"));
    return WASI_ERRNO_NOSYS;
#else

    if (oldPathLength >= PATH_MAX) {
        WASI_TRACE(("path_symlink: old path too long"));
        return WASI_ERRNO_INVAL;
    }
    if (!wasiMemoryRangeIsValid(memory, oldPathPointer, oldPathLength, 1)) {
        return WASI_ERRNO_FAULT;
    }
    if (oldPathLength != 0 && memory->data[oldPathPointer] == '/') {
        return WASI_ERRNO_NOTCAPABLE;
    }

    memcpy(
        oldResolvedPath,
        memory->data + oldPathPointer,
        oldPathLength
    );
    oldResolvedPath[oldPathLength] = '\0';

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
#endif /* Macintosh or Wii */
}

WASI_IMPORT(U32, 12_pathX5Fsymlink, (
    wasmModuleInstance* instance,
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 dirFD,
    U32 newPathPointer,
    U32 newPathLength
), {
    return wasiPathSymlink(
        instance,
        oldPathPointer,
        oldPathLength,
        dirFD,
        newPathPointer,
        newPathLength
    );
})

static
U32
wasiNativePathLink(
    const char* oldPath,
    const char* newPath,
    bool follow
) {
#ifdef _WIN32
    typedef BOOL (WINAPI *CreateHardLinkFunction)(
        LPCSTR,
        LPCSTR,
        LPSECURITY_ATTRIBUTES
    );
    typedef DWORD (WINAPI *GetFinalPathFunction)(
        HANDLE,
        LPSTR,
        DWORD,
        DWORD
    );
    HMODULE kernel = GetModuleHandleA("kernel32.dll");
    CreateHardLinkFunction createHardLink;
    char target[PATH_MAX];
    size_t newPathLength = strlen(newPath);

    /* Resolve these functions dynamically
     * so older Windows versions still load.
     */
    createHardLink = (CreateHardLinkFunction)GetProcAddress(
        kernel,
        "CreateHardLinkA"
    );
    if (createHardLink == NULL) {
        return WASI_ERRNO_NOSYS;
    }
    if (GetFileAttributesA(newPath) != INVALID_FILE_ATTRIBUTES) {
        return WASI_ERRNO_EXIST;
    }
    if (newPathLength != 0
        && (newPath[newPathLength - 1] == '/' || newPath[newPathLength - 1] == '\\')) {
        return WASI_ERRNO_NOENT;
    }
    if (follow) {
        DWORD attributes = GetFileAttributesA(oldPath);
        if (attributes == INVALID_FILE_ATTRIBUTES) {
            wasiSetErrno(GetLastError());
            return wasiErrno();
        }
        if (attributes & FILE_ATTRIBUTE_REPARSE_POINT) {
            HANDLE handle;
            DWORD length;
            DWORD error;
            GetFinalPathFunction getFinalPath = (GetFinalPathFunction)GetProcAddress(
                kernel,
                "GetFinalPathNameByHandleA"
            );
            if (getFinalPath == NULL) {
                return WASI_ERRNO_NOTSUP;
            }
            handle = CreateFileA(
                oldPath,
                0,
                FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                NULL,
                OPEN_EXISTING,
                FILE_FLAG_BACKUP_SEMANTICS,
                NULL
            );
            if (handle == INVALID_HANDLE_VALUE) {
                wasiSetErrno(GetLastError());
                return wasiErrno();
            }
            length = getFinalPath(
                handle,
                target,
                sizeof(target),
                0
            );
            error = GetLastError();
            CloseHandle(handle);
            if (length == 0) {
                wasiSetErrno(error);
                return wasiErrno();
            }
            if (length >= sizeof(target)) {
                return WASI_ERRNO_NAMETOOLONG;
            }
            oldPath = target;
        }
    }
    if (!createHardLink(newPath, oldPath, NULL)) {
        DWORD error = GetLastError();
        if (error == ERROR_NOT_SUPPORTED || error == ERROR_INVALID_FUNCTION) {
            return WASI_ERRNO_NOTSUP;
        }
        wasiSetErrno(error);
        return wasiErrno();
    }
    return WASI_ERRNO_SUCCESS;
#elif HAS_LINKAT
    if (linkat(
        AT_FDCWD,
        oldPath,
        AT_FDCWD,
        newPath,
        follow ? AT_SYMLINK_FOLLOW : 0
    ) != 0) {
        return wasiErrno();
    }
    return WASI_ERRNO_SUCCESS;
#elif HAS_LINK && HAS_LSTAT
    struct stat st;
#if HAS_REALPATH
    char target[PATH_MAX];
#endif
    if (lstat(oldPath, &st) != 0) {
        return wasiErrno();
    }
    if (S_ISLNK(st.st_mode)) {
        /* link() differs across hosts in whether it follows symbolic links. */
        if (!follow) {
            return WASI_ERRNO_NOTSUP;
        }
#if HAS_REALPATH
        if (realpath(oldPath, target) == NULL) {
            return wasiErrno();
        }
        oldPath = target;
        if (stat(oldPath, &st) != 0) {
            return wasiErrno();
        }
#else
        return WASI_ERRNO_NOTSUP;
#endif
    }
    if (S_ISDIR(st.st_mode)) {
        return WASI_ERRNO_PERM;
    }
    /* The source can change between inspection and link() on older hosts. */
    return link(oldPath, newPath) == 0 ? WASI_ERRNO_SUCCESS : wasiErrno();
#else
    UNUSED_PARAMETER(oldPath);
    UNUSED_PARAMETER(newPath);
    UNUSED_PARAMETER(follow);
#if HAS_LINK
    return WASI_ERRNO_NOTSUP;
#else
    return WASI_ERRNO_NOSYS;
#endif
#endif
}

static
U32
wasiPathLink(
    wasmModuleInstance* instance,
    U32 oldFD,
    U32 lookupFlags,
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 newFD,
    U32 newPathPointer,
    U32 newPathLength
) {
    wasmMemory* memory = wasiMemory(instance);
    WasiFileDescriptor oldDescriptor = emptyWasiFileDescriptor;
    WasiFileDescriptor newDescriptor = emptyWasiFileDescriptor;
    char oldPath[PATH_MAX];
    char newPath[PATH_MAX];
    char* oldGuestPath;
    char* newGuestPath;

    WASI_TRACE((
        "path_link(oldFD=%u, lookupFlags=%u, newFD=%u)",
        oldFD,
        lookupFlags,
        newFD
    ));

    if (!wasiFileDescriptorGet(oldFD, &oldDescriptor) || oldDescriptor.path == NULL ||
        !wasiFileDescriptorGet(newFD, &newDescriptor) || newDescriptor.path == NULL) {
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &oldDescriptor,
        WASI_RIGHTS_PATH_LINK_SOURCE
    ) || !wasiFileDescriptorHasRights(
        &newDescriptor,
        WASI_RIGHTS_PATH_LINK_TARGET
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }
    if (lookupFlags & ~(U32)WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW) {
        return WASI_ERRNO_INVAL;
    }
    if (oldPathPointer > memory->size || oldPathLength > memory->size - oldPathPointer ||
        newPathPointer > memory->size || newPathLength > memory->size - newPathPointer) {
        return WASI_ERRNO_FAULT;
    }
    oldGuestPath = (char*)memory->data + oldPathPointer;
    newGuestPath = (char*)memory->data + newPathPointer;
    if (memchr(oldGuestPath, '\0', oldPathLength) != NULL ||
        memchr(newGuestPath, '\0', newPathLength) != NULL) {
        return WASI_ERRNO_INVAL;
    }
    if (!resolvePath(
        oldDescriptor.path,
        oldGuestPath,
        oldPathLength,
        oldPath
    ) || !resolvePath(
        newDescriptor.path,
        newGuestPath,
        newPathLength,
        newPath
    )) {
        return WASI_ERRNO_INVAL;
    }
#if HAS_NONPOSIXPATH
    wasiToNativePath(oldPath);
    wasiToNativePath(newPath);
#endif
    return wasiNativePathLink(
        oldPath,
        newPath,
        (lookupFlags & WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW) != 0
    );
}

WASI_IMPORT(U32, 9_pathX5Flink, (
    wasmModuleInstance* instance,
    U32 oldFD,
    U32 lookupFlags,
    U32 oldPathPointer,
    U32 oldPathLength,
    U32 newFD,
    U32 newPathPointer,
    U32 newPathLength
), {
    return wasiPathLink(
        instance,
        oldFD,
        lookupFlags,
        oldPathPointer,
        oldPathLength,
        newFD,
        newPathPointer,
        newPathLength
    );
})

static
W2C2_INLINE
U32
wasiPathReadlink(
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength,
    U32 bufferPointer,
    U32 bufferLength,
    U32 lengthPointer
) {
    WasiFileDescriptor preopenFileDescriptor = emptyWasiFileDescriptor;
#if (defined(__MWERKS__) && defined(macintosh)) || \
    defined(__wii__)
    UNUSED_PARAMETER(instance);
    UNUSED_PARAMETER(dirFD);
    UNUSED_PARAMETER(pathPointer);
    UNUSED_PARAMETER(pathLength);
    UNUSED_PARAMETER(bufferPointer);
    UNUSED_PARAMETER(bufferLength);
    UNUSED_PARAMETER(lengthPointer);
#else
    wasmMemory* memory = wasiMemory(instance);

    char* path = (char*) memory->data + pathPointer;
    char resolvedPath[PATH_MAX];
    char nativeResolvedPath[PATH_MAX];
    char* buffer = NULL;
    long length = 0;
    char* preopenPath = NULL;
#endif

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

    if (!wasiFileDescriptorGet(dirFD, &preopenFileDescriptor)) {
        WASI_TRACE(("path_readlink: bad preopen FD"));
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &preopenFileDescriptor,
        WASI_RIGHTS_PATH_READLINK
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

#if defined(__MWERKS__) && defined(macintosh)
    /* TODO: */
    WASI_TRACE(("path_readlink: not supported on Macintosh"));
    return WASI_ERRNO_NOSYS;
#elif defined(__wii__)
    /* TODO: */
    WASI_TRACE(("path_readlink: not supported on Wii"));
    return WASI_ERRNO_NOSYS;
#else
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

    buffer = (char*)memory->data + bufferPointer;

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

    i32_store(memory, lengthPointer, length);

    return WASI_ERRNO_SUCCESS;
#endif /* Macintosh or Wii */
}

WASI_IMPORT(U32, 13_pathX5Freadlink, (
    wasmModuleInstance* instance,
    U32 dirFD,
    U32 pathPointer,
    U32 pathLength,
    U32 bufferPointer,
    U32 bufferLength,
    U32 lengthPointer
), {
    return wasiPathReadlink(
        instance,
        dirFD,
        pathPointer,
        pathLength,
        bufferPointer,
        bufferLength,
        lengthPointer
    );
})

static
W2C2_INLINE
U32
wasiFdFdstatSetFlags(
    U32 wasiFD,
    U32 flags
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
#if HAS_FCNTL
    int nativeFlags;
    int newFlags;
#endif

    WASI_TRACE(("fd_fdstat_set_flags(wasiFD=%u, flags=%u)", wasiFD, flags));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_FD_FDSTAT_SET_FLAGS
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }

    if (descriptor.socket != WASI_INVALID_SOCKET) {
        U32 error;
        wasiFileDescriptorsLock();
        if (!wasiFileDescriptorGetLocked(wasiFD, &descriptor)) {
            error = WASI_ERRNO_BADF;
        } else if (!wasiFileDescriptorHasRights(
            &descriptor, WASI_RIGHTS_FD_FDSTAT_SET_FLAGS
        )) {
            error = WASI_ERRNO_NOTCAPABLE;
        } else if (descriptor.socket == WASI_INVALID_SOCKET) {
            error = WASI_ERRNO_NOTSOCK;
        } else {
            error = wasiSocketSetFlags(descriptor.socket, flags);
            if (error == WASI_ERRNO_SUCCESS) {
                wasi.fds.fds[wasiFD].socketFlags = (U16)flags;
            }
        }
        wasiFileDescriptorsUnlock();
        return error;
    }

    if (flags & ~(U32)(WASI_FDFLAGS_APPEND | WASI_FDFLAGS_DSYNC |
                      WASI_FDFLAGS_NONBLOCK | WASI_FDFLAGS_RSYNC |
                      WASI_FDFLAGS_SYNC)) {
        return WASI_ERRNO_INVAL;
    }

    if (descriptor.fd < 0) {
        return flags == 0 ? WASI_ERRNO_SUCCESS : WASI_ERRNO_NOTSUP;
    }

#ifdef _WIN32
    {
        U32 error = WASI_ERRNO_SUCCESS;
        if ((flags ^ descriptor.fileFlags)
            & (WASI_FDFLAGS_DSYNC | WASI_FDFLAGS_RSYNC | WASI_FDFLAGS_SYNC)) {
            return WASI_ERRNO_NOTSUP;
        }
        wasiFileDescriptorsLock();
        if (!wasiFileDescriptorGetLocked(wasiFD, &descriptor)) {
            error = WASI_ERRNO_BADF;
        } else if (!wasiFileDescriptorHasRights(
            &descriptor, WASI_RIGHTS_FD_FDSTAT_SET_FLAGS
        )) {
            error = WASI_ERRNO_NOTCAPABLE;
        } else if (descriptor.socket != WASI_INVALID_SOCKET) {
            error = WASI_ERRNO_NOTSUP;
        } else if (flags != 0 && GetFileType((HANDLE)_get_osfhandle(descriptor.fd))
                   != FILE_TYPE_DISK) {
            error = WASI_ERRNO_NOTSUP;
        } else {
            wasi.fds.fds[wasiFD].fileFlags = (U16)flags;
        }
        wasiFileDescriptorsUnlock();
        return error;
    }
#elif HAS_FCNTL
    nativeFlags = fcntl(descriptor.fd, F_GETFL);
    if (nativeFlags < 0) {
        return wasiErrno();
    }

    /* F_SETFL cannot portably change synchronization flags,
     * and some hosts silently ignore attempts to do so. */
    if ((flags ^ wasiFdFlagsFromNative(nativeFlags)) &
        (WASI_FDFLAGS_DSYNC | WASI_FDFLAGS_RSYNC | WASI_FDFLAGS_SYNC)) {
        return WASI_ERRNO_NOTSUP;
    }

    newFlags = nativeFlags & ~O_APPEND;
    if (flags & WASI_FDFLAGS_APPEND) {
        newFlags |= O_APPEND;
    }
#ifdef O_NONBLOCK
    newFlags &= ~O_NONBLOCK;
    if (flags & WASI_FDFLAGS_NONBLOCK) {
        newFlags |= O_NONBLOCK;
    }
#else
    if (flags & WASI_FDFLAGS_NONBLOCK) {
        return WASI_ERRNO_NOTSUP;
    }
#endif

    if (newFlags != nativeFlags && fcntl(descriptor.fd, F_SETFL, newFlags) < 0) {
        return wasiErrno();
    }

    return WASI_ERRNO_SUCCESS;
#else
    /* TODO: */
    WASI_TRACE(("fd_fdstat_set_flags: not supported on this host"));
    return WASI_ERRNO_NOSYS;
#endif /* HAS_FCNTL */
}

static
U32
wasiFdFdstatSetRights(
    U32 wasiFD,
    WasiRights base,
    WasiRights inheriting
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    U32 error = WASI_ERRNO_SUCCESS;

    WASI_TRACE((
        "fd_fdstat_set_rights(wasiFD=%u, base=%llu, inheriting=%llu)",
        wasiFD,
        base,
        inheriting
    ));

    wasiFileDescriptorsLock();
    if (!wasiFileDescriptorGetLocked(wasiFD, &descriptor)) {
        error = WASI_ERRNO_BADF;
    } else if ((base & ~descriptor.rightsBase) != 0
               || (inheriting & ~descriptor.rightsInheriting) != 0) {
        error = WASI_ERRNO_NOTCAPABLE;
    } else {
        wasi.fds.fds[wasiFD].rightsBase = base;
        wasi.fds.fds[wasiFD].rightsInheriting = inheriting;
    }
    wasiFileDescriptorsUnlock();
    return error;
}

WASI_IMPORT(U32, 20_fdX5FfdstatX5FsetX5Frights, (
    wasmModuleInstance* instance,
    U32 fd,
    U64 fsRightsBase,
    U64 fsRightsInheriting
), {
    UNUSED_PARAMETER(instance);
    return wasiFdFdstatSetRights(fd, fsRightsBase, fsRightsInheriting);
})

WASI_IMPORT(U32, 19_fdX5FfdstatX5FsetX5Fflags, (
    wasmModuleInstance* instance,
    U32 fd,
    U32 flags
), {
    UNUSED_PARAMETER(instance);
    return wasiFdFdstatSetFlags(fd, flags);
})

#if HAS_POLL || defined(_WIN32)

#ifdef _WIN32

typedef struct WasiPollFD {
    WasiNativeSocket fd;
    HANDLE handle;
    short events;
    short revents;
} WasiPollFD;

#define WASI_POLLIN 1
#define WASI_POLLOUT 2
#define WASI_POLLERR 4
#define WASI_POLLHUP 8
#define WASI_POLLNVAL 16

static
U32
wasiPollWait(WasiPollFD* descriptors, U32 count, int timeout) {
    fd_set reads, writes, errors;
    struct timeval time;
    struct timeval* timePointer = NULL;
    U32 i;
    bool hasSocket = false;
    FD_ZERO(&reads);
    FD_ZERO(&writes);
    FD_ZERO(&errors);
    for (i = 0; i < count; i++) {
        WasiPollFD* descriptor = &descriptors[i];
        fd_set* set = descriptor->events == WASI_POLLIN ? &reads : &writes;
        int type;
        int length = sizeof(type);
        descriptor->revents = 0;
        if (descriptor->handle != NULL) {
            DWORD handleType = GetFileType(descriptor->handle);
            if (handleType == FILE_TYPE_UNKNOWN) {
                descriptor->revents = WASI_POLLNVAL;
            } else if (handleType == FILE_TYPE_DISK || descriptor->events == WASI_POLLOUT) {
                descriptor->revents = descriptor->events;
            } else if (handleType == FILE_TYPE_PIPE) {
                DWORD available = 0;
                if (PeekNamedPipe(
                    descriptor->handle, NULL, 0, NULL, &available, NULL
                )) {
                    if (available != 0) {
                        descriptor->revents = WASI_POLLIN;
                    }
                } else {
                    DWORD error = GetLastError();
                    descriptor->revents = error == ERROR_BROKEN_PIPE
                        || error == ERROR_PIPE_NOT_CONNECTED
                        ? WASI_POLLHUP : WASI_POLLERR;
                }
            } else if (handleType == FILE_TYPE_CHAR) {
                if (WaitForSingleObject(descriptor->handle, 0) == WAIT_OBJECT_0) {
                    descriptor->revents = WASI_POLLIN;
                }
            } else {
                descriptor->revents = WASI_POLLNVAL;
            }
            if (descriptor->revents != 0) {
                timeout = 0;
            } else if (timeout < 0 || timeout > 10) {
                /* Recheck non-socket handles while waiting for sockets or clocks. */
                timeout = 10;
            }
            continue;
        }
        if (descriptor->fd == WASI_INVALID_SOCKET) {
            continue;
        }
        if (getsockopt(
            descriptor->fd, SOL_SOCKET, SO_TYPE, (char*)&type, &length
        ) != 0) {
            descriptor->revents = WASI_POLLNVAL;
            timeout = 0;
            continue;
        }
        if (!FD_ISSET(descriptor->fd, &errors)) {
            if (errors.fd_count == FD_SETSIZE) {
                return WASI_ERRNO_INVAL;
            }
            FD_SET(descriptor->fd, &errors);
        }
        FD_SET(descriptor->fd, set);
        hasSocket = true;
    }
    if (!hasSocket) {
        Sleep(timeout < 0 ? INFINITE : (DWORD)timeout);
        return WASI_ERRNO_SUCCESS;
    }
    if (timeout >= 0) {
        time.tv_sec = timeout / 1000;
        time.tv_usec = (timeout % 1000) * 1000;
        timePointer = &time;
    }
    if (select(0, &reads, &writes, &errors, timePointer) == SOCKET_ERROR) {
        return wasiSocketError();
    }
    for (i = 0; i < count; i++) {
        WasiPollFD* descriptor = &descriptors[i];
        if (descriptor->fd == WASI_INVALID_SOCKET) {
            continue;
        }
        if (FD_ISSET(descriptor->fd, &reads)) {
            descriptor->revents |= WASI_POLLIN;
        }
        if (FD_ISSET(descriptor->fd, &writes)) {
            descriptor->revents |= WASI_POLLOUT;
        }
        if (FD_ISSET(descriptor->fd, &errors)) {
            descriptor->revents |= WASI_POLLERR;
        }
    }
    return WASI_ERRNO_SUCCESS;
}

#else

typedef struct pollfd WasiPollFD;
#define WASI_POLLIN POLLIN
#define WASI_POLLOUT POLLOUT
#define WASI_POLLERR POLLERR
#define WASI_POLLHUP POLLHUP
#define WASI_POLLNVAL POLLNVAL

static
U32
wasiPollWait(WasiPollFD* descriptors, U32 count, int timeout) {
    return poll(descriptors, count, timeout) < 0
        ? wasiErrno() : WASI_ERRNO_SUCCESS;
}

#endif

static const U32 wasiSubscriptionSize = 48;
static const U32 wasiSubscriptionUserdataOffset = 0;
static const U32 wasiSubscriptionTypeOffset = 8;
static const U32 wasiSubscriptionClockIDOffset = 16;
static const U32 wasiSubscriptionClockTimeoutOffset = 24;
static const U32 wasiSubscriptionClockFlagsOffset = 40;
static const U32 wasiSubscriptionFDOffset = 16;

static const U32 wasiEventSize = 32;
static const U32 wasiEventUserdataOffset = 0;
static const U32 wasiEventErrorOffset = 8;
static const U32 wasiEventTypeOffset = 10;
static const U32 wasiEventFDReadwriteOffset = 16;
static const U32 wasiEventFDReadwriteFlagsOffset = 24;

#ifndef NSEC_PER_MSEC
#define NSEC_PER_MSEC W2C2_LL(1000000)
#endif

typedef struct WasiPollSubscription {
    U64 userdata;
    U64 deadline;
    U32 clockID;
    U16 error;
    WasiEventType type;
    bool socket;
} WasiPollSubscription;

static
W2C2_INLINE
U32
wasiPollClockTime(
    U32 clockID,
    U64* timestamp
) {
    I64 result = 0;
    U32 error = wasiClockTime(clockID, &result);

    if (error != WASI_ERRNO_SUCCESS) {
        return error;
    }
    if (result < 0) {
        return WASI_ERRNO_INVAL;
    }

    *timestamp = (U64)result;
    return WASI_ERRNO_SUCCESS;
}

static
W2C2_INLINE
U32
wasiPollTimeout(
    WasiPollSubscription* subscriptions,
    U32 subscriptionCount,
    bool hasImmediateEvent,
    int* timeout
) {
    U64 minimum = UINT64_MAX;
    U32 i = 0;

    if (hasImmediateEvent) {
        minimum = 0;
    }

    for (i = 0; i < subscriptionCount; i++) {
        WasiPollSubscription* subscription = &subscriptions[i];
        U64 now = 0;
        U64 remaining = 0;
        U32 error = WASI_ERRNO_SUCCESS;

        if (subscription->type != WASI_EVENT_TYPE_CLOCK) {
            continue;
        }

        error = wasiPollClockTime(subscription->clockID, &now);
        if (error != WASI_ERRNO_SUCCESS) {
            return error;
        }

        if (subscription->deadline > now) {
            remaining = subscription->deadline - now;
        }
        if (remaining < minimum) {
            minimum = remaining;
        }
    }

    if (minimum == UINT64_MAX) {
        *timeout = -1;
    } else {
        U64 milliseconds = minimum / NSEC_PER_MSEC;

        if (minimum % NSEC_PER_MSEC != 0) {
            milliseconds++;
        }
        if (milliseconds > INT_MAX) {
            milliseconds = INT_MAX;
        }
        *timeout = (int)milliseconds;
    }

    return WASI_ERRNO_SUCCESS;
}

static
W2C2_INLINE
void
wasiPollWriteEvent(
    wasmMemory* memory,
    U32 outPointer,
    U32 eventIndex,
    WasiPollSubscription* subscription,
    U16 error,
    WasiEventRwFlags flags
) {
    U32 eventPointer = outPointer + eventIndex * wasiEventSize;

    memset(memory->data + eventPointer, 0, wasiEventSize);
    i64_store(
        memory,
        eventPointer + wasiEventUserdataOffset,
        subscription->userdata
    );
    i32_store16(
        memory,
        eventPointer + wasiEventErrorOffset,
        error
    );
    i32_store8(
        memory,
        eventPointer + wasiEventTypeOffset,
        subscription->type
    );
    i64_store(
        memory,
        eventPointer + wasiEventFDReadwriteOffset,
        0
    );
    i32_store16(
        memory,
        eventPointer + wasiEventFDReadwriteFlagsOffset,
        flags
    );
}

#endif /* HAS_POLL || _WIN32 */

static
W2C2_INLINE
U32
wasiPollOneoff(
    wasmModuleInstance* instance,
    U32 inPointer,
    U32 outPointer,
    U32 subscriptionCount,
    U32 eventCountPointer
) {
#if HAS_POLL || defined(_WIN32)
    wasmMemory* memory = wasiMemory(instance);
    WasiPollSubscription* subscriptions = NULL;
    WasiPollFD* pollFDs = NULL;
    U32 result = WASI_ERRNO_SUCCESS;
    U32 i = 0;
    U32 eventCount = 0;
    bool hasImmediateEvent = false;

    WASI_TRACE((
        "poll_oneoff("
        "inPointer=0x%x, "
        "outPointer=0x%x, "
        "subscriptionCount=%d, "
        "eventCountPointer=0x%x"
        ")",
        inPointer,
        outPointer,
        subscriptionCount,
        eventCountPointer
    ));

    if (subscriptionCount == 0) {
        return WASI_ERRNO_INVAL;
    }
    if (!wasiMemoryRangeIsValid(
        memory,
        inPointer,
        subscriptionCount,
        wasiSubscriptionSize
    ) || !wasiMemoryRangeIsValid(
        memory,
        outPointer,
        subscriptionCount,
        wasiEventSize
    ) || !wasiMemoryRangeIsValid(
        memory,
        eventCountPointer,
        1,
        sizeof(U32)
    )) {
        return WASI_ERRNO_FAULT;
    }

    subscriptions = (WasiPollSubscription*)calloc(
        subscriptionCount,
        sizeof(WasiPollSubscription)
    );
    pollFDs = (WasiPollFD*)calloc(
        subscriptionCount,
        sizeof(WasiPollFD)
    );
    if (subscriptions == NULL || pollFDs == NULL) {
        result = WASI_ERRNO_NOMEM;
        goto done;
    }

    for (i = 0; i < subscriptionCount; i++) {
        U32 subscriptionPointer = inPointer + i * wasiSubscriptionSize;
        WasiPollSubscription* subscription = &subscriptions[i];
        WasiPollFD* pollFD = &pollFDs[i];

        subscription->userdata = i64_load(
            memory,
            subscriptionPointer + wasiSubscriptionUserdataOffset
        );
        subscription->type = (WasiEventType)i32_load8_u(
            memory,
            subscriptionPointer + wasiSubscriptionTypeOffset
        );
        pollFD->fd = WASI_INVALID_SOCKET;

        switch (subscription->type) {
            case WASI_EVENT_TYPE_CLOCK: {
                U64 timeout = i64_load(
                    memory,
                    subscriptionPointer
                    + wasiSubscriptionClockTimeoutOffset
                );
                WasiSubclockFlags flags = (WasiSubclockFlags)i32_load16_u(
                    memory,
                    subscriptionPointer
                    + wasiSubscriptionClockFlagsOffset
                );

                subscription->clockID = i32_load(
                    memory,
                    subscriptionPointer + wasiSubscriptionClockIDOffset
                );
                if (subscription->clockID != WASI_CLOCK_REALTIME
                    && subscription->clockID != WASI_CLOCK_MONOTONIC) {
                    result = WASI_ERRNO_NOTSUP;
                    goto done;
                }
                if ((flags & ~WASI_SUBCLOCK_FLAGS_ABSTIME) != 0) {
                    result = WASI_ERRNO_INVAL;
                    goto done;
                }

                if ((flags & WASI_SUBCLOCK_FLAGS_ABSTIME) != 0) {
                    subscription->deadline = timeout;
                } else {
                    U64 now = 0;

                    result = wasiPollClockTime(
                        subscription->clockID,
                        &now
                    );
                    if (result != WASI_ERRNO_SUCCESS) {
                        goto done;
                    }
                    if (timeout > UINT64_MAX - now) {
                        subscription->deadline = UINT64_MAX;
                    } else {
                        subscription->deadline = now + timeout;
                    }
                }
                break;
            }
            case WASI_EVENT_TYPE_FD_READ:
            case WASI_EVENT_TYPE_FD_WRITE: {
                WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
                WasiRights required = WASI_RIGHTS_POLL_FD_READWRITE
                    | (subscription->type == WASI_EVENT_TYPE_FD_READ
                       ? WASI_RIGHTS_FD_READ : WASI_RIGHTS_FD_WRITE);
                U32 wasiFD = i32_load(
                    memory,
                    subscriptionPointer + wasiSubscriptionFDOffset
                );

                if (!wasiFileDescriptorGet(wasiFD, &descriptor)
                    || (descriptor.fd < 0
                        && descriptor.socket == WASI_INVALID_SOCKET)) {
                    subscription->error = WASI_ERRNO_BADF;
                    hasImmediateEvent = true;
                } else if (!wasiFileDescriptorHasRights(&descriptor, required)) {
                    subscription->error = WASI_ERRNO_NOTCAPABLE;
                    hasImmediateEvent = true;
                } else {
                    subscription->socket = descriptor.socket != WASI_INVALID_SOCKET;
#ifdef _WIN32
                    if (descriptor.socket == WASI_INVALID_SOCKET) {
                        pollFD->handle = (HANDLE)_get_osfhandle(descriptor.fd);
                    } else {
                        pollFD->fd = descriptor.socket;
                    }
#else
                    pollFD->fd = descriptor.socket != WASI_INVALID_SOCKET
                        ? descriptor.socket : descriptor.fd;
#endif
                }

                if (subscription->type == WASI_EVENT_TYPE_FD_READ) {
                    pollFD->events = WASI_POLLIN;
                } else {
                    pollFD->events = WASI_POLLOUT;
                }
                break;
            }
            default: {
                result = WASI_ERRNO_INVAL;
                goto done;
            }
        }
    }

    for (;;) {
        int timeout = -1;

        result = wasiPollTimeout(
            subscriptions,
            subscriptionCount,
            hasImmediateEvent,
            &timeout
        );
        if (result != WASI_ERRNO_SUCCESS) {
            goto done;
        }

        result = wasiPollWait(pollFDs, subscriptionCount, timeout);
        if (result != WASI_ERRNO_SUCCESS) {
            goto done;
        }

        eventCount = 0;
        for (i = 0; i < subscriptionCount; i++) {
            WasiPollSubscription* subscription = &subscriptions[i];
            WasiPollFD* pollFD = &pollFDs[i];

            if (subscription->type == WASI_EVENT_TYPE_CLOCK) {
                U64 now = 0;

                result = wasiPollClockTime(
                    subscription->clockID,
                    &now
                );
                if (result != WASI_ERRNO_SUCCESS) {
                    goto done;
                }
                if (subscription->deadline > now) {
                    continue;
                }

                wasiPollWriteEvent(
                    memory,
                    outPointer,
                    eventCount,
                    subscription,
                    WASI_ERRNO_SUCCESS,
                    0
                );
                eventCount++;
                continue;
            }

            if (subscription->error != WASI_ERRNO_SUCCESS) {
                wasiPollWriteEvent(
                    memory,
                    outPointer,
                    eventCount,
                    subscription,
                    subscription->error,
                    0
                );
                eventCount++;
                continue;
            }

            if (pollFD->revents != 0) {
                U16 error = WASI_ERRNO_SUCCESS;
                WasiEventRwFlags flags = 0;

                if ((pollFD->revents & WASI_POLLNVAL) != 0) {
                    error = WASI_ERRNO_BADF;
                } else if ((pollFD->revents & WASI_POLLERR) != 0
                           && !subscription->socket) {
                    error = WASI_ERRNO_IO;
                }
                if ((pollFD->revents & WASI_POLLHUP) != 0) {
                    flags |= WASI_EVENT_RW_FLAGS_HANGUP;
                }

                wasiPollWriteEvent(
                    memory,
                    outPointer,
                    eventCount,
                    subscription,
                    error,
                    flags
                );
                eventCount++;
            }
        }

        if (eventCount > 0) {
            break;
        }
    }

    i32_store(memory, eventCountPointer, eventCount);

done:
    free(pollFDs);
    free(subscriptions);
    return result;
#else
    UNUSED_PARAMETER(instance);
    UNUSED_PARAMETER(inPointer);
    UNUSED_PARAMETER(outPointer);
    UNUSED_PARAMETER(subscriptionCount);
    UNUSED_PARAMETER(eventCountPointer);
    WASI_TRACE(("poll_oneoff: not supported on this host"));
    return WASI_ERRNO_NOSYS;
#endif /* HAS_POLL || _WIN32 */
}

WASI_IMPORT(U32, 11_pollX5Foneoff, (
    wasmModuleInstance* instance,
    U32 inPointer,
    U32 outPointer,
    U32 subscriptionCount,
    U32 eventCountPointer
), {
    return wasiPollOneoff(
        instance,
        inPointer,
        outPointer,
        subscriptionCount,
        eventCountPointer
    );
})

static
W2C2_INLINE
U32
wasiRandomGet(
    wasmModuleInstance* instance,
    U32 bufferPointer,
    U32 bufferLength
) {
    wasmMemory* memory = wasiMemory(instance);
    U8* bufferStart = NULL;
#if !(defined(_WIN32) && !(defined(_MSC_VER) && _MSC_VER <= 1000))
    ssize_t result = 0;
#endif

    WASI_TRACE((
        "random_get("
        "bufferPointer=0x%x, "
        "bufferLength=%d"
        ")",
        bufferPointer,
        bufferLength
    ));

    if (!wasiMemoryRangeIsValid(memory, bufferPointer, bufferLength, 1)) {
        return WASI_ERRNO_FAULT;
    }
    if (bufferLength == 0) {
        return WASI_ERRNO_SUCCESS;
    }
    bufferStart = memory->data + bufferPointer;

#if defined(_WIN32) && !(defined(_MSC_VER) && _MSC_VER <= 1000)
#include <wincrypt.h>
    {
        HCRYPTPROV provider;
        bool success;

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
    while (bufferLength > 0) {
        U32 length = bufferLength > 256 ? 256 : bufferLength;
        if (getentropy(bufferStart, length) != 0) {
            if (errno == EINTR) {
                continue;
            }
            if (errno == ENOSYS) {
                break;
            }
            WASI_TRACE(("random_get: getentropy failed: %s", strerror(errno)));
            return wasiErrno();
        }
        bufferStart += length;
        bufferLength -= length;
    }
    if (bufferLength == 0) {
        return WASI_ERRNO_SUCCESS;
    }
#endif
    /* Try /dev/random. Might not be available */
    {
        int fd = -1;

        fd = open("/dev/random", O_RDONLY, 0);
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
#if defined(PLAN9) || (defined(__MWERKS__) && defined(macintosh)) || (defined(_MSC_VER) && _MSC_VER <= 1000)
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

WASI_IMPORT(U32, 10_randomX5Fget, (
    wasmModuleInstance* instance,
    U32 bufferPointer,
    U32 bufferLength
), {
    return wasiRandomGet(
        instance,
        bufferPointer,
        bufferLength
    );
})

static
W2C2_INLINE
U32
wasiSchedYield(void) {
    WASI_TRACE(("sched_yield()"));

#ifdef _WIN32
    Sleep(0);
#elif HAS_SCHED_YIELD
    if (sched_yield() != 0) {
        return wasiErrno();
    }
#elif defined(WASM_THREAD_TYPE)
    /* TODO: */
    WASI_TRACE(("sched_yield: not supported on this host"));
    return WASI_ERRNO_NOSYS;
#else
    /* A build without thread support can treat yielding as a no-op. */
#endif

    return WASI_ERRNO_SUCCESS;
}

WASI_IMPORT(U32, 11_schedX5Fyield, (
    wasmModuleInstance* instance
), {
    UNUSED_PARAMETER(instance);
    return wasiSchedYield();
})

static
W2C2_INLINE
bool
wasiFileRangeFitsNative(U64 offset, U64 length) {
    U64 end;
    if (length > UINT64_MAX - offset) {
        return false;
    }
    end = offset + length;
#ifdef _WIN32
    return end <= (U64)INT64_MAX;
#else
    return (off_t)end >= 0 && (U64)(off_t)end == end;
#endif
}

#ifdef _WIN32

static
U32
wasiWindowsAllocate(int fd, U64 end) {
    typedef BOOL (WINAPI *FileInformationFunction)(
        HANDLE,
        int,
        LPVOID,
        DWORD
    );
    /* FILE_STANDARD_INFO layout and information classes for older SDKs. */
    struct {
        LARGE_INTEGER allocationSize;
        LARGE_INTEGER endOfFile;
        DWORD numberOfLinks;
        BYTE deletePending;
        BYTE directory;
    } standard;
    enum {
        wasiFileStandardInfo = 1,
        wasiFileAllocationInfo = 5,
        wasiFileEndOfFileInfo = 6
    };
    HMODULE kernel = GetModuleHandleA("kernel32.dll");
    HANDLE handle = (HANDLE)_get_osfhandle(fd);
    FileInformationFunction getInfo;
    FileInformationFunction setInfo;
    BY_HANDLE_FILE_INFORMATION info;
    LARGE_INTEGER size;
    DWORD error;

    if (handle == INVALID_HANDLE_VALUE) {
        return WASI_ERRNO_BADF;
    }
    getInfo = (FileInformationFunction)GetProcAddress(
        kernel,
        "GetFileInformationByHandleEx"
    );
    setInfo = (FileInformationFunction)GetProcAddress(
        kernel,
        "SetFileInformationByHandle"
    );
    if (getInfo == NULL || setInfo == NULL) {
        return WASI_ERRNO_NOSYS;
    }
    if (!GetFileInformationByHandle(handle, &info)) {
        goto failed;
    }
    if (info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
        return WASI_ERRNO_ISDIR;
    }
    /* Allocation size does not reserve storage for sparse or compressed files. */
    if (info.dwFileAttributes & (FILE_ATTRIBUTE_SPARSE_FILE | FILE_ATTRIBUTE_COMPRESSED)) {
        return WASI_ERRNO_NOTSUP;
    }
    if (!getInfo(
        handle,
        wasiFileStandardInfo,
        &standard,
        sizeof(standard)
    )) {
        goto failed;
    }
    size.QuadPart = (I64)end;
    if (size.QuadPart < standard.allocationSize.QuadPart) {
        size = standard.allocationSize;
    }
    if (size.QuadPart < standard.endOfFile.QuadPart) {
        size = standard.endOfFile;
    }
    if (!setInfo(
        handle,
        wasiFileAllocationInfo,
        &size,
        sizeof(size)
    )) {
        goto failed;
    }
    /* Allocation and size extension are separate operations,
     * so concurrent file size changes are not atomic with this sequence.
     */
    if ((U64)standard.endOfFile.QuadPart < end) {
        size.QuadPart = (I64)end;
        if (!setInfo(
            handle,
            wasiFileEndOfFileInfo,
            &size,
            sizeof(size)
        )) {
            goto failed;
        }
    }
    return WASI_ERRNO_SUCCESS;

failed:
    error = GetLastError();
    if (error == ERROR_CALL_NOT_IMPLEMENTED) {
        return WASI_ERRNO_NOSYS;
    }
    if (error == ERROR_NOT_SUPPORTED || error == ERROR_INVALID_FUNCTION) {
        return WASI_ERRNO_NOTSUP;
    }
    wasiSetErrno(error);
    return wasiErrno();
}

#endif /* _WIN32 */

static
U32
wasiFdAllocate(
    U32 wasiFD,
    U64 offset,
    U64 length
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
#ifndef _WIN32
    struct stat st;
#endif
    WASI_TRACE((
        "fd_allocate(wasiFD=%u, offset=%llu, length=%llu)",
        wasiFD,
        offset,
        length
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_FD_ALLOCATE
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }
    if (descriptor.fd < 0) {
        return WASI_ERRNO_ISDIR;
    }
    if (length == 0) {
        return WASI_ERRNO_INVAL;
    }
    if (!wasiFileRangeFitsNative(offset, length)) {
        return WASI_ERRNO_OVERFLOW;
    }
#ifdef _WIN32
    return wasiWindowsAllocate(descriptor.fd, offset + length);
#else
    if (fstat(descriptor.fd, &st) != 0) {
        return wasiErrno();
    }
    if (S_ISDIR(st.st_mode)) {
        return WASI_ERRNO_ISDIR;
    }
    if (!S_ISREG(st.st_mode)) {
        return WASI_ERRNO_NODEV;
    }
#if HAS_POSIX_FALLOCATE
    {
        int error = posix_fallocate(
            descriptor.fd,
            (off_t)offset,
            (off_t)length
        );
        if (error != 0) {
            /* posix_fallocate returns an error number without setting errno. */
            errno = error;
            return wasiErrno();
        }
    }
#elif HAS_F_PREALLOCATE
    {
        U64 end = offset + length;
        U64 required = end > (U64)st.st_size ? end : (U64)st.st_size;
        U64 allocated = (U64)st.st_blocks * 512;
        int flags = fcntl(descriptor.fd, F_GETFL);
        if (flags < 0) {
            return wasiErrno();
        }
        if ((flags & O_ACCMODE) == O_RDONLY) {
            return WASI_ERRNO_BADF;
        }
        if (allocated < required) {
            fstore_t store;
            memset(&store, 0, sizeof(store));
            store.fst_flags = F_ALLOCATEALL;
            store.fst_posmode = F_PEOFPOSMODE;
            /* F_PEOFPOSMODE adds space to the physical end of the file.
             * Reserve only the missing storage to avoid repeated over-allocation.
             */
            store.fst_length = (off_t)(required - allocated);
            if (fcntl(descriptor.fd, F_PREALLOCATE, &store) != 0) {
                return wasiErrno();
            }
        }
        /* Allocation and size extension are separate operations,
         * so concurrent file size changes are not atomic with this sequence.
         */
        if ((U64)st.st_size < end && ftruncate(descriptor.fd, (off_t)end) != 0) {
            return wasiErrno();
        }
    }
#else
    return WASI_ERRNO_NOSYS;
#endif
    return WASI_ERRNO_SUCCESS;
#endif /* _WIN32 */
}

WASI_IMPORT(U32, 11_fdX5Fallocate, (
    wasmModuleInstance* instance,
    U32 fd,
    U64 offset,
    U64 len
), {
    UNUSED_PARAMETER(instance);
    return wasiFdAllocate(fd, offset, len);
})

static
U32
wasiFdAdvise(
    U32 wasiFD,
    U64 offset,
    U64 length,
    U32 advice
) {
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
#ifndef _WIN32
    struct stat st;
#endif
    WASI_TRACE((
        "fd_advise(wasiFD=%u, offset=%llu, length=%llu, advice=%u)",
        wasiFD,
        offset,
        length,
        advice
    ));

    if (!wasiFileDescriptorGet(wasiFD, &descriptor)) {
        return WASI_ERRNO_BADF;
    }
    if (!wasiFileDescriptorHasRights(
        &descriptor,
        WASI_RIGHTS_FD_ADVISE
    )) {
        return WASI_ERRNO_NOTCAPABLE;
    }
    if (descriptor.fd < 0) {
        return WASI_ERRNO_ISDIR;
    }
    if (advice > WASI_ADVICE_NOREUSE) {
        return WASI_ERRNO_INVAL;
    }
    if (!wasiFileRangeFitsNative(offset, length)) {
        return WASI_ERRNO_OVERFLOW;
    }
#ifdef _WIN32
    {
        HANDLE handle = (HANDLE)_get_osfhandle(descriptor.fd);
        DWORD type;
        if (handle == INVALID_HANDLE_VALUE) {
            return WASI_ERRNO_BADF;
        }
        type = GetFileType(handle);
        if (type == FILE_TYPE_UNKNOWN) {
            wasiSetErrno(GetLastError());
            return wasiErrno();
        }
        if (type == FILE_TYPE_PIPE) {
            return WASI_ERRNO_SPIPE;
        }
    }
#else
    if (fstat(descriptor.fd, &st) != 0) {
        return wasiErrno();
    }
#ifdef S_ISFIFO
    if (S_ISFIFO(st.st_mode)) {
        return WASI_ERRNO_SPIPE;
    }
#endif
#if HAS_POSIX_FADVISE
    {
        int nativeAdvice;
        int error;
        switch (advice) {
            case WASI_ADVICE_NORMAL:
                nativeAdvice = POSIX_FADV_NORMAL;
                break;
            case WASI_ADVICE_SEQUENTIAL:
                nativeAdvice = POSIX_FADV_SEQUENTIAL;
                break;
            case WASI_ADVICE_RANDOM:
                nativeAdvice = POSIX_FADV_RANDOM;
                break;
            case WASI_ADVICE_WILLNEED:
                nativeAdvice = POSIX_FADV_WILLNEED;
                break;
            case WASI_ADVICE_DONTNEED:
                nativeAdvice = POSIX_FADV_DONTNEED;
                break;
            case WASI_ADVICE_NOREUSE:
                nativeAdvice = POSIX_FADV_NOREUSE;
                break;
            default:
                return WASI_ERRNO_INVAL;
        }
        error = posix_fadvise(
            descriptor.fd,
            (off_t)offset,
            (off_t)length,
            nativeAdvice
        );
        if (error != 0) {
            /* posix_fadvise returns an error number without setting errno. */
            errno = error;
            return wasiErrno();
        }
    }
#endif
#endif /* _WIN32 */
    /* Advice is optional on hosts without a corresponding native API. */
    return WASI_ERRNO_SUCCESS;
}

WASI_IMPORT(U32, 9_fdX5Fadvise, (
    wasmModuleInstance* instance,
    U32 fd,
    U64 offset,
    U64 len,
    U32 advise
), {
    UNUSED_PARAMETER(instance);
    return wasiFdAdvise(
        fd,
        offset,
        len,
        advise
    );
})

static
U32
wasiSockAccept(
    wasmMemory* memory,
    U32 wasiFD,
    U32 flags,
    U32 resultPointer
) {
#if HAS_SOCKETS || defined(_WIN32)
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    WasiNativeSocket accepted;
    U32 newFD;
    U32 error = wasiSocketGet(wasiFD, WASI_RIGHTS_SOCK_ACCEPT, &descriptor);
    if (error != WASI_ERRNO_SUCCESS) {
        return error;
    }
    if (!wasiMemoryRangeIsValid(memory, resultPointer, 1, 4)) {
        return WASI_ERRNO_FAULT;
    }
    if (flags & ~(U32)(WASI_FDFLAGS_APPEND | WASI_FDFLAGS_DSYNC |
                      WASI_FDFLAGS_NONBLOCK | WASI_FDFLAGS_RSYNC |
                      WASI_FDFLAGS_SYNC)) {
        return WASI_ERRNO_INVAL;
    }
    if (flags & ~(U32)WASI_FDFLAGS_NONBLOCK) {
        return WASI_ERRNO_NOTSUP;
    }
    accepted = accept(descriptor.socket, NULL, NULL);
    if (accepted == WASI_INVALID_SOCKET) {
        return wasiSocketError();
    }
    error = wasiSocketAddWithRights(
        accepted,
        flags,
        descriptor.rightsInheriting,
        descriptor.rightsInheriting,
        &newFD
    );
    if (error != WASI_ERRNO_SUCCESS) {
        wasiSocketClose(accepted);
        return error;
    }
    i32_store(memory, resultPointer, newFD);
    return WASI_ERRNO_SUCCESS;
#else
    UNUSED_PARAMETER(memory);
    UNUSED_PARAMETER(wasiFD);
    UNUSED_PARAMETER(flags);
    UNUSED_PARAMETER(resultPointer);
    return WASI_ERRNO_NOSYS;
#endif
}

WASI_IMPORT(U32, 11_sockX5Faccept, (
    wasmModuleInstance* instance,
    U32 fd,
    U32 flags,
    U32 resultPointer
), {
    return wasiSockAccept(wasiMemory(instance), fd, flags, resultPointer);
})

static
U32
wasiSockRecv(
    wasmMemory* memory,
    U32 fd,
    U32 iovecsPointer,
    U32 iovecsCount,
    U32 flags,
    U32 sizeResultPointer,
    U32 flagsResultPointer
) {
#if HAS_SOCKETS || defined(_WIN32)
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    U16 resultFlags;
    U32 error = wasiSocketGet(fd, WASI_RIGHTS_FD_READ, &descriptor);
    if (error != WASI_ERRNO_SUCCESS) {
        return error;
    }
    if (!wasiMemoryRangeIsValid(memory, flagsResultPointer, 1, 2)) {
        return WASI_ERRNO_FAULT;
    }
    error = wasiSocketTransfer(
        memory, &descriptor, iovecsPointer, iovecsCount,
        flags, sizeResultPointer, &resultFlags, true
    );
    if (error == WASI_ERRNO_SUCCESS) {
        i32_store16(memory, flagsResultPointer, resultFlags);
    }
    return error;
#else
    UNUSED_PARAMETER(memory);
    UNUSED_PARAMETER(fd);
    UNUSED_PARAMETER(iovecsPointer);
    UNUSED_PARAMETER(iovecsCount);
    UNUSED_PARAMETER(flags);
    UNUSED_PARAMETER(sizeResultPointer);
    UNUSED_PARAMETER(flagsResultPointer);
    return WASI_ERRNO_NOSYS;
#endif
}

WASI_IMPORT(U32, 9_sockX5Frecv, (
    wasmModuleInstance* instance,
    U32 fd,
    U32 iovecsPointer,
    U32 iovecsCount,
    U32 flags,
    U32 sizeResultPointer,
    U32 flagsResultPointer
), {
    return wasiSockRecv(
        wasiMemory(instance), fd, iovecsPointer, iovecsCount,
        flags, sizeResultPointer, flagsResultPointer
    );
})

static
U32
wasiSockSend(
    wasmMemory* memory,
    U32 fd,
    U32 ciovecsPointer,
    U32 ciovecsCount,
    U32 flags,
    U32 resultPointer
) {
#if HAS_SOCKETS || defined(_WIN32)
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    U32 error = wasiSocketGet(fd, WASI_RIGHTS_FD_WRITE, &descriptor);
    if (error != WASI_ERRNO_SUCCESS) {
        return error;
    }
    return wasiSocketTransfer(
        memory, &descriptor, ciovecsPointer, ciovecsCount,
        flags, resultPointer, NULL, false
    );
#else
    UNUSED_PARAMETER(memory);
    UNUSED_PARAMETER(fd);
    UNUSED_PARAMETER(ciovecsPointer);
    UNUSED_PARAMETER(ciovecsCount);
    UNUSED_PARAMETER(flags);
    UNUSED_PARAMETER(resultPointer);
    return WASI_ERRNO_NOSYS;
#endif
}

WASI_IMPORT(U32, 9_sockX5Fsend, (
    wasmModuleInstance* instance,
    U32 fd,
    U32 ciovecsPointer,
    U32 ciovecsCount,
    U32 flags,
    U32 resultPointer
), {
    return wasiSockSend(
        wasiMemory(instance), fd, ciovecsPointer, ciovecsCount,
        flags, resultPointer
    );
})

static
U32
wasiSockShutdown(U32 fd, U32 how) {
#if HAS_SOCKETS || defined(_WIN32)
    WasiFileDescriptor descriptor = emptyWasiFileDescriptor;
    int nativeHow;
    U32 error = wasiSocketGet(fd, WASI_RIGHTS_SOCK_SHUTDOWN, &descriptor);
    if (error != WASI_ERRNO_SUCCESS) {
        return error;
    }
    if (how == 0 || (how & ~(U32)(WASI_SDFLAGS_RD | WASI_SDFLAGS_WR))) {
        return WASI_ERRNO_INVAL;
    }
#ifdef _WIN32
    nativeHow = how == WASI_SDFLAGS_RD ? SD_RECEIVE
        : how == WASI_SDFLAGS_WR ? SD_SEND : SD_BOTH;
#else
    nativeHow = how == WASI_SDFLAGS_RD ? SHUT_RD
        : how == WASI_SDFLAGS_WR ? SHUT_WR : SHUT_RDWR;
#endif
    if (shutdown(descriptor.socket, nativeHow) != 0) {
        return wasiSocketError();
    }
    return WASI_ERRNO_SUCCESS;
#else
    UNUSED_PARAMETER(fd);
    UNUSED_PARAMETER(how);
    return WASI_ERRNO_NOSYS;
#endif
}

WASI_IMPORT(U32, 13_sockX5Fshutdown, (
    wasmModuleInstance* instance,
    U32 fd,
    U32 how
), {
    UNUSED_PARAMETER(instance);
    return wasiSockShutdown(fd, how);
})

typedef void (*wasiThreadStartFunc)(wasmModuleInstance* instance, U32 threadID, U32 startArg);

typedef struct ThreadStartArg {
    wasmModuleInstance* instance;
    U32 startArg;
    U32 threadID;
    wasiThreadStartFunc startFunc;
} ThreadStartArg;

static
void*
wasiThreadSpawn(
    void* arg
) {
    ThreadStartArg* threadStartArg = (ThreadStartArg*) arg;
    wasmModuleInstance* instance = threadStartArg->instance;
    U32 threadID = threadStartArg->threadID;
    U32 startArg = threadStartArg->startArg;
    wasiThreadStartFunc startFunc = threadStartArg->startFunc;
    free(threadStartArg);

    startFunc(instance, threadID, startArg);
    instance->freeChild(instance);

    return NULL;
}

U32
i4_wasi12_threadX2Dspawn(
    wasmModuleInstance* instance,
    U32 startArg
) {
    static U32 nextThreadID = 1;

    ThreadStartArg *threadStartArg = NULL;
    U32 threadID = 0;
    wasmFuncExport* funcExport = instance->funcExports;
    wasmFunc startFunc = NULL;

    WASI_TRACE(("thread-spawn(startArg=%d)", startArg));

#if defined(WASM_THREAD_TYPE) && (defined(WASM_ATOMICS_MSVC) || defined(WASM_ATOMICS_GCC))

    /* Find the thread start function that must be exported by the module */
    for (; funcExport->func != NULL; funcExport++) {
        if (funcExport->name.length == sizeof("wasi_thread_start") - 1
            && memcmp(funcExport->name.data, "wasi_thread_start", funcExport->name.length) == 0) {
            startFunc = funcExport->func;
            break;
        }
    }
    if (startFunc == NULL) {
        WASI_TRACE(("thread-spawn: wasi_thread_start not found"));
        return UINT32_MAX;
    }

    /* Allocate and set up the argument for the thread.
     * It will be freed at the start of the thread execution,
     * see wasiThreadSpawn.
     */
    threadStartArg = calloc(1, sizeof(ThreadStartArg));
    if (threadStartArg == NULL) {
        WASI_TRACE(("thread-spawn: allocation failed"));
        return UINT32_MAX;
    }

    threadID = atomic_add_U32(&nextThreadID, 1);

    threadStartArg->instance = instance->newChild(instance);
    threadStartArg->startArg = startArg;
    threadStartArg->threadID = threadID;
    threadStartArg->startFunc = (wasiThreadStartFunc)startFunc;

    /* Finally, start the thread */
    {
        WASM_THREAD_TYPE thread;
        if (!WASM_THREAD_CREATE(&thread, wasiThreadSpawn, threadStartArg)) {
            WASI_TRACE(("thread-spawn: pthread_create failed"));
            threadStartArg->instance->freeChild(threadStartArg->instance);
            free(threadStartArg);
            return UINT32_MAX;
        }
        WASM_THREAD_DETACH(thread);
    }

    WASI_TRACE(("thread-spawn: threadID=%d", threadID));

#else
    WASI_TRACE(("thread-spawn: missing threads and atomics implementation"))
    return UINT32_MAX;
#endif

    return threadID;
}
