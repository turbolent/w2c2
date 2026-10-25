
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.84.h"

void test() {
    m8_constX2E84Instance instance;
    m8_constX2E84Instantiate(&instance, resolveTestImports);
    printStart("const.84.wasm");
}
