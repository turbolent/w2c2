#include "test.h"
#include "test_exports.46.h"

void test(void) {
    static m10_exportsX2E46Instance instance;
    m10_exportsX2E46Instantiate(&instance, resolveTestImports);
    printStart("exports.46.wasm");
    m10_exportsX2E46FreeInstance(&instance);
}
