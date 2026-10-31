#include "test.h"
#include "test_binary-leb128.9.h"

void test(void) {
    static m15_binaryX2Dleb128X2E9Instance instance;
    m15_binaryX2Dleb128X2E9Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.9.wasm");
    m15_binaryX2Dleb128X2E9FreeInstance(&instance);
}
