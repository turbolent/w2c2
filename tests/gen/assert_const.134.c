
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.134.h"

void test() {
    const134Instance instance;
    const134Instantiate(&instance, resolveTestImports);
    printStart("const.134.wasm");
}
