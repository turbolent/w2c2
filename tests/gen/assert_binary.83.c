#include "test.h"
#include "test_binary.83.h"

void test(void) {
    static m9_binaryX2E83Instance instance;
    m9_binaryX2E83Instantiate(&instance, resolveTestImports);
    printStart("binary.83.wasm");
    m9_binaryX2E83FreeInstance(&instance);
}
