
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.18.h"

void test() {
    m8_constX2E18Instance instance;
    m8_constX2E18Instantiate(&instance, resolveTestImports);
    printStart("const.18.wasm");
}
