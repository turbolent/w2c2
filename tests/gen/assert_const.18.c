
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.18.h"

void test() {
    const18Instance instance;
    const18Instantiate(&instance, resolveTestImports);
    printStart("const.18.wasm");
}
