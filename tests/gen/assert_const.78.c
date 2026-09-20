
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.78.h"

void test() {
    m8_constX2E78Instance instance;
    m8_constX2E78Instantiate(&instance, resolveTestImports);
    printStart("const.78.wasm");
}
