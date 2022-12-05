
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.13.h"

void test() {
    const13Instance instance;
    const13Instantiate(&instance, resolveTestImports);
    printStart("const.13.wasm");
}
