#ifndef W2C2_NAME_H
#define W2C2_NAME_H

#include "array.h"

ARRAY_TYPE(
    WasmNames,
    char*,
    wasmNames,
    names,
    name
)

static const WasmNames emptyWasmNames = {0, 0, NULL};

#endif /* W2C2_NAME_H */
