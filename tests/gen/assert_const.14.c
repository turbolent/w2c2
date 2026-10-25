
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.14.h"

void test() {
    m8_constX2E14Instance instance;
    m8_constX2E14Instantiate(&instance, resolveTestImports);
    printStart("const.14.wasm");
}
