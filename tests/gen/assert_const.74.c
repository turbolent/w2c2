
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.74.h"

void test() {
    const74Instance instance;
    const74Instantiate(&instance, resolveTestImports);
    printStart("const.74.wasm");
}
