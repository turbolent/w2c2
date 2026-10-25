
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.164.h"

void test() {
    m9_constX2E164Instance instance;
    m9_constX2E164Instantiate(&instance, resolveTestImports);
    printStart("const.164.wasm");
}
