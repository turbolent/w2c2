#include "test.h"
#include "test_data.23.h"

void test(void) {
    static m7_dataX2E23Instance instance;
    m7_dataX2E23Instantiate(&instance, resolveTestImports);
    printStart("data.23.wasm");
    m7_dataX2E23FreeInstance(&instance);
}
