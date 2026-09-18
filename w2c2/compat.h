#ifndef W2C2_COMPAT_H
#define W2C2_COMPAT_H

/* Use the caller's buffer to support concurrent translations. */
char* wasmBasename(char* s);

#if HAS_LIBGEN
#include <libgen.h>
#else
char* dirname(char* s);
#endif /* HAS_LIBGEN */

#endif /* W2C2_COMPAT_H */
