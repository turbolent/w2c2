
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.132.h"

void test() {
    m9_constX2E132Instance instance;
    m9_constX2E132Instantiate(&instance, resolveTestImports);
    printStart("const.132.wasm");
}
