#include "test.h"
#include "test_binary-leb128.86.h"

void test(void) {
    static m16_binaryX2Dleb128X2E86Instance instance;
    m16_binaryX2Dleb128X2E86Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.86.wasm");
    m16_binaryX2Dleb128X2E86FreeInstance(&instance);
}
