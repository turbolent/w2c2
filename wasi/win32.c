#ifdef _WIN32
#include "win32.h"
#include <fcntl.h>
#include <io.h>
#include <limits.h>
#include <sys/stat.h>
#include <winioctl.h>

#ifndef FSCTL_GET_REPARSE_POINT
#define FSCTL_GET_REPARSE_POINT 0x000900a8
#endif

static int
wasiWindowsError(void) {
    wasiSetErrno(GetLastError());
    return -1;
}

static int
wasiWindowsPath(const char* path, char* result) {
    size_t length = strlen(path);
    int trailing = 0;
    if (length >= MAX_PATH) {
        errno = ENAMETOOLONG;
        return -1;
    }
    memcpy(result, path, length + 1);
    while (length > 1 && !(length == 3 && result[1] == ':')
           && (result[length - 1] == '/' || result[length - 1] == '\\')) {
        trailing = 1;
        result[--length] = '\0';
    }
    if (trailing) {
        DWORD attributes = GetFileAttributesA(result);
        if (attributes == INVALID_FILE_ATTRIBUTES) {
            return wasiWindowsError();
        }
        if (!(attributes & FILE_ATTRIBUTE_DIRECTORY)) {
            errno = ENOTDIR;
            return -1;
        }
    }
    return 0;
}

static void
wasiWindowsTime(FILETIME time, I64* seconds, long* nanoseconds) {
    U64 ticks = ((U64)time.dwHighDateTime << 32) | time.dwLowDateTime;
    I64 unixTicks = (I64)ticks - W2C2_LL(116444736000000000);
    *seconds = unixTicks / 10000000;
    *nanoseconds = (long)(unixTicks % 10000000) * 100;
    if (*nanoseconds < 0) {
        (*seconds)--;
        *nanoseconds += 1000000000;
    }
}

static int
wasiWindowsHandleStat(HANDLE handle, struct wasiWindowsStat* st) {
    BY_HANDLE_FILE_INFORMATION info;
    DWORD type = GetFileType(handle);
    memset(st, 0, sizeof(*st));
    if (type == FILE_TYPE_CHAR || type == FILE_TYPE_PIPE) {
        st->st_mode = type == FILE_TYPE_CHAR ? _S_IFCHR : _S_IFIFO;
        st->st_nlink = 1;
        return 0;
    }
    if (!GetFileInformationByHandle(handle, &info)) {
        return wasiWindowsError();
    }
    st->st_dev = info.dwVolumeSerialNumber;
    st->st_ino = ((U64)info.nFileIndexHigh << 32) | info.nFileIndexLow;
    st->st_nlink = info.nNumberOfLinks;
    st->st_size = ((U64)info.nFileSizeHigh << 32) | info.nFileSizeLow;
    st->st_mode = (unsigned short)(info.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT
        ? WASI_WINDOWS_S_IFLNK
        : info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ? _S_IFDIR : _S_IFREG);
    wasiWindowsTime(info.ftLastAccessTime, &st->st_atime, &st->accessNanoseconds);
    wasiWindowsTime(info.ftLastWriteTime, &st->st_mtime, &st->modificationNanoseconds);
    wasiWindowsTime(info.ftCreationTime, &st->st_ctime, &st->creationNanoseconds);
    return 0;
}

static int
wasiWindowsPathStat(const char* path, struct wasiWindowsStat* st, int follow) {
    char nativePath[MAX_PATH];
    HANDLE handle;
    int result;
    if (wasiWindowsPath(path, nativePath) != 0) {
        return -1;
    }
    handle = CreateFileA(
        nativePath, FILE_READ_ATTRIBUTES,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL, OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS | (follow ? 0 : FILE_FLAG_OPEN_REPARSE_POINT),
        NULL
    );
    if (handle == INVALID_HANDLE_VALUE) {
        return wasiWindowsError();
    }
    result = wasiWindowsHandleStat(handle, st);
    CloseHandle(handle);
    return result;
}

int
wasiWindowsStat(const char* path, struct wasiWindowsStat* st) {
    return wasiWindowsPathStat(path, st, 1);
}

int
wasiWindowsLstat(const char* path, struct wasiWindowsStat* st) {
    return wasiWindowsPathStat(path, st, 0);
}

