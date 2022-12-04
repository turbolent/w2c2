
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.0.h"

void test() {
    const0Instance instance;
    const0Instantiate(&instance, resolveTestImports);
    printStart("const.0.wasm");
}
