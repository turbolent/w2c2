
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.1.h"

void test() {
    m7_constX2E1Instance instance;
    m7_constX2E1Instantiate(&instance, resolveTestImports);
    printStart("const.1.wasm");
}
