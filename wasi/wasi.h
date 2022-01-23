#ifndef W2C2_WASI_H
#define W2C2_WASI_H

#include "../w2c2_base.h"
#include <dirent.h>

typedef struct WasiFileDescriptor {
    int fd;
    DIR* dir;
} WasiFileDescriptor;

typedef struct WasiFileDescriptors {
    WasiFileDescriptor* fds;
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
    int* nativeFD,
    DIR** nativeDir
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


/* Identifiers for preopened capabilities */
typedef U8 WasiPreopentype;

/* A pre-opened directory */
static const WasiPreopentype wasiPreopentypeDirectory = 0;


/* The type of a file descriptor or file */
typedef U8 WasiFileType;

/*  The type of the file descriptor or file is unknown or is different from any of the other types specified */
static const WasiFileType wasiFileTypeUnknown = 0;

/* The file descriptor or file refers to a block device inode */
static const WasiFileType wasiFileTypeBlockDevice = 1;

/* The file descriptor or file refers to a character device inode. */
static const WasiFileType wasiFileTypeCharacterDevice = 2;

/* The file descriptor or file refers to a directory inode */
static const WasiFileType wasiFileTypeDirectory = 3;

/* The file descriptor or file refers to a regular file inode */
static const WasiFileType wasiFileTypeRegularFile = 4;

/* The file refers to a symbolic link inode */
static const WasiFileType wasiFileTypeSymbolicLink = 7;


/* File descriptor flags */
typedef U16 WasiFdflags;

/* Append mode: Data written to the file is always appended to the file's end */
static const WasiFdflags wasiFdflagsAppend = 1ULL << 0;

/*
 * Write according to synchronized I/O data integrity completion.
 * Only the data stored in the file is synchronized
 */
static const WasiFdflags wasiFdflagsDsync = 1ULL << 1;

/* Non-blocking mode */
static const WasiFdflags wasiFdflagsNonblock = 1ULL << 2;

/* Synchronized read I/O operations */
static const WasiFdflags wasiFdflagsRsync = 1ULL << 3;

/*
 * Write according to synchronized I/O file integrity completion.
 * In addition to synchronizing the data stored in the file,
 * the implementation may also synchronously update the file's metadata
 */
static const WasiFdflags wasiFdflagsSync = 1ULL << 4;


/* Open flags used by path_open */
typedef U16 WasiOflags;

/* Create file if it does not exist */
static const WasiOflags wasiOflagsCreat = 1ULL << 0;

/* Fail if not a directory */
static const WasiOflags wasiOflagsDirectory = 1ULL << 1;

/* Fail if file already exists */
static const WasiOflags wasiOflagsExcl = 1ULL << 2;

/* Truncate file to size 0 */
static const WasiOflags wasiOflagsTrunc = 1ULL << 3;


typedef U32 WasiLookupFlag;

/* As long as the resolved path corresponds to a symbolic link, it is expanded */
static const WasiLookupFlag wasiLookupFlagSymlinkFollow = 1ULL << 0;


/* File descriptor rights, determining which actions may be performed */
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


/* Error codes returned by functions.
 * Not all of these error codes are returned by the functions provided by this API;
 * some are used in higher-level library layers,
 * and others are provided merely for alignment with POSIX.
 */
typedef U32 WasiErrno;

/* No error occurred. System call completed successfully */
static const WasiErrno wasiErrnoSuccess = 0;

/* Argument list too long */
static const WasiErrno wasiErrno2big = 1;

/* Permission denied */
static const WasiErrno wasiErrnoAcces = 2;

/* Address in use */
static const WasiErrno wasiErrnoAddrinuse = 3;

/* Address not available */
static const WasiErrno wasiErrnoAddrnotavail = 4;

/* Address family not supported */
static const WasiErrno wasiErrnoAfnosupport = 5;

/* Resource unavailable, or operation would block */
static const WasiErrno wasiErrnoAgain = 6;

/* Connection already in progress */
static const WasiErrno wasiErrnoAlready = 7;

/* Bad file descriptor */
static const WasiErrno wasiErrnoBadf = 8;

/* Bad message */
static const WasiErrno wasiErrnoBadmsg = 9;

/* Device or resource busy */
static const WasiErrno wasiErrnoBusy = 10;

/* Operation canceled */
static const WasiErrno wasiErrnoCanceled = 11;

/* No child processes */
static const WasiErrno wasiErrnoChild = 12;

/* Connection aborted */
static const WasiErrno wasiErrnoConnaborted = 13;

/* Connection refused */
static const WasiErrno wasiErrnoConnrefused = 14;

/* Connection reset */
static const WasiErrno wasiErrnoConnreset = 15;

/* Resource deadlock would occur */
static const WasiErrno wasiErrnoDeadlk = 16;

/* Destination address required */
static const WasiErrno wasiErrnoDestaddrreq = 17;

/* Mathematics argument out of domain of function */
static const WasiErrno wasiErrnoDom = 18;

/* Reserved */
static const WasiErrno wasiErrnoDquot = 19;

/* File exists */
static const WasiErrno wasiErrnoExist = 20;

/* Bad address */
static const WasiErrno wasiErrnoFault = 21;

/* File too large */
static const WasiErrno wasiErrnoFbig = 22;

/* Host is unreachable */
static const WasiErrno wasiErrnoHostunreach = 23;

/* Identifier removed */
static const WasiErrno wasiErrnoIdrm = 24;

/* Illegal byte sequence */
static const WasiErrno wasiErrnoIlseq = 25;

/* Operation in progress */
static const WasiErrno wasiErrnoInprogress = 26;

/* Interrupted function */
static const WasiErrno wasiErrnoIntr = 27;

/* Invalid argument */
static const WasiErrno wasiErrnoInval = 28;

/* I/O error */
static const WasiErrno wasiErrnoIo = 29;

/* Socket is connected */
static const WasiErrno wasiErrnoIsconn = 30;

/* Is a directory */
static const WasiErrno wasiErrnoIsdir = 31;

/* Too many levels of symbolic links */
static const WasiErrno wasiErrnoLoop = 32;

/* File descriptor value too large */
static const WasiErrno wasiErrnoMfile = 33;

/* Too many links */
static const WasiErrno wasiErrnoMlink = 34;

/* Message too large */
static const WasiErrno wasiErrnoMsgsize = 35;

/* Reserved */
static const WasiErrno wasiErrnoMultihop = 36;

/* Filename too long */
static const WasiErrno wasiErrnoNametoolong = 37;

/* Network is down */
static const WasiErrno wasiErrnoNetdown = 38;

/* Connection aborted by network */
static const WasiErrno wasiErrnoNetreset = 39;

/* Network unreachable */
static const WasiErrno wasiErrnoNetunreach = 40;

/* Too many files open in system */
static const WasiErrno wasiErrnoNfile = 41;

/* No buffer space available */
static const WasiErrno wasiErrnoNobufs = 42;

/* No such device */
static const WasiErrno wasiErrnoNodev = 43;

/* No such file or directory */
static const WasiErrno wasiErrnoNoent = 44;

/* Executable file format error */
static const WasiErrno wasiErrnoNoexec = 45;

/* No locks available */
static const WasiErrno wasiErrnoNolck = 46;

/* Reserved */
static const WasiErrno wasiErrnoNolink = 47;

/* Not enough space */
static const WasiErrno wasiErrnoNomem = 48;

/* No message of the desired type */
static const WasiErrno wasiErrnoNomsg = 49;

/* Protocol not available */
static const WasiErrno wasiErrnoNoprotoopt = 50;

/* No space left on device */
static const WasiErrno wasiErrnoNospc = 51;

/* Function not supported */
static const WasiErrno wasiErrnoNosys = 52;

/* The socket is not connected */
static const WasiErrno wasiErrnoNotconn = 53;

/* Not a directory or a symbolic link to a directory */
static const WasiErrno wasiErrnoNotdir = 54;

/* Directory not empty */
static const WasiErrno wasiErrnoNotempty = 55;

/* State not recoverable */
static const WasiErrno wasiErrnoNotrecoverable = 56;

/* Not a socket */
static const WasiErrno wasiErrnoNotsock = 57;

/* Not supported, or operation not supported on socket */
static const WasiErrno wasiErrnoNotsup = 58;

/* Inappropriate I/O control operation */
static const WasiErrno wasiErrnoNotty = 59;

/* No such device or address */
static const WasiErrno wasiErrnoNxio = 60;

/* Value too large to be stored in data type */
static const WasiErrno wasiErrnoOverflow = 61;

/* Previous owner died */
static const WasiErrno wasiErrnoOwnerdead = 62;

/* Operation not permitted */
static const WasiErrno wasiErrnoPerm = 63;

/* Broken pipe */
static const WasiErrno wasiErrnoPipe = 64;

/* Protocol error */
static const WasiErrno wasiErrnoProto = 65;

/* Protocol not supported */
static const WasiErrno wasiErrnoProtonosupport = 66;

/* Protocol wrong type for socket */
static const WasiErrno wasiErrnoPrototype = 67;

/* Result too large */
static const WasiErrno wasiErrnoRange = 68;

/* Read-only file system */
static const WasiErrno wasiErrnoRofs = 69;

/* Invalid seek */
static const WasiErrno wasiErrnoSpipe = 70;

/* No such process */
static const WasiErrno wasiErrnoSrch = 71;

/* Reserved */
static const WasiErrno wasiErrnoStale = 72;

/* Connection timed out */
static const WasiErrno wasiErrnoTimedout = 73;

/* Text file busy */
static const WasiErrno wasiErrnoTxtbsy = 74;

/* Cross-device link */
static const WasiErrno wasiErrnoXdev = 75;

/* Extension: Capabilities insufficient */
static const WasiErrno wasiErrnoNotcapable = 76;


/* Identifiers for clocks */
typedef U32 WasiClock;

/* The clock measuring real time. Time value zero corresponds with 1970-01-01T00:00:00Z */
static const WasiClock wasiClockRealtime = 0;
#define WASI_CLOCK_REALTIME 0

/*
 * The store-wide monotonic clock, which is defined as a clock measuring real time,
 * whose value cannot be adjusted and which cannot have negative clock jumps.
 * The epoch of this clock is undefined.
 * The absolute time value of this clock therefore has no meaning
 */
static const WasiClock wasiClockMonotonic = 1;
#define WASI_CLOCK_MONOTONIC 1

/* The CPU-time clock associated with the current process */
static const WasiClock wasiClockProcessCputimeId = 2;
#define WASI_CLOCK_PROCESS_CPUTIME_ID 2

/* The CPU-time clock associated with the current thread */
static const WasiClock wasiClockThreadCputimeId = 3;
#define WASI_CLOCK_THREAD_CPUTIME_ID 3


#endif /* W2C2_WASI_H */
