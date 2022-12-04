
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.65.h"

void test() {
    const65Instance instance;
    const65Instantiate(&instance, resolveTestImports);
    printStart("const.65.wasm");
}
