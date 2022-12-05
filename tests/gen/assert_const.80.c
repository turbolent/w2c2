
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.80.h"

void test() {
    const80Instance instance;
    const80Instantiate(&instance, resolveTestImports);
    printStart("const.80.wasm");
}
