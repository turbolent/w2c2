#include "test.h"
#include "test_global.25.h"

void test(void) {
    static m9_globalX2E25Instance instance;
    m9_globalX2E25Instantiate(&instance, resolveTestImports);
    printStart("global.25.wasm");
    m9_globalX2E25FreeInstance(&instance);
}
