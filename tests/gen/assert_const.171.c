
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.171.h"

void test() {
    const171Instance instance;
    const171Instantiate(&instance, resolveTestImports);
    printStart("const.171.wasm");
}
