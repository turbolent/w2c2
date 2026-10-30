#include "test.h"
#include "test_binary.88.h"

void test(void) {
    static m9_binaryX2E88Instance instance;
    m9_binaryX2E88Instantiate(&instance, resolveTestImports);
    printStart("binary.88.wasm");
    m9_binaryX2E88FreeInstance(&instance);
}
