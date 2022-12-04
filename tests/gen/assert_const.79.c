
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.79.h"

void test() {
    const79Instance instance;
    const79Instantiate(&instance, resolveTestImports);
    printStart("const.79.wasm");
}
