#include "test.h"
#include "test_binary-leb128.24.h"

void test(void) {
    static m16_binaryX2Dleb128X2E24Instance instance;
    m16_binaryX2Dleb128X2E24Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.24.wasm");
    m16_binaryX2Dleb128X2E24FreeInstance(&instance);
}
