#include "test.h"
#include "test_data.19.h"

void test(void) {
    static m7_dataX2E19Instance instance;
    m7_dataX2E19Instantiate(&instance, resolveTestImports);
    printStart("data.19.wasm");
    m7_dataX2E19FreeInstance(&instance);
}
