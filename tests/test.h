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
assertEqualF32(
    F32 actual,
    F32 expected,
    const char* description
);

void
assertEqualF64(
    F64 actual,
    F64 expected,
    const char *description
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
    const char* module,
    const char* name
);