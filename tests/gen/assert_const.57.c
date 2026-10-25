
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.57.h"

void test() {
    m8_constX2E57Instance instance;
    m8_constX2E57Instantiate(&instance, resolveTestImports);
    printStart("const.57.wasm");
}
