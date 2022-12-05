
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.115.h"

void test() {
    const115Instance instance;
    const115Instantiate(&instance, resolveTestImports);
    printStart("const.115.wasm");
}
