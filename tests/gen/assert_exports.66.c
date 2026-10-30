#include "test.h"
#include "test_exports.66.h"

void test(void) {
    static m10_exportsX2E66Instance instance;
    m10_exportsX2E66Instantiate(&instance, resolveTestImports);
    printStart("exports.66.wasm");
    m10_exportsX2E66FreeInstance(&instance);
}
