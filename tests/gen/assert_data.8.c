#include "test.h"
#include "test_data.8.h"

void test(void) {
    static m6_dataX2E8Instance instance;
    m6_dataX2E8Instantiate(&instance, resolveTestImports);
    printStart("data.8.wasm");
    m6_dataX2E8FreeInstance(&instance);
}
