
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.82.h"

void test() {
    m8_constX2E82Instance instance;
    m8_constX2E82Instantiate(&instance, resolveTestImports);
    printStart("const.82.wasm");
}
