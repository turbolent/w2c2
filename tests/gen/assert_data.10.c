#include "test.h"
#include "test_data.10.h"

void test(void) {
    static m7_dataX2E10Instance instance;
    m7_dataX2E10Instantiate(&instance, resolveTestImports);
    printStart("data.10.wasm");
    m7_dataX2E10FreeInstance(&instance);
}
