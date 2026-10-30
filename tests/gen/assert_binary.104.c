#include "test.h"
#include "test_binary.104.h"

void test(void) {
    static m10_binaryX2E104Instance instance;
    m10_binaryX2E104Instantiate(&instance, resolveTestImports);
    printStart("binary.104.wasm");
    m10_binaryX2E104FreeInstance(&instance);
}
