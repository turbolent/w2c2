#include "test.h"
#include "test_binary-leb128.88.h"

void test(void) {
    static m16_binaryX2Dleb128X2E88Instance instance;
    m16_binaryX2Dleb128X2E88Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.88.wasm");
    m16_binaryX2Dleb128X2E88FreeInstance(&instance);
}
