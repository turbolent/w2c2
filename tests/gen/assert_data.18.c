#include "test.h"
#include "test_data.18.h"

void test(void) {
    static m7_dataX2E18Instance instance;
    m7_dataX2E18Instantiate(&instance, resolveTestImports);
    printStart("data.18.wasm");
    m7_dataX2E18FreeInstance(&instance);
}
