
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.0.h"

void test() {
    m7_constX2E0Instance instance;
    m7_constX2E0Instantiate(&instance, resolveTestImports);
    printStart("const.0.wasm");
}
