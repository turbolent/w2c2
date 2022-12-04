
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.71.h"

void test() {
    const71Instance instance;
    const71Instantiate(&instance, resolveTestImports);
    printStart("const.71.wasm");
}
