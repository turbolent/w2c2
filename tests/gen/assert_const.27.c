
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.27.h"

void test() {
    m8_constX2E27Instance instance;
    m8_constX2E27Instantiate(&instance, resolveTestImports);
    printStart("const.27.wasm");
}
