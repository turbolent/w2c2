
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.58.h"

void test() {
    m8_constX2E58Instance instance;
    m8_constX2E58Instantiate(&instance, resolveTestImports);
    printStart("const.58.wasm");
}
