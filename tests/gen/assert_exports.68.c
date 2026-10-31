#include "test.h"
#include "test_exports.68.h"

void test(void) {
    static m10_exportsX2E68Instance instance;
    m10_exportsX2E68Instantiate(&instance, resolveTestImports);
    printStart("exports.68.wasm");
    m10_exportsX2E68FreeInstance(&instance);
}
