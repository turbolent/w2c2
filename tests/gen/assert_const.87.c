
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.87.h"

void test() {
    m8_constX2E87Instance instance;
    m8_constX2E87Instantiate(&instance, resolveTestImports);
    printStart("const.87.wasm");
}
