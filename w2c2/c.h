#ifndef W2C2_C_H
#define W2C2_C_H

#include "w2c2_base.h"
#include "module.h"
#include "w2c2.h"

#ifdef __cplusplus
extern "C" {
#endif

#define W2C2_IMPL_FILENAME_LENGTH 13

WasmBool
WARN_UNUSED_RESULT
wasmCWriteModule(
    const WasmModule *module,
    const char *moduleName,
    WasmCWriteModuleOptions options,
    WasmFunctionIDs staticFunctionIDs,
    WasmFunctionIDs dynamicFunctionIDs
);

#ifdef __cplusplus
}
#endif

#endif /* W2C2_C_H */
