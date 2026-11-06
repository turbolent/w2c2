#include "test.h"
#include "test_table_set.8.h"

void test(void) {
    static m11_tableX5FsetX2E8Instance instance;
    m11_tableX5FsetX2E8Instantiate(&instance, resolveTestImports);
    printStart("table_set.8.wasm");
    assertEqualU32((m11_tableX5FsetX2E8Export3_get(&instance, 0u)).func == NULL, 1u, "get(0u)");
    (void)(m11_tableX5FsetX2E8Export3_set(&instance, 0u));
    assertEqualU32((m11_tableX5FsetX2E8Export3_get(&instance, 0u)).func != NULL, 1u, "get(0u)");
    (void)(m11_tableX5FsetX2E8Export5_clear(&instance, 0u, wasmNullFuncRef));
    assertEqualU32((m11_tableX5FsetX2E8Export3_get(&instance, 0u)).func == NULL, 1u, "get(0u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_tableX5FsetX2E8Export3_set(&instance, 2u), trapTableOutOfBounds, "set(2u)");
#endif
    m11_tableX5FsetX2E8FreeInstance(&instance);
}
