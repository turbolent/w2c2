
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.114.h"

void test() {
    const114Instance instance;
    const114Instantiate(&instance, resolveTestImports);
    printStart("const.114.wasm");
}
