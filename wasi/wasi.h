#ifndef W2C2_WASI_H
#define W2C2_WASI_H

#include "../w2c2/w2c2_base.h"

#ifdef __MSL__
#include <stat.h>
typedef long ssize_t;
#else
#include <sys/types.h>
#endif

#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

#ifdef _WIN32
#include "win32.h"
#elif defined(_NEXT_SOURCE)
#include <sys/dir.h>
#else
#include <dirent.h>
#endif

typedef struct WasiFileDescriptor {
    int fd;
    DIR* dir;
    char* path;
} WasiFileDescriptor;

static const WasiFileDescriptor emptyWasiFileDescriptor = {-1, NULL, NULL};

typedef struct WasiFileDescriptors {
    WasiFileDescriptor* fds;
    size_t length;
    size_t capacity;
} WasiFileDescriptors;

typedef struct WASI {
    int envc;
    char** envp;
    int argc;
    char** argv;
    WasiFileDescriptors fds;
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
    char* path,
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
    WasiFileDescriptor* result
);

bool
WARN_UNUSED_RESULT
wasiFileDescriptorClose(
    U32 wasiFD
);

typedef U8 WasiPreopenType;

/* A pre-opened directory */
#define WASI_PREOPEN_TYPE_DIRECTORY 0

/* The type of a file descriptor or file */
typedef U8 WasiFileType;

/* The type of the file descriptor or file is unknown or is different from any of the other types specified */
#define WASI_FILE_TYPE_UNKNOWN 0

/* The file descriptor or file refers to a block device inode */
#define WASI_FILE_TYPE_BLOCK_DEVICE 1

/* The file descriptor or file refers to a character device inode. */
#define WASI_FILE_TYPE_CHARACTER_DEVICE 2

/* The file descriptor or file refers to a directory inode */
#define WASI_FILE_TYPE_DIRECTORY 3

/* The file descriptor or file refers to a regular file inode */
#define WASI_FILE_TYPE_REGULAR_FILE 4

/* The file refers to a symbolic link inode */
#define WASI_FILE_TYPE_SYMBOLIC_LINK 7

/* File descriptor flags */
typedef U16 WasiFdflags;

/* Append mode: Data written to the file is always appended to the file's end */
#define WASI_FDFLAGS_APPEND (1 << 0)

/*
 * Write according to synchronized I/O data integrity completion.
 * Only the data stored in the file is synchronized
 */
#define WASI_FDFLAGS_DSYNC (1 << 1)

/* Non-blocking mode */
#define WASI_FDFLAGS_NONBLOCK (1 << 2)

/* Synchronized read I/O operations */
#define WASI_FDFLAGS_RSYNC (1 << 3)

/*
 * Write according to synchronized I/O file integrity completion.
 * In addition to synchronizing the data stored in the file,
 * the implementation may also synchronously update the file's metadata
 */
#define WASI_FDFLAGS_SYNC (1 << 4)

/* Open flags used by path_open */
typedef U16 WasiOflags;

/* Create file if it does not exist */
#define WASI_OFLAGS_CREAT (1 << 0)

/* Fail if not a directory */
#define WASI_OFLAGS_DIRECTORY (1 << 1)

/* Fail if file already exists */
#define WASI_OFLAGS_EXCL (1 << 2)

/* Truncate file to size 0 */
#define WASI_OFLAGS_TRUNC (1 << 3)

typedef U32 WasiLookupFlags;

/* As long as the resolved path corresponds to a symbolic link, it is expanded */
#define WASI_LOOKUP_FLAGS_SYMLINK_FOLLOW (1 << 0)

/* File descriptor rights, determining which actions may be performed */
typedef U64 WasiRights;

/*
 * The right to invoke `fd_datasync`.
 * If `path_open` is set, includes the right to invoke
 * `path_open` with fdflags dsync
 */
#define WASI_RIGHTS_FD_DATASYNC (1 << 0)

/*
 * The right to invoke `fd_read` and `sock_recv`.
 * If rights fd_seek is set, includes the right to invoke `fd_pread`.
 */
#define WASI_RIGHTS_FD_READ (1 << 1)

/* The right to invoke `fd_seek`. This flag implies rights fd_tell */
#define WASI_RIGHTS_FD_SEEK (1 << 2)

