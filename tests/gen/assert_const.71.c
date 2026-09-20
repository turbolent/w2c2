
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.71.h"

void test() {
    m8_constX2E71Instance instance;
    m8_constX2E71Instantiate(&instance, resolveTestImports);
    printStart("const.71.wasm");
}
