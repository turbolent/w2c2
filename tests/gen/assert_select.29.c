#include "test.h"
#include "test_select.29.h"

void test(void) {
    static m9_selectX2E29Instance instance;
    m9_selectX2E29Instantiate(&instance, resolveTestImports);
    printStart("select.29.wasm");
    m9_selectX2E29FreeInstance(&instance);
}
