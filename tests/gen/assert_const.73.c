
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.73.h"

void test() {
    const73Instance instance;
    const73Instantiate(&instance, resolveTestImports);
    printStart("const.73.wasm");
}
