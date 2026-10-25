#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "w2c2.h"
#include "diagnostic_print.h"

typedef struct Output {
    char* text;
    size_t length;
} Output;

typedef struct Outputs {
    Output c;
    Output header;
} Outputs;

static WasmBool
complete(
    void* context, const char* name, WasmOutputKind kind,
    const U8* bytes, size_t length, int* systemError
) {
    Outputs* outputs = (Outputs*)context;
    Output* output = kind == wasmOutputHeader ? &outputs->header : &outputs->c;
    (void)name;
    output->text = (char*)malloc(length + 1);
    if (output->text == NULL) {
        *systemError = ENOMEM;
        return 0;
    }
    memcpy(output->text, bytes, length + 1);
    output->length = length;
    return 1;
}

static void
report(void* context, const WasmDiagnostic* diagnostic) {
    (void)context;
    wasmDiagnosticPrint(stderr, diagnostic, "example.wasm");
}

int
main(void) {
    /* (module (func (export "answer") (result i32) i32.const 42)) */
    static const U8 bytes[] = {
        0, 97, 115, 109, 1, 0, 0, 0,
        1, 5, 1, 96, 0, 1, 127,
        3, 2, 1, 0,
        7, 10, 1, 6, 'a', 'n', 's', 'w', 'e', 'r', 0, 0,
        10, 6, 1, 4, 0, 65, 42, 11
    };
    Outputs outputs = {{NULL, 0}, {NULL, 0}};
    WasmMemoryOutput memory;
    WasmCWriteModuleOptions options = emptyWasmCWriteModuleOptions;
    WasmBool success;
    memory.context = &outputs;
    memory.complete = complete;
    options.outputName = "example.c";
    options.output = wasmMemoryOutputProvider(&memory);
    options.diagnostics.report = report;
    success = wasmTranslate(bytes, sizeof(bytes), "example", &options);
    if (success) {
        printf("Generated %lu C bytes and %lu header bytes in memory\n",
            (unsigned long)outputs.c.length, (unsigned long)outputs.header.length);
    }
    free(outputs.c.text);
    free(outputs.header.text);
    return success ? 0 : 1;
}
