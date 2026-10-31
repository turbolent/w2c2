#include "test.h"
#include "test_binary.71.h"

void test(void) {
    static m9_binaryX2E71Instance instance;
    m9_binaryX2E71Instantiate(&instance, resolveTestImports);
    printStart("binary.71.wasm");
    m9_binaryX2E71FreeInstance(&instance);
}
