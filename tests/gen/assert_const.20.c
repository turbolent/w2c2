
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.20.h"

void test() {
    const20Instance instance;
    const20Instantiate(&instance, resolveTestImports);
    printStart("const.20.wasm");
}
