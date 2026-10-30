#include "test.h"
#include "test_data.15.h"

void test(void) {
    static m7_dataX2E15Instance instance;
    m7_dataX2E15Instantiate(&instance, resolveTestImports);
    printStart("data.15.wasm");
    m7_dataX2E15FreeInstance(&instance);
}
