
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.128.h"

void test() {
    m9_constX2E128Instance instance;
    m9_constX2E128Instantiate(&instance, resolveTestImports);
    printStart("const.128.wasm");
}
