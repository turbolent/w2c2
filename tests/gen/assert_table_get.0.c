#include "test.h"
#include "test_table_get.0.h"

void test(void) {
    static m11_tableX5FgetX2E0Instance instance;
    m11_tableX5FgetX2E0Instantiate(&instance, resolveTestImports);
    printStart("table_get.0.wasm");
    assertEqualU32((m11_tableX5FgetX2E0Export5_first(&instance)).func == NULL, 1u, "first()");
    assertEqualU32((m11_tableX5FgetX2E0Export3_get(&instance, 0u)).func == NULL, 1u, "get(0u)");
    assertEqualU32((m11_tableX5FgetX2E0Export3_get(&instance, 1u)).func != NULL, 1u, "get(1u)");
    m11_tableX5FgetX2E0FreeInstance(&instance);
}
