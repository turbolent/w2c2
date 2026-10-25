#include <cstdlib>
#include <cstring>
#include <type_traits>

#include "w2c2.h"

static_assert(std::is_same<decltype(WasmName::data), const char*>::value,
    "name bytes must be read-only");

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
    static const char nameBytes[] = {'a', '\0', 'b'};
    const WasmName name = wasmNameFromBytes(nameBytes, sizeof(nameBytes));
    const WasmName literal = {"a\0b", 3};
    const U8 bytes[] = {0, 97, 115, 109, 1, 0, 0, 0};
    unsigned count = 0;
    if (name.data != nameBytes || name.length != sizeof(nameBytes)
        || wasmNameCompare(name, literal) != 0) {
        return 1;
    }
    WasmMemoryOutput memory = {&count, complete};
    WasmCWriteModuleOptions options = emptyWasmCWriteModuleOptions;
    options.outputName = "example.c";
    options.pretty = 255;
    options.output = wasmMemoryOutputProvider(&memory);
    return wasmTranslate(bytes, sizeof(bytes), "example", &options) && count == 2 ? 0 : 1;
}
