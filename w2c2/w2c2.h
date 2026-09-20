#ifndef W2C2_H
#define W2C2_H

#include "api.h"
#include "diagnostic.h"
#include "output.h"

typedef struct WasmCWriteModuleOptions {
    /*
     * Logical C filename;
     * the provider chooses its destination.
     * Must be a basename usable in a quoted C include,
     * with no quotes, backslashes, control characters, or trigraph sequences.
     * Generated filenames must not conflict with this name or the runtime header;
     * comparisons ignore ASCII case.
     */
    const char* outputName;
    WasmOutputProvider output;
    /*
     * A zero thread count selects one worker.
     * At most one worker is created per implementation file.
     * Work runs on the calling thread when one worker suffices.
     */
    U32 threadCount;
    U32 functionsPerFile;
    WasmBool pretty;
    WasmBool debug;
    WasmBool multipleModules;
    WasmDataSegmentMode dataSegmentMode;
    WasmDiagnostics diagnostics;
} WasmCWriteModuleOptions;

static const WasmCWriteModuleOptions emptyWasmCWriteModuleOptions = {
    NULL, {NULL, NULL}, 0, 0, false, false, false, wasmDataSegmentModeArrays, {NULL, NULL}
};

/*
 * Translates one module and frees all translator-owned storage before returning.
 * bytes, moduleName, options, and callback contexts are borrowed until return.
 * bytes must be non-NULL;
 * moduleName must be a nonempty C identifier.
 * options must specify outputName and an output provider.
 * Zero functionsPerFile selects a single implementation file.
 * Failures return zero and report through options->diagnostics when available.
 * NULL options returns zero without reporting a diagnostic.
 * Earlier completed outputs remain delivered on failure.
 */
#ifdef __cplusplus
extern "C" {
#endif

WasmBool
WARN_UNUSED_RESULT
wasmTranslate(
    const U8* bytes,
    size_t length,
    const char* moduleName,
    const WasmCWriteModuleOptions* options
);

#ifdef __cplusplus
}
#endif

#endif /* W2C2_H */
