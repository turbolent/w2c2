
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.35.h"

void test() {
    m8_constX2E35Instance instance;
    m8_constX2E35Instantiate(&instance, resolveTestImports);
    printStart("const.35.wasm");
}
