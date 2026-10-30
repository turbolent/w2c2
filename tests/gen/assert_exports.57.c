#include "test.h"
#include "test_exports.57.h"

void test(void) {
    static m10_exportsX2E57Instance instance;
    m10_exportsX2E57Instantiate(&instance, resolveTestImports);
    printStart("exports.57.wasm");
    m10_exportsX2E57FreeInstance(&instance);
}
