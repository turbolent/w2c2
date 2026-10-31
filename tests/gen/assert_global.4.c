#include "test.h"
#include "test_global.4.h"

void test(void) {
    static m8_globalX2E4Instance instance;
    m8_globalX2E4Instantiate(&instance, resolveTestImports);
    printStart("global.4.wasm");
    m8_globalX2E4FreeInstance(&instance);
}
