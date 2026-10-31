#include "test.h"
#include "test_exports.30.h"

void test(void) {
    static m10_exportsX2E30Instance instance;
    m10_exportsX2E30Instantiate(&instance, resolveTestImports);
    printStart("exports.30.wasm");
    m10_exportsX2E30FreeInstance(&instance);
}
