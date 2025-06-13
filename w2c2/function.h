#ifndef W2C2_FUNCTION_H
#define W2C2_FUNCTION_H

#include "w2c2_base.h"
#include "buffer.h"
#include "locals.h"
#include "array.h"
#include "sha1.h"

typedef struct WasmFunction {
    U32 functionTypeIndex;
    WasmLocalsDeclarations localsDeclarations;
    Buffer code;
    /* Offset relative to the code section start (function count) */
    size_t start;
    /* Hash of the locals (as declared in the binary) and the code */
    unsigned char hash[SHA1_DIGEST_LENGTH];
    char *exportName;
} WasmFunction;

static const WasmFunction wasmEmptyFunction =
    {0, {NULL, 0}, {NULL, 0}, 0, SHA1_DIGEST_EMPTY, NULL};

typedef struct WasmFunctionID {
    /* Hash of the locals (as declared in the binary) and the code */
    unsigned char hash[SHA1_DIGEST_LENGTH];
    U32 functionIndex;
} WasmFunctionID;

static const WasmFunctionID emptyWasmFunctionID = {SHA1_DIGEST_EMPTY, 0};

ARRAY_TYPE(
    WasmFunctionIDs,
    WasmFunctionID,
    wasmFunctionIDs,
    functionIDs,
    functionID
)

static const WasmFunctionIDs emptyWasmFunctionIDs = {0, 0, NULL};

#endif /* W2C2_FUNCTION_H */
