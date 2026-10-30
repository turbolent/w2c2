#include "test.h"
#include "test_bulk.7.h"

void test(void) {
    static m6_bulkX2E7Instance instance;
    m6_bulkX2E7Instantiate(&instance, resolveTestImports);
    printStart("bulk.7.wasm");
    m6_bulkX2E7FreeInstance(&instance);
}
