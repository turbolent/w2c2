#include "test.h"
#include "test_exports.52.h"

void test(void) {
    static m10_exportsX2E52Instance instance;
    m10_exportsX2E52Instantiate(&instance, resolveTestImports);
    printStart("exports.52.wasm");
    m10_exportsX2E52FreeInstance(&instance);
}
