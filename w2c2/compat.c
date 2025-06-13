#include <string.h>
#include "compat.h"
#include "path.h"

#if !HAS_LIBGEN

/*
 * Taken from musl. Copyright © 2005-2020 Rich Felker, et al.
 */

char*
basename(
    char* s
) {
    size_t i;
    if (!s || !*s) {
        return ".";
    }
    i = strlen(s)-1;
    for (; i && s[i] == PATH_SEPARATOR; i--) {
        s[i] = 0;
    }
    for (; i && s[i - 1] != PATH_SEPARATOR; i--) { }
    return s+i;
}

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
    for (; s[i] == PATH_SEPARATOR; i--) {
        if (!i) {
            return PATH_SEPARATOR_STRING;
        }
    }
    for (; s[i] != PATH_SEPARATOR; i--) {
        if (!i) {
            return ".";
        }
    }
    for (; s[i] == PATH_SEPARATOR; i--) {
        if (!i) {
            return PATH_SEPARATOR_STRING;
        }
    }
    s[i+1] = 0;
    return s;
}

#endif /* !HAS_LIBGEN */
