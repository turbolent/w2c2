#include "test.h"
#include "test_exports.25.h"

void test(void) {
    static m10_exportsX2E25Instance instance;
    m10_exportsX2E25Instantiate(&instance, resolveTestImports);
    printStart("exports.25.wasm");
    m10_exportsX2E25FreeInstance(&instance);
}
