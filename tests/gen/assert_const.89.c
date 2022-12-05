
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.89.h"

void test() {
    const89Instance instance;
    const89Instantiate(&instance, resolveTestImports);
    printStart("const.89.wasm");
}
