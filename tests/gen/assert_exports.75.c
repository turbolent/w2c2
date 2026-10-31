#include "test.h"
#include "test_exports.75.h"

void test(void) {
    static m10_exportsX2E75Instance instance;
    m10_exportsX2E75Instantiate(&instance, resolveTestImports);
    printStart("exports.75.wasm");
    m10_exportsX2E75FreeInstance(&instance);
}
