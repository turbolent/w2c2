
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.66.h"

void test() {
    m8_constX2E66Instance instance;
    m8_constX2E66Instantiate(&instance, resolveTestImports);
    printStart("const.66.wasm");
}
