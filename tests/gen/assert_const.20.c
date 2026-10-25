
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.20.h"

void test() {
    m8_constX2E20Instance instance;
    m8_constX2E20Instantiate(&instance, resolveTestImports);
    printStart("const.20.wasm");
}
