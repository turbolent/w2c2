#ifndef W2C2_STR_H
#define W2C2_STR_H

#include <string.h>
#include <stdlib.h>

char *strdup(const char *s) {
    char *r = (char*) malloc(strlen(s) + 1);
    if (r != NULL) {
        strcpy(r, s);
    }
    return r;
}

#endif /* W2C2_STR_H */
