
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.141.h"

void test() {
    const141Instance instance;
    const141Instantiate(&instance, resolveTestImports);
    printStart("const.141.wasm");
}
