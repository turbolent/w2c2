#ifndef W2C2_NAME_H
#define W2C2_NAME_H

#include "array.h"

ARRAY_TYPE(
    WasmNames,
    WasmName,
    wasmNames,
    names,
    name
)

static const WasmNames emptyWasmNames = {0, 0, NULL};

/* Frees a name whose storage is owned by the translator.
 * Borrowed names must not be passed here.
 */
static
W2C2_INLINE
void
wasmNameFree(WasmName name) {
    free((void*)name.data);
}

#endif /* W2C2_NAME_H */
