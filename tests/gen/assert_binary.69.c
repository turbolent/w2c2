#include "test.h"
#include "test_binary.69.h"

void test(void) {
    static m9_binaryX2E69Instance instance;
    m9_binaryX2E69Instantiate(&instance, resolveTestImports);
    printStart("binary.69.wasm");
    m9_binaryX2E69FreeInstance(&instance);
}
