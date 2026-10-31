#include "test.h"
#include "test_table_get.6.h"

void test(void) {
    static m11_tableX5FgetX2E6Instance instance;
    m11_tableX5FgetX2E6Instantiate(&instance, resolveTestImports);
    printStart("table_get.6.wasm");
    assertEqualU32((m11_tableX5FgetX2E6Export5_first(&instance)).func == NULL, 1u, "first()");
    assertEqualU32((m11_tableX5FgetX2E6Export3_get(&instance, 0u)).func == NULL, 1u, "get(0u)");
    assertEqualU32((m11_tableX5FgetX2E6Export3_get(&instance, 1u)).func != NULL, 1u, "get(1u)");
    m11_tableX5FgetX2E6FreeInstance(&instance);
}
