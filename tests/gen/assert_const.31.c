
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.31.h"

void test() {
    const31Instance instance;
    const31Instantiate(&instance, resolveTestImports);
    printStart("const.31.wasm");
}
