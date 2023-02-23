#include <dirent.h>
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    const char* basepath = argv[1];
    size_t baselen = strlen(basepath);

    DIR* dir = opendir(basepath);
    if (!dir) {
        fprintf(stderr, "Couldn't open directory '%s': %s\n", basepath, strerror(errno));
        return 1;
    }

    while (1) {
        struct dirent* dirent = readdir(dir);
        if (dirent) {
            char fullpath[baselen + 1 + strlen(dirent->d_name) + 1];
            strcpy(fullpath, basepath);
            fullpath[baselen] = '/';
            strcpy(fullpath + baselen + 1, dirent->d_name);

            const char* typeString;
            switch (dirent->d_type) {
                case DT_BLK: typeString = "DT_BLK"; break;
                case DT_CHR: typeString = "DT_CHR"; break;
                case DT_DIR: typeString = "DT_DIR"; break;
                case DT_FIFO: typeString = "DT_FIFO"; break;
                case DT_LNK: typeString = "DT_LNK"; break;
                case DT_REG: typeString = "DT_REG"; break;
                case DT_UNKNOWN: typeString = "DT_UNKNOWN"; break;
                default: typeString = "?"; break;
            }

            printf(
                "%s (%s)\n",
                dirent->d_name,
                fullpath
            );

            printf(
                "  dirent_type: %s\n"
                "  dirent_ino: %llu\n",
                typeString,
                dirent->d_ino
            );

            struct stat st;
            if (stat(fullpath, &st) == -1) {
                fprintf(stderr, "Couldn't stat '%s': %s\n", dirent->d_name, strerror(errno));
                return 1;
            }

            printf(
                "  stat_mode: %d\n"
                "  stat_ino: %llu\n"
                "  stat_size: %llu\n"
                ,
                st.st_mode,
                st.st_ino,
                st.st_size
            );

            switch (st.st_mode & S_IFMT) {
                case S_IFBLK: typeString = "DT_BLK"; break;
                case S_IFCHR: typeString = "DT_CHR"; break;
                case S_IFDIR: typeString = "DT_DIR"; break;
                case S_IFIFO: typeString = "DT_FIFO"; break;
                case S_IFLNK: typeString = "DT_LNK"; break;
                case S_IFREG: typeString = "DT_REG"; break;
                default: typeString = "?"; break;
            }

            printf(
                "  stat_type: %s\n",
                typeString
            );

        } else if (errno) {
            fprintf(stderr, "Couldn't read directory '%s': %s\n", argv[1], strerror(errno));
            return 1;
        } else {
            break;
        }
    }

    printf("\n");

    if (closedir(dir)) {
        fprintf(stderr, "Couldn't close directory '%s': %s\n", argv[1], strerror(errno));
        return 1;
    }

    return 0;
}
