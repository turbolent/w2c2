#include "test.h"
#include "test_exports.34.h"

void test(void) {
    static m10_exportsX2E34Instance instance;
    m10_exportsX2E34Instantiate(&instance, resolveTestImports);
    printStart("exports.34.wasm");
    m10_exportsX2E34FreeInstance(&instance);
}
