
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.75.h"

void test() {
    m8_constX2E75Instance instance;
    m8_constX2E75Instantiate(&instance, resolveTestImports);
    printStart("const.75.wasm");
}
