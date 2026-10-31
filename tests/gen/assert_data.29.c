#include "test.h"
#include "test_data.29.h"

void test(void) {
    static m7_dataX2E29Instance instance;
    m7_dataX2E29Instantiate(&instance, resolveTestImports);
    printStart("data.29.wasm");
    m7_dataX2E29FreeInstance(&instance);
}
