
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.82.h"

void test() {
    const82Instance instance;
    const82Instantiate(&instance, resolveTestImports);
    printStart("const.82.wasm");
}
