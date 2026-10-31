#include "test.h"
#include "test_binary.100.h"

void test(void) {
    static m10_binaryX2E100Instance instance;
    m10_binaryX2E100Instantiate(&instance, resolveTestImports);
    printStart("binary.100.wasm");
    m10_binaryX2E100FreeInstance(&instance);
}
