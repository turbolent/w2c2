#include "test.h"
#include "test_func.1.h"

void test(void) {
    static m6_funcX2E1Instance instance;
    m6_funcX2E1Instantiate(&instance, resolveTestImports);
    printStart("func.1.wasm");
    m6_funcX2E1FreeInstance(&instance);
}
