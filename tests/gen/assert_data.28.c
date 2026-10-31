#include "test.h"
#include "test_data.28.h"

void test(void) {
    static m7_dataX2E28Instance instance;
    m7_dataX2E28Instantiate(&instance, resolveTestImports);
    printStart("data.28.wasm");
    m7_dataX2E28FreeInstance(&instance);
}
