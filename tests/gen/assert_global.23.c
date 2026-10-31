#include "test.h"
#include "test_global.23.h"

void test(void) {
    static m9_globalX2E23Instance instance;
    m9_globalX2E23Instantiate(&instance, resolveTestImports);
    printStart("global.23.wasm");
    m9_globalX2E23FreeInstance(&instance);
}
