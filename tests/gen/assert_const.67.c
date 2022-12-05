
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.67.h"

void test() {
    const67Instance instance;
    const67Instantiate(&instance, resolveTestImports);
    printStart("const.67.wasm");
}
