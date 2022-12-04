
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.119.h"

void test() {
    const119Instance instance;
    const119Instantiate(&instance, resolveTestImports);
    printStart("const.119.wasm");
}
