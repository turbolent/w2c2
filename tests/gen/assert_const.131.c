
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.131.h"

void test() {
    m9_constX2E131Instance instance;
    m9_constX2E131Instantiate(&instance, resolveTestImports);
    printStart("const.131.wasm");
}
