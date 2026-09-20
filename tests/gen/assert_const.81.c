
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.81.h"

void test() {
    m8_constX2E81Instance instance;
    m8_constX2E81Instantiate(&instance, resolveTestImports);
    printStart("const.81.wasm");
}
