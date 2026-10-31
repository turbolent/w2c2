#include "test.h"
#include "test_unreached-valid.1.h"

void test(void) {
    static m17_unreachedX2DvalidX2E1Instance instance;
    m17_unreachedX2DvalidX2E1Instantiate(&instance, resolveTestImports);
    printStart("unreached-valid.1.wasm");
    m17_unreachedX2DvalidX2E1FreeInstance(&instance);
}
