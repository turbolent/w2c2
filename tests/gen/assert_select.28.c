#include "test.h"
#include "test_select.28.h"

void test(void) {
    static m9_selectX2E28Instance instance;
    m9_selectX2E28Instantiate(&instance, resolveTestImports);
    printStart("select.28.wasm");
    m9_selectX2E28FreeInstance(&instance);
}
