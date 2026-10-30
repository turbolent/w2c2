#include "test.h"
#include "test_exports.7.h"

void test(void) {
    static m9_exportsX2E7Instance instance;
    m9_exportsX2E7Instantiate(&instance, resolveTestImports);
    printStart("exports.7.wasm");
    m9_exportsX2E7FreeInstance(&instance);
}
