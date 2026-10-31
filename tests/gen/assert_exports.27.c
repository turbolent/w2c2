#include "test.h"
#include "test_exports.27.h"

void test(void) {
    static m10_exportsX2E27Instance instance;
    m10_exportsX2E27Instantiate(&instance, resolveTestImports);
    printStart("exports.27.wasm");
    m10_exportsX2E27FreeInstance(&instance);
}
