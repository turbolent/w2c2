#include "test.h"
#include "test_table_get.6.h"

void test(void) {
    static m11_tableX5FgetX2E6Instance instance;
    m11_tableX5FgetX2E6Instantiate(&instance, resolveTestImports);
    printStart("table_get.6.wasm");
    assertEqualU32((m11_tableX5FgetX2E6Export5_first(&instance)).func == NULL, 1u, "first()");
    assertEqualU32((m11_tableX5FgetX2E6Export3_get(&instance, 0u)).func == NULL, 1u, "get(0u)");
    assertEqualU32((m11_tableX5FgetX2E6Export3_get(&instance, 1u)).func != NULL, 1u, "get(1u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_tableX5FgetX2E6Export3_get(&instance, 2u), trapTableOutOfBounds, "get(2u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_tableX5FgetX2E6Export3_get(&instance, 4294967295u), trapTableOutOfBounds, "get(4294967295u)");
#endif
    m11_tableX5FgetX2E6FreeInstance(&instance);
}
