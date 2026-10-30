#include "test.h"
#include "test_exports.12.h"

void test(void) {
    static m10_exportsX2E12Instance instance;
    m10_exportsX2E12Instantiate(&instance, resolveTestImports);
    printStart("exports.12.wasm");
    m10_exportsX2E12FreeInstance(&instance);
}
