#include "test.h"
#include "test_binary.61.h"

void test(void) {
    static m9_binaryX2E61Instance instance;
    m9_binaryX2E61Instantiate(&instance, resolveTestImports);
    printStart("binary.61.wasm");
    m9_binaryX2E61FreeInstance(&instance);
}
