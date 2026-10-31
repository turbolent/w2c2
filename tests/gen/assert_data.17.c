#include "test.h"
#include "test_data.17.h"

void test(void) {
    static m7_dataX2E17Instance instance;
    m7_dataX2E17Instantiate(&instance, resolveTestImports);
    printStart("data.17.wasm");
    m7_dataX2E17FreeInstance(&instance);
}
