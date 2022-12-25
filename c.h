#ifndef W2C2_C_H
#define W2C2_C_H

#include "w2c2_base.h"
#include "module.h"

typedef struct WasmCWriteModuleOptions {
    const char* outputPath;
    U32 threadCount;
    U32 functionsPerFile;
    bool pretty;
    bool debug;
    WasmDataSegmentMode dataSegmentMode;
} WasmCWriteModuleOptions;

static const WasmCWriteModuleOptions emptyWasmCWriteModuleOptions ={
    NULL, 0, 0, false, false, wasmDataSegmentModeArrays
};

bool
WARN_UNUSED_RESULT
wasmCWriteModule(
    const WasmModule* module,
    const char* moduleName,
    WasmCWriteModuleOptions options
);

#endif /* W2C2_C_H */
