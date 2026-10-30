#include "test.h"
#include "test_binary.1.h"

void test(void) {
    static m8_binaryX2E1Instance instance;
    m8_binaryX2E1Instantiate(&instance, resolveTestImports);
    printStart("binary.1.wasm");
    m8_binaryX2E1FreeInstance(&instance);
}
