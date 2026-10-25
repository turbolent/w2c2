
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.170.h"

void test() {
    m9_constX2E170Instance instance;
    m9_constX2E170Instantiate(&instance, resolveTestImports);
    printStart("const.170.wasm");
}
