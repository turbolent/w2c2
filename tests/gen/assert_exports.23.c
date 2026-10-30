#include "test.h"
#include "test_exports.23.h"

void test(void) {
    static m10_exportsX2E23Instance instance;
    m10_exportsX2E23Instantiate(&instance, resolveTestImports);
    printStart("exports.23.wasm");
    m10_exportsX2E23FreeInstance(&instance);
}
