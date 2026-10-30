#include "test.h"
#include "test_exports.71.h"

void test(void) {
    static m10_exportsX2E71Instance instance;
    m10_exportsX2E71Instantiate(&instance, resolveTestImports);
    printStart("exports.71.wasm");
    m10_exportsX2E71FreeInstance(&instance);
}
