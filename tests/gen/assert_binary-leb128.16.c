#include "test.h"
#include "test_binary-leb128.16.h"

void test(void) {
    static m16_binaryX2Dleb128X2E16Instance instance;
    m16_binaryX2Dleb128X2E16Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.16.wasm");
    m16_binaryX2Dleb128X2E16FreeInstance(&instance);
}
