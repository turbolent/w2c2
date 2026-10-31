#include "test.h"
#include "test_exports.0.h"

void test(void) {
    static m9_exportsX2E0Instance instance;
    m9_exportsX2E0Instantiate(&instance, resolveTestImports);
    printStart("exports.0.wasm");
    m9_exportsX2E0FreeInstance(&instance);
}
