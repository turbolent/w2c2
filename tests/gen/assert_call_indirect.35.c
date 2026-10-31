#include "test.h"
#include "test_call_indirect.35.h"

void test(void) {
    static m16_callX5FindirectX2E35Instance instance;
    m16_callX5FindirectX2E35Instantiate(&instance, resolveTestImports);
    printStart("call_indirect.35.wasm");
    m16_callX5FindirectX2E35FreeInstance(&instance);
}
