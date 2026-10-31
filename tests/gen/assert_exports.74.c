#include "test.h"
#include "test_exports.74.h"

void test(void) {
    static m10_exportsX2E74Instance instance;
    m10_exportsX2E74Instantiate(&instance, resolveTestImports);
    printStart("exports.74.wasm");
    m10_exportsX2E74FreeInstance(&instance);
}
