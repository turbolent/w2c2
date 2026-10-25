
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.65.h"

void test() {
    m8_constX2E65Instance instance;
    m8_constX2E65Instantiate(&instance, resolveTestImports);
    printStart("const.65.wasm");
}
