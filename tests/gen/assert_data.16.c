#include "test.h"
#include "test_data.16.h"

void test(void) {
    static m7_dataX2E16Instance instance;
    m7_dataX2E16Instantiate(&instance, resolveTestImports);
    printStart("data.16.wasm");
    m7_dataX2E16FreeInstance(&instance);
}
