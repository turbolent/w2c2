#include "test.h"
#include "test_global.26.h"

void test(void) {
    static m9_globalX2E26Instance instance;
    m9_globalX2E26Instantiate(&instance, resolveTestImports);
    printStart("global.26.wasm");
    m9_globalX2E26FreeInstance(&instance);
}
