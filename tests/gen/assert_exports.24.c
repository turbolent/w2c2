#include "test.h"
#include "test_exports.24.h"

void test(void) {
    static m10_exportsX2E24Instance instance;
    m10_exportsX2E24Instantiate(&instance, resolveTestImports);
    printStart("exports.24.wasm");
    m10_exportsX2E24FreeInstance(&instance);
}
