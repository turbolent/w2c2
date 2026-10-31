#include "test.h"
#include "test_ref.0.h"

void test(void) {
    static m5_refX2E0Instance instance;
    m5_refX2E0Instantiate(&instance, resolveTestImports);
    printStart("ref.0.wasm");
    m5_refX2E0FreeInstance(&instance);
}
