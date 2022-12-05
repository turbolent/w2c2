
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.29.h"

void test() {
    const29Instance instance;
    const29Instantiate(&instance, resolveTestImports);
    printStart("const.29.wasm");
}
