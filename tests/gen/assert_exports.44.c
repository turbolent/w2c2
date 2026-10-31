#include "test.h"
#include "test_exports.44.h"

void test(void) {
    static m10_exportsX2E44Instance instance;
    m10_exportsX2E44Instantiate(&instance, resolveTestImports);
    printStart("exports.44.wasm");
    m10_exportsX2E44FreeInstance(&instance);
}
