#include "test.h"
#include "test_data.3.h"

void test(void) {
    static m6_dataX2E3Instance instance;
    m6_dataX2E3Instantiate(&instance, resolveTestImports);
    printStart("data.3.wasm");
    m6_dataX2E3FreeInstance(&instance);
}
