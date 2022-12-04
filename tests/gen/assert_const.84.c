
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.84.h"

void test() {
    const84Instance instance;
    const84Instantiate(&instance, resolveTestImports);
    printStart("const.84.wasm");
}
