#include "test.h"
#include "test_traps.2.h"

void test(void) {
    static m7_trapsX2E2Instance instance;
    m7_trapsX2E2Instantiate(&instance, resolveTestImports);
    printStart("traps.2.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E2Export22_noX5FdceX2Ei32X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fc00000u)), trapInvalidConversion, "no_dce.i32.trunc_f32_s(f32_reinterpret_i32(0x7fc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E2Export22_noX5FdceX2Ei32X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fc00000u)), trapInvalidConversion, "no_dce.i32.trunc_f32_u(f32_reinterpret_i32(0x7fc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E2Export22_noX5FdceX2Ei32X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)), trapInvalidConversion, "no_dce.i32.trunc_f64_s(f64_reinterpret_i64(0x7ff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E2Export22_noX5FdceX2Ei32X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)), trapInvalidConversion, "no_dce.i32.trunc_f64_u(f64_reinterpret_i64(0x7ff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E2Export22_noX5FdceX2Ei64X2EtruncX5Ff32X5Fs(&instance, f32_reinterpret_i32(0x7fc00000u)), trapInvalidConversion, "no_dce.i64.trunc_f32_s(f32_reinterpret_i32(0x7fc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E2Export22_noX5FdceX2Ei64X2EtruncX5Ff32X5Fu(&instance, f32_reinterpret_i32(0x7fc00000u)), trapInvalidConversion, "no_dce.i64.trunc_f32_u(f32_reinterpret_i32(0x7fc00000u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E2Export22_noX5FdceX2Ei64X2EtruncX5Ff64X5Fs(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)), trapInvalidConversion, "no_dce.i64.trunc_f64_s(f64_reinterpret_i64(0x7ff8000000000000ull))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E2Export22_noX5FdceX2Ei64X2EtruncX5Ff64X5Fu(&instance, f64_reinterpret_i64(0x7ff8000000000000ull)), trapInvalidConversion, "no_dce.i64.trunc_f64_u(f64_reinterpret_i64(0x7ff8000000000000ull))");
#endif
    m7_trapsX2E2FreeInstance(&instance);
}
