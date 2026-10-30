#include "test.h"
#include "test_binary.97.h"

void test(void) {
    static m9_binaryX2E97Instance instance;
    m9_binaryX2E97Instantiate(&instance, resolveTestImports);
    printStart("binary.97.wasm");
    m9_binaryX2E97FreeInstance(&instance);
}
