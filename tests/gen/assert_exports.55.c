#include "test.h"
#include "test_exports.55.h"

void test(void) {
    static m10_exportsX2E55Instance instance;
    m10_exportsX2E55Instantiate(&instance, resolveTestImports);
    printStart("exports.55.wasm");
    m10_exportsX2E55FreeInstance(&instance);
}
