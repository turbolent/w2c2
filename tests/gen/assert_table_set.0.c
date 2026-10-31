#include "test.h"
#include "test_table_set.0.h"

void test(void) {
    static m11_tableX5FsetX2E0Instance instance;
    m11_tableX5FsetX2E0Instantiate(&instance, resolveTestImports);
    printStart("table_set.0.wasm");
    assertEqualU32((m11_tableX5FsetX2E0Export3_get(&instance, 0u)).func == NULL, 1u, "get(0u)");
    (void)(m11_tableX5FsetX2E0Export3_set(&instance, 0u));
    assertEqualU32((m11_tableX5FsetX2E0Export3_get(&instance, 0u)).func != NULL, 1u, "get(0u)");
    (void)(m11_tableX5FsetX2E0Export5_clear(&instance, 0u, wasmNullFuncRef));
    assertEqualU32((m11_tableX5FsetX2E0Export3_get(&instance, 0u)).func == NULL, 1u, "get(0u)");
    m11_tableX5FsetX2E0FreeInstance(&instance);
}
