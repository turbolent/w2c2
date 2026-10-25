
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.7.h"

void test() {
    m7_constX2E7Instance instance;
    m7_constX2E7Instantiate(&instance, resolveTestImports);
    printStart("const.7.wasm");
}
