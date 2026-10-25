
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.33.h"

void test() {
    m8_constX2E33Instance instance;
    m8_constX2E33Instantiate(&instance, resolveTestImports);
    printStart("const.33.wasm");
}
