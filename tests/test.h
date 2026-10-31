#ifndef W2C2_TEST_H
#define W2C2_TEST_H

#include <setjmp.h>
#include "w2c2_base.h"

#ifdef W2C2_SIMDE_HEADER
#include "w2c2_simd.h"

void
assertEqualV128(
    V128 actual,
    const U8* expected,
    const U8* masks,
    const char* description
);
#endif

extern jmp_buf testTrapTarget;
extern int testTrapExpected;

#define assertTrap(expression, description) do { \
    testTrapExpected = 1; \
    if (setjmp(testTrapTarget) == 0) { \
        (void)(expression); \
        printFail(description); \
    } else { \
        printOK(description); \
    } \
    testTrapExpected = 0; \
} while (0)

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

void
printFail(
    const char* description
);

void
bindTestImport(
    const char* module,
    const char* name,
    void* value
);

wasmExternRef
testExternRef(
    U32 id
);

void*
resolveTestImports(
    WasmName module,
    WasmName name
);

#endif
