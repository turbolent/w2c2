#include "test.h"
#include "test_table.1.h"

void test(void) {
    static m7_tableX2E1Instance instance;
    m7_tableX2E1Instantiate(&instance, resolveTestImports);
    printStart("table.1.wasm");
    m7_tableX2E1FreeInstance(&instance);
}
