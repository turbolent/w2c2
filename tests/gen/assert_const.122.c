
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.122.h"

void test() {
    const122Instance instance;
    const122Instantiate(&instance, resolveTestImports);
    printStart("const.122.wasm");
}
