#include "test.h"
#include "test_binary-leb128.2.h"

void test(void) {
    static m15_binaryX2Dleb128X2E2Instance instance;
    m15_binaryX2Dleb128X2E2Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.2.wasm");
    m15_binaryX2Dleb128X2E2FreeInstance(&instance);
}
