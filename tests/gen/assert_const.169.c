
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.169.h"

void test() {
    const169Instance instance;
    const169Instantiate(&instance, resolveTestImports);
    printStart("const.169.wasm");
}
