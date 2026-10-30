#include "test.h"
#include "test_binary-leb128.14.h"

void test(void) {
    static m16_binaryX2Dleb128X2E14Instance instance;
    m16_binaryX2Dleb128X2E14Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.14.wasm");
    m16_binaryX2Dleb128X2E14FreeInstance(&instance);
}
