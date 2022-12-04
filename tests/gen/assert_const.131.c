
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.131.h"

void test() {
    const131Instance instance;
    const131Instantiate(&instance, resolveTestImports);
    printStart("const.131.wasm");
}
