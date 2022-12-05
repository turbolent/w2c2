
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.152.h"

void test() {
    const152Instance instance;
    const152Instantiate(&instance, resolveTestImports);
    printStart("const.152.wasm");
}
