#include "test.h"
#include "test_bulk.6.h"

void test(void) {
    static m6_bulkX2E6Instance instance;
    m6_bulkX2E6Instantiate(&instance, resolveTestImports);
    printStart("bulk.6.wasm");
    m6_bulkX2E6FreeInstance(&instance);
}
