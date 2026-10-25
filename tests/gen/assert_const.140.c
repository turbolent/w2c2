
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.140.h"

void test() {
    m9_constX2E140Instance instance;
    m9_constX2E140Instantiate(&instance, resolveTestImports);
    printStart("const.140.wasm");
}