int
wasiWindowsFstat(int fd, struct wasiWindowsStat* st) {
    HANDLE handle = (HANDLE)_get_osfhandle(fd);
    if (handle == INVALID_HANDLE_VALUE) {
        errno = EBADF;
        return -1;
    }
    return wasiWindowsHandleStat(handle, st);
}

int
wasiWindowsOpen(const char* path, int flags, int mode) {
    char nativePath[MAX_PATH];
    DWORD access = flags & _O_RDWR ? GENERIC_READ | GENERIC_WRITE
        : flags & _O_WRONLY ? GENERIC_WRITE : GENERIC_READ;
    DWORD disposition = flags & _O_CREAT
        ? flags & _O_EXCL ? CREATE_NEW : flags & _O_TRUNC ? CREATE_ALWAYS : OPEN_ALWAYS
        : flags & _O_TRUNC ? TRUNCATE_EXISTING : OPEN_EXISTING;
    HANDLE handle;
    int fd;
    UNUSED_PARAMETER(mode);
    if (wasiWindowsPath(path, nativePath) != 0) {
        return -1;
    }
    /* Truncation requires native write access.
     * WASI descriptor rights are enforced separately.
     */
    if (flags & _O_TRUNC) {
        access |= GENERIC_WRITE;
    }
    handle = CreateFileA(
        nativePath, access,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL, disposition, FILE_ATTRIBUTE_NORMAL, NULL
    );
    if (handle == INVALID_HANDLE_VALUE) {
        return wasiWindowsError();
    }
    fd = _open_osfhandle(
        (ptrdiff_t)handle,
        (flags & (_O_RDONLY | _O_WRONLY | _O_RDWR)) | _O_BINARY
    );
    if (fd < 0) {
        CloseHandle(handle);
    }
    return fd;
}

int
wasiWindowsWrite(int fd, const void* bytes, unsigned int length) {
    DWORD written;
    if (length > INT_MAX) {
        length = INT_MAX;
    }
    if (!WriteFile((HANDLE)_get_osfhandle(fd), bytes, length, &written, NULL)) {
        return wasiWindowsError();
    }
    return (int)written;
}

int
wasiWindowsSymlink(const char* target, const char* path) {
    typedef BOOLEAN (WINAPI *CreateSymbolicLinkFunction)(LPCSTR, LPCSTR, DWORD);
    CreateSymbolicLinkFunction createLink = (CreateSymbolicLinkFunction)GetProcAddress(
        GetModuleHandleA("kernel32.dll"), "CreateSymbolicLinkA"
    );
    char targetPath[MAX_PATH];
    const char* separator = strrchr(path, '\\');
    size_t prefix = separator == NULL ? 0 : (size_t)(separator - path + 1);
    size_t length = strlen(target);
    DWORD flags = 0;
    DWORD attributes;
    size_t pathLength = strlen(path);
    if (createLink == NULL) {
        /* TODO: */
        errno = ENOSYS;
        return -1;
    }
    if (pathLength != 0 && (path[pathLength - 1] == '/' || path[pathLength - 1] == '\\')) {
        errno = ENOENT;
        return -1;
    }
    if (GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES) {
        errno = EEXIST;
        return -1;
    }
    if (prefix + length >= sizeof(targetPath)) {
        errno = ENAMETOOLONG;
        return -1;
    }
    memcpy(targetPath, path, prefix);
    memcpy(targetPath + prefix, target, length + 1);
    attributes = GetFileAttributesA(targetPath);
    if (attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY)) {
        flags = 1;
    }
    /* Retry without the unprivileged flag on older Windows versions. */
    if (!createLink(path, target, flags | 2)) {
        if (GetLastError() != ERROR_INVALID_PARAMETER || !createLink(path, target, flags)) {
            return wasiWindowsError();
        }
    }
    return 0;
}

