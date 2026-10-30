#include "test.h"
#include "test_binary.60.h"

void test(void) {
    static m9_binaryX2E60Instance instance;
    m9_binaryX2E60Instantiate(&instance, resolveTestImports);
    printStart("binary.60.wasm");
    m9_binaryX2E60FreeInstance(&instance);
}
