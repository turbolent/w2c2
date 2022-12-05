
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.153.h"

void test() {
    const153Instance instance;
    const153Instantiate(&instance, resolveTestImports);
    printStart("const.153.wasm");
}
