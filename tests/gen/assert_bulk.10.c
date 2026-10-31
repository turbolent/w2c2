#include "test.h"
#include "test_bulk.10.h"

void test(void) {
    static m7_bulkX2E10Instance instance;
    m7_bulkX2E10Instantiate(&instance, resolveTestImports);
    printStart("bulk.10.wasm");
    m7_bulkX2E10FreeInstance(&instance);
}
