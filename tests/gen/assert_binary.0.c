#include "test.h"
#include "test_binary.0.h"

void test(void) {
    static m8_binaryX2E0Instance instance;
    m8_binaryX2E0Instantiate(&instance, resolveTestImports);
    printStart("binary.0.wasm");
    m8_binaryX2E0FreeInstance(&instance);
}
