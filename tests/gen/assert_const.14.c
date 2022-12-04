
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.14.h"

void test() {
    const14Instance instance;
    const14Instantiate(&instance, resolveTestImports);
    printStart("const.14.wasm");
}
