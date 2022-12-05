
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.160.h"

void test() {
    const160Instance instance;
    const160Instantiate(&instance, resolveTestImports);
    printStart("const.160.wasm");
}
