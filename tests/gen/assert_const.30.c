
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.30.h"

void test() {
    m8_constX2E30Instance instance;
    m8_constX2E30Instantiate(&instance, resolveTestImports);
    printStart("const.30.wasm");
}
