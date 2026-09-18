#include <errno.h>

#include "output.h"
#include "output_buffer.h"

typedef struct MemoryOutputSink {
    const WasmMemoryOutput* output;
    const char* name;
    WasmOutputKind kind;
    OutputBuffer buffer;
} MemoryOutputSink;

static
bool
memoryOutputWrite(void* context, const U8* bytes, size_t length, int* systemError) {
    MemoryOutputSink* sink = (MemoryOutputSink*)context;
    if (!outputBufferAppend(&sink->buffer, bytes, length)) {
        *systemError = ENOMEM;
        return false;
    }
    return true;
}

static
void
memoryOutputAbort(void* context) {
    MemoryOutputSink* sink = (MemoryOutputSink*)context;
    outputBufferFree(&sink->buffer);
    free(sink);
}

static
bool
memoryOutputClose(void* context, int* systemError) {
    MemoryOutputSink* sink = (MemoryOutputSink*)context;
    const WasmMemoryOutput* output = sink->output;
    const bool result = output->complete(
        output->context, sink->name, sink->kind,
        sink->buffer.data, sink->buffer.length, systemError
    );
    memoryOutputAbort(context);
    return result;
}

static
bool
memoryOutputOpen(
    void* context,
    const char* name,
    WasmOutputKind kind,
    WasmOutputSink* result,
    int* systemError
) {
    const WasmMemoryOutput* output = (const WasmMemoryOutput*)context;
    MemoryOutputSink* sink;
    if (output == NULL || output->complete == NULL) {
        *systemError = EINVAL;
        return false;
    }
    sink = (MemoryOutputSink*)malloc(sizeof(*sink));
    if (sink == NULL) {
        *systemError = ENOMEM;
        return false;
    }
    sink->output = output;
    sink->name = name;
    sink->kind = kind;
    sink->buffer = emptyOutputBuffer;
    if (!outputBufferInitialize(&sink->buffer)) {
        free(sink);
        *systemError = ENOMEM;
        return false;
    }
    result->context = sink;
    result->write = memoryOutputWrite;
    result->close = memoryOutputClose;
    result->abort = memoryOutputAbort;
    return true;
}

WasmOutputProvider
wasmMemoryOutputProvider(const WasmMemoryOutput* output) {
    WasmOutputProvider provider;
    provider.context = (void*)output;
    provider.open = memoryOutputOpen;
    return provider;
}
