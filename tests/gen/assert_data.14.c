#include "test.h"
#include "test_data.14.h"

void test(void) {
    static m7_dataX2E14Instance instance;
    m7_dataX2E14Instantiate(&instance, resolveTestImports);
    printStart("data.14.wasm");
    m7_dataX2E14FreeInstance(&instance);
}
