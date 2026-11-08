#ifndef W2C2_WASI_WIN32_H
#define W2C2_WASI_WIN32_H

#include <windows.h>
#include <errno.h>
#include "../w2c2/w2c2_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/* defines for MSVC 4.0 */
#ifndef ERROR_DELETE_PENDING
#define ERROR_DELETE_PENDING 303
#endif

#ifndef ERROR_CANT_RESOLVE_FILENAME
#define ERROR_CANT_RESOLVE_FILENAME 1921
#endif

#ifndef INVALID_FILE_ATTRIBUTES
#define INVALID_FILE_ATTRIBUTES (~0u)
#endif

#ifndef FILE_ATTRIBUTE_REPARSE_POINT
#define FILE_ATTRIBUTE_REPARSE_POINT 0x00000400
#endif

#ifndef FILE_ATTRIBUTE_SPARSE_FILE
#define FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#endif

#ifndef IO_REPARSE_TAG_MOUNT_POINT
#define IO_REPARSE_TAG_MOUNT_POINT 0xA0000003l
#endif

#ifndef IO_REPARSE_TAG_SYMLINK
#define IO_REPARSE_TAG_SYMLINK 0xA000000Cl
#endif

#ifndef FILE_FLAG_OPEN_REPARSE_POINT
#define FILE_FLAG_OPEN_REPARSE_POINT 0x00200000
#endif

#define WASI_WINDOWS_S_IFLNK 0120000

struct wasiWindowsStat {
    U64 st_dev;
    U64 st_ino;
    U64 st_nlink;
    U64 st_size;
    unsigned short st_mode;
    I64 st_atime;
    I64 st_mtime;
    I64 st_ctime;
    long accessNanoseconds;
    long modificationNanoseconds;
    long creationNanoseconds;
};

int wasiWindowsStat(const char* path, struct wasiWindowsStat* st);
int wasiWindowsLstat(const char* path, struct wasiWindowsStat* st);
int wasiWindowsFstat(int fd, struct wasiWindowsStat* st);
int wasiWindowsOpen(const char* path, int flags, int mode);
int wasiWindowsWrite(int fd, const void* bytes, unsigned int length);
int wasiWindowsSymlink(const char* target, const char* path);
long wasiWindowsReadlink(const char* path, char* buffer, size_t length);
int wasiWindowsUnlink(const char* path);
int wasiWindowsRmdir(const char* path);
int wasiWindowsRename(const char* source, const char* target);

struct dirent {
    U64 d_ino;
    unsigned short d_reclen;
    unsigned char d_type;
    unsigned short d_namlen;
    char d_name[MAX_PATH];
};

typedef struct DIR DIR;

void wasiSetErrno(unsigned long error);

DIR* opendir(const char*);
struct dirent* readdir(DIR*);
int closedir(DIR*);
void rewinddir(DIR*);

/* File types for 'd_type' */
#define DT_UNKNOWN  0
#define DT_FIFO     1
#define DT_CHR      2
#define DT_DIR      4
#define DT_BLK      6
#define DT_REG      8
#define DT_LNK      10
#define DT_SOCK     12
#define DT_WHT      14
#define DTTOIF(type) ((unsigned short)((type) << 12))

struct DIR {
    char* dirname;
    struct dirent ret;
    HANDLE handle;
};

#ifdef __cplusplus
}
#endif

#endif /* W2C2_WASI_WIN32_H */
