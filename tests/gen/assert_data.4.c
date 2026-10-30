#include "test.h"
#include "test_data.4.h"

void test(void) {
    static m6_dataX2E4Instance instance;
    m6_dataX2E4Instantiate(&instance, resolveTestImports);
    printStart("data.4.wasm");
    m6_dataX2E4FreeInstance(&instance);
}
