#include "test.h"
#include "test_data.11.h"

void test(void) {
    static m7_dataX2E11Instance instance;
    m7_dataX2E11Instantiate(&instance, resolveTestImports);
    printStart("data.11.wasm");
    m7_dataX2E11FreeInstance(&instance);
}
