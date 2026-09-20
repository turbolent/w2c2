
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.90.h"

void test() {
    m8_constX2E90Instance instance;
    m8_constX2E90Instantiate(&instance, resolveTestImports);
    printStart("const.90.wasm");
}
