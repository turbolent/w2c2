
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.88.h"

void test() {
    m8_constX2E88Instance instance;
    m8_constX2E88Instantiate(&instance, resolveTestImports);
    printStart("const.88.wasm");
}
