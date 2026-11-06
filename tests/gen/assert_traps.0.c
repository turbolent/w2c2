#include "test.h"
#include "test_traps.0.h"

void test(void) {
    static m7_trapsX2E0Instance instance;
    m7_trapsX2E0Instantiate(&instance, resolveTestImports);
    printStart("traps.0.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E0Export16_noX5FdceX2Ei32X2EdivX5Fs(&instance, 1u, 0u), trapDivByZero, "no_dce.i32.div_s(1u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E0Export16_noX5FdceX2Ei32X2EdivX5Fu(&instance, 1u, 0u), trapDivByZero, "no_dce.i32.div_u(1u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E0Export16_noX5FdceX2Ei64X2EdivX5Fs(&instance, 1ull, 0ull), trapDivByZero, "no_dce.i64.div_s(1ull, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E0Export16_noX5FdceX2Ei64X2EdivX5Fu(&instance, 1ull, 0ull), trapDivByZero, "no_dce.i64.div_u(1ull, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E0Export16_noX5FdceX2Ei32X2EdivX5Fs(&instance, 2147483648u, 4294967295u), trapIntOverflow, "no_dce.i32.div_s(2147483648u, 4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E0Export16_noX5FdceX2Ei64X2EdivX5Fs(&instance, 9223372036854775808ull, 18446744073709551615ull), trapIntOverflow, "no_dce.i64.div_s(9223372036854775808ull, 18446744073709551615ull)");
#endif
    m7_trapsX2E0FreeInstance(&instance);
}
