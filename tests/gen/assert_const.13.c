
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.13.h"

void test() {
    m8_constX2E13Instance instance;
    m8_constX2E13Instantiate(&instance, resolveTestImports);
    printStart("const.13.wasm");
}
