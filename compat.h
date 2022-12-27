#ifndef W2C2_COMPAT_H
#define W2C2_COMPAT_H

#include <string.h>

#if HAS_LIBGEN
#include <libgen.h>
#else
char* basename(char* s);
char* dirname(char* s);
#endif /* HAS_LIBGEN */

#endif /* W2C2_COMPAT_H */
