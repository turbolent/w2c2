
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.126.h"

void test() {
    m9_constX2E126Instance instance;
    m9_constX2E126Instantiate(&instance, resolveTestImports);
    printStart("const.126.wasm");
}
