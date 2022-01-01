#ifndef W2C2_WASI_H
#define W2C2_WASI_H

#include "../w2c2_base.h"

typedef struct WasiFileDescriptors {
    int* fds;
    size_t length;
    size_t capacity;
} WasiFileDescriptors;

typedef struct WasiPreopen {
    char* path;
    int fd;
} WasiPreopen;

static const WasiPreopen wasiEmptyPreopen = {NULL, -1};

typedef struct WasiPreopens {
    WasiPreopen* preopens;
    size_t length;
    size_t capacity;
} WasiPreopens;

typedef struct WASI {
    int envc;
    char** envp;
    int argc;
    char** argv;
    WasiFileDescriptors fds;
    WasiPreopens preopens;
} WASI;

bool
WARN_UNUSED_RESULT
wasiInit(
    int argc,
    char* argv[],
    char** envp
);

bool
WARN_UNUSED_RESULT
wasiFileDescriptorAdd(
    int nativeFD,
    U32* wasiFD
);

bool
WARN_UNUSED_RESULT
wasiFileDescriptorSet(
    U32 wasiFD,
    int nativeFD
);

bool
WARN_UNUSED_RESULT
wasiFileDescriptorGet(
    U32 wasiFD,
    int* nativeFD
);

bool
WARN_UNUSED_RESULT
wasiFileDescriptorClose(
    U32 wasiFD
);

bool
WARN_UNUSED_RESULT
wasiPreopenAdd(
    WasiPreopen preopen,
    U32* wasiFD
);

bool
WARN_UNUSED_RESULT
wasiPreopenGet(
    U32 wasiFD,
    WasiPreopen* preopen
);

typedef enum WasiPreopentype {
    wasiPreopentypeDirectory = 0
} WasiPreopentype;

typedef enum WasiFiletype {
    wasiFiletypeUnknown = 0,
    wasiFiletypeBlockDevice = 1,
    wasiFiletypeCharacterDevice = 2,
    wasiFiletypeDirectory = 3,
    wasiFiletypeRegularFile = 4,
    wasiFiletypeSymbolicLink = 7
} WasiFiletype;

typedef enum WasiFdflags {
    /* Append mode: Data written to the file is always appended to the file's end */
    wasiFdflagsAppend = 1ULL << 0,

    /*
     * Write according to synchronized I/O data integrity completion.
     * Only the data stored in the file is synchronized
     */
    wasiFdflagsDsync = 1ULL << 1,

    /* Non-blocking mode */
    wasiFdflagsNonblock = 1ULL << 2,

    /* Synchronized read I/O operations */
    wasiFdflagsRsync = 1ULL << 3,

    /*
     * Write according to synchronized I/O file integrity completion.
     * In addition to synchronizing the data stored in the file,
     * the implementation may also synchronously update the file's metadata
     */
    wasiFdflagsSync = 1ULL << 4
} WasiFdflags;

typedef enum WasiOflags {
    /* Create file if it does not exist */
    wasiOflagsCreat = 1ULL << 0,

    /* Fail if not a directory */
    wasiOflagsDirectory = 1ULL << 1,

    /* Fail if file already exists */
    wasiOflagsExcl = 1ULL << 2,

    /* Truncate file to size 0 */
    wasiOflagsTrunc = 1ULL << 3
} WasiOflags;

typedef enum WasiLookupFlag {
    /* As long as the resolved path corresponds to a symbolic link, it is expanded */
    wasiLookupFlagSymlinkFollow = 1ULL << 0
} WasiLookupFlag;

typedef U64 WasiRights;

/*
 * The right to invoke `fd_datasync`.
 * If `path_open` is set, includes the right to invoke
 * `path_open` with fdflags dsync
 */
static const WasiRights wasiRightsFdDatasync = 1ULL << 0;

/*
 * The right to invoke `fd_read` and `sock_recv`.
 * If rights fd_seek is set, includes the right to invoke `fd_pread`.
 */
static const WasiRights wasiRightsFdRead = 1ULL << 1;

/* The right to invoke `fd_seek`. This flag implies rights fd_tell */
static const WasiRights wasiRightsFdSeek = 1ULL << 2;

/* The right to invoke `fd_fdstat_set_flags` */
static const WasiRights wasiRightsFdFdstatSetFlags = 1ULL << 3;

/*
 * The right to invoke `fd_sync`.
 * If `path_open` is set, includes the right to invoke
 * `path_open` with fdflags rsync and fdflags dsync.
 */
static const WasiRights wasiRightsFdSync = 1ULL << 4;

/*
 * The right to invoke `fd_seek` in such a way that the file offset
 * remains unaltered (i.e., whence cur with offset zero), or to
 * invoke `fd_tell`.
 */
static const WasiRights wasiRightsFdTell = 1ULL << 5;

/*
 * The right to invoke `fd_write` and `sock_send`.
 * If right `FdSeek` is set, includes the right to invoke `fd_pwrite`.
 */
static const WasiRights wasiRightsFdWrite = 1ULL << 6;

/* The right to invoke `fd_advise` */
static const WasiRights wasiRightsFdAdvise = 1ULL << 7;

