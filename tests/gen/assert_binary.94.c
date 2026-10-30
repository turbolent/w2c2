#include "test.h"
#include "test_binary.94.h"

void test(void) {
    static m9_binaryX2E94Instance instance;
    m9_binaryX2E94Instantiate(&instance, resolveTestImports);
    printStart("binary.94.wasm");
    m9_binaryX2E94FreeInstance(&instance);
}
