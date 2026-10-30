#include "test.h"
#include "test_binary-leb128.3.h"

void test(void) {
    static m15_binaryX2Dleb128X2E3Instance instance;
    m15_binaryX2Dleb128X2E3Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.3.wasm");
    m15_binaryX2Dleb128X2E3FreeInstance(&instance);
}
