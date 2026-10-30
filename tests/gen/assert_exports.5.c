#include "test.h"
#include "test_exports.5.h"

void test(void) {
    static m9_exportsX2E5Instance instance;
    m9_exportsX2E5Instantiate(&instance, resolveTestImports);
    printStart("exports.5.wasm");
    m9_exportsX2E5FreeInstance(&instance);
}
