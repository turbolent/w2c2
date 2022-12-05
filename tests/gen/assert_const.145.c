
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.145.h"

void test() {
    const145Instance instance;
    const145Instantiate(&instance, resolveTestImports);
    printStart("const.145.wasm");
}
