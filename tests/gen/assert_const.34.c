
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.34.h"

void test() {
    m8_constX2E34Instance instance;
    m8_constX2E34Instantiate(&instance, resolveTestImports);
    printStart("const.34.wasm");
}
