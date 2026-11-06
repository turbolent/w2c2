#include "test.h"
#include "test_traps.1.h"

void test(void) {
    static m7_trapsX2E1Instance instance;
    m7_trapsX2E1Instantiate(&instance, resolveTestImports);
    printStart("traps.1.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E1Export16_noX5FdceX2Ei32X2EremX5Fs(&instance, 1u, 0u), trapDivByZero, "no_dce.i32.rem_s(1u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E1Export16_noX5FdceX2Ei32X2EremX5Fu(&instance, 1u, 0u), trapDivByZero, "no_dce.i32.rem_u(1u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E1Export16_noX5FdceX2Ei64X2EremX5Fs(&instance, 1ull, 0ull), trapDivByZero, "no_dce.i64.rem_s(1ull, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E1Export16_noX5FdceX2Ei64X2EremX5Fu(&instance, 1ull, 0ull), trapDivByZero, "no_dce.i64.rem_u(1ull, 0ull)");
#endif
    m7_trapsX2E1FreeInstance(&instance);
}
