#include "test.h"
#include "test_data.25.h"

void test(void) {
    static m7_dataX2E25Instance instance;
    m7_dataX2E25Instantiate(&instance, resolveTestImports);
    printStart("data.25.wasm");
    m7_dataX2E25FreeInstance(&instance);
}
