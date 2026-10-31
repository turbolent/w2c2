#include "test.h"
#include "test_exports.4.h"

void test(void) {
    static m9_exportsX2E4Instance instance;
    m9_exportsX2E4Instantiate(&instance, resolveTestImports);
    printStart("exports.4.wasm");
    m9_exportsX2E4FreeInstance(&instance);
}
