
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.1.h"

void test() {
    data1Instance instance;
    data1Instantiate(&instance, resolveTestImports);
    printStart("data.1.wasm");
}
