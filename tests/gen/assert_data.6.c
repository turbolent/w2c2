#include "test.h"
#include "test_data.6.h"

void test(void) {
    static m6_dataX2E6Instance instance;
    m6_dataX2E6Instantiate(&instance, resolveTestImports);
    printStart("data.6.wasm");
    m6_dataX2E6FreeInstance(&instance);
}
