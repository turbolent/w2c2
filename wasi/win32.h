#ifndef W2C2_WASI_WIN32_H
#define W2C2_WASI_WIN32_H

#include <windows.h>
#include <errno.h>

#ifdef __cplusplus
extern "C" {
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
