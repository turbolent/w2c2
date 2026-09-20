
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.130.h"

void test() {
    m9_constX2E130Instance instance;
    m9_constX2E130Instantiate(&instance, resolveTestImports);
    printStart("const.130.wasm");
}
