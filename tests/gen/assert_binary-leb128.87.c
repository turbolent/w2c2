#include "test.h"
#include "test_binary-leb128.87.h"

void test(void) {
    static m16_binaryX2Dleb128X2E87Instance instance;
    m16_binaryX2Dleb128X2E87Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.87.wasm");
    m16_binaryX2Dleb128X2E87FreeInstance(&instance);
}
