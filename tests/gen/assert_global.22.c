#include "test.h"
#include "test_global.22.h"

void test(void) {
    static m9_globalX2E22Instance instance;
    m9_globalX2E22Instantiate(&instance, resolveTestImports);
    printStart("global.22.wasm");
    m9_globalX2E22FreeInstance(&instance);
}
