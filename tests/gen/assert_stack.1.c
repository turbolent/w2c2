
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_stack.1.h"

void test() {
    m7_stackX2E1Instance instance;
    m7_stackX2E1Instantiate(&instance, resolveTestImports);
    printStart("stack.1.wasm");
}
