#include "test.h"
#include "test_bulk.0.h"

void test(void) {
    static m6_bulkX2E0Instance instance;
    m6_bulkX2E0Instantiate(&instance, resolveTestImports);
    printStart("bulk.0.wasm");
    m6_bulkX2E0FreeInstance(&instance);
}
