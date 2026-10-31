#include "test.h"
#include "test_table.4.h"

void test(void) {
    static m7_tableX2E4Instance instance;
    m7_tableX2E4Instantiate(&instance, resolveTestImports);
    printStart("table.4.wasm");
    m7_tableX2E4FreeInstance(&instance);
}
