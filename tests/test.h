#include "w2c2_base.h"

void
assertEqualU32(
    U32 actual,
    U32 expected,
    const char* description
);

void
assertEqualU64(
    U64 actual,
    U64 expected,
    const char* description
);

void
printStart(
    const char* name
);

void
printOK(
    const char* description
);

void*
resolveTestImports(
    WasmName module,
    WasmName name
);
