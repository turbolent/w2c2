#ifndef W2C2_C_H
#define W2C2_C_H

#include "w2c2_base.h"
#include "module.h"

bool
WARN_UNUSED_RESULT
wasmCWriteModule(
    FILE* file,
    const WasmModule* module
);

#endif /* W2C2_C_H */
