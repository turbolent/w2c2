
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.1.h"

void test() {
    const1Instance instance;
    const1Instantiate(&instance, resolveTestImports);
    printStart("const.1.wasm");
}
