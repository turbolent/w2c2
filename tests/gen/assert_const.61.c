
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.61.h"

void test() {
    const61Instance instance;
    const61Instantiate(&instance, resolveTestImports);
    printStart("const.61.wasm");
}
