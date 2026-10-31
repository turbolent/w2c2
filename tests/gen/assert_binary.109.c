#include "test.h"
#include "test_binary.109.h"

void test(void) {
    static m10_binaryX2E109Instance instance;
    m10_binaryX2E109Instantiate(&instance, resolveTestImports);
    printStart("binary.109.wasm");
    m10_binaryX2E109FreeInstance(&instance);
}
