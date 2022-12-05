
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.81.h"

void test() {
    const81Instance instance;
    const81Instantiate(&instance, resolveTestImports);
    printStart("const.81.wasm");
}
