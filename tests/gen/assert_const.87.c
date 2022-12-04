
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.87.h"

void test() {
    const87Instance instance;
    const87Instantiate(&instance, resolveTestImports);
    printStart("const.87.wasm");
}
