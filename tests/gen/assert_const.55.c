
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.55.h"

void test() {
    m8_constX2E55Instance instance;
    m8_constX2E55Instantiate(&instance, resolveTestImports);
    printStart("const.55.wasm");
}
