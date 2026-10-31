#include "test.h"
#include "test_exports.31.h"

void test(void) {
    static m10_exportsX2E31Instance instance;
    m10_exportsX2E31Instantiate(&instance, resolveTestImports);
    printStart("exports.31.wasm");
    m10_exportsX2E31FreeInstance(&instance);
}
