#include "test.h"
#include "test_data.2.h"

void test(void) {
    static m6_dataX2E2Instance instance;
    m6_dataX2E2Instantiate(&instance, resolveTestImports);
    printStart("data.2.wasm");
    m6_dataX2E2FreeInstance(&instance);
}
