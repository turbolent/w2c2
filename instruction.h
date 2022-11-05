#ifndef W2C2_INSTRUCTION_H
#define W2C2_INSTRUCTION_H

#include "w2c2_base.h"
#include "buffer.h"
#include "opcode.h"

/* WasmLocalInstruction */

typedef struct WasmLocalInstruction {
    WasmOpcode opcode;
    U32 localIndex;
} WasmLocalInstruction;

bool
WARN_UNUSED_RESULT
wasmLocalInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmLocalInstruction* result
);

/* WasmGlobalInstruction */

typedef struct WasmGlobalInstruction {
    WasmOpcode opcode;
    U32 globalIndex;
} WasmGlobalInstruction;

bool
WARN_UNUSED_RESULT
wasmGlobalInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
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
    WasmOpcode opcode;
    WasmValue value;
} WasmConstInstruction;

bool
WARN_UNUSED_RESULT
wasmConstInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmConstInstruction* result
);

/* WasmLoadStoreInstruction */

typedef struct WasmLoadStoreInstruction {
    WasmOpcode opcode;
    U32 align;
    U32 offset;
} WasmLoadStoreInstruction;

bool
WARN_UNUSED_RESULT
wasmLoadStoreInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmLoadStoreInstruction* result
);

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
    WasmOpcode opcode;
    U32 labelIndex;
} WasmBranchInstruction;

bool
WARN_UNUSED_RESULT
wasmBranchInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
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
    WasmOpcode opcode;
    U32 memoryIndex;
} WasmMemoryInstruction;

bool
WARN_UNUSED_RESULT
wasmMemoryInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmMemoryInstruction* result
);

#endif /* W2C2_INSTRUCTION_H */
