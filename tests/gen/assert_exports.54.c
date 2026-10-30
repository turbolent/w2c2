#include "test.h"
#include "test_exports.54.h"

void test(void) {
    static m10_exportsX2E54Instance instance;
    m10_exportsX2E54Instantiate(&instance, resolveTestImports);
    printStart("exports.54.wasm");
    m10_exportsX2E54FreeInstance(&instance);
}
