#include "test.h"
#include "test_data.21.h"

void test(void) {
    static m7_dataX2E21Instance instance;
    m7_dataX2E21Instantiate(&instance, resolveTestImports);
    printStart("data.21.wasm");
    m7_dataX2E21FreeInstance(&instance);
}
