#ifndef W2C2_OPCODE_H
#define W2C2_OPCODE_H

#include "w2c2_base.h"
#include "buffer.h"
#include "valuetype.h"

typedef enum WasmOpcode {
    wasmOpcodeUnreachable        = 0x00,
    wasmOpcodeNop                = 0x01,
    wasmOpcodeBlock              = 0x02,
    wasmOpcodeLoop               = 0x03,
    wasmOpcodeIf                 = 0x04,
    wasmOpcodeElse               = 0x05,
    wasmOpcodeEnd                = 0x0B,
    wasmOpcodeBr                 = 0x0C,
    wasmOpcodeBrIf               = 0x0D,
    wasmOpcodeBrTable            = 0x0E,
    wasmOpcodeReturn             = 0x0F,
    wasmOpcodeCall               = 0x10,
    wasmOpcodeCallIndirect       = 0x11,
    wasmOpcodeDrop               = 0x1A,
    wasmOpcodeSelect             = 0x1B,
    wasmOpcodeLocalGet           = 0x20,
    wasmOpcodeLocalSet           = 0x21,
    wasmOpcodeLocalTee           = 0x22,
    wasmOpcodeGlobalGet          = 0x23,
    wasmOpcodeGlobalSet          = 0x24,
    wasmOpcodeI32Load            = 0x28,
    wasmOpcodeI64Load            = 0x29,
    wasmOpcodeF32Load            = 0x2A,
    wasmOpcodeF64Load            = 0x2B,
    wasmOpcodeI32Load8S          = 0x2C,
    wasmOpcodeI32Load8U          = 0x2D,
    wasmOpcodeI32Load16S         = 0x2E,
    wasmOpcodeI32Load16U         = 0x2F,
    wasmOpcodeI64Load8S          = 0x30,
    wasmOpcodeI64Load8U          = 0x31,
    wasmOpcodeI64Load16S         = 0x32,
    wasmOpcodeI64Load16U         = 0x33,
    wasmOpcodeI64Load32S         = 0x34,
    wasmOpcodeI64Load32U         = 0x35,
    wasmOpcodeI32Store           = 0x36,
    wasmOpcodeI64Store           = 0x37,
    wasmOpcodeF32Store           = 0x38,
    wasmOpcodeF64Store           = 0x39,
    wasmOpcodeI32Store8          = 0x3A,
    wasmOpcodeI32Store16         = 0x3B,
    wasmOpcodeI64Store8          = 0x3C,
    wasmOpcodeI64Store16         = 0x3D,
    wasmOpcodeI64Store32         = 0x3E,
    wasmOpcodeMemorySize         = 0x3F,
    wasmOpcodeMemoryGrow         = 0x40,
    wasmOpcodeI32Const           = 0x41,
    wasmOpcodeI64Const           = 0x42,
    wasmOpcodeF32Const           = 0x43,
    wasmOpcodeF64Const           = 0x44,
    wasmOpcodeI32Eqz             = 0x45,
    wasmOpcodeI32Eq              = 0x46,
    wasmOpcodeI32Ne              = 0x47,
    wasmOpcodeI32LtS             = 0x48,
    wasmOpcodeI32LtU             = 0x49,
    wasmOpcodeI32GtS             = 0x4A,
    wasmOpcodeI32GtU             = 0x4B,
    wasmOpcodeI32LeS             = 0x4C,
    wasmOpcodeI32LeU             = 0x4D,
    wasmOpcodeI32GeS             = 0x4E,
    wasmOpcodeI32GeU             = 0x4F,
    wasmOpcodeI64Eqz             = 0x50,
    wasmOpcodeI64Eq              = 0x51,
    wasmOpcodeI64Ne              = 0x52,
    wasmOpcodeI64LtS             = 0x53,
    wasmOpcodeI64LtU             = 0x54,
    wasmOpcodeI64GtS             = 0x55,
    wasmOpcodeI64GtU             = 0x56,
    wasmOpcodeI64LeS             = 0x57,
    wasmOpcodeI64LeU             = 0x58,
    wasmOpcodeI64GeS             = 0x59,
    wasmOpcodeI64GeU             = 0x5A,
    wasmOpcodeF32Eq              = 0x5B,
    wasmOpcodeF32Ne              = 0x5C,
    wasmOpcodeF32Lt              = 0x5D,
    wasmOpcodeF32Gt              = 0x5E,
    wasmOpcodeF32Le              = 0x5F,
    wasmOpcodeF32Ge              = 0x60,
    wasmOpcodeF64Eq              = 0x61,
    wasmOpcodeF64Ne              = 0x62,
    wasmOpcodeF64Lt              = 0x63,
    wasmOpcodeF64Gt              = 0x64,
    wasmOpcodeF64Le              = 0x65,
    wasmOpcodeF64Ge              = 0x66,
    wasmOpcodeI32Clz             = 0x67,
    wasmOpcodeI32Ctz             = 0x68,
    wasmOpcodeI32PopCnt          = 0x69,
    wasmOpcodeI32Add             = 0x6A,
    wasmOpcodeI32Sub             = 0x6B,
    wasmOpcodeI32Mul             = 0x6C,
    wasmOpcodeI32DivS            = 0x6D,
    wasmOpcodeI32DivU            = 0x6E,
    wasmOpcodeI32RemS            = 0x6F,
    wasmOpcodeI32RemU            = 0x70,
    wasmOpcodeI32And             = 0x71,
    wasmOpcodeI32Or              = 0x72,
    wasmOpcodeI32Xor             = 0x73,
    wasmOpcodeI32Shl             = 0x74,
    wasmOpcodeI32ShrS            = 0x75,
    wasmOpcodeI32ShrU            = 0x76,
    wasmOpcodeI32Rotl            = 0x77,
    wasmOpcodeI32Rotr            = 0x78,
    wasmOpcodeI64Clz             = 0x79,
    wasmOpcodeI64Ctz             = 0x7A,
    wasmOpcodeI64PopCnt          = 0x7B,
    wasmOpcodeI64Add             = 0x7C,
    wasmOpcodeI64Sub             = 0x7D,
    wasmOpcodeI64Mul             = 0x7E,
    wasmOpcodeI64DivS            = 0x7F,
    wasmOpcodeI64DivU            = 0x80,
    wasmOpcodeI64RemS            = 0x81,
    wasmOpcodeI64RemU            = 0x82,
    wasmOpcodeI64And             = 0x83,
    wasmOpcodeI64Or              = 0x84,
    wasmOpcodeI64Xor             = 0x85,
    wasmOpcodeI64Shl             = 0x86,
    wasmOpcodeI64ShrS            = 0x87,
    wasmOpcodeI64ShrU            = 0x88,
    wasmOpcodeI64Rotl            = 0x89,
    wasmOpcodeI64Rotr            = 0x8A,
    wasmOpcodeF32Abs             = 0x8B,
    wasmOpcodeF32Neg             = 0x8C,
    wasmOpcodeF32Ceil            = 0x8D,
    wasmOpcodeF32Floor           = 0x8E,
    wasmOpcodeF32Trunc           = 0x8F,
    wasmOpcodeF32Nearest         = 0x90,
    wasmOpcodeF32Sqrt            = 0x91,
    wasmOpcodeF32Add             = 0x92,
    wasmOpcodeF32Sub             = 0x93,
    wasmOpcodeF32Mul             = 0x94,
    wasmOpcodeF32Div             = 0x95,
    wasmOpcodeF32Min             = 0x96,
    wasmOpcodeF32Max             = 0x97,
    wasmOpcodeF32CopySign        = 0x98,
    wasmOpcodeF64Abs             = 0x99,
    wasmOpcodeF64Neg             = 0x9A,
    wasmOpcodeF64Ceil            = 0x9B,
    wasmOpcodeF64Floor           = 0x9C,
    wasmOpcodeF64Trunc           = 0x9D,
    wasmOpcodeF64Nearest         = 0x9E,
    wasmOpcodeF64Sqrt            = 0x9F,
    wasmOpcodeF64Add             = 0xA0,
    wasmOpcodeF64Sub             = 0xA1,
    wasmOpcodeF64Mul             = 0xA2,
    wasmOpcodeF64Div             = 0xA3,
    wasmOpcodeF64Min             = 0xA4,
    wasmOpcodeF64Max             = 0xA5,
    wasmOpcodeF64CopySign        = 0xA6,
    wasmOpcodeI32WrapI64         = 0xA7,
    wasmOpcodeI32TruncF32S       = 0xA8,
    wasmOpcodeI32TruncF32U       = 0xA9,
    wasmOpcodeI32TruncF64S       = 0xAA,
    wasmOpcodeI32TruncF64U       = 0xAB,
    wasmOpcodeI64ExtendI32S      = 0xAC,
    wasmOpcodeI64ExtendI32U      = 0xAD,
    wasmOpcodeI64TruncF32S       = 0xAE,
    wasmOpcodeI64TruncF32U       = 0xAF,
    wasmOpcodeI64TruncF64S       = 0xB0,
    wasmOpcodeI64TruncF64U       = 0xB1,
    wasmOpcodeF32ConvertI32S     = 0xB2,
    wasmOpcodeF32ConvertI32U     = 0xB3,
    wasmOpcodeF32ConvertI64S     = 0xB4,
    wasmOpcodeF32ConvertI64U     = 0xB5,
    wasmOpcodeF32DemoteF64       = 0xB6,
    wasmOpcodeF64ConvertI32S     = 0xB7,
    wasmOpcodeF64ConvertI32U     = 0xB8,
    wasmOpcodeF64ConvertI64S     = 0xB9,
    wasmOpcodeF64ConvertI64U     = 0xBA,
    wasmOpcodeF64PromoteF32      = 0xBB,
    wasmOpcodeI32ReinterpretF32  = 0xBC,
    wasmOpcodeI64ReinterpretF64  = 0xBD,
    wasmOpcodeF32ReinterpretI32  = 0xBE,
    wasmOpcodeF64ReinterpretI64  = 0xBF,
    wasmOpcodeI32Extend8S        = 0xC0,
    wasmOpcodeI32Extend16S       = 0xC1,
    wasmOpcodeI64Extend8S        = 0xC2,
    wasmOpcodeI64Extend16S       = 0xC3,
    wasmOpcodeI64Extend32S       = 0xC4,
    wasmOpcodeMiscPrefix         = 0xFC
} WasmOpcode;

