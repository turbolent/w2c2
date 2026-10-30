#include "test.h"
#include "test_bulk.11.h"

void test(void) {
    static m7_bulkX2E11Instance instance;
    m7_bulkX2E11Instantiate(&instance, resolveTestImports);
    printStart("bulk.11.wasm");
    m7_bulkX2E11FreeInstance(&instance);
}
