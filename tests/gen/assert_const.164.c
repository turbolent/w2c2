
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.164.h"

void test() {
    const164Instance instance;
    const164Instantiate(&instance, resolveTestImports);
    printStart("const.164.wasm");
}
