#include "test.h"
#include "test_binary-leb128.89.h"

void test(void) {
    static m16_binaryX2Dleb128X2E89Instance instance;
    m16_binaryX2Dleb128X2E89Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.89.wasm");
    m16_binaryX2Dleb128X2E89FreeInstance(&instance);
}
