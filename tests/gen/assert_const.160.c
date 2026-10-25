
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.160.h"

void test() {
    m9_constX2E160Instance instance;
    m9_constX2E160Instantiate(&instance, resolveTestImports);
    printStart("const.160.wasm");
}
