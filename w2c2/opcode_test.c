#include <stdio.h>
#include "opcode_test.h"
#include "opcode.h"

void
testOpcodes(void) {
    WasmOpcode opcode = 0;
    for (; opcode < 0xFF; opcode++) {
        const char* description = wasmOpcodeDescription(opcode);
        if (strcmp(description, "unknown") == 0) {
            continue;
        }
        switch (opcode) {
        case wasmOpcodeUnreachable:
        case wasmOpcodeNop:
        case wasmOpcodeBlock:
        case wasmOpcodeLoop:
        case wasmOpcodeIf:
        case wasmOpcodeElse:
        case wasmOpcodeEnd:
        case wasmOpcodeBr:
        case wasmOpcodeBrIf:
        case wasmOpcodeBrTable:
        case wasmOpcodeReturn:
        case wasmOpcodeCall:
        case wasmOpcodeCallIndirect:
        case wasmOpcodeDrop:
        case wasmOpcodeSelect:
        case wasmOpcodeLocalGet:
        case wasmOpcodeLocalSet:
        case wasmOpcodeLocalTee:
        case wasmOpcodeGlobalGet:
        case wasmOpcodeGlobalSet:
        case wasmOpcodeI32Store:
        case wasmOpcodeI32Store8:
        case wasmOpcodeI32Store16:
        case wasmOpcodeI64Store:
        case wasmOpcodeI64Store8:
        case wasmOpcodeI64Store16:
        case wasmOpcodeI64Store32:
        case wasmOpcodeF32Store:
        case wasmOpcodeF64Store:
            continue;
        }
        wasmOpcodeResultType(opcode);
    }

    fprintf(stderr, "PASS testOpcodes\n");
}
