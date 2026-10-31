#include "test.h"
#include "test_select.31.h"

void test(void) {
    static m9_selectX2E31Instance instance;
    m9_selectX2E31Instantiate(&instance, resolveTestImports);
    printStart("select.31.wasm");
    m9_selectX2E31FreeInstance(&instance);
}
