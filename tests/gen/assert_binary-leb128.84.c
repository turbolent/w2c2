#include "test.h"
#include "test_binary-leb128.84.h"

void test(void) {
    static m16_binaryX2Dleb128X2E84Instance instance;
    m16_binaryX2Dleb128X2E84Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.84.wasm");
    m16_binaryX2Dleb128X2E84FreeInstance(&instance);
}
