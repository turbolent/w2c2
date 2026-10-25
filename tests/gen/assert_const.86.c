
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.86.h"

void test() {
    m8_constX2E86Instance instance;
    m8_constX2E86Instantiate(&instance, resolveTestImports);
    printStart("const.86.wasm");
}
