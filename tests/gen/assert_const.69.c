
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.69.h"

void test() {
    m8_constX2E69Instance instance;
    m8_constX2E69Instantiate(&instance, resolveTestImports);
    printStart("const.69.wasm");
}
