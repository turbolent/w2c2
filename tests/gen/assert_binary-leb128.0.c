#include "test.h"
#include "test_binary-leb128.0.h"

void test(void) {
    static m15_binaryX2Dleb128X2E0Instance instance;
    m15_binaryX2Dleb128X2E0Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.0.wasm");
    m15_binaryX2Dleb128X2E0FreeInstance(&instance);
}
