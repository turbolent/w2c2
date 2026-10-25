
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.89.h"

void test() {
    m8_constX2E89Instance instance;
    m8_constX2E89Instantiate(&instance, resolveTestImports);
    printStart("const.89.wasm");
}
