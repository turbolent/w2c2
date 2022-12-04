
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.170.h"

void test() {
    const170Instance instance;
    const170Instantiate(&instance, resolveTestImports);
    printStart("const.170.wasm");
}
