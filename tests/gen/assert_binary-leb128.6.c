#include "test.h"
#include "test_binary-leb128.6.h"

void test(void) {
    static m15_binaryX2Dleb128X2E6Instance instance;
    m15_binaryX2Dleb128X2E6Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.6.wasm");
    m15_binaryX2Dleb128X2E6FreeInstance(&instance);
}
