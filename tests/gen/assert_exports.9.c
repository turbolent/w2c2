#include "test.h"
#include "test_exports.9.h"

void test(void) {
    static m9_exportsX2E9Instance instance;
    m9_exportsX2E9Instantiate(&instance, resolveTestImports);
    printStart("exports.9.wasm");
    m9_exportsX2E9FreeInstance(&instance);
}