/* The right to invoke `fd_fdstat_set_flags` */
#define WASI_RIGHTS_FD_FDSTAT_SET_FLAGS (1 << 3)

/*
 * The right to invoke `fd_sync`.
 * If `path_open` is set, includes the right to invoke
 * `path_open` with fdflags rsync and fdflags dsync.
 */
#define WASI_RIGHTS_FD_SYNC (1 << 4)

/*
 * The right to invoke `fd_seek` in such a way that the file offset
 * remains unaltered (i.e., whence cur with offset zero), or to
 * invoke `fd_tell`.
 */
#define WASI_RIGHTS_FD_TELL (1 << 5)

/*
 * The right to invoke `fd_write` and `sock_send`.
 * If right `FdSeek` is set, includes the right to invoke `fd_pwrite`.
 */
#define WASI_RIGHTS_FD_WRITE (1 << 6)

/* The right to invoke `fd_advise` */
#define WASI_RIGHTS_FD_ADVISE (1 << 7)

/* The right to invoke `fd_allocate` */
#define WASI_RIGHTS_FD_ALLOCATE (1 << 8)

/* The right to invoke `path_create_directory` */
#define WASI_RIGHTS_PATH_CREATE_DIRECTORY (1 << 9)

/* If `path_open` is set, the right to invoke `path_open` with oflags creat */
#define WASI_RIGHTS_PATH_CREATE_FILE (1 << 10)

/*
 * The right to invoke `path_link` with the file descriptor as the
 * source directory.
 */
#define WASI_RIGHTS_PATH_LINK_SOURCE (1 << 11)

/*
 * The right to invoke `path_link` with the file descriptor as the
 * target directory.
 */
#define WASI_RIGHTS_PATH_LINK_TARGET (1 << 12)

/* The right to invoke `path_open` */
#define WASI_RIGHTS_PATH_OPEN (1 << 13)

/* The right to invoke `fd_readdir` */
#define WASI_RIGHTS_FD_READDIR (1 << 14)

/* The right to invoke `path_readlink` */
#define WASI_RIGHTS_PATH_READLINK (1 << 15)

/*
 * The right to invoke `path_rename` with the file descriptor as the source
 * directory.
 */
#define WASI_RIGHTS_PATH_RENAME_SOURCE (1 << 16)

/*
 * The right to invoke `path_rename` with the file descriptor as the target
 * directory.
 */
#define WASI_RIGHTS_PATH_RENAME_TARGET (1 << 17)

/* The right to invoke `path_filestat_get` */
#define WASI_RIGHTS_PATH_FILESTAT_GET (1 << 18)

/*
 * The right to change a file's size (there is no `path_filestat_set_size`).
 * If `path_open` is set, includes the right to invoke `path_open` with
 * oflags trunc.
 */
#define WASI_RIGHTS_PATH_FILESTAT_SET_SIZE (1 << 19)

/* The right to invoke `path_filestat_set_times` */
#define WASI_RIGHTS_PATH_FILESTAT_SET_TIMES (1 << 20)

/* The right to invoke `fd_filestat_get` */
#define WASI_RIGHTS_FD_FILESTAT_GET (1 << 21)

/* The right to invoke `fd_filestat_set_size` */
#define WASI_RIGHTS_FD_FILESTAT_SET_SIZE (1 << 22)

/* The right to invoke `fd_filestat_set_times` */
#define WASI_RIGHTS_FD_FILESTAT_SET_TIMES (1 << 23)

/* The right to invoke `path_symlink` */
#define WASI_RIGHTS_PATH_SYMLINK (1 << 24)

/* The right to invoke `path_remove_directory` */
#define WASI_RIGHTS_PATH_REMOVE_DIRECTORY (1 << 25)

/* The right to invoke `path_unlink_file` */
#define WASI_RIGHTS_PATH_UNLINK_FILE (1 << 26)

/*
 * If rights fd_read is set, includes the right to invoke `poll_oneoff` to
 * subscribe to event type fd_read. If rights fd_write is set, includes
 * the right to invoke `poll_oneoff` to subscribe to eventtype fd_write.
 */
