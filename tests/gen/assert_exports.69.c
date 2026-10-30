#include "test.h"
#include "test_exports.69.h"

void test(void) {
    static m10_exportsX2E69Instance instance;
    m10_exportsX2E69Instantiate(&instance, resolveTestImports);
    printStart("exports.69.wasm");
    m10_exportsX2E69FreeInstance(&instance);
}
