
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.64.h"

void test() {
    const64Instance instance;
    const64Instantiate(&instance, resolveTestImports);
    printStart("const.64.wasm");
}
