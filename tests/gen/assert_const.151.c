
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.151.h"

void test() {
    const151Instance instance;
    const151Instantiate(&instance, resolveTestImports);
    printStart("const.151.wasm");
}
