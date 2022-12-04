
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.57.h"

void test() {
    const57Instance instance;
    const57Instantiate(&instance, resolveTestImports);
    printStart("const.57.wasm");
}
