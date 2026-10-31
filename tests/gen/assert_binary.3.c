#include "test.h"
#include "test_binary.3.h"

void test(void) {
    static m8_binaryX2E3Instance instance;
    m8_binaryX2E3Instantiate(&instance, resolveTestImports);
    printStart("binary.3.wasm");
    m8_binaryX2E3FreeInstance(&instance);
}
