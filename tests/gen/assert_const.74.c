
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.74.h"

void test() {
    m8_constX2E74Instance instance;
    m8_constX2E74Instantiate(&instance, resolveTestImports);
    printStart("const.74.wasm");
}
