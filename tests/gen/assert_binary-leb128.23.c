#include "test.h"
#include "test_binary-leb128.23.h"

void test(void) {
    static m16_binaryX2Dleb128X2E23Instance instance;
    m16_binaryX2Dleb128X2E23Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.23.wasm");
    m16_binaryX2Dleb128X2E23FreeInstance(&instance);
}
