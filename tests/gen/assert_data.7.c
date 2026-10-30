#include "test.h"
#include "test_data.7.h"

void test(void) {
    static m6_dataX2E7Instance instance;
    m6_dataX2E7Instantiate(&instance, resolveTestImports);
    printStart("data.7.wasm");
    m6_dataX2E7FreeInstance(&instance);
}
