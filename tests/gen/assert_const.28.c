
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.28.h"

void test() {
    m8_constX2E28Instance instance;
    m8_constX2E28Instantiate(&instance, resolveTestImports);
    printStart("const.28.wasm");
}
