#include "test.h"
#include "test_exports.51.h"

void test(void) {
    static m10_exportsX2E51Instance instance;
    m10_exportsX2E51Instantiate(&instance, resolveTestImports);
    printStart("exports.51.wasm");
    m10_exportsX2E51FreeInstance(&instance);
}
