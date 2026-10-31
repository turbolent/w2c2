#include "test.h"
#include "test_exports.76.h"

void test(void) {
    static m10_exportsX2E76Instance instance;
    m10_exportsX2E76Instantiate(&instance, resolveTestImports);
    printStart("exports.76.wasm");
    m10_exportsX2E76FreeInstance(&instance);
}
