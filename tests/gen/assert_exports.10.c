#include "test.h"
#include "test_exports.10.h"

void test(void) {
    static m10_exportsX2E10Instance instance;
    m10_exportsX2E10Instantiate(&instance, resolveTestImports);
    printStart("exports.10.wasm");
    m10_exportsX2E10FreeInstance(&instance);
}
