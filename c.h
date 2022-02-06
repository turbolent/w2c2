#ifndef W2C2_C_H
#define W2C2_C_H

#include "w2c2_base.h"
#include "module.h"

typedef struct WasmCWriteModuleOptions {
    const char* outputPath;
    U32 jobCount;
    U32 functionsPerFile;
    bool pretty;
    WasmDataSegmentMode dataSegmentMode;
} WasmCWriteModuleOptions;

static const WasmCWriteModuleOptions emptyWasmCWriteModuleOptions ={
    NULL, 0, 0, false, wasmDataSegmentModeArrays
};

bool
WARN_UNUSED_RESULT
wasmCWriteModule(
    const WasmModule* module,
    WasmCWriteModuleOptions options
);

#endif /* W2C2_C_H */
