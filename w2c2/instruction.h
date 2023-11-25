#ifndef W2C2_INSTRUCTION_H
#define W2C2_INSTRUCTION_H

#include "w2c2_base.h"
#include "buffer.h"
#include "opcode.h"

/* WasmLocalInstruction */

typedef struct WasmLocalInstruction {
    U32 localIndex;
} WasmLocalInstruction;

bool
WARN_UNUSED_RESULT
wasmLocalInstructionRead(
    Buffer* buffer,
    WasmLocalInstruction* result
);

/* WasmGlobalInstruction */

typedef struct WasmGlobalInstruction {
    U32 globalIndex;
} WasmGlobalInstruction;

bool
WARN_UNUSED_RESULT
wasmGlobalInstructionRead(
    Buffer* buffer,
    WasmGlobalInstruction* result
);

/* WasmConstInstruction */

typedef union WasmValue {
    I32 i32;
    I64 i64;
    F32 f32;
    F64 f64;
} WasmValue;

typedef struct WasmConstInstruction {
    WasmValue value;
} WasmConstInstruction;

bool
WARN_UNUSED_RESULT
wasmConstInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmConstInstruction* result
);

/* WasmMemoryArgumentInstruction */

typedef struct WasmMemoryArgumentInstruction {
    U32 align;
    U32 offset;
} WasmMemoryArgumentInstruction;

bool
WARN_UNUSED_RESULT
wasmMemoryArgumentInstructionRead(
    Buffer* buffer,
    WasmMemoryArgumentInstruction* result
);

#define WASM_MEMARG8_ALIGN  0
#define WASM_MEMARG16_ALIGN 1
#define WASM_MEMARG32_ALIGN 2
#define WASM_MEMARG64_ALIGN 3

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmMemoryArgument8InstructionRead(
        Buffer* buffer,
        WasmMemoryArgumentInstruction* result
) {
    MUST (wasmMemoryArgumentInstructionRead(buffer, result))
    return result->align == WASM_MEMARG8_ALIGN;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmMemoryArgument16InstructionRead(
        Buffer* buffer,
        WasmMemoryArgumentInstruction* result
) {
    MUST (wasmMemoryArgumentInstructionRead(buffer, result))
    return result->align == WASM_MEMARG16_ALIGN;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmMemoryArgument32InstructionRead(
    Buffer* buffer,
    WasmMemoryArgumentInstruction* result
) {
    MUST (wasmMemoryArgumentInstructionRead(buffer, result))
    return result->align == WASM_MEMARG32_ALIGN;
}

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmMemoryArgument64InstructionRead(
        Buffer* buffer,
        WasmMemoryArgumentInstruction* result
) {
    MUST (wasmMemoryArgumentInstructionRead(buffer, result))
    return result->align == WASM_MEMARG64_ALIGN;
}

/* WasmCallInstruction */

typedef struct WasmCallInstruction {
    U32 funcIndex;
} WasmCallInstruction;

bool
WARN_UNUSED_RESULT
wasmCallInstructionRead(
    Buffer* buffer,
    WasmCallInstruction* result
);

/* WasmCallIndirectInstruction */

typedef struct WasmCallIndirectInstruction {
    U32 functionTypeIndex;
    U32 tableIndex;
} WasmCallIndirectInstruction;

bool
WARN_UNUSED_RESULT
wasmCallIndirectInstructionRead(
    Buffer* buffer,
    WasmCallIndirectInstruction* result
);

/* WasmBranchInstruction */

typedef struct WasmBranchInstruction {
    U32 labelIndex;
} WasmBranchInstruction;

bool
WARN_UNUSED_RESULT
wasmBranchInstructionRead(
    Buffer* buffer,
    WasmBranchInstruction* result
);

/* WasmBranchTableInstruction */

typedef struct WasmBranchTableInstruction {
    U32* labelIndices;
    U32 labelIndexCount;
    U32 defaultLabelIndex;
} WasmBranchTableInstruction;

void
wasmBranchTableInstructionFree(
    WasmBranchTableInstruction instruction
);

bool
WARN_UNUSED_RESULT
wasmBranchTableInstructionRead(
    Buffer* buffer,
    WasmBranchTableInstruction* result
);

/* WasmMemoryInstruction */

typedef struct WasmMemoryInstruction {
    U32 memoryIndex;
} WasmMemoryInstruction;

bool
WARN_UNUSED_RESULT
wasmMemoryInstructionRead(
    Buffer* buffer,
    WasmMemoryInstruction* result
);

/* WasmMemoryCopyInstruction */

typedef struct WasmMemoryCopyInstruction {
    U32 memoryIndex1;
    U32 memoryIndex2;
} WasmMemoryCopyInstruction;

bool
WARN_UNUSED_RESULT
wasmMemoryCopyInstructionRead(
    Buffer* buffer,
    WasmMemoryCopyInstruction* result
);

/* WasmMemoryInitInstruction */

typedef struct WasmMemoryInitInstruction {
    U32 dataSegmentIndex;
    U32 memoryIndex;
} WasmMemoryInitInstruction;

bool
WARN_UNUSED_RESULT
wasmMemoryInitInstructionRead(
    Buffer* buffer,
    WasmMemoryInitInstruction* result
);

#endif /* W2C2_INSTRUCTION_H */
