#include "instruction.h"

/* WasmLocalInstruction */

bool
wasmLocalInstructionRead(
    Buffer* buffer,
    WasmLocalInstruction* result
) {
    U32 localIndex = 0;
    MUST (leb128ReadU32(buffer, &localIndex) > 0)

    result->localIndex = localIndex;

    return true;
}

/* WasmGlobalInstruction */

bool
wasmGlobalInstructionRead(
    Buffer* buffer,
    WasmGlobalInstruction* result
) {
    U32 globalIndex = 0;
    MUST (leb128ReadU32(buffer, &globalIndex) > 0)

    result->globalIndex = globalIndex;

    return true;
}

/* WasmConstInstruction */

bool
wasmConstInstructionRead(
    Buffer* buffer,
    const WasmOpcode opcode,
    WasmConstInstruction* result
) {
    switch (opcode) {
        case wasmOpcodeI32Const:
            return leb128ReadI32(buffer, &result->value.i32) > 0;
        case wasmOpcodeI64Const:
            return leb128ReadI64(buffer, &result->value.i64) > 0;
        case wasmOpcodeF32Const:
            return bufferReadF32(buffer, &result->value.i32) > 0;
        case wasmOpcodeF64Const:
            return bufferReadF64(buffer, &result->value.i64) > 0;
        default:
            return false;
    }
}

/* WasmMemoryArgumentInstruction */

bool
wasmMemoryArgumentInstructionRead(
    Buffer* buffer,
    WasmMemoryArgumentInstruction* result
) {
    U32 align = 0;
    U32 offset = 0;

    MUST (leb128ReadU32(buffer, &align) > 0)
    MUST (leb128ReadU32(buffer, &offset) > 0)

    result->align = align;
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
    WasmBranchInstruction* result
) {
    U32 labelIndex = 0;
    MUST(leb128ReadU32(buffer, &labelIndex) > 0)

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

    labelIndices = calloc( labelIndexCount, sizeof(U32));
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
    const WasmBranchTableInstruction instruction
) {
    free(instruction.labelIndices);
}

/* WasmMemoryInstruction */

bool
wasmMemoryInstructionRead(
    Buffer* buffer,
    WasmMemoryInstruction* result
) {
    U32 memoryIndex = 0;
    MUST(leb128ReadU32(buffer, &memoryIndex) > 0)

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
    U32 memoryIndex1 = 0;
    U32 memoryIndex2 = 0;
    MUST (leb128ReadU32(buffer, &memoryIndex1) > 0)
    MUST (leb128ReadU32(buffer, &memoryIndex2) > 0)

    result->memoryIndex1 = memoryIndex1;
    result->memoryIndex2 = memoryIndex2;

    return true;
}

/* WasmMemoryInitInstruction */

bool
WARN_UNUSED_RESULT
wasmMemoryInitInstructionRead(
    Buffer* buffer,
    WasmMemoryInitInstruction* result
) {
    U32 dataSegmentIndex = 0;
    U32 memoryIndex = 0;

    MUST (leb128ReadU32(buffer, &dataSegmentIndex) > 0)
    MUST (leb128ReadU32(buffer, &memoryIndex) > 0)

    result->dataSegmentIndex = dataSegmentIndex;
    result->memoryIndex = memoryIndex;

    return true;
}
