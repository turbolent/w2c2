#include "test.h"
#include "test_exports.6.h"

void test(void) {
    static m9_exportsX2E6Instance instance;
    m9_exportsX2E6Instantiate(&instance, resolveTestImports);
    printStart("exports.6.wasm");
    m9_exportsX2E6FreeInstance(&instance);
}
