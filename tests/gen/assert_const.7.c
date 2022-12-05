
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.7.h"

void test() {
    const7Instance instance;
    const7Instantiate(&instance, resolveTestImports);
    printStart("const.7.wasm");
}
