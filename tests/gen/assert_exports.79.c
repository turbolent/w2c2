#include "test.h"
#include "test_exports.79.h"

void test(void) {
    static m10_exportsX2E79Instance instance;
    m10_exportsX2E79Instantiate(&instance, resolveTestImports);
    printStart("exports.79.wasm");
    m10_exportsX2E79FreeInstance(&instance);
}
