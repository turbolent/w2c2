
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.111.h"

void test() {
    m9_constX2E111Instance instance;
    m9_constX2E111Instantiate(&instance, resolveTestImports);
    printStart("const.111.wasm");
}
