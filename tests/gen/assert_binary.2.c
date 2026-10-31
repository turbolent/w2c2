#include "test.h"
#include "test_binary.2.h"

void test(void) {
    static m8_binaryX2E2Instance instance;
    m8_binaryX2E2Instantiate(&instance, resolveTestImports);
    printStart("binary.2.wasm");
    m8_binaryX2E2FreeInstance(&instance);
}
