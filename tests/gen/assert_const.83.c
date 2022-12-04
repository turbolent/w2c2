
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.83.h"

void test() {
    const83Instance instance;
    const83Instantiate(&instance, resolveTestImports);
    printStart("const.83.wasm");
}
