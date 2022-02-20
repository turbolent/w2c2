#include "w2c2_base.h"

extern U32 *g_spectest_globalX5Fi32;
extern U64 *g_spectest_globalX5Fi64;
extern void (*f_spectest_print)(void);
extern void (*f_spectest_printX5Fi32)(U32 l0);

extern wasmTable* t_spectest_table;
extern wasmMemory* m_spectest_memory;

void assertEqualU32(
    U32 actual,
    U32 expected,
    const char* description
);

void assertEqualU64(
    U64 actual,
    U64 expected,
    const char* description
);

void assertEqualF32(
    F32 actual,
    F32 expected,
    const char* description
);

void assertEqualF64(
    F64 actual,
    F64 expected,
    const char *description
);

void printStart(const char* name);

void printOK(const char* description);
