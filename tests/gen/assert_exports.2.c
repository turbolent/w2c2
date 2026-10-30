#include "test.h"
#include "test_exports.2.h"

void test(void) {
    static m9_exportsX2E2Instance instance;
    m9_exportsX2E2Instantiate(&instance, resolveTestImports);
    printStart("exports.2.wasm");
    m9_exportsX2E2FreeInstance(&instance);
}
