#include "test.h"
#include "test_binary-leb128.85.h"

void test(void) {
    static m16_binaryX2Dleb128X2E85Instance instance;
    m16_binaryX2Dleb128X2E85Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.85.wasm");
    m16_binaryX2Dleb128X2E85FreeInstance(&instance);
}
