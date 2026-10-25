
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.24.h"

void test() {
    m8_constX2E24Instance instance;
    m8_constX2E24Instantiate(&instance, resolveTestImports);
    printStart("const.24.wasm");
}
