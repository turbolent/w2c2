#include "test.h"
#include "test_data.27.h"

void test(void) {
    static m7_dataX2E27Instance instance;
    m7_dataX2E27Instantiate(&instance, resolveTestImports);
    printStart("data.27.wasm");
    m7_dataX2E27FreeInstance(&instance);
}
