#include "test.h"
#include "test_traps_regression.2.h"

void test(void) {
    static m18_trapsX5FregressionX2E2Instance instance;
    m18_trapsX5FregressionX2E2Instantiate(&instance, resolveTestImports);
    printStart("traps_regression.2.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E2Export6_notify(&instance, 0u), trapMemoryOutOfBounds, "notify(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E2Export6_wait32(&instance), trapMemoryOutOfBounds, "wait32()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E2Export6_wait64(&instance), trapMemoryOutOfBounds, "wait64()");
#endif
    assertEqualU32(
        m18_trapsX5FregressionX2E2Export4_grow(&instance),
        0u,
        "grow()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E2Export6_notify(&instance, 1u), trapUnalignedAtomic, "notify(1u)");
#endif
    m18_trapsX5FregressionX2E2FreeInstance(&instance);
}
