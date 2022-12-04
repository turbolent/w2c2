
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.155.h"

void test() {
    const155Instance instance;
    const155Instantiate(&instance, resolveTestImports);
    printStart("const.155.wasm");
}