long
wasiWindowsReadlink(const char* path, char* buffer, size_t length) {
    union {
        DWORD alignment;
        unsigned char bytes[16384];
    } data;
    HANDLE handle;
    DWORD used;
    DWORD tag;
    USHORT offset, count;
    int bytes;
    char target[32768];
    size_t i;
    handle = CreateFileA(
        path, 0, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL, OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OPEN_REPARSE_POINT, NULL
    );
    if (handle == INVALID_HANDLE_VALUE) {
        return wasiWindowsError();
    }
    if (!DeviceIoControl(
        handle, FSCTL_GET_REPARSE_POINT, NULL, 0,
        data.bytes, sizeof(data.bytes), &used, NULL
    )) {
        DWORD error = GetLastError();
        CloseHandle(handle);
        wasiSetErrno(error);
        return -1;
    }
    CloseHandle(handle);
    memcpy(&tag, data.bytes, sizeof(tag));
    if (used < 20 || tag != IO_REPARSE_TAG_SYMLINK) {
        errno = EINVAL;
        return -1;
    }
    /* The symlink print name is UTF-16;
     * its offset is relative to the path buffer at byte 20.
     */
    memcpy(&offset, data.bytes + 12, sizeof(offset));
    memcpy(&count, data.bytes + 14, sizeof(count));
    if (20u + offset + count > used || offset % 2 != 0 || count % 2 != 0) {
        errno = EINVAL;
        return -1;
    }
    bytes = WideCharToMultiByte(
        CP_UTF8, 0, (WCHAR*)(data.bytes + 20 + offset), count / 2,
        target, sizeof(target), NULL, NULL
    );
    if (bytes == 0) {
        return wasiWindowsError();
    }
    if ((size_t)bytes < length) {
        length = (size_t)bytes;
    }
    for (i = 0; i < length; i++) {
        buffer[i] = target[i] == '\\' ? '/' : target[i];
    }
    return (long)length;
}

int
wasiWindowsUnlink(const char* path) {
    char nativePath[MAX_PATH];
    DWORD attributes;
    if (wasiWindowsPath(path, nativePath) != 0) {
        return -1;
    }
    attributes = GetFileAttributesA(nativePath);
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        return wasiWindowsError();
    }
    if ((attributes & (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_REPARSE_POINT))
        == (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_REPARSE_POINT)) {
        if (!RemoveDirectoryA(nativePath)) {
            return wasiWindowsError();
        }
    } else if (!DeleteFileA(nativePath)) {
        return wasiWindowsError();
    }
    return 0;
}

int
wasiWindowsRmdir(const char* path) {
    char nativePath[MAX_PATH];
    DWORD attributes;
    if (wasiWindowsPath(path, nativePath) != 0) {
        return -1;
    }
    attributes = GetFileAttributesA(nativePath);
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        return wasiWindowsError();
    }
    if (!(attributes & FILE_ATTRIBUTE_DIRECTORY)
        || (attributes & FILE_ATTRIBUTE_REPARSE_POINT)) {
        errno = ENOTDIR;
        return -1;
    }
    return RemoveDirectoryA(nativePath) ? 0 : wasiWindowsError();
}

