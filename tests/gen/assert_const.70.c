
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.70.h"

void test() {
    m8_constX2E70Instance instance;
    m8_constX2E70Instantiate(&instance, resolveTestImports);
    printStart("const.70.wasm");
}
