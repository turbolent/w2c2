#include "test.h"
#include "test_data.20.h"

void test(void) {
    static m7_dataX2E20Instance instance;
    m7_dataX2E20Instantiate(&instance, resolveTestImports);
    printStart("data.20.wasm");
    m7_dataX2E20FreeInstance(&instance);
}
