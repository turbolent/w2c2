
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.56.h"

void test() {
    m8_constX2E56Instance instance;
    m8_constX2E56Instantiate(&instance, resolveTestImports);
    printStart("const.56.wasm");
}
