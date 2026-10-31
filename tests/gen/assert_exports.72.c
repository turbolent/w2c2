#include "test.h"
#include "test_exports.72.h"

void test(void) {
    static m10_exportsX2E72Instance instance;
    m10_exportsX2E72Instantiate(&instance, resolveTestImports);
    printStart("exports.72.wasm");
    m10_exportsX2E72FreeInstance(&instance);
}
