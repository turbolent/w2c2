
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.31.h"

void test() {
    m8_constX2E31Instance instance;
    m8_constX2E31Instantiate(&instance, resolveTestImports);
    printStart("const.31.wasm");
}