#define WASI_RIGHTS_POLL_FD_READWRITE (1 << 27)


#define WASI_RIGHTS_ALL (                  \
    WASI_RIGHTS_FD_DATASYNC                \
    | WASI_RIGHTS_FD_READ                  \
    | WASI_RIGHTS_FD_SEEK                  \
    | WASI_RIGHTS_FD_FDSTAT_SET_FLAGS      \
    | WASI_RIGHTS_FD_SYNC                  \
    | WASI_RIGHTS_FD_TELL                  \
    | WASI_RIGHTS_FD_WRITE                 \
    | WASI_RIGHTS_FD_ADVISE                \
    | WASI_RIGHTS_FD_ALLOCATE              \
    | WASI_RIGHTS_PATH_CREATE_DIRECTORY    \
    | WASI_RIGHTS_PATH_CREATE_FILE         \
    | WASI_RIGHTS_PATH_LINK_SOURCE         \
    | WASI_RIGHTS_PATH_LINK_TARGET         \
    | WASI_RIGHTS_PATH_OPEN                \
    | WASI_RIGHTS_FD_READDIR               \
    | WASI_RIGHTS_PATH_READLINK            \
    | WASI_RIGHTS_PATH_RENAME_SOURCE       \
    | WASI_RIGHTS_PATH_RENAME_TARGET       \
    | WASI_RIGHTS_PATH_FILESTAT_GET        \
    | WASI_RIGHTS_PATH_FILESTAT_SET_SIZE   \
    | WASI_RIGHTS_PATH_FILESTAT_SET_TIMES  \
    | WASI_RIGHTS_FD_FILESTAT_GET          \
    | WASI_RIGHTS_FD_FILESTAT_SET_SIZE     \
    | WASI_RIGHTS_FD_FILESTAT_SET_TIMES    \
    | WASI_RIGHTS_PATH_SYMLINK             \
    | WASI_RIGHTS_PATH_REMOVE_DIRECTORY    \
    | WASI_RIGHTS_PATH_UNLINK_FILE         \
    | WASI_RIGHTS_POLL_FD_READWRITE        \
)

#define WASI_RIGHTS_REGULAR_FILE_BASE (  \
    WASI_RIGHTS_FD_DATASYNC              \
    | WASI_RIGHTS_FD_READ                \
    | WASI_RIGHTS_FD_SEEK                \
    | WASI_RIGHTS_FD_FDSTAT_SET_FLAGS    \
    | WASI_RIGHTS_FD_SYNC                \
    | WASI_RIGHTS_FD_TELL                \
    | WASI_RIGHTS_FD_WRITE               \
    | WASI_RIGHTS_FD_ADVISE              \
    | WASI_RIGHTS_FD_ALLOCATE            \
    | WASI_RIGHTS_FD_FILESTAT_GET        \
    | WASI_RIGHTS_FD_FILESTAT_SET_SIZE   \
    | WASI_RIGHTS_FD_FILESTAT_SET_TIMES  \
    | WASI_RIGHTS_POLL_FD_READWRITE      \
)

#define WASI_RIGHTS_REGULAR_FILE_INHERITING 0

#define WASI_RIGHTS_DIRECTORY_BASE (       \
    WASI_RIGHTS_FD_FDSTAT_SET_FLAGS        \
    | WASI_RIGHTS_FD_SYNC                  \
    | WASI_RIGHTS_FD_ADVISE                \
    | WASI_RIGHTS_PATH_CREATE_DIRECTORY    \
    | WASI_RIGHTS_PATH_CREATE_FILE         \
    | WASI_RIGHTS_PATH_LINK_SOURCE         \
    | WASI_RIGHTS_PATH_LINK_TARGET         \
    | WASI_RIGHTS_PATH_OPEN                \
    | WASI_RIGHTS_FD_READDIR               \
    | WASI_RIGHTS_PATH_READLINK            \
    | WASI_RIGHTS_PATH_RENAME_SOURCE       \
    | WASI_RIGHTS_PATH_RENAME_TARGET       \
    | WASI_RIGHTS_PATH_FILESTAT_GET        \
    | WASI_RIGHTS_PATH_FILESTAT_SET_SIZE   \
    | WASI_RIGHTS_PATH_FILESTAT_SET_TIMES  \
    | WASI_RIGHTS_FD_FILESTAT_GET          \
    | WASI_RIGHTS_FD_FILESTAT_SET_TIMES    \
    | WASI_RIGHTS_PATH_SYMLINK             \
    | WASI_RIGHTS_PATH_UNLINK_FILE         \
    | WASI_RIGHTS_PATH_REMOVE_DIRECTORY    \
    | WASI_RIGHTS_POLL_FD_READWRITE        \
)

