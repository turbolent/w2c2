#include "valuetype.h"

const char*
wasmValueTypeDescription(
    const WasmValueType valueType
) {
    switch (valueType) {
        case wasmValueTypeI32:
            return "i32";
        case wasmValueTypeI64:
            return "i64";
        case wasmValueTypeF32:
            return "f32";
        case wasmValueTypeF64:
            return "f64";
        default:
            return "unknown";
    }
}
