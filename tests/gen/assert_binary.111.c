#include "test.h"
#include "test_binary.111.h"

void test(void) {
    static m10_binaryX2E111Instance instance;
    m10_binaryX2E111Instantiate(&instance, resolveTestImports);
    printStart("binary.111.wasm");
    m10_binaryX2E111FreeInstance(&instance);
}
