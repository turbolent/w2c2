#include "test.h"
#include "test_exports.33.h"

void test(void) {
    static m10_exportsX2E33Instance instance;
    m10_exportsX2E33Instantiate(&instance, resolveTestImports);
    printStart("exports.33.wasm");
    m10_exportsX2E33FreeInstance(&instance);
}
