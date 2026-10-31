#include "test.h"
#include "test_exports.28.h"

void test(void) {
    static m10_exportsX2E28Instance instance;
    m10_exportsX2E28Instantiate(&instance, resolveTestImports);
    printStart("exports.28.wasm");
    m10_exportsX2E28FreeInstance(&instance);
}
