#include "test.h"
#include "test_data.24.h"

void test(void) {
    static m7_dataX2E24Instance instance;
    m7_dataX2E24Instantiate(&instance, resolveTestImports);
    printStart("data.24.wasm");
    m7_dataX2E24FreeInstance(&instance);
}
