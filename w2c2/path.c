#include <stdlib.h>
#include <string.h>

#include "path.h"

char*
wasmPathJoin(const char* directory, const char* name) {
    const size_t directoryLength = directory == NULL ? 0 : strlen(directory);
    const size_t nameLength = strlen(name);
    size_t prefixLength = directoryLength;
    char* path;
    if (prefixLength > (size_t)-1 - 2
        || nameLength > (size_t)-1 - prefixLength - 2) {
        return NULL;
    }
    path = (char*)malloc(prefixLength + nameLength + 2);
    if (path == NULL) {
        return NULL;
    }
    if (prefixLength != 0) {
        memcpy(path, directory, prefixLength);
        if (!wasmPathIsSeparator(directory[prefixLength - 1])
#if _WIN32
            && !(prefixLength == 2 && directory[1] == ':')
#endif
        ) {
            path[prefixLength++] = PATH_SEPARATOR;
        }
    }
    memcpy(path + prefixLength, name, nameLength + 1);
    return path;
}
