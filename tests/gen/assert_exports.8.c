#include "test.h"
#include "test_exports.8.h"

void test(void) {
    static m9_exportsX2E8Instance instance;
    m9_exportsX2E8Instantiate(&instance, resolveTestImports);
    printStart("exports.8.wasm");
    m9_exportsX2E8FreeInstance(&instance);
}
