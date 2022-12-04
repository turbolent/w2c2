
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.0.h"

void test() {
    data0Instance instance;
    data0Instantiate(&instance, resolveTestImports);
    printStart("data.0.wasm");
}
