
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.64.h"

void test() {
    m8_constX2E64Instance instance;
    m8_constX2E64Instantiate(&instance, resolveTestImports);
    printStart("const.64.wasm");
}
