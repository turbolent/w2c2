
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.56.h"

void test() {
    const56Instance instance;
    const56Instantiate(&instance, resolveTestImports);
    printStart("const.56.wasm");
}