#define WASI_RIGHTS_DIRECTORY_INHERITING (  \
    WASI_RIGHTS_DIRECTORY_BASE              \
    | WASI_RIGHTS_REGULAR_FILE_BASE         \
)

#define WASI_RIGHTS_TTY_BASE (         \
    WASI_RIGHTS_FD_READ                \
    | WASI_RIGHTS_FD_FDSTAT_SET_FLAGS  \
    | WASI_RIGHTS_FD_WRITE             \
    | WASI_RIGHTS_FD_FILESTAT_GET      \
    | WASI_RIGHTS_POLL_FD_READWRITE    \
)

#define WASI_RIGHTS_TTY_INHERITING 0

/* Error codes returned by functions.
 * Not all of these error codes are returned by the functions provided by this API;
 * some are used in higher-level library layers,
 * and others are provided merely for alignment with POSIX.
 */
typedef U16 WasiErrno;

/* No error occurred. System call completed successfully */
#define WASI_ERRNO_SUCCESS 0

/* Argument list too long */
#define WASI_ERRNO_2_BIG 1

/* Permission denied */
#define WASI_ERRNO_ACCES 2

/* Address in use */
#define WASI_ERRNO_ADDRINUSE 3

/* Address not available */
#define WASI_ERRNO_ADDRNOTAVAIL 4

/* Address family not supported */
#define WASI_ERRNO_AFNOSUPPORT 5

/* Resource unavailable, or operation would block */
#define WASI_ERRNO_AGAIN 6

/* Connection already in progress */
#define WASI_ERRNO_ALREADY 7

/* Bad file descriptor */
#define WASI_ERRNO_BADF 8

/* Bad message */
#define WASI_ERRNO_BADMSG 9

/* Device or resource busy */
#define WASI_ERRNO_BUSY 10

/* Operation canceled */
#define WASI_ERRNO_CANCELED 11

/* No child processes */
#define WASI_ERRNO_CHILD 12

/* Connection aborted */
#define WASI_ERRNO_CONNABORTED 13

/* Connection refused */
#define WASI_ERRNO_CONNREFUSED 14

/* Connection reset */
#define WASI_ERRNO_CONNRESET 15

/* Resource deadlock would occur */
#define WASI_ERRNO_DEADLK 16

/* Destination address required */
#define WASI_ERRNO_DESTADDRREQ 17

/* Mathematics argument out of domain of function */
#define WASI_ERRNO_DOM 18

/* Reserved */
#define WASI_ERRNO_DQUOT 19

/* File exists */
#define WASI_ERRNO_EXIST 20

/* Bad address */
#define WASI_ERRNO_FAULT 21

/* File too large */
#define WASI_ERRNO_FBIG 22

/* Host is unreachable */
#define WASI_ERRNO_HOSTUNREACH 23

/* Identifier removed */
#define WASI_ERRNO_IDRM 24

/* Illegal byte sequence */
#define WASI_ERRNO_ILSEQ 25

/* Operation in progress */
#define WASI_ERRNO_INPROGRESS 26

/* Interrupted function */
#define WASI_ERRNO_INTR 27

/* Invalid argument */
#define WASI_ERRNO_INVAL 28

/* I/O error */
#define WASI_ERRNO_IO 29

/* Socket is connected */
#define WASI_ERRNO_ISCONN 30

/* Is a directory */
#define WASI_ERRNO_ISDIR 31

/* Too many levels of symbolic links */
#define WASI_ERRNO_LOOP 32

/* File descriptor value too large */
#define WASI_ERRNO_MFILE 33

/* Too many links */
#define WASI_ERRNO_MLINK 34

/* Message too large */
#define WASI_ERRNO_MSGSIZE 35

