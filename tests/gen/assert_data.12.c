#include "test.h"
#include "test_data.12.h"

void test(void) {
    static m7_dataX2E12Instance instance;
    m7_dataX2E12Instantiate(&instance, resolveTestImports);
    printStart("data.12.wasm");
    m7_dataX2E12FreeInstance(&instance);
}
