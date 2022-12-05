
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.58.h"

void test() {
    const58Instance instance;
    const58Instantiate(&instance, resolveTestImports);
    printStart("const.58.wasm");
}
