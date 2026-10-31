#include "test.h"
#include "test_data.9.h"

void test(void) {
    static m6_dataX2E9Instance instance;
    m6_dataX2E9Instantiate(&instance, resolveTestImports);
    printStart("data.9.wasm");
    m6_dataX2E9FreeInstance(&instance);
}
