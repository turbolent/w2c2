
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.35.h"

void test() {
    const35Instance instance;
    const35Instantiate(&instance, resolveTestImports);
    printStart("const.35.wasm");
}
