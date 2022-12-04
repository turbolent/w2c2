
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_type.0.h"

void test() {
    type0Instance instance;
    type0Instantiate(&instance, resolveTestImports);
    printStart("type.0.wasm");
}
