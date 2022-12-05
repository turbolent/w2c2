
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.111.h"

void test() {
    const111Instance instance;
    const111Instantiate(&instance, resolveTestImports);
    printStart("const.111.wasm");
}
