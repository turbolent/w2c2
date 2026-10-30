#include "test.h"
#include "test_table.3.h"

void test(void) {
    static m7_tableX2E3Instance instance;
    m7_tableX2E3Instantiate(&instance, resolveTestImports);
    printStart("table.3.wasm");
    m7_tableX2E3FreeInstance(&instance);
}
