#ifndef W2C2_C_H
#define W2C2_C_H

#include "w2c2_base.h"
#include "module.h"
#include "w2c2.h"

#ifdef __cplusplus
extern "C" {
#endif

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
 *
 * Functions with zero results return void.
 * Functions with one result return that value directly.
 * Multiple results use struct w2c2_result_<types>,
 * with fields v0, v1, and so on in result order.
 * Type codes are i (i32), j (i64), f (f32), d (f64), and v (v128).
 * Shared declaration guards prevent duplicate definitions across module headers.
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
