
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.6.h"

void test() {
    m6_dataX2E6Instance instance;
    m6_dataX2E6Instantiate(&instance, resolveTestImports);
    printStart("data.6.wasm");
}
