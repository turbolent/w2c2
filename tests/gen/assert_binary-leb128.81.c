#include "test.h"
#include "test_binary-leb128.81.h"

void test(void) {
    static m16_binaryX2Dleb128X2E81Instance instance;
    m16_binaryX2Dleb128X2E81Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.81.wasm");
    m16_binaryX2Dleb128X2E81FreeInstance(&instance);
}
