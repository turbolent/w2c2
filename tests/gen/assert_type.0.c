#include "test.h"
#include "test_type.0.h"

void test(void) {
    static m6_typeX2E0Instance instance;
    m6_typeX2E0Instantiate(&instance, resolveTestImports);
    printStart("type.0.wasm");
    m6_typeX2E0FreeInstance(&instance);
}
