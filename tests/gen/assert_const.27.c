
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.27.h"

void test() {
    const27Instance instance;
    const27Instantiate(&instance, resolveTestImports);
    printStart("const.27.wasm");
}
