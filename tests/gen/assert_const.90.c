
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.90.h"

void test() {
    const90Instance instance;
    const90Instantiate(&instance, resolveTestImports);
    printStart("const.90.wasm");
}
