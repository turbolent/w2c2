#include "test.h"
#include "test_binary-leb128.4.h"

void test(void) {
    static m15_binaryX2Dleb128X2E4Instance instance;
    m15_binaryX2Dleb128X2E4Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.4.wasm");
    m15_binaryX2Dleb128X2E4FreeInstance(&instance);
}
