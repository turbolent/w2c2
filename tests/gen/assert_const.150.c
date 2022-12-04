
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.150.h"

void test() {
    const150Instance instance;
    const150Instantiate(&instance, resolveTestImports);
    printStart("const.150.wasm");
}
