
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.76.h"

void test() {
    const76Instance instance;
    const76Instantiate(&instance, resolveTestImports);
    printStart("const.76.wasm");
}
