
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.73.h"

void test() {
    m8_constX2E73Instance instance;
    m8_constX2E73Instantiate(&instance, resolveTestImports);
    printStart("const.73.wasm");
}
