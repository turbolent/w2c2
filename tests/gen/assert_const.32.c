
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.32.h"

void test() {
    m8_constX2E32Instance instance;
    m8_constX2E32Instantiate(&instance, resolveTestImports);
    printStart("const.32.wasm");
}
