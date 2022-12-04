
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.66.h"

void test() {
    const66Instance instance;
    const66Instantiate(&instance, resolveTestImports);
    printStart("const.66.wasm");
}
