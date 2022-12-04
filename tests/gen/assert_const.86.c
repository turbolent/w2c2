
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.86.h"

void test() {
    const86Instance instance;
    const86Instantiate(&instance, resolveTestImports);
    printStart("const.86.wasm");
}
