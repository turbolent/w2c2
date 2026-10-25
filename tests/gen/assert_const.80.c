
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.80.h"

void test() {
    m8_constX2E80Instance instance;
    m8_constX2E80Instantiate(&instance, resolveTestImports);
    printStart("const.80.wasm");
}
