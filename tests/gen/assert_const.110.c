
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.110.h"

void test() {
    const110Instance instance;
    const110Instantiate(&instance, resolveTestImports);
    printStart("const.110.wasm");
}
