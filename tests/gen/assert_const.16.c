
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.16.h"

void test() {
    m8_constX2E16Instance instance;
    m8_constX2E16Instantiate(&instance, resolveTestImports);
    printStart("const.16.wasm");
}
