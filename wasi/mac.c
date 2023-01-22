#include "mac.h"
#include <string.h>

char* posixToMacPath(char* path) {
    size_t len = strlen(path);
    char* pos = NULL;

    if (*path == '/') {
        /* absolute, remove leading / */
        path++;
        len--;
    } else {
        /* relative, prepend : */
        memmove(path+1, path, len);
        len++;
        path[0] = ':';
        path[len] = '\0';
    }

    /* replace all ../ with : */
    pos = path;
    while ((pos = strstr(pos, "../"))) {
        memmove(pos + 1, pos + 3, len - (pos + 3 - path));
        pos[0] = ':';
        len -= 2;
    }

    /* remove all ./ */
    pos = path;
    while ((pos = strstr(pos, "./"))) {
        memmove(pos, pos + 2, len - (pos + 2 - path));
        len -= 2;
    }

    /* replace trailing .. with : */
    pos = path;
    if ((pos = strstr(pos, ".."))) {
        memmove(pos + 1, pos + 2, len - (pos + 2 - path));
        pos[0] = ':';
        len--;
    }

    /* replace all / with : */
    pos = path;
    while ((pos = strchr(pos, '/'))) {
        *pos = ':';
    }

    path[len] = '\0';

    return path;
}

char* macToPosixPath(char* path) {
    size_t len = strlen(path);
    char* pos = NULL;

    if (*path == ':') {
        /* relative, prepend . */
        memmove(path+1, path, len);
        len += 1;
        path[0] = '.';
        path[len] = '\0';
    } else {
        /* absolute, prepend / */
        memmove(path+1, path, len);
        len++;
        path[0] = '/';
        path[len] = '\0';
    }


    /* replace all : with / */
    pos = path;
    while ((pos = strchr(pos, ':'))) {
        *pos++ = '/';
        /* replace all following : with ../ */
        while (*pos == ':') {
            memmove(pos + 3, pos + 1, len - (pos + 1 - path));
            *pos++ = '.';
            *pos++ = '.';
            *pos++ = '/';
            len += 2;
        }
    }

    path[len] = '\0';

    return path;
}
