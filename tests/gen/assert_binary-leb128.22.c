#include "test.h"
#include "test_binary-leb128.22.h"

void test(void) {
    static m16_binaryX2Dleb128X2E22Instance instance;
    m16_binaryX2Dleb128X2E22Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.22.wasm");
    m16_binaryX2Dleb128X2E22FreeInstance(&instance);
}
