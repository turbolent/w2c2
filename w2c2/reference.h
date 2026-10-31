#ifndef W2C2_REFERENCE_H
#define W2C2_REFERENCE_H

#include "valuetype.h"

/* ref.null carries a type; ref.func and global.get carry an index. */
typedef union WasmReferenceImmediate {
    WasmValueType type;
    U32 index;
} WasmReferenceImmediate;

#endif /* W2C2_REFERENCE_H */
