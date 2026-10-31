#include "test.h"
#include "test_binary-leb128.21.h"

void test(void) {
    static m16_binaryX2Dleb128X2E21Instance instance;
    m16_binaryX2Dleb128X2E21Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.21.wasm");
    m16_binaryX2Dleb128X2E21FreeInstance(&instance);
}
