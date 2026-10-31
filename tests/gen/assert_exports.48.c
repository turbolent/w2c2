#include "test.h"
#include "test_exports.48.h"

void test(void) {
    static m10_exportsX2E48Instance instance;
    m10_exportsX2E48Instantiate(&instance, resolveTestImports);
    printStart("exports.48.wasm");
    m10_exportsX2E48FreeInstance(&instance);
}
