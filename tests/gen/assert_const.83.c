
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.83.h"

void test() {
    m8_constX2E83Instance instance;
    m8_constX2E83Instantiate(&instance, resolveTestImports);
    printStart("const.83.wasm");
}
