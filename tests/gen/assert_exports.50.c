#include "test.h"
#include "test_exports.50.h"

void test(void) {
    static m10_exportsX2E50Instance instance;
    m10_exportsX2E50Instantiate(&instance, resolveTestImports);
    printStart("exports.50.wasm");
    m10_exportsX2E50FreeInstance(&instance);
}
