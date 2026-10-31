#include "test.h"
#include "test_exports.53.h"

void test(void) {
    static m10_exportsX2E53Instance instance;
    m10_exportsX2E53Instantiate(&instance, resolveTestImports);
    printStart("exports.53.wasm");
    m10_exportsX2E53FreeInstance(&instance);
}
