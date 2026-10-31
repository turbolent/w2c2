#include "test.h"
#include "test_table.18.h"

void test(void) {
    static m8_tableX2E18Instance instance;
    m8_tableX2E18Instantiate(&instance, resolveTestImports);
    printStart("table.18.wasm");
    assertEqualU32((m8_tableX2E18Export4_get1(&instance)).func == NULL, 1u, "get1()");
    m8_tableX2E18FreeInstance(&instance);
}
