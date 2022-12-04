
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.60.h"

void test() {
    const60Instance instance;
    const60Instantiate(&instance, resolveTestImports);
    printStart("const.60.wasm");
}
