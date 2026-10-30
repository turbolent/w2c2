#include "test.h"
#include "test_table.6.h"

void test(void) {
    static m7_tableX2E6Instance instance;
    m7_tableX2E6Instantiate(&instance, resolveTestImports);
    printStart("table.6.wasm");
    m7_tableX2E6FreeInstance(&instance);
}
