#include "test.h"
#include "test_binary-leb128.1.h"

void test(void) {
    static m15_binaryX2Dleb128X2E1Instance instance;
    m15_binaryX2Dleb128X2E1Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.1.wasm");
    m15_binaryX2Dleb128X2E1FreeInstance(&instance);
}
