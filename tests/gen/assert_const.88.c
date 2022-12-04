
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.88.h"

void test() {
    const88Instance instance;
    const88Instantiate(&instance, resolveTestImports);
    printStart("const.88.wasm");
}
