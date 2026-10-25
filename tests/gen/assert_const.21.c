
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.21.h"

void test() {
    m8_constX2E21Instance instance;
    m8_constX2E21Instantiate(&instance, resolveTestImports);
    printStart("const.21.wasm");
}