int
wasiWindowsRename(const char* source, const char* target) {
    char nativeSource[MAX_PATH];
    char nativeTarget[MAX_PATH];
    DWORD sourceAttributes;
    DWORD targetAttributes;
    if (wasiWindowsPath(source, nativeSource) != 0) {
        return -1;
    }
    if (wasiWindowsPath(target, nativeTarget) != 0) {
        if (errno != ENOENT) {
            return -1;
        }
    }
    sourceAttributes = GetFileAttributesA(nativeSource);
    targetAttributes = GetFileAttributesA(nativeTarget);
    if (sourceAttributes != INVALID_FILE_ATTRIBUTES
        && targetAttributes != INVALID_FILE_ATTRIBUTES
        && (sourceAttributes & FILE_ATTRIBUTE_DIRECTORY)
        && !(targetAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
        errno = ENOTDIR;
        return -1;
    }
    if (!MoveFileExA(nativeSource, nativeTarget, MOVEFILE_REPLACE_EXISTING)) {
        return wasiWindowsError();
    }
    return 0;
}

/*
 * Taken from PostgreSQL.
 * Portions Copyright (c) 1996-2022, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, The Regents of the University of California
 */

static const struct {
    DWORD winerr;
    int doserr;
} doserrors[] = {
    {
        ERROR_INVALID_FUNCTION, EINVAL
    },
    {
        ERROR_FILE_NOT_FOUND, ENOENT
    },
    {
        ERROR_PATH_NOT_FOUND, ENOENT
    },
    {
        ERROR_TOO_MANY_OPEN_FILES, EMFILE
    },
    {
        ERROR_ACCESS_DENIED, EACCES
    },
    {
        ERROR_INVALID_HANDLE, EBADF
    },
    {
        ERROR_ARENA_TRASHED, ENOMEM
    },
    {
        ERROR_NOT_ENOUGH_MEMORY, ENOMEM
    },
    {
        ERROR_INVALID_BLOCK, ENOMEM
    },
    {
        ERROR_BAD_ENVIRONMENT, E2BIG
    },
    {
        ERROR_BAD_FORMAT, ENOEXEC
    },
    {
        ERROR_INVALID_ACCESS, EINVAL
    },
    {
        ERROR_INVALID_DATA, EINVAL
    },
    {
        ERROR_INVALID_DRIVE, ENOENT
    },
    {
        ERROR_CURRENT_DIRECTORY, EACCES
    },
    {
        ERROR_NOT_SAME_DEVICE, EXDEV
    },
    {
        ERROR_NO_MORE_FILES, ENOENT
    },
    {
        ERROR_LOCK_VIOLATION, EACCES
    },
    {
        ERROR_SHARING_VIOLATION, EACCES
    },
    {
        ERROR_BAD_NETPATH, ENOENT
    },
    {
        ERROR_NETWORK_ACCESS_DENIED, EACCES
    },
    {
        ERROR_BAD_NET_NAME, ENOENT
    },
    {
        ERROR_FILE_EXISTS, EEXIST
    },
    {
        ERROR_CANNOT_MAKE, EACCES
    },
    {
        ERROR_FAIL_I24, EACCES
    },
    {
        ERROR_INVALID_PARAMETER, EINVAL
    },
    {
        ERROR_NO_PROC_SLOTS, EAGAIN
    },
    {
        ERROR_DRIVE_LOCKED, EACCES
    },
    {
        ERROR_BROKEN_PIPE, EPIPE
    },
    {
        ERROR_DISK_FULL, ENOSPC
    },
    {
        ERROR_INVALID_TARGET_HANDLE, EBADF
    },
    {
        ERROR_INVALID_HANDLE, EINVAL
    },
    {
        ERROR_WAIT_NO_CHILDREN, ECHILD
    },
    {
        ERROR_CHILD_NOT_COMPLETE, ECHILD
    },
    {
        ERROR_DIRECT_ACCESS_HANDLE, EBADF
    },
    {
        ERROR_NEGATIVE_SEEK, EINVAL
    },
    {
        ERROR_SEEK_ON_DEVICE, EACCES
    },
    {
        ERROR_DIR_NOT_EMPTY, ENOTEMPTY
    },
    {
        ERROR_NOT_LOCKED, EACCES
    },
    {
        ERROR_BAD_PATHNAME, ENOENT
    },
    {
        ERROR_MAX_THRDS_REACHED, EAGAIN
    },
    {
        ERROR_LOCK_FAILED, EACCES
    },
    {
        ERROR_ALREADY_EXISTS, EEXIST
    },
    {
        ERROR_FILENAME_EXCED_RANGE, ENAMETOOLONG
    },
    {
        ERROR_NESTING_NOT_ALLOWED, EAGAIN
    },
    {
        ERROR_NOT_ENOUGH_QUOTA, ENOMEM
    },
    {
        ERROR_DELETE_PENDING, ENOENT
    },
    {
        ERROR_INVALID_NAME, ENOENT
    },
    {
        ERROR_CANT_RESOLVE_FILENAME, ENOENT
    }
};

void
wasiSetErrno(
   unsigned long e
) {
    int i;
    if (e == 0) {
        errno = 0;
        return;
    }

    for (i = 0; i < (sizeof(doserrors) / sizeof(doserrors[0])); i++) {
        if (doserrors[i].winerr == e) {
            errno = doserrors[i].doserr;
            return;
        }
    }

    errno = EINVAL;
}

/*
 * Taken from PostgreSQL.
 * Portions Copyright (c) 1996-2022, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, The Regents of the University of California
 */

DIR *
opendir(
    const char* dirname
) {
    DWORD attr;
    DIR *d;

    /* Make sure it is a directory */
    attr = GetFileAttributes(dirname);
    if (attr == INVALID_FILE_ATTRIBUTES) {
        errno = ENOENT;
        return NULL;
    }
    if ((attr & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY) {
        errno = ENOTDIR;
        return NULL;
    }

    d = malloc(sizeof(DIR));
    if (!d) {
        errno = ENOMEM;
        return NULL;
    }
    d->dirname = malloc(strlen(dirname) + 4);
    if (!d->dirname) {
        errno = ENOMEM;
        free(d);
        return NULL;
    }
    strcpy(d->dirname, dirname);
    if (d->dirname[strlen(d->dirname) - 1] != '/' &&
        d->dirname[strlen(d->dirname) - 1] != '\\') {

        strcat(d->dirname, "\\"); /* Append backslash if not already there */
    }
    strcat(d->dirname, "*"); /* Search for entries named anything */
    d->handle = INVALID_HANDLE_VALUE;
    d->ret.d_ino = 0; /* no inodes on win32 */
    d->ret.d_reclen = 0; /* not used on win32 */
    d->ret.d_type = DT_UNKNOWN;

    return d;
}

/*
 * Taken from PostgreSQL.
 * Portions Copyright (c) 1996-2022, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, The Regents of the University of California
 */

struct dirent*
readdir(
    DIR* d
) {
    WIN32_FIND_DATA fd;

    if (d->handle == INVALID_HANDLE_VALUE) {
        d->handle = FindFirstFile(d->dirname, &fd);

        if (d->handle == INVALID_HANDLE_VALUE) {
            unsigned long e = GetLastError();
            /* If there are no files, force errno=0 (unlike mingw) */
            if (e == ERROR_FILE_NOT_FOUND) {
                errno = 0;
            } else {
                wasiSetErrno(e);
            }
            return NULL;
        }
    } else {
        if (!FindNextFile(d->handle, &fd)) {
            unsigned long e = GetLastError();
            /* If there are no more files, force errno=0 (like mingw) */
            if (e == ERROR_NO_MORE_FILES)
                errno = 0;
            else {
                wasiSetErrno(e);
            }
            return NULL;
        }
    }
    strcpy(d->ret.d_name, fd.cFileName); /* Both strings are MAX_PATH long */
    d->ret.d_namlen = (unsigned short)strlen(d->ret.d_name);

    /*
     * For reparse points dwReserved0 field will contain the ReparseTag.  We
     * check this first, because reparse points are also reported as
     * directories.
     */
    if ((fd.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) != 0 &&
        (fd.dwReserved0 == IO_REPARSE_TAG_MOUNT_POINT ||
         fd.dwReserved0 == IO_REPARSE_TAG_SYMLINK)) {

        d->ret.d_type = DT_LNK;
    } else if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
        d->ret.d_type = DT_DIR;
    } else {
        d->ret.d_type = DT_REG;
    }
    {
        char path[MAX_PATH];
        size_t prefix = strlen(d->dirname) - 1;
        struct wasiWindowsStat st;
        if (prefix + d->ret.d_namlen >= sizeof(path)) {
            errno = ENAMETOOLONG;
            return NULL;
        }
        memcpy(path, d->dirname, prefix);
        strcpy(path + prefix, d->ret.d_name);
        if (wasiWindowsLstat(path, &st) != 0) {
            return NULL;
        }
        d->ret.d_ino = st.st_ino;
    }
    return &d->ret;
}

void
rewinddir(DIR* d) {
    if (d->handle != INVALID_HANDLE_VALUE) {
        FindClose(d->handle);
        d->handle = INVALID_HANDLE_VALUE;
    }
}

/*
 * Taken from PostgreSQL.
 * Portions Copyright (c) 1996-2022, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, The Regents of the University of California
 */

int
closedir(
    DIR* d
) {
    int ret = 0;

    if (d->handle != INVALID_HANDLE_VALUE) {
        ret = !FindClose(d->handle);
    }
    free(d->dirname);
    free(d);

    return ret;
}

#endif /* _WIN32 */
