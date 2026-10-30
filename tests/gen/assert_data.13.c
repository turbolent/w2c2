#include "test.h"
#include "test_data.13.h"

void test(void) {
    static m7_dataX2E13Instance instance;
    m7_dataX2E13Instantiate(&instance, resolveTestImports);
    printStart("data.13.wasm");
    m7_dataX2E13FreeInstance(&instance);
}
