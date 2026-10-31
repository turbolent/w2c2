#include "test.h"
#include "test_exports.3.h"

void test(void) {
    static m9_exportsX2E3Instance instance;
    m9_exportsX2E3Instantiate(&instance, resolveTestImports);
    printStart("exports.3.wasm");
    m9_exportsX2E3FreeInstance(&instance);
}
