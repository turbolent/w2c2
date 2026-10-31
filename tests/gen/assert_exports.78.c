#include "test.h"
#include "test_exports.78.h"

void test(void) {
    static m10_exportsX2E78Instance instance;
    m10_exportsX2E78Instantiate(&instance, resolveTestImports);
    printStart("exports.78.wasm");
    m10_exportsX2E78FreeInstance(&instance);
}
