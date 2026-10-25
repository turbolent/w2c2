
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.63.h"

void test() {
    m8_constX2E63Instance instance;
    m8_constX2E63Instantiate(&instance, resolveTestImports);
    printStart("const.63.wasm");
}
