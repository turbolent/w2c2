#include <string.h>
#include "compat.h"
#include "path.h"

/*
 * Taken from musl. Copyright © 2005-2020 Rich Felker, et al.
 */

char*
wasmBasename(
    char* s
) {
    size_t i;
    if (!s || !*s) {
        return ".";
    }
    i = strlen(s)-1;
    for (; i && wasmPathIsSeparator(s[i]); i--) {
        s[i] = 0;
    }
    for (; i && !wasmPathIsSeparator(s[i - 1]); i--) { }
#if _WIN32
    if (i == 0 && s[1] == ':') {
        return s + 2;
    }
#endif
    return s+i;
}

#if !HAS_LIBGEN

/*
 * Taken from musl. Copyright © 2005-2020 Rich Felker, et al.
 */

char*
dirname(
    char* s
) {
    size_t i;
    if (!s || !*s) {
        return ".";
    }
    i = strlen(s)-1;
    for (; wasmPathIsSeparator(s[i]); i--) {
        if (!i) {
            return PATH_SEPARATOR_STRING;
        }
    }
    for (; !wasmPathIsSeparator(s[i]); i--) {
        if (!i) {
#if _WIN32
            if (s[1] == ':') {
                s[2] = 0;
                return s;
            }
#endif
            return ".";
        }
    }
    for (; wasmPathIsSeparator(s[i]); i--) {
        if (!i) {
            return PATH_SEPARATOR_STRING;
        }
    }
#if _WIN32
    if (i == 1 && s[1] == ':') {
        s[3] = 0;
        return s;
    }
#endif
    s[i+1] = 0;
    return s;
}

#endif /* !HAS_LIBGEN */
