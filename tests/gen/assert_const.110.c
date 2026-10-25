
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.110.h"

void test() {
    m9_constX2E110Instance instance;
    m9_constX2E110Instantiate(&instance, resolveTestImports);
    printStart("const.110.wasm");
}
