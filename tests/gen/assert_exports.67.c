#include "test.h"
#include "test_exports.67.h"

void test(void) {
    static m10_exportsX2E67Instance instance;
    m10_exportsX2E67Instantiate(&instance, resolveTestImports);
    printStart("exports.67.wasm");
    m10_exportsX2E67FreeInstance(&instance);
}
