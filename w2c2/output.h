#ifndef W2C2_OUTPUT_H
#define W2C2_OUTPUT_H

#include "w2c2_base.h"

typedef enum WasmOutputKind {
    wasmOutputC,
    wasmOutputHeader,
    wasmOutputData
} WasmOutputKind;

/*
 * write consumes all bytes on success and borrows them only during the call.
 * Each opened sink gets one close or abort,
 * which must release its resources even on failure.
 * abort discards incomplete output.
 * systemError is non-NULL and starts at zero;
 * callbacks may set it to a native error code on failure.
 */
typedef struct WasmOutputSink {
    void* context;
    bool (*write)(void* context, const U8* bytes, size_t length, int* systemError);
    bool (*close)(void* context, int* systemError);
    void (*abort)(void* context);
} WasmOutputSink;

/*
 * name has no directory components and stays valid until close or abort.
 * open must set every sink callback on success and free its resources on failure.
 * Calls on one sink are sequential;
 * different outputs may run concurrently.
 * Keep context valid until translation returns,
 * when all callbacks have finished.
 */
typedef struct WasmOutputProvider {
    void* context;
    bool (*open)(
        void* context,
        const char* name,
        WasmOutputKind kind,
        WasmOutputSink* sink,
        int* systemError
    );
} WasmOutputProvider;

/* The directory is borrowed until translation returns. */
WasmOutputProvider
wasmFileOutputProvider(const char* directory);

/*
 * complete borrows name and bytes during the call.
 * bytes[length] is always zero;
 * length counts all output bytes, including zeros.
 * Returning false fails translation;
 * earlier outputs remain delivered.
 */
typedef struct WasmMemoryOutput {
    void* context;
    bool (*complete)(
        void* context,
        const char* name,
        WasmOutputKind kind,
        const U8* bytes,
        size_t length,
        int* systemError
    );
} WasmMemoryOutput;

/* The configuration is borrowed until translation returns. */
WasmOutputProvider
wasmMemoryOutputProvider(const WasmMemoryOutput* output);

#endif /* W2C2_OUTPUT_H */
