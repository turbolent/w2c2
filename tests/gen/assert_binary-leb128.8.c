#include "test.h"
#include "test_binary-leb128.8.h"

void test(void) {
    static m15_binaryX2Dleb128X2E8Instance instance;
    m15_binaryX2Dleb128X2E8Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.8.wasm");
    m15_binaryX2Dleb128X2E8FreeInstance(&instance);
}
