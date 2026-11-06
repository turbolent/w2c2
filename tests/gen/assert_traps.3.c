#include "test.h"
#include "test_traps.3.h"

void test(void) {
    static m7_trapsX2E3Instance instance;
    m7_trapsX2E3Instantiate(&instance, resolveTestImports);
    printStart("traps.3.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export15_noX5FdceX2Ei32X2Eload(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i32.load(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export19_noX5FdceX2Ei32X2Eload16X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i32.load16_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export19_noX5FdceX2Ei32X2Eload16X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i32.load16_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export18_noX5FdceX2Ei32X2Eload8X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i32.load8_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export18_noX5FdceX2Ei32X2Eload8X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i32.load8_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export15_noX5FdceX2Ei64X2Eload(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i64.load(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export19_noX5FdceX2Ei64X2Eload32X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i64.load32_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export19_noX5FdceX2Ei64X2Eload32X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i64.load32_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export19_noX5FdceX2Ei64X2Eload16X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i64.load16_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export19_noX5FdceX2Ei64X2Eload16X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i64.load16_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export18_noX5FdceX2Ei64X2Eload8X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i64.load8_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export18_noX5FdceX2Ei64X2Eload8X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.i64.load8_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export15_noX5FdceX2Ef32X2Eload(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.f32.load(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m7_trapsX2E3Export15_noX5FdceX2Ef64X2Eload(&instance, 65536u), trapMemoryOutOfBounds, "no_dce.f64.load(65536u)");
#endif
    m7_trapsX2E3FreeInstance(&instance);
}
