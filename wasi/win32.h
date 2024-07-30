#ifndef W2C2_WASI_WIN32_H
#define W2C2_WASI_WIN32_H

#include <windows.h>
#include <errno.h>

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

#ifndef IO_REPARSE_TAG_MOUNT_POINT
#define IO_REPARSE_TAG_MOUNT_POINT 0xA0000003l
#endif

struct dirent {
    long d_ino;
    unsigned short d_reclen;
    unsigned char d_type;
    unsigned short d_namlen;
    char d_name[MAX_PATH];
};

typedef struct DIR DIR;

DIR* opendir(const char*);
struct dirent* readdir(DIR*);
int closedir(DIR*);

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

struct DIR {
    char* dirname;
    struct dirent ret;
    HANDLE handle;
};

#ifdef __cplusplus
}
#endif

#endif /* W2C2_WASI_WIN32_H */
