#include "test.h"
#include "test_data.30.h"

void test(void) {
    static m7_dataX2E30Instance instance;
    m7_dataX2E30Instantiate(&instance, resolveTestImports);
    printStart("data.30.wasm");
    m7_dataX2E30FreeInstance(&instance);
}
