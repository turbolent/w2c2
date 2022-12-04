
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.33.h"

void test() {
    const33Instance instance;
    const33Instantiate(&instance, resolveTestImports);
    printStart("const.33.wasm");
}
