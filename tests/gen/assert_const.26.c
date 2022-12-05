
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.26.h"

void test() {
    const26Instance instance;
    const26Instantiate(&instance, resolveTestImports);
    printStart("const.26.wasm");
}
