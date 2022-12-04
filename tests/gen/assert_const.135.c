
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.135.h"

void test() {
    const135Instance instance;
    const135Instantiate(&instance, resolveTestImports);
    printStart("const.135.wasm");
}
