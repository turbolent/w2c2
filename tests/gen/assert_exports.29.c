#include "test.h"
#include "test_exports.29.h"

void test(void) {
    static m10_exportsX2E29Instance instance;
    m10_exportsX2E29Instantiate(&instance, resolveTestImports);
    printStart("exports.29.wasm");
    m10_exportsX2E29FreeInstance(&instance);
}
