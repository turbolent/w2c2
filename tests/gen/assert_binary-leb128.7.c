#include "test.h"
#include "test_binary-leb128.7.h"

void test(void) {
    static m15_binaryX2Dleb128X2E7Instance instance;
    m15_binaryX2Dleb128X2E7Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.7.wasm");
    m15_binaryX2Dleb128X2E7FreeInstance(&instance);
}
