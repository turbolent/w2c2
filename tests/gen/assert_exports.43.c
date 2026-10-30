#include "test.h"
#include "test_exports.43.h"

void test(void) {
    static m10_exportsX2E43Instance instance;
    m10_exportsX2E43Instantiate(&instance, resolveTestImports);
    printStart("exports.43.wasm");
    m10_exportsX2E43FreeInstance(&instance);
}
