
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.123.h"

void test() {
    m9_constX2E123Instance instance;
    m9_constX2E123Instantiate(&instance, resolveTestImports);
    printStart("const.123.wasm");
}
