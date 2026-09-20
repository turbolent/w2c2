
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.15.h"

void test() {
    m8_constX2E15Instance instance;
    m8_constX2E15Instantiate(&instance, resolveTestImports);
    printStart("const.15.wasm");
}
