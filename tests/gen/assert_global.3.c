#include "test.h"
#include "test_global.3.h"

void test(void) {
    static m8_globalX2E3Instance instance;
    m8_globalX2E3Instantiate(&instance, resolveTestImports);
    printStart("global.3.wasm");
    m8_globalX2E3FreeInstance(&instance);
}
