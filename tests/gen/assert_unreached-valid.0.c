#include "test.h"
#include "test_unreached-valid.0.h"

void test(void) {
    static m17_unreachedX2DvalidX2E0Instance instance;
    m17_unreachedX2DvalidX2E0Instantiate(&instance, resolveTestImports);
    printStart("unreached-valid.0.wasm");
    m17_unreachedX2DvalidX2E0FreeInstance(&instance);
}
