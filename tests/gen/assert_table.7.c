#include "test.h"
#include "test_table.7.h"

void test(void) {
    static m7_tableX2E7Instance instance;
    m7_tableX2E7Instantiate(&instance, resolveTestImports);
    printStart("table.7.wasm");
    m7_tableX2E7FreeInstance(&instance);
}
