
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.72.h"

void test() {
    m8_constX2E72Instance instance;
    m8_constX2E72Instantiate(&instance, resolveTestImports);
    printStart("const.72.wasm");
}
