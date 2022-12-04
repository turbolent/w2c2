
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.6.h"

void test() {
    const6Instance instance;
    const6Instantiate(&instance, resolveTestImports);
    printStart("const.6.wasm");
}
