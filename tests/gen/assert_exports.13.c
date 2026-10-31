#include "test.h"
#include "test_exports.13.h"

void test(void) {
    static m10_exportsX2E13Instance instance;
    m10_exportsX2E13Instantiate(&instance, resolveTestImports);
    printStart("exports.13.wasm");
    m10_exportsX2E13FreeInstance(&instance);
}
