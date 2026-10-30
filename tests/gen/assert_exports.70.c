#include "test.h"
#include "test_exports.70.h"

void test(void) {
    static m10_exportsX2E70Instance instance;
    m10_exportsX2E70Instantiate(&instance, resolveTestImports);
    printStart("exports.70.wasm");
    m10_exportsX2E70FreeInstance(&instance);
}
