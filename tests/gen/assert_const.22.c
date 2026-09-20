
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.22.h"

void test() {
    m8_constX2E22Instance instance;
    m8_constX2E22Instantiate(&instance, resolveTestImports);
    printStart("const.22.wasm");
}
