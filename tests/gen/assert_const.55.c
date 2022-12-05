
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.55.h"

void test() {
    const55Instance instance;
    const55Instantiate(&instance, resolveTestImports);
    printStart("const.55.wasm");
}
