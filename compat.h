#ifndef W2C2_COMPAT_H
#define W2C2_COMPAT_H

#include <string.h>

#if NEED_BASENAME
char *basename(char *s);
#else
#include <libgen.h>
#endif

#if NEED_DIRNAME
char *dirname(char *s);
#else
#include <libgen.h>
#endif

#endif /* W2C2_COMPAT_H */
