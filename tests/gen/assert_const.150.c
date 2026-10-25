
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.150.h"

void test() {
    m9_constX2E150Instance instance;
    m9_constX2E150Instantiate(&instance, resolveTestImports);
    printStart("const.150.wasm");
}
