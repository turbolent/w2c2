#ifndef W2C2_C_H
#define W2C2_C_H

#include "w2c2_base.h"
#include "module.h"

bool
WARN_UNUSED_RESULT
wasmCWriteModule(
    const char* outputPath,
    const WasmModule* module,
    U32 jobCount,
    U32 functionsPerFile
);

#endif /* W2C2_C_H */
