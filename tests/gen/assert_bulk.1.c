#include "test.h"
#include "test_bulk.1.h"

void test(void) {
    static m6_bulkX2E1Instance instance;
    m6_bulkX2E1Instantiate(&instance, resolveTestImports);
    printStart("bulk.1.wasm");
    m6_bulkX2E1FreeInstance(&instance);
}
