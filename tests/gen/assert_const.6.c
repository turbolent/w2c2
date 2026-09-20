
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.6.h"

void test() {
    m7_constX2E6Instance instance;
    m7_constX2E6Instantiate(&instance, resolveTestImports);
    printStart("const.6.wasm");
}
