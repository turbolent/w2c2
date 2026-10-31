#include "test.h"
#include "test_table.5.h"

void test(void) {
    static m7_tableX2E5Instance instance;
    m7_tableX2E5Instantiate(&instance, resolveTestImports);
    printStart("table.5.wasm");
    m7_tableX2E5FreeInstance(&instance);
}
