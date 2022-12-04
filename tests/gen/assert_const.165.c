
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.165.h"

void test() {
    const165Instance instance;
    const165Instantiate(&instance, resolveTestImports);
    printStart("const.165.wasm");
}
