#include "test.h"
#include "test_data.26.h"

void test(void) {
    static m7_dataX2E26Instance instance;
    m7_dataX2E26Instantiate(&instance, resolveTestImports);
    printStart("data.26.wasm");
    m7_dataX2E26FreeInstance(&instance);
}
