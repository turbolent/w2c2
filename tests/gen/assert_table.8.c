#include "test.h"
#include "test_table.8.h"

void test(void) {
    static m7_tableX2E8Instance instance;
    m7_tableX2E8Instantiate(&instance, resolveTestImports);
    printStart("table.8.wasm");
    m7_tableX2E8FreeInstance(&instance);
}
