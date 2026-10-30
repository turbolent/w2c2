#include "test.h"
#include "test_binary.70.h"

void test(void) {
    static m9_binaryX2E70Instance instance;
    m9_binaryX2E70Instantiate(&instance, resolveTestImports);
    printStart("binary.70.wasm");
    m9_binaryX2E70FreeInstance(&instance);
}
