
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.61.h"

void test() {
    m8_constX2E61Instance instance;
    m8_constX2E61Instantiate(&instance, resolveTestImports);
    printStart("const.61.wasm");
}
