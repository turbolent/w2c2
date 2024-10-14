
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_unreached-valid.0.h"

void test() {
    unreachedvalid0Instance instance;
    unreachedvalid0Instantiate(&instance, resolveTestImports);
    printStart("unreached-valid.0.wasm");
}
