#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "runtime_division_test.h"

/* Keep trap capture local to this copy of the runtime helpers. */
#define trap divisionTestTrap
#include "w2c2_base.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testRuntimeDivision: line %d: %s\n", __LINE__, #condition); \
            exit(1); \
        } \
    } while (0)

static jmp_buf divisionTrap;
static bool expectTrap;
static Trap actualTrap;

void divisionTestTrap(Trap reason) {
    CHECK(expectTrap);
    actualTrap = reason;
    longjmp(divisionTrap, 1);
}

#define CHECK_TRAP(expression, reason) \
    do { \
        expectTrap = true; \
        if (setjmp(divisionTrap) == 0) { \
            (void)(expression); \
            CHECK(false); \
        } \
        expectTrap = false; \
        CHECK(actualTrap == (reason)); \
    } while (0)

/* GCC warns about TRAP's unreachable int-to-unsigned conversion. */
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Wsign-conversion"
#endif

void testRuntimeDivision(void) {
    volatile U32 zero32 = 0;
    volatile U64 zero64 = 0;
    volatile I32 minusOne32 = -1;
    volatile I64 minusOne64 = -1;

    CHECK_TRAP(DIV_U((U32)9, zero32), trapDivByZero);
    CHECK_TRAP(REM_U((U32)9, zero32), trapDivByZero);
    CHECK_TRAP(DIV_U((U64)9, zero64), trapDivByZero);
    CHECK_TRAP(REM_U((U64)9, zero64), trapDivByZero);

    CHECK(DIV_U((U32)9, (U32)2) == 4);
    CHECK(REM_U((U32)9, (U32)2) == 1);
    CHECK(DIV_U(UINT32_MAX, (U32)2) == (U32)INT32_MAX);
    CHECK(REM_U(UINT32_MAX, (U32)2) == 1);
    CHECK(DIV_U((U64)9, (U64)2) == 4);
    CHECK(REM_U((U64)9, (U64)2) == 1);
    CHECK(DIV_U(UINT64_MAX, (U64)2) == (U64)INT64_MAX);
    CHECK(REM_U(UINT64_MAX, (U64)2) == 1);

    CHECK_TRAP(I32_DIV_S(9, zero32), trapDivByZero);
    CHECK_TRAP(I32_REM_S(9, zero32), trapDivByZero);
    CHECK_TRAP(I64_DIV_S(9, zero64), trapDivByZero);
    CHECK_TRAP(I64_REM_S(9, zero64), trapDivByZero);
    CHECK_TRAP(I32_DIV_S(INT32_MIN, minusOne32), trapIntOverflow);
    CHECK_TRAP(I64_DIV_S(INT64_MIN, minusOne64), trapIntOverflow);
    CHECK(I32_REM_S(INT32_MIN, minusOne32) == 0);
    CHECK(I64_REM_S(INT64_MIN, minusOne64) == 0);
    CHECK(I32_DIV_S(-9, 2) == (U32)-4);
    CHECK(I32_REM_S(-9, 2) == (U32)-1);
    CHECK(I64_DIV_S(-9, 2) == (U64)-4);
    CHECK(I64_REM_S(-9, 2) == (U64)-1);

    fprintf(stderr, "PASS testRuntimeDivision\n");
}