/* The right to invoke `fd_allocate` */
static const WasiRights wasiRightsFdAllocate = 1ULL << 8;

/* The right to invoke `path_create_directory` */
static const WasiRights wasiRightsPathCreateDirectory = 1ULL << 9;

/* If `path_open` is set, the right to invoke `path_open` with oflags creat */
static const WasiRights wasiRightsPathCreateFile = 1ULL << 10;

/*
 * The right to invoke `path_link` with the file descriptor as the
 * source directory.
 */
static const WasiRights wasiRightsPathLinkSource = 1ULL << 11;

/*
 * The right to invoke `path_link` with the file descriptor as the
 * target directory.
 */
static const WasiRights wasiRightsPathLinkTarget = 1ULL << 12;

/* The right to invoke `path_open` */
static const WasiRights wasiRightsPathOpen = 1ULL << 13;

/* The right to invoke `fd_readdir` */
static const WasiRights wasiRightsFdReaddir = 1ULL << 14;

/* The right to invoke `path_readlink` */
static const WasiRights wasiRightsPathReadlink = 1ULL << 15;

/*
 * The right to invoke `path_rename` with the file descriptor as the source
 * directory.
 */
static const WasiRights wasiRightsPathRenameSource = 1ULL << 16;

/*
 * The right to invoke `path_rename` with the file descriptor as the target
 * directory.
 */
static const WasiRights wasiRightsPathRenameTarget = 1ULL << 17;

/* The right to invoke `path_filestat_get` */
static const WasiRights wasiRightsPathFilestatGet = 1ULL << 18;

/*
 * The right to change a file's size (there is no `path_filestat_set_size`).
 * If `path_open` is set, includes the right to invoke `path_open` with
 * oflags trunc.
 */
static const WasiRights wasiRightsPathFilestatSetSize = 1ULL << 19;

/* The right to invoke `path_filestat_set_times` */
static const WasiRights wasiRightsPathFilestatSetTimes = 1ULL << 20;

/* The right to invoke `fd_filestat_get` */
static const WasiRights wasiRightsFdFilestatGet = 1ULL << 21;

/* The right to invoke `fd_filestat_set_size` */
static const WasiRights wasiRightsFdFilestatSetSize = 1ULL << 22;

/* The right to invoke `fd_filestat_set_times` */
static const WasiRights wasiRightsFdFilestatSetTimes = 1ULL << 23;

/* The right to invoke `path_symlink` */
static const WasiRights wasiRightsPathSymlink = 1ULL << 24;

/* The right to invoke `path_remove_directory` */
static const WasiRights wasiRightsPathRemoveDirectory = 1ULL << 25;

/* The right to invoke `path_unlink_file` */
static const WasiRights wasiRightsPathUnlinkFile = 1ULL << 26;

/*
 * If rights fd_read is set, includes the right to invoke `poll_oneoff` to
 * subscribe to event type fd_read. If rights fd_write is set, includes
 * the right to invoke `poll_oneoff` to subscribe to eventtype fd_write.
 */
static const WasiRights wasiRightsPollFdReadwrite = 1ULL << 27;

/* The right to invoke `sock_shutdown` */
static const WasiRights wasiRightsSockShutdown = 1ULL << 28;

/* The right to invoke `sock_open` */
static const WasiRights wasiRightsSockOpen = 1ULL << 29;

/* The right to invoke `sock_close` */
static const WasiRights wasiRightsSockClose = 1ULL << 30;

/* The right to invoke `sock_bind` */
static const WasiRights wasiRightsSockBind = 1ULL << 31;

/* The right to invoke `sock_recv` */
static const WasiRights wasiRightsSockRecv = 1ULL << 32;

/* The right to invoke `sock_recv_from` */
static const WasiRights wasiRightsSockRecvFrom = 1ULL << 33;

/* The right to invoke `sock_send` */
static const WasiRights wasiRightsSockSend = 1ULL << 34;

/* The right to invoke `sock_send_to` */
static const WasiRights wasiRightsSockSendTo = 1ULL << 35;

