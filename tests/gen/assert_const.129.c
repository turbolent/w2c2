
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.129.h"

void test() {
    const129Instance instance;
    const129Instantiate(&instance, resolveTestImports);
    printStart("const.129.wasm");
}
