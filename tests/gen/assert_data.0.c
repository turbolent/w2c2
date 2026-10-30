#include "test.h"
#include "test_data.0.h"

void test(void) {
    static m6_dataX2E0Instance instance;
    m6_dataX2E0Instantiate(&instance, resolveTestImports);
    printStart("data.0.wasm");
    m6_dataX2E0FreeInstance(&instance);
}
