#include "test.h"
#include "test_binary-leb128.5.h"

void test(void) {
    static m15_binaryX2Dleb128X2E5Instance instance;
    m15_binaryX2Dleb128X2E5Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.5.wasm");
    m15_binaryX2Dleb128X2E5FreeInstance(&instance);
}
