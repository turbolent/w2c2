#ifdef _WIN32
#include "win32.h"

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

static
void
setErrno(
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
                setErrno(e);
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
                setErrno(e);
            }
            return NULL;
        }
    }
    strcpy(d->ret.d_name, fd.cFileName); /* Both strings are MAX_PATH long */
    d->ret.d_namlen = strlen(d->ret.d_name);

    /*
     * For reparse points dwReserved0 field will contain the ReparseTag.  We
     * check this first, because reparse points are also reported as
     * directories.
     */
    if ((fd.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) != 0 &&
        (fd.dwReserved0 == IO_REPARSE_TAG_MOUNT_POINT)) {

        d->ret.d_type = DT_LNK;
    } else if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
        d->ret.d_type = DT_DIR;
    } else {
        d->ret.d_type = DT_REG;
    }
    return &d->ret;
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
