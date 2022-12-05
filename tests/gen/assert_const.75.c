
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.75.h"

void test() {
    const75Instance instance;
    const75Instantiate(&instance, resolveTestImports);
    printStart("const.75.wasm");
}
