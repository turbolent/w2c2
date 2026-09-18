#include <cstdlib>
#include <cstring>

#include "w2c2.h"

static WasmBool
complete(
    void* context, const char* name, WasmOutputKind kind,
    const U8* bytes, size_t length, int* systemError
) {
    unsigned* count = static_cast<unsigned*>(context);
    (void)systemError;
    if (bytes[length] != 0 || length == 0
        || (kind != wasmOutputHeader && kind != wasmOutputC)
        || std::strncmp(name, "example.", 8) != 0) {
        std::abort();
    }
    ++*count;
    return 255;
}

int main() {
    const U8 bytes[] = {0, 97, 115, 109, 1, 0, 0, 0};
    unsigned count = 0;
    WasmMemoryOutput memory = {&count, complete};
    WasmCWriteModuleOptions options = emptyWasmCWriteModuleOptions;
    options.outputName = "example.c";
    options.pretty = 255;
    options.output = wasmMemoryOutputProvider(&memory);
    return wasmTranslate(bytes, sizeof(bytes), "example", &options) && count == 2 ? 0 : 1;
}
