#include "test.h"
#include "test_exports.47.h"

void test(void) {
    static m10_exportsX2E47Instance instance;
    m10_exportsX2E47Instantiate(&instance, resolveTestImports);
    printStart("exports.47.wasm");
    m10_exportsX2E47FreeInstance(&instance);
}
