
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.34.h"

void test() {
    const34Instance instance;
    const34Instantiate(&instance, resolveTestImports);
    printStart("const.34.wasm");
}
