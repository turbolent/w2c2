
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.68.h"

void test() {
    const68Instance instance;
    const68Instantiate(&instance, resolveTestImports);
    printStart("const.68.wasm");
}
