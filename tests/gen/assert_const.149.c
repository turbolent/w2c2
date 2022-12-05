
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.149.h"

void test() {
    const149Instance instance;
    const149Instantiate(&instance, resolveTestImports);
    printStart("const.149.wasm");
}
