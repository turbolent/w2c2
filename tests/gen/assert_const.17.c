
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.17.h"

void test() {
    m8_constX2E17Instance instance;
    m8_constX2E17Instantiate(&instance, resolveTestImports);
    printStart("const.17.wasm");
}
