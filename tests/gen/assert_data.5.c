#include "test.h"
#include "test_data.5.h"

void test(void) {
    static m6_dataX2E5Instance instance;
    m6_dataX2E5Instantiate(&instance, resolveTestImports);
    printStart("data.5.wasm");
    m6_dataX2E5FreeInstance(&instance);
}
