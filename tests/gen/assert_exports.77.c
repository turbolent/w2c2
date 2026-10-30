#include "test.h"
#include "test_exports.77.h"

void test(void) {
    static m10_exportsX2E77Instance instance;
    m10_exportsX2E77Instantiate(&instance, resolveTestImports);
    printStart("exports.77.wasm");
    m10_exportsX2E77FreeInstance(&instance);
}
