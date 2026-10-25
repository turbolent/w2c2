
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.1.h"

void test() {
    m6_dataX2E1Instance instance;
    m6_dataX2E1Instantiate(&instance, resolveTestImports);
    printStart("data.1.wasm");
}
