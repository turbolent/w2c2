#include "test.h"
#include "test_data.1.h"

void test(void) {
    static m6_dataX2E1Instance instance;
    m6_dataX2E1Instantiate(&instance, resolveTestImports);
    printStart("data.1.wasm");
    m6_dataX2E1FreeInstance(&instance);
}
