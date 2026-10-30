#include "test.h"
#include "test_data.22.h"

void test(void) {
    static m7_dataX2E22Instance instance;
    m7_dataX2E22Instantiate(&instance, resolveTestImports);
    printStart("data.22.wasm");
    m7_dataX2E22FreeInstance(&instance);
}