typedef enum WasiErrno {
    /* No error occurred. System call completed successfully */
    wasiErrnoSuccess = 0,

    /* Argument list too long */
    wasiErrno2big = 1,

    /* Permission denied */
    wasiErrnoAcces = 2,

    /* Address in use */
    wasiErrnoAddrinuse = 3,

    /* Address not available */
    wasiErrnoAddrnotavail = 4,

    /* Address family not supported */
    wasiErrnoAfnosupport = 5,

    /* Resource unavailable, or operation would block */
    wasiErrnoAgain = 6,

    /* Connection already in progress */
    wasiErrnoAlready = 7,

    /* Bad file descriptor */
    wasiErrnoBadf = 8,

    /* Bad message */
    wasiErrnoBadmsg = 9,

    /* Device or resource busy */
    wasiErrnoBusy = 10,

    /* Operation canceled */
    wasiErrnoCanceled = 11,

    /* No child processes */
    wasiErrnoChild = 12,

    /* Connection aborted */
    wasiErrnoConnaborted = 13,

    /* Connection refused */
    wasiErrnoConnrefused = 14,

    /* Connection reset */
    wasiErrnoConnreset = 15,

    /* Resource deadlock would occur */
    wasiErrnoDeadlk = 16,

    /* Destination address required */
    wasiErrnoDestaddrreq = 17,

    /* Mathematics argument out of domain of function */
    wasiErrnoDom = 18,

    /* Reserved */
    wasiErrnoDquot = 19,

    /* File exists */
    wasiErrnoExist = 20,

    /* Bad address */
    wasiErrnoFault = 21,

    /* File too large */
    wasiErrnoFbig = 22,

    /* Host is unreachable */
    wasiErrnoHostunreach = 23,

    /* Identifier removed */
    wasiErrnoIdrm = 24,

    /* Illegal byte sequence */
    wasiErrnoIlseq = 25,

    /* Operation in progress */
    wasiErrnoInprogress = 26,

    /* Interrupted function */
    wasiErrnoIntr = 27,

    /* Invalid argument */
    wasiErrnoInval = 28,

    /* I/O error */
    wasiErrnoIo = 29,

    /* Socket is connected */
    wasiErrnoIsconn = 30,

    /* Is a directory */
    wasiErrnoIsdir = 31,

    /* Too many levels of symbolic links */
    wasiErrnoLoop = 32,

    /* File descriptor value too large */
    wasiErrnoMfile = 33,

    /* Too many links */
    wasiErrnoMlink = 34,

    /* Message too large */
    wasiErrnoMsgsize = 35,

    /* Reserved */
    wasiErrnoMultihop = 36,

    /* Filename too long */
    wasiErrnoNametoolong = 37,

    /* Network is down */
    wasiErrnoNetdown = 38,

    /* Connection aborted by network */
    wasiErrnoNetreset = 39,

    /* Network unreachable */
    wasiErrnoNetunreach = 40,

    /* Too many files open in system */
    wasiErrnoNfile = 41,

    /* No buffer space available */
    wasiErrnoNobufs = 42,

    /* No such device */
    wasiErrnoNodev = 43,

    /* No such file or directory */
    wasiErrnoNoent = 44,

    /* Executable file format error */
    wasiErrnoNoexec = 45,

    /* No locks available */
    wasiErrnoNolck = 46,

    /* Reserved */
    wasiErrnoNolink = 47,

    /* Not enough space */
    wasiErrnoNomem = 48,

    /* No message of the desired type */
    wasiErrnoNomsg = 49,

    /* Protocol not available */
    wasiErrnoNoprotoopt = 50,

    /* No space left on device */
    wasiErrnoNospc = 51,

    /* Function not supported */
    wasiErrnoNosys = 52,

    /* The socket is not connected */
    wasiErrnoNotconn = 53,

    /* Not a directory or a symbolic link to a directory */
    wasiErrnoNotdir = 54,

    /* Directory not empty */
    wasiErrnoNotempty = 55,

    /* State not recoverable */
    wasiErrnoNotrecoverable = 56,

    /* Not a socket */
    wasiErrnoNotsock = 57,

    /* Not supported, or operation not supported on socket */
    wasiErrnoNotsup = 58,

    /* Inappropriate I/O control operation */
    wasiErrnoNotty = 59,

    /* No such device or address */
    wasiErrnoNxio = 60,

    /* Value too large to be stored in data type */
    wasiErrnoOverflow = 61,

    /* Previous owner died */
    wasiErrnoOwnerdead = 62,

    /* Operation not permitted */
    wasiErrnoPerm = 63,

    /* Broken pipe */
    wasiErrnoPipe = 64,

    /* Protocol error */
    wasiErrnoProto = 65,

    /* Protocol not supported */
    wasiErrnoProtonosupport = 66,

    /* Protocol wrong type for socket */
    wasiErrnoPrototype = 67,

    /* Result too large */
    wasiErrnoRange = 68,

    /* Read-only file system */
    wasiErrnoRofs = 69,

    /* Invalid seek */
    wasiErrnoSpipe = 70,

    /* No such process */
    wasiErrnoSrch = 71,

    /* Reserved */
    wasiErrnoStale = 72,

    /* Connection timed out */
    wasiErrnoTimedout = 73,

    /* Text file busy */
    wasiErrnoTxtbsy = 74,

    /* Cross-device link */
    wasiErrnoXdev = 75,

    /* Extension: Capabilities insufficient */
    wasiErrnoNotcapable = 76
} WasiErrno;

typedef enum WasiClock {
    /* The clock measuring real time. Time value zero corresponds with 1970-01-01T00:00:00Z */
    wasiClockRealtime = 0,

    /*
     * The store-wide monotonic clock, which is defined as a clock measuring real time,
     * whose value cannot be adjusted and which cannot have negative clock jumps.
     * The epoch of this clock is undefined.
     * The absolute time value of this clock therefore has no meaning
     */
    wasiClockMonotonic = 1,

    /* The CPU-time clock associated with the current process */
    wasiClockProcessCputimeId = 2,

    /* The CPU-time clock associated with the current thread */
    wasiClockThreadCputimeId = 3
} WasiClock;

#endif /* W2C2_WASI_H */
