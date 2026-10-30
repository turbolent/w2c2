#include "test.h"
#include "test_exports.56.h"

void test(void) {
    static m10_exportsX2E56Instance instance;
    m10_exportsX2E56Instantiate(&instance, resolveTestImports);
    printStart("exports.56.wasm");
    m10_exportsX2E56FreeInstance(&instance);
}
