#include "test.h"
#include "test_binary-leb128.18.h"

void test(void) {
    static m16_binaryX2Dleb128X2E18Instance instance;
    m16_binaryX2Dleb128X2E18Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.18.wasm");
    m16_binaryX2Dleb128X2E18FreeInstance(&instance);
}
