
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_unreached-valid.1.h"

void test() {
    unreachedvalid1Instance instance;
    unreachedvalid1Instantiate(&instance, resolveTestImports);
    printStart("unreached-valid.1.wasm");
}