const char*
wasmOpcodeDescription(
    WasmOpcode opcode
);

typedef enum WasmMiscOpcode {
    wasmMiscOpcodeI32TruncSatF32S    = 0,
    wasmMiscOpcodeI32TruncSatF32U    = 1,
    wasmMiscOpcodeI32TruncSatF64S    = 2,
    wasmMiscOpcodeI32TruncSatF64U    = 3,
    wasmMiscOpcodeI64TruncSatF32S    = 4,
    wasmMiscOpcodeI64TruncSatF32U    = 5,
    wasmMiscOpcodeI64TruncSatF64S    = 6,
    wasmMiscOpcodeI64TruncSatF64U    = 7,
    wasmMiscOpcodeMemoryInit         = 8,
    wasmMiscOpcodeDataDrop           = 9,
    wasmMiscOpcodeMemoryCopy         = 10,
    wasmMiscOpcodeMemoryFill         = 11,
    wasmMiscOpcodeTableInit          = 12,
    wasmMiscOpcodeElemDrop           = 13,
    wasmMiscOpcodeTableCopy          = 14,
    wasmMiscOpcodeTableGrow          = 15,
    wasmMiscOpcodeTableSize          = 16,
    wasmMiscOpcodeTableFill          = 17
} WasmMiscOpcode;

const char*
wasmMiscOpcodeDescription(
    WasmMiscOpcode miscOpcode
);

WasmValueType
wasmOpcodeResultType(
    WasmOpcode opcode
);

WasmValueType
wasmOpcodeParameter1Type(
    WasmOpcode opcode
);

static
W2C2_INLINE
bool
WARN_UNUSED_RESULT
wasmOpcodeRead(
    Buffer* buffer,
    WasmOpcode* result
) {
    U8 byte = 0;
    MUST (bufferReadByte(buffer, &byte))

    *result = (WasmOpcode) byte;

    return true;
}

#endif /* W2C2_OPCODE_H */
