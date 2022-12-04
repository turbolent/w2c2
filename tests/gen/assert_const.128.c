
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.128.h"

void test() {
    const128Instance instance;
    const128Instantiate(&instance, resolveTestImports);
    printStart("const.128.wasm");
}
