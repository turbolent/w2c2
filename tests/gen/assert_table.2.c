#include "test.h"
#include "test_table.2.h"

void test(void) {
    static m7_tableX2E2Instance instance;
    m7_tableX2E2Instantiate(&instance, resolveTestImports);
    printStart("table.2.wasm");
    m7_tableX2E2FreeInstance(&instance);
}
