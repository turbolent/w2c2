
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.23.h"

void test() {
    m8_constX2E23Instance instance;
    m8_constX2E23Instantiate(&instance, resolveTestImports);
    printStart("const.23.wasm");
}
