#include "test.h"
#include "test_traps_regression.0.h"

void test(void) {
    static m18_trapsX5FregressionX2E0Instance instance;
    m18_trapsX5FregressionX2E0Instantiate(&instance, resolveTestImports);
    printStart("traps_regression.0.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E0Export8_i32X2Eload(&instance), trapMemoryOutOfBounds, "i32.load()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E0Export8_i64X2Eload(&instance), trapMemoryOutOfBounds, "i64.load()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E0Export8_f32X2Eload(&instance), trapMemoryOutOfBounds, "f32.load()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E0Export8_f64X2Eload(&instance), trapMemoryOutOfBounds, "f64.load()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E0Export11_i32X2Eload8X5Fs(&instance), trapMemoryOutOfBounds, "i32.load8_s()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E0Export12_i64X2Eload16X5Fu(&instance), trapMemoryOutOfBounds, "i64.load16_u()");
#endif
    m18_trapsX5FregressionX2E0FreeInstance(&instance);
}
