#include "test.h"
#include "test_exports.49.h"

void test(void) {
    static m10_exportsX2E49Instance instance;
    m10_exportsX2E49Instantiate(&instance, resolveTestImports);
    printStart("exports.49.wasm");
    m10_exportsX2E49FreeInstance(&instance);
}
