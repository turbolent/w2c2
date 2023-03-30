#include "instruction.h"
#include <stdio.h>

/* WasmLocalInstruction */

bool
wasmLocalInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmLocalInstruction* result
) {
    U32 localIndex = 0;
    MUST (leb128ReadU32(buffer, &localIndex) > 0)

    result->opcode = opcode;
    result->localIndex = localIndex;

    return true;
}

/* WasmGlobalInstruction */

bool
wasmGlobalInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmGlobalInstruction* result
) {
    U32 globalIndex = 0;
    MUST (leb128ReadU32(buffer, &globalIndex) > 0)

    result->opcode = opcode;
    result->globalIndex = globalIndex;

    return true;
}

/* WasmConstInstruction */

bool
wasmConstInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmConstInstruction* result
) {
    result->opcode = opcode;
    switch (opcode) {
        case wasmOpcodeI32Const:
            return leb128ReadI32(buffer, &result->value.i32) > 0;
        case wasmOpcodeI64Const:
            return leb128ReadI64(buffer, &result->value.i64) > 0;
        case wasmOpcodeF32Const:
            return bufferReadF32(buffer, &result->value.f32) > 0;
        case wasmOpcodeF64Const:
            return bufferReadF64(buffer, &result->value.f64) > 0;
        default:
            return false;
    }
}

/* WasmLoadStoreInstruction */

bool
wasmLoadStoreInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmLoadStoreInstruction* result
) {
    U32 align = 0;
    U32 offset = 0;

    MUST (leb128ReadU32(buffer, &align) > 0)
    MUST (leb128ReadU32(buffer, &offset) > 0)

    result->opcode = opcode;
    result->align = 1 << align;
    result->offset = offset;

    return true;
}

/* WasmCallInstruction */

bool
wasmCallInstructionRead(
    Buffer* buffer,
    WasmCallInstruction* result
) {
    U32 funcIndex = 0;
    MUST (leb128ReadU32(buffer, &funcIndex) > 0)

    result->funcIndex = funcIndex;

    return true;
}

/* WasmCallIndirectInstruction */

bool
wasmCallIndirectInstructionRead(
    Buffer* buffer,
    WasmCallIndirectInstruction* result
) {
    U32 typeIndex = 0;
    U32 memoryIndex = 0;

    MUST (leb128ReadU32(buffer, &typeIndex) > 0)
    MUST (leb128ReadU32(buffer, &memoryIndex) > 0)

    result->functionTypeIndex = typeIndex;
    result->tableIndex = memoryIndex;

    return true;
}

/* WasmBranchInstruction */

bool
wasmBranchInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmBranchInstruction* result
) {
    U32 labelIndex = 0;
    MUST(leb128ReadU32(buffer, &labelIndex) > 0)

    result->opcode = opcode;
    result->labelIndex = labelIndex;

    return true;
}

/* WasmBranchTableInstruction */

bool
wasmBranchTableInstructionRead(
    Buffer* buffer,
    WasmBranchTableInstruction* result
) {
    U32 labelIndexCount = 0;
    U32* labelIndices = NULL;
    U32 defaultLabelIndex = 0;

    MUST(leb128ReadU32(buffer, &labelIndexCount) > 0)

    labelIndices = calloc(sizeof(U32) * labelIndexCount, 1);
    {
        U32 labelIndex = 0;
        for (; labelIndex < labelIndexCount; labelIndex++) {
            MUST(leb128ReadU32(buffer, &labelIndices[labelIndex]) > 0)
        }
    }

    MUST (leb128ReadU32(buffer, &defaultLabelIndex) > 0)

    result->labelIndexCount = labelIndexCount;
    result->labelIndices = labelIndices;
    result->defaultLabelIndex = defaultLabelIndex;

    return true;
}

void
wasmBranchTableInstructionFree(
    WasmBranchTableInstruction instruction
) {
    free(instruction.labelIndices);
}

/* WasmMemoryInstruction */

bool
wasmMemoryInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmMemoryInstruction* result
) {
    U32 memoryIndex = 0;
    MUST(leb128ReadU32(buffer, &memoryIndex) > 0)

    result->opcode = opcode;
    result->memoryIndex = memoryIndex;

    return true;
}

/* WasmMiscMemoryInstruction */

bool
WARN_UNUSED_RESULT
wasmMiscMemoryInstructionRead(
    Buffer* buffer,
    WasmMiscOpcode opcode,
    WasmMiscMemoryInstruction* result
) {
    U32 memoryIndex = 0;
    MUST(leb128ReadU32(buffer, &memoryIndex) > 0)

    result->opcode = opcode;
    result->memoryIndex = memoryIndex;

    return true;
}

/* WasmMemoryCopyInstruction */

bool
WARN_UNUSED_RESULT
wasmMemoryCopyInstructionRead(
    Buffer* buffer,
    WasmMemoryCopyInstruction* result
) {
    U8 memoryIndex1 = 0;
    U8 memoryIndex2 = 0;
    MUST (bufferReadByte(buffer, &memoryIndex1) > 0)
    MUST (bufferReadByte(buffer, &memoryIndex2) > 0)

    result->memoryIndex1 = memoryIndex1;
    result->memoryIndex2 = memoryIndex2;

    return true;
}

