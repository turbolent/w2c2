
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.21.h"

void test() {
    const21Instance instance;
    const21Instantiate(&instance, resolveTestImports);
    printStart("const.21.wasm");
}
