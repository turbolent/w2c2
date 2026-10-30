#include "test.h"
#include "test_binary.74.h"

void test(void) {
    static m9_binaryX2E74Instance instance;
    m9_binaryX2E74Instantiate(&instance, resolveTestImports);
    printStart("binary.74.wasm");
    m9_binaryX2E74FreeInstance(&instance);
}