/* Reserved */
#define WASI_ERRNO_MULTIHOP 36

/* Filename too long */
#define WASI_ERRNO_NAMETOOLONG 37

/* Network is down */
#define WASI_ERRNO_NETDOWN 38

/* Connection aborted by network */
#define WASI_ERRNO_NETRESET 39

/* Network unreachable */
#define WASI_ERRNO_NETUNREACH 40

/* Too many files open in system */
#define WASI_ERRNO_NFILE 41

/* No buffer space available */
#define WASI_ERRNO_NOBUFS 42

/* No such device */
#define WASI_ERRNO_NODEV 43

/* No such file or directory */
#define WASI_ERRNO_NOENT 44

/* Executable file format error */
#define WASI_ERRNO_NOEXEC 45

/* No locks available */
#define WASI_ERRNO_NOLCK 46

/* Reserved */
#define WASI_ERRNO_NOLINK 47

/* Not enough space */
#define WASI_ERRNO_NOMEM 48

/* No message of the desired type */
#define WASI_ERRNO_NOMSG 49

/* Protocol not available */
#define WASI_ERRNO_NOPROTOOPT 50

/* No space left on device */
#define WASI_ERRNO_NOSPC 51

/* Function not supported */
#define WASI_ERRNO_NOSYS 52

/* The socket is not connected */
#define WASI_ERRNO_NOTCONN 53

/* Not a directory or a symbolic link to a directory */
#define WASI_ERRNO_NOTDIR 54

/* Directory not empty */
#define WASI_ERRNO_NOTEMPTY 55

/* State not recoverable */
#define WASI_ERRNO_NOTRECOVERABLE 56

/* Not a socket */
#define WASI_ERRNO_NOTSOCK 57

/* Not supported, or operation not supported on socket */
#define WASI_ERRNO_NOTSUP 58

/* Inappropriate I/O control operation */
#define WASI_ERRNO_NOTTY 59

/* No such device or address */
#define WASI_ERRNO_NXIO 60

/* Value too large to be stored in data type */
#define WASI_ERRNO_OVERFLOW 61

/* Previous owner died */
#define WASI_ERRNO_OWNERDEAD 62

/* Operation not permitted */
#define WASI_ERRNO_PERM 63

/* Broken pipe */
#define WASI_ERRNO_PIPE 64

/* Protocol error */
#define WASI_ERRNO_PROTO 65

/* Protocol not supported */
#define WASI_ERRNO_PROTONOSUPPORT 66

/* Protocol wrong type for socket */
#define WASI_ERRNO_PROTOTYPE 67

/* Result too large */
#define WASI_ERRNO_RANGE 68

/* Read-only file system */
#define WASI_ERRNO_ROFS 69

/* Invalid seek */
#define WASI_ERRNO_SPIPE 70

/* No such process */
#define WASI_ERRNO_SRCH 71

/* Reserved */
#define WASI_ERRNO_STALE 72

/* Connection timed out */
#define WASI_ERRNO_TIMEDOUT 73

/* Text file busy */
#define WASI_ERRNO_TXTBSY 74

/* Cross-device link */
#define WASI_ERRNO_XDEV 75

/* Extension: Capabilities insufficient */
#define WASI_ERRNO_NOTCAPABLE 76

typedef U32 WasiClock;

/* The clock measuring real time. Time value zero corresponds with 1970-01-01T00:00:00Z */
#define WASI_CLOCK_REALTIME 0

/*
 * The store-wide monotonic clock, which is defined as a clock measuring real time,
 * whose value cannot be adjusted and which cannot have negative clock jumps.
 * The epoch of this clock is undefined.
 * The absolute time value of this clock therefore has no meaning
 */
#define WASI_CLOCK_MONOTONIC 1

/* The CPU-time clock associated with the current process */
#define WASI_CLOCK_PROCESS_CPUTIME_ID 2

/* The CPU-time clock associated with the current thread */
#define WASI_CLOCK_THREAD_CPUTIME_ID 3

/* Permanent reference to the first directory entry within a directory */
#define WASI_DIRCOOKIE_START 0

void
wasiToNativePath(
    char *path
);

void
wasiFromNativePath(
    char *path
);

#endif /* W2C2_WASI_H */
