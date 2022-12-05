
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.144.h"

void test() {
    const144Instance instance;
    const144Instantiate(&instance, resolveTestImports);
    printStart("const.144.wasm");
}
