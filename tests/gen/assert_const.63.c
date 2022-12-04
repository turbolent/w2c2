
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.63.h"

void test() {
    const63Instance instance;
    const63Instantiate(&instance, resolveTestImports);
    printStart("const.63.wasm");
}
