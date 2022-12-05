
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.15.h"

void test() {
    const15Instance instance;
    const15Instantiate(&instance, resolveTestImports);
    printStart("const.15.wasm");
}
