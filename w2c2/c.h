#ifndef W2C2_C_H
#define W2C2_C_H

#include "w2c2_base.h"
#include "module.h"
#include "w2c2.h"

#ifdef __cplusplus
extern "C" {
#endif

#define W2C2_IMPL_FILENAME_LENGTH 13

/*
 * Name components contain the original byte length,
 * an underscore,
 * and bytes escaped as XHH unless they are ASCII letters or digits other than X.
 * Module symbols start with m<module component> and a category suffix:
 * Instance, Instantiate, FreeInstance, Export<name component>, and so on.
 * Function imports use i<import module component><import name component>,
 * or the module prefix followed by Import and both components in multiple-module mode.
 * Imported globals, memories, and tables use g, m, and t followed by their Wasm index.
 * Data segments use the module prefix followed by Data and their Wasm index.
 * External data uses the module prefix followed by Data for its base symbol.
 * Mach-O external-data modes use the module prefix as the section name in __DATA;
 * the encoded prefix must fit in 16 bytes.
 */
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
