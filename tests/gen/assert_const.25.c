
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.25.h"

void test() {
    m8_constX2E25Instance instance;
    m8_constX2E25Instantiate(&instance, resolveTestImports);
    printStart("const.25.wasm");
}
