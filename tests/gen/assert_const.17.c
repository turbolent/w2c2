
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.17.h"

void test() {
    const17Instance instance;
    const17Instantiate(&instance, resolveTestImports);
    printStart("const.17.wasm");
}
