#include "test.h"
#include "test_exports.26.h"

void test(void) {
    static m10_exportsX2E26Instance instance;
    m10_exportsX2E26Instantiate(&instance, resolveTestImports);
    printStart("exports.26.wasm");
    m10_exportsX2E26FreeInstance(&instance);
}
