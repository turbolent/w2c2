#include "test.h"
#include "test_table.0.h"

void test(void) {
    static m7_tableX2E0Instance instance;
    m7_tableX2E0Instantiate(&instance, resolveTestImports);
    printStart("table.0.wasm");
    m7_tableX2E0FreeInstance(&instance);
}
