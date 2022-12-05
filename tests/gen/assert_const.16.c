
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.16.h"

void test() {
    const16Instance instance;
    const16Instantiate(&instance, resolveTestImports);
    printStart("const.16.wasm");
}
