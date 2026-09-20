
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.26.h"

void test() {
    m8_constX2E26Instance instance;
    m8_constX2E26Instantiate(&instance, resolveTestImports);
    printStart("const.26.wasm");
}
